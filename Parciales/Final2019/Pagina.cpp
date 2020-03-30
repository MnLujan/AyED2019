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
Pagina::Pagina (char d, u_int8_t o, u_int8_t dest)
{
  dato = d;
  Origen = o;
  Destino = dest;
}

/**
 * Devuelve el dato almacenado en la pagina. Dato a enviar.
 * @return string
 */
string Pagina::getDato() {
  return dato;
}

/**
 * Devuelve el Ip de origen, que es de la maquina que fue enviada la pagina
 * @return  Origen de tipo unsigned int de 8 bits.
 */
u_int8_t Pagina::getOrigen() {
  return Origen;
}

/**
 * Devuelve el Ip de destino almacenado en la pagina a enviar.
 * @return Destino de tipo unsigned int de 8 bits.
 */
u_int8_t Pagina::getDestino() {
  return Destino;
}