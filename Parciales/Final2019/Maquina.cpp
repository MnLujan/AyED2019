//
// Created by mlujan on 3/30/20.
//


#include "Maquina.h"

using namespace std;

/**
 * @brief Constructor de la clase maquina, inicializa todas las variables, crea un numero
 * aleatorio de datos que se enviaran y crea los datos a enviar.
 * @param ip
 * @param bw
 */
Maquina::Maquina (uint16_t ip, int bw, Logger *l)
{
  this->IpMaquina = ip;
  this->BW = bw;
  this->PaginasEnviadas = 0;
  this->envio = new Lista<string>;
  this->recep = new Lista<Pagina *>;
  this->log = l;

  /* Genero aleatoriamente la cantidad de paginas que va a enviar la maquina */
  srand (IpMaquina * time (NULL));
  cantPag = rand () % 10 + 1;

  //this->CrearAux ();
  this->CrearDatos ();

}

/**
 * @brief Metodo encargado de crear palabras, para despues almacenarlas en una lista. Estas palabras seran las que
 * se enviaran posteriormente en forma de paginas.
 */
void Maquina::CrearDatos ()
{
  char dic[] = "abcdefghijklmnopqrstuvwxyz";
  char s[20];
  int cant = cantPag;
  int fin = 0;
  while (fin != cant)
    {
      int largo = rand () % 10 + 1;
      for (int j = 0; j < largo; j++)
        {
          s[j] = dic[rand () % (sizeof (dic) - 1)];
        }
      string std = string (s);
      this->envio->Add (std);
      fin++;
    }
  return;
}

/**
 * @brief Metodo que devuelve entero de 16bits que forma el ip de la maquina
 * @return IpMaquina
 */
uint16_t Maquina::getIP () const
{
  return this->IpMaquina;
}

/**
 * @brief Metodo encargado de devolver la cantidad de paginas que enviara la maquina
 * @return cantPag
 */
int Maquina::GetCantPag () const
{
  return cantPag;
}

/**
 * @brief Metodo encarcado de extraer un dato generado aleatoriamente en el constructor y crear una pagina
 * para posteriormente enviarla al router. Borra el dato extraido de la lista.
 * @param dest puntero a un Lista de posibles destinos. La maquina decide cual es.
 * @return puntero a una pagina
 */
Pagina *Maquina::CreatedPage (const uint16_t dest[], int numDir)
{
  if (cantPag != 0)
    {

      uint16_t ipDes = this->getIP ();
      /* Dato aleatorio */
      int random = rand () % (this->envio->get_size ());
      string data = this->envio->get_nodo (random)->getdato ();
      this->envio->DeletNode (random);

      /* Obtengo un nodo al azar y extraigo el IP, siempre distinto del IP propio de la maquina */
      while (ipDes == this->getIP ())
        {
          ipDes = dest[uint16_t (rand () % (numDir - 1))];
        }
      auto *nuevo = new Pagina (data, this->getIP (), ipDes, this->PaginasEnviadas + 1);
      this->PaginasEnviadas++;
      this->cantPag--;
      return nuevo;
    }
  else
    {
      printf ("Ya se enviaron todas las paginas que debian\n");
      return nullptr;
    }

}

/**
 * @brief Metodo creado con el fin de debagiar el trabajo
 */
void Maquina::CrearAux ()
{
  int cant = 0;
  fstream input;
  string line;
  input.open ("texto");

  while (input >> line)
    {
      envio->Add (line);
      cant++;
      if (cant == cantPag)
        {
          break;
        }
    }

  input.close ();

}

/**
 * @brief Metodo encargado de recibir la pagina entregada por el router y almacenarla en la lista de recepcion.
 * Saca por pantalla el dato de la pagina reciba.
 * @param p puntero a la pagina recibida.
 */
void Maquina::toReceive (Pagina *p)
{
  this->recep->Add (p);
  string msj =
      "\nRecepcion | MaquinaIP: " + to_string (this->getIP ()) + " | Nº Pag " + to_string (p->getIDpag ())
      + " | Origen " + to_string (p->getOrigen ()) + " | Destino "
      + to_string (p->getDestino ()) + " | Dato: " + p->getDato ();
  cout << msj << endl;
  this->log->write (msj);

}

/**
 * @brief Metodo encargado de devolver la cantidad de paginas que recibio la maquina.
 * @return int size
 */
int Maquina::cantPagReceive ()
{
  return recep->get_size ();
}

/**
 * @brief Metodo encargado de verificar si la maquina tiene paginas pendientes por enviar
 * @return true si hay paginas pendientes o false caso contrario
 */
bool Maquina::Pending ()
{
  return this->cantPag != 0;
}
