//
// Created by mlujan on 4/3/20.
//

#include "Router.h"

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
Router::Router (uint8_t ip, uint8_t nr)
{
  IPRouter = ip;
  N_R = nr;

  ///@brief Lista de router vecinos
  this->Rvecinos = new Lista<Router *>;

  ///@brief Lista de Maquinas conectadas
  this->Maqui = new Lista<Maquina *>;

  ///@brief Lista de paquetes a enviar
  this->paquetes = new Lista<Packages *>;

  ///@brief Lista de paginas armadas para las maquinas
  this->Pag = new Lista<Pagina *>;

  ///@brief Lista de colas de salida del router
  this->Buffers = new Lista<Buffer *>;
}

/**
 * @brief Metodo encargado de retornar el numero de Ip del router.
 * @return uint8_t IPRouter
 */
uint8_t Router::getIpRouter ()
{
  return IPRouter;
}

/**
 * @brief Metodo encargado de retornar el puntero a la lista de paginas almacenadas en el Router.
 * @return puntero de tipo Lista<Pagina *>, NULL en caso que no exista dicha Lista.
 */
Lista<Pagina *> *Router::getPagList ()
{
  if (Pag != NULL)
    {
      return this->Pag;
    }
  else
    {
      return NULL;
    }
}

/**
 * @brief Metodo encargado de retornar el el puntero a la lista donde se encuentran
 * almacenado los paquetes.
 * @return Puntero de tipo lista. paquetes.
 */
Lista<Packages *> *Router::getPackList ()
{
  if (paquetes != NULL)
    {
      return paquetes;
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
 * @brief Metodo encargado de recibir la pagina a enviar y hacer los checkeos
 * correspondientes para las direcciones IP a las que se debe enviar.
 *
void Router::toRecivePag (Pagina *p)
{

}
 */

/**
 * @brief Metodo encargado de conectar un nuevo router vecino
 * @param R Router a conectar
 */
void Router::linkRouter (Router *R)
{
  this->Rvecinos->Add (R);
  Buffer *temp = new Buffer (NULL, R->getIpRouter ());
  this->Buffers->Add (temp);
}

/**
 * @brief Metodo encargado de conectar una maquina al router actual.
 * @param M maquina a conectar
 */
void Router::linkMachine (Maquina *M)
{
  this->Maqui->Add (M);
  Buffer *temp = new Buffer (NULL, M->getIP ());
  this->Buffers->Add (temp);
}

