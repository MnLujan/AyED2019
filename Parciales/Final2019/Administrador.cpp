//
// Created by mlujan on 5/17/20.
//

#include <iostream>
#include "Administrador.h"

/**
 * @brief Constructor de la clase
 */
Administrador::Administrador (Logger *log)
{
  this->links = new Lista<Lista<NodoGrafo *> *> ();
  this->routers = new Lista<Router *> ();
  this->pagReceive = 0;
  this->pagtoSend = 0;
  this->log = log;

  //Construyo el grafo
  this->BuildGraph ();

  /*Seteo la cantidad de paginas a enviar.*/
  pag2Send ();

  /* Creo el objeto necesario para ejecutra Dijkstra */
  Mpls *route = new Mpls (this->links);

}

/**
 * @brief Metodo encargado de la generacion del grafo que representa la red, apartir de un archivo.
 */
void Administrador::BuildGraph ()
{

  /* Leo los datos */
  Lista<string> *info = ReadFile ();

  /* Routers-Host */
  uint8_t N_R;
  uint8_t Host;
  uint8_t BW;
  uint16_t Ip_R = 0;

  /* Router-Router */
  uint8_t N_R1;
  uint8_t N_R2;
  uint8_t BW_R;
  uint16_t Ip_R1 = 0;
  uint16_t Ip_R2 = 0;

  int bucle = info->get_size ();
  //pedir cabeza y borrar
  for (int i = 0; i < info->get_size (); ++i)
    {
      if (info->getCabeza ()->getdato () == "+")
        {
          info->borrarCabeza ();

          N_R = stoi (info->Pop ());
          Host = stoi (info->Pop ());
          //El ancho de banda entre los routers y las maquinas siempre es 1 (ya q envian y reciben paginas)
          BW = 1;
          Ip_R += (1 << 8);

          this->ListRouter (Ip_R, N_R);
          this->linkMachines (N_R, Host, Ip_R, BW);
        }
      else if (info->getCabeza ()->getdato () == "-")
        {
          info->borrarCabeza ();

          N_R1 = stoi (info->Pop ());
          N_R2 = stoi (info->Pop ());
          BW_R = stoi (info->Pop ());

          Router *tempR1 = this->routers->get_nodo (N_R1 - 1)->getdato ();
          Router *tempR2 = this->routers->get_nodo (N_R2 - 1)->getdato ();

          auto *link1 = new NodoGrafo (tempR1, BW_R);
          auto *link2 = new NodoGrafo (tempR2, BW_R);

          //Busco el router dentro de mi lista de routers y los conecto
          this->links->get_nodo (N_R1 - 1)->getdato ()->Add (link2); //Router 1
          this->links->get_nodo (N_R2 - 1)->getdato ()->Add (link1); //Router 2

          //Creo los buffers de los routers con la correspondiente IP.
          auto *buffer1to2 = new Buffer (new Lista<Packages *>, tempR2->getIpRouter ());
          auto *buffer2to1 = new Buffer (new Lista<Packages *>, tempR1->getIpRouter ());

          tempR1->agreeBuffer (buffer1to2);
          tempR2->agreeBuffer (buffer2to1);

          //Indico el router vecino
          tempR1->linkRouter (tempR2);
          tempR2->linkRouter (tempR1);

        }
      else
        {
          //Elimino si no fue ninguno de los caracteres q busco.
          info->borrarCabeza ();
          if (info->esvacia ())
            {
              break;
            }
        }
    }

}

/**
 * @brief Metodo en encargado de leer el archivo parametrizador armando una lista con todos los datos.
 * @return characters. Puntero a Lista.
 */
Lista<string> *Administrador::ReadFile ()
{
  string file = "ConfigRed";
  ifstream fi (file);

  auto *characters = new Lista<string> ();
  char *ptr;
  char del[4] = " \n\t";

  //Leo el archivo para la construccion del Grafo
  while (!fi.eof ())
    {
      char arr[10000];
      fi.getline (arr, 10000);
      if (arr[0] == '\0')
        {
          continue;
        }
      ptr = strtok (arr, del);
      string aux (ptr);
      //Lo agrego a la lista
      characters->Add (aux);
      while ((ptr = strtok (NULL, del)) != NULL)
        {
          string aux2 (ptr);
          characters->Add (aux2);
        }
    }

  return characters;
}

/**
 *  @brief Metodo encargado de listar el Router en la lista de Routers y agregarlo al grafo.
 *  @param ip numero de ip del router
 *  @param n_r numero de router
 */
void Administrador::ListRouter (uint16_t ip, uint16_t n_r)
{
  //Se agrega a la lista de routers
  auto *router = new Router (ip, n_r);
  this->routers->Add (router);

  //Se agrega en la lista de conexiones
  auto *nuevo = new NodoGrafo (router, 0);
  auto *listNodoGrafo = new Lista<NodoGrafo *> ();
  listNodoGrafo->Add (nuevo);
  this->links->Add (listNodoGrafo);
}

/**
 * @brief Metodo encargado de conectar las maquinas con el router padre.
 * @param n_r numero de router
 * @param bw Ancho de banda entre la maquina y el router (el cual es siempre 1)
 * @param ip_r ip del router padre
 * @param nhost numero de maquina
 */
