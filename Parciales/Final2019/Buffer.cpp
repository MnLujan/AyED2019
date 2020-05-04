//
// Created by mlujan on 4/3/20.
//

#include "Buffer.h"

/**
 * Inicializacion de la clase. Constructor.
 * @param cola
 * @param id
 */
Buffer::Buffer (Lista<Pagina *> *colaN, uint8_t id)
{
  this->cola = colaN;
  this->ID = id;
}

/**
 * Metodo encargado de la devolver el ID del buffer.
 * @return numero de 8 bits que representa el ID
 */
uint8_t Buffer::getID ()
{
  return this->ID;
}

/**
 * Metodo encargado de devolver la lista que contiene las paginas para enviar
 * @return Pagina* cola
 */
Lista<Pagina *> *Buffer::getLista ()
{
  return this->cola;
}

