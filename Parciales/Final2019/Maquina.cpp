//
// Created by mlujan on 3/30/20.
//

#include <stdint.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

#include "Maquina.h"
#include "Pagina.h"

using namespace std;

/**
 * @brief Constructor de la clase maquina, inicializa todas las variables, crea un numero
 * aleatorio de datos que se enviaran y crea los datos a enviar.
 * @param ip
 * @param bw
 */
Maquina::Maquina (uint8_t ip, int bw)
{
  this->IpMaquina = ip;
  this->BW = bw;
  this->PaginasEnviadas = 0;
  this->envio = new Lista<string>;
  this->recep = new Lista<Pagina>;

  /* Genero aleatoriamente la cantidad de paginas que va a enviar la maquina */
  srand (IpMaquina * time (nullptr));
  cantPag = rand () % 10 + 1;
  //CrearDatos ();
  CrearAux ();
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
      envio->Add (std);
      fin++;
    }
  return;
}

/**
 * @brief Metodo que devuelve entero de 8bits que forma el ip de la maquina
 * @return IpMaquina
 */
uint8_t Maquina::getIP ()
{
  return this->IpMaquina;
}

/**
 * @brief Metodo encargado de devolver el ancho de banda asignado a la maquina
 * @return BW
 */
int Maquina::GetBW ()
{
  return this->BW;
}

/**
 * @brief Metodo encargado de actualizar el valor de ancho de banda en el caso de que
 * cambie.
 * @param bw nuevo ancho de banda a setear
 */
void Maquina::setBW (int bw)
{
  this->BW = bw;
  return;
}

/**
 * @brief Metodo encargado de devolver la cantidad de paginas que enviara la maquina
 * @return cantPag
 */
int Maquina::GetCantPag ()
{
  return cantPag;
}

/**
 * @brief Metodo encarcado de extraer un dato generado aleatoriamente en el constructor y crear una pagina
 * para posteriormente enviarla al router. Borra el dato extraido de la lista.
 * @param dest direccion de destino para la pagina
 * @return puntero a una pagina
 */
Pagina *Maquina::CreatedPage (uint8_t dest)
{
  if (cantPag != 0)
    {
      string data = envio->get_dato ();
      envio->borrarCabeza ();
      Pagina *nuevo = new Pagina (data, this->getIP (), dest);
      this->cantPag--;
      return nuevo;
    }
  else
    {
      printf ("Ya se enviaron todas las paginas que debian\n");
      return NULL;
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
  Pagina *temp = p;
  recep->Add (*temp);
  cout << "El dato recibido es el siguiente: " << temp->getDato () << endl;
}

/**
 * @brief Metodo encargado de devolver la cantidad de paginas que recibio la maquina.
 * @return int size
 */
int Maquina::cantPagReceive() {
  return recep->get_size();
}

/**
 * @brief Metodo encargado de verificar si la maquina tiene paginas pendientes por enviar
 * @return true si hay paginas pendientes o false caso contrario
 */
bool Maquina::Pending() {
  return this->cantPag != 0;
}
