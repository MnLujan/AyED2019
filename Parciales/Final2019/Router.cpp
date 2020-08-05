//
// Created by mlujan on 4/3/20.
//

#include <libzvbi.h>
#include "Router.h"
using namespace std;

/**
 * @brief Inicializa las variables, contrsuctor sin parametros. (Constructor 1)
 */
Router::Router ()
{
  IPRouter = 0;
  N_R = 0;
}

/**
 * @brief Se inicializan las variables con los parametros pasados. (Constructor 2).
 */
Router::Router (uint16_t ip, uint8_t nr)
{
  IPRouter = ip;
  N_R = nr;

  ///@brief Lista de router vecinos
  this->Rvecinos = new Lista<Router *>;

  ///@brief Lista de Maquinas conectadas
  this->Maqui = new Lista<Maquina *>;

  ///@brief Lista de Input a enviar
  this->Input = new Lista<Packages *>;

  ///@brief Lista de paginas armadas para las maquinas
  this->Pag = new Lista<Pagina *>;

  ///@brief Lista de colas de salida del router
  this->BuffersSalida = new Lista<Buffer *>;

  ///@brief Lista de Listas de paquetes a compaginar para armar las paginas a entregar
  this->package2pag = new Lista<Lista<Packages *> *>;
}

/**
 * @brief Metodo encargado de retornar el numero de Ip del router.
 * @return uint8_t IPRouter
 */
uint16_t Router::getIpRouter () const
{
  return IPRouter;
}

/**
 * @brief Metodo encargado de retornar el puntero a la lista de paginas almacenadas en el Router.
 * @return puntero de tipo Lista<Pagina *>, NULL en caso que no exista dicha Lista.
 */
Lista<Pagina *> *Router::getPagList ()
{
  if (Pag != nullptr)
    {
      return this->Pag;
    }
  else
    {
      return nullptr;
    }
}

/**
 * @brief Metodo encargado de retornar el el puntero a la lista donde se encuentran
 * almacenado los Input.
 * @return Puntero de tipo lista. Input.
 */
Lista<Packages *> *Router::getInputList ()
{
  if (Input != nullptr)
    {
      return Input;
    }
  else
    {
      return NULL;
    }
}

/**
 * @brief Metodo encargado de devolver el puntero a una lista que almacena las maquinas
 * que se encuentran conectadas al router
 * @return puntero de Lista, Maqui.
 */
Lista<Maquina *> *Router::getMaquiList ()
{
  if (Maqui != NULL)
    {
      return Maqui;
    }
  else
    {
      return NULL;
    }
}

/**
 * @brief Metodo encargado de retornar el puntero a la Lista de router que se encuentran
 * conectados a este.
 * @return puntero del tipo Lista. Rvecinos.
 */
Lista<Router *> *Router::getRouterList ()
{
  if (Rvecinos != NULL)
    {
      return Rvecinos;
    }
  else
    {
      return NULL;
    }
}

/**
 * @brief  Metodo encargado de devolver el numero del router.
 * @return entero de 8 bits que indica el numero del router. N_R.
 */
uint8_t Router::getN_R ()
{
  return N_R;
}

/**
 * @brief Metodo encargado de recibir la pagina y desarmarla en los Input necesarrios para transimitir.
 * Estos los coloca en la cola de entrada del router.
 **/
void Router::toRecivePag (Pagina *p)
{
  string data = p->getDato ();
  for (int i = 0; i < data.size (); i++)
    {
      char dataAux = data[i];
      auto auxPackage = new Packages (dataAux, p->getOrigen (), p->getDestino (), i, data.size (), p->getIDpag ());

      /* Lo agrego a la cola de entrada del router */
      this->getInputList ()->Add (auxPackage);
    }

}

/**
 * @brief Metodo encargado de conectar un nuevo router vecino
 * @param R Router a conectar
 */
void Router::linkRouter (Router *R)
{
  this->Rvecinos->Add (R);
  /* Crea el buffer, posteriormente se le pasara la lista de paginas */
  auto *temp = new Buffer (nullptr, R->getIpRouter ());
  this->BuffersSalida->Add (temp);
}

/**
 * @brief Metodo encargado de conectar una maquina al router actual.
 * @param M maquina a conectar
 */
void Router::linkMachine (Maquina *M)
{
  this->Maqui->Add (M);
  /* Crea el buffer, posteriormente se le pasara la lista de paginas */
  auto *temp = new Buffer (nullptr, M->getIP ());
  this->BuffersSalida->Add (temp);
}

/**
 * @brief Metodo encargado de consultar si hay elementos en la cola de entrada.
 * @return True en caso de que la cola este vacia, False, caso contrario
 */
bool Router::StateInput ()
{
  return this->getInputList ()->esvacia ();
}

/**
 * @brief Metodo encargado de recibir un paquete proveniente de otro Router, identificar para quien es y
 * colocarlo en la cola correspondiente. En caso de que no pertenezca a ninguna maquina hija, se coloca en la cola
 * de entrada del Router, para despues ver que hacer.
 */
void Router::toRecivePackage (Packages *newPack)
{
  for (int i = 0; i < this->getMaquiList ()->get_size (); i++)
    {
      /* Verifico si el paquete recibido es para alguna de las maquinas conectadas */
      if (this->getMaquiList ()->get_nodo (i)->getdato ()->getIP () == newPack->getDestino ())
        {
          encolar (newPack, 0);
          return;
        }
    }
  /* En caso de que no sea para alguna maquina hija se envia a la cola de entrada */
  encolar (newPack, newPack->getDestino ());
}

/**
 * @brief Metodo encargado de buscar y colocar el paquete en la cola de paquetes a compaginar o colocar el
 * paquete en la cola de entrada.
 * @param newPackage Puntero al paquete a encolar
 * @param ip direccion del paquete.
 */
void Router::encolar (Packages *newPackage, int ip)
{
  if (ip == 0)
    {
      for (int i = 0; i < this->package2pag->get_size (); i++)
        {
          bool match = false;
          /* Verifico que el IDpag, origen y destino correspondan con alguno de los paquetes. Los tres deben coincidir */
          if (this->package2pag->get_nodo (i)->getdato ()->get_dato ()->getIdPag () == newPackage->getIdPag () &&
              this->package2pag->get_nodo (i)->getdato ()->get_dato ()->getDestino () == newPackage->getDestino () &&
              this->package2pag->get_nodo (i)->getdato ()->get_dato ()->getOrigen () == newPackage->getOrigen ())
            {
              this->package2pag->get_nodo (i)->getdato ()->Add (newPackage);
              match = true;
            }
          if (!match)
            {
              /* En caso de no haber encontrado el paquete en la lista, lo agrego */
              this->package2pag->Add (new Lista<Packages *>);
              this->package2pag->get_nodo (0)->getdato ()->Add (newPackage);
            }
        }
    }
  else
    {
      /* En caso de q no sea para mi, lo mando a la cola de entrada y verifico para quien es, para redireccionar */
      this->getInputList ()->Add (newPackage);
    }
}

/**
 * @brief Metodo encargado de agregar un Buffer de conexion en el router.
 */
void Router::agreeBuffer(Buffer *newB) {
  this->BuffersSalida->Add(newB);
}