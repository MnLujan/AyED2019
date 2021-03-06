//
// Created by mlujan on 5/23/20.
//

#include "NodoGrafo.h"

/**
 * Constructor de la calse NodoGrafo.
 * @param p puntero a un objeto Router.
 * @param bw ancho de banda que tendra el router.
 */
NodoGrafo::NodoGrafo (Router *p, int bw)
{
  this->R = p;
  this->BW = bw;
  this->peso = 0;
}

/**
 * Metodo encargado de devolver el peso del enlace
 * @return int peso
 */
int NodoGrafo::getPeso ()
{
  return peso;
}

/**
 * Retorna el el puntero al objeto router que se encuentra en el nodo.
 * @return Router
 */
Router *NodoGrafo::getRouter ()
{
  return this->R;
}

/**
 * Metodo encargado de modificar el valor de peso del enlace
 */
void NodoGrafo::setPeso (int pe)
{
  this->peso = pe;
}

/**
 * @brief Retorna el ancho de banda del nodo.
 * @return bw
 */
uint8_t NodoGrafo::getBW ()
{
  return this->BW;
}