void Administrador::linkMachines (uint16_t n_r, uint16_t nhost, uint16_t ip_r, uint16_t bw)
{
  //Direccionamiento disponible
  static int indice = 0;

  for (int i = 1; i <= nhost; i++)
    {
      auto *maquina = new Maquina (ip_r + i, bw);
      //Busco el router en la lista, pido el nodo y agrego la maquina
      this->routers->get_nodo (n_r - 1)->getdato ()->linkMachine (maquina);

      this->addressAvailabe[indice] = ip_r + i;
      this->quantAddres++;
      indice++;
    }
}

/**
 * @brief Establece la cantidad de paginas a enviar, tomando este numero desde los routers.
 */
void Administrador::pag2Send ()
{
  for (int i = 0; i < this->routers->get_size (); i++)
    {
      //Busco en todos los routers asociados
      Router *temp = this->routers->get_nodo (i)->getdato ();
      for (int j = 0; j < temp->getMaquiList ()->get_size (); j++)
        {
          //Le pido la cantidad de paginas a enviar a cada maquina que tiene el router actual.
          this->pagtoSend += temp->getMaquiList ()->get_nodo (j)->getdato ()->GetCantPag ();
        }
    }
}

/**
 * @brief Calcula los pesos entre los routers del grafo.
 */
void Administrador::weighing ()
{
  for (int i = 0; i < this->links->get_size (); i++)
    {

      //Voy router por router viendo sus vecinos
      NodoGrafo *father = this->links->get_nodo (i)->getdato ()->get_dato ();
      for (int j = 1; j < this->links->get_nodo (i)->getdato ()->get_size (); j++)
        {
          //Obtengo cada uno de los routers vecinos
          NodoGrafo *son = this->links->get_nodo (i)->getdato ()->get_nodo (j)->getdato ();

          uint16_t ip_son = son->getRouter ()->getIpRouter ();

          int lenghtQueue = father->getRouter ()->getColaSalida (ip_son);

          //BW entre routers
          uint8_t bw = son->getBW ();

          /* Calculo */
          int peso = (lenghtQueue / bw) + 1;

          /* Actualizo el peso */
          son->setPeso (peso);

          string msj = "R" + to_string (father->getRouter ()->getN_R ()) + " IP: "
                       + to_string (father->getRouter ()->getIpRouter ()) + " y R"
                       + to_string (son->getRouter ()->getN_R ()) + " IP: "
                       + to_string (ip_son) + " | Recompuntan su peso | Peso actualizado: " + to_string (peso) + "\n";

          /* Muestro en pantalla */
          cout << msj << endl;

          /* Escribo en el log */
          log->write(msj);

        }

    }
}

/**
 * @brief Metodo encargado de ejecutar los metodos necesarios para crear la ruta entre el origen y el destino pasados
 * como parametro
 * @param init direccion inicial
 * @param dest direccion de destino
 * @return vector con cada uno de los vertices
 */
vector<uint16_t> Administrador::getRoad (int init, int dest)
{
  /* Calculo los pesos nuevamente */
  this->weighing ();

  /* Se calculan los caminos */
  route->Dijkstra (init);

  /* Construyo la Ruta */
  route->BuildRoute (dest);

  /* Retorno la ruta */
  return route->getRoute ();
}

/**
 * @brief Muestra por pantalla el grafo de la red.
 */
void Administrador::printGraph ()
{
  /* Muestro los routers */
  string msj = "--------------------------------------------------------\n"
               "                 Composicion de la Red\n"
               "--------------------------------------------------------";
  for (int i = 0; i < this->routers->get_size (); i++)
    {
      auto *temp = this->routers->get_nodo (i)->getdato ();
      msj = msj + "\n->R" + to_string (temp->getN_R ()) + " IP: " +
            to_string (temp->getIpRouter ());
      for (int j = 0; j < temp->getMaquiList ()->get_size (); j++)
        {
          msj = msj + "\n    |-->Maquina-" + to_string (j) + " IP: "
                + to_string (temp->getMaquiList ()->get_nodo (j)->getdato ()->getIP ());
        }
    }

  msj = msj + "\n---------------------------------------------------------\n"
              "                 Conexiones entre Routers\n"
              "-----------------------------------------------------------";
  for (int i = 0; i < this->links->get_size (); ++i)
    {
      auto *temp = this->links->get_nodo (i)->getdato ();
      msj = msj + "\nR" + to_string (temp->get_nodo (0)->getdato ()->getRouter ()->getN_R ()) + " IP: "
            + to_string (temp->get_nodo (0)->getdato ()->getRouter ()->getIpRouter ());
      for (int j = 1; j < temp->get_size (); ++j)
        {
          msj = msj + "\n |_____R" + to_string (temp->get_nodo (j)->getdato ()->getRouter ()->getN_R ()) + " IP: "
                + to_string (temp->get_nodo (j)->getdato ()->getRouter ()->getIpRouter ());
        }
    }

  msj = msj + "\n--------------------------------------------------------\n"
              "               Paginas a enviar por Maquina:\n"
              "--------------------------------------------------------";
  for (int i = 0; i < this->routers->get_size (); ++i)
    {
      auto *temp = this->routers->get_nodo (i)->getdato ();
      msj = msj + "\n R" + to_string (temp->getN_R ()) + ": ";
      for (int j = 0; j < temp->getMaquiList ()->get_size (); ++j)
        {
          msj = msj + "\n    |->Maquina-" + to_string (j) + " enviara: "
                + to_string (temp->getMaquiList ()->get_nodo (j)->getdato ()->GetCantPag ());
        }
    }

  msj = msj + "\n Paginas totales a enviar: " + to_string (this->pagtoSend);

  /* Saco por pantalla */
  cout << msj << endl;

  /* Escribo en el Log */
  log->write (msj);

}

