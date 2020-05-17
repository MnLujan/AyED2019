//
// Created by mlujan on 3/30/20.
//

#include "Pagina.h"

/**
 * @brief Inicializa el objeto pero no asigna valores utiles. (Constructor 1)
 */
Pagina::Pagina ()
{
  dato = "";
  Origen = 0;
  Destino = 0;
}

/**
 * Inicializa los valores con los datos pasados por parametro. (Constructor 2)
 */
Pagina::Pagina (string d, uint16_t o, uint16_t dest, uint8_t idpag)
{
  this->dato = d;
  this->Origen = o;
  this->Destino = dest;
  this->IDpag = idpag;
}

/**
 * Devuelve el dato almacenado en la pagina. Dato a enviar.
 * @return string
 */
string Pagina::getDato ()
{
  return dato;
}

/**
 * Devuelve el Ip de origen, que es de la maquina que fue enviada la pagina
 * @return  Origen de tipo unsigned int de 8 bits.
 */
uint16_t Pagina::getOrigen ()
{
  return Origen;
}

/**
 * Devuelve el Ip de destino almacenado en la pagina a enviar.
 * @return Destino de tipo unsigned int de 8 bits.
 */
uint16_t Pagina::getDestino ()
{
  return Destino;
}

/**
 * Metodo encargado de retornar el ID de la pagina
 * @return ID de la pagina tipo unsigned int de 8 bits.
 */
uint8_t Pagina::getIDpag ()
{
  return this->IDpag;
}