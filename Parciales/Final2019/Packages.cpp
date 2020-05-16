//
// Created by mlujan on 4/2/20.
//

#include "Packages.h"

/**
 * Inicializa las variables del paquete.
 * @param l letra o dato
 * @param o direccion de origen
 * @param d direccion de destino
 * @param f numero de frame que pertenece el paquete
 * @param ft numero de frame totales que hay
 */
Packages::Packages (char l, uint8_t o, uint8_t d, int f, int ft)
{
  this->letra = l;
  this->origen = o;
  this->destino = d;
  this->frame = f;
  this->frameTotal = ft;
}

/**
 * @brief Metodo que devuelve la direccion de origen del paquete
 * @return entero de 8 bits de origen
 */
uint8_t Packages::getOrigen ()
{
  return this->origen;
}

/**
 * @brief Metodo encargado de entregar la direccion de destino del paquete
 * @return entero de 8 bits de destino
 */
uint8_t Packages::getDestino ()
{
  return this->destino;
}

/**
 * @brief Metodo encargado de entregar el numero del packete que conforma este.
 * @return int frame
 */
int Packages::getFrame ()
{
  return this->frame;
}

/**
 * @brief Metodo encargado de devolver el numero total de Input que conforman el
 * dato que se esta enviando a traves de la red
 * @return int frametotal
 */
int Packages::getFrameTotal ()
{
  return this->frameTotal;
}

/**
 * @brief Metodo encargado de entregar la letra que se encuentra en el paquete
 * @return char letra
 */
char Packages::getletra ()
{
  return this->letra;
}

/**
 * Metodo encargado de devolver el ID de la pagina a la que pertenece el paquete
 * @return
 */
uint8_t Packages::getIdPag() {
  return this->idpag;
}