//
// Created by mlujan on 5/5/19.
//

#include "Variables.h"

/**
 * Constructor de la clase variables, crea el objeto y le asigna valores predeterminados
 */
Variables::Variables ()
{
  this->nombre = -1;
  this->valor = 0;
}

/**
 * Constructor con parametros, crea el objeto y le asigna valores a la variables ingresados por parametros
 * @param n nombre
 * @param v valor entero
 */
Variables::Variables (char n, int v)
{
  this->nombre = n;
  this->valor = v;
}

char Variables::get_name ()
{
  return this->nombre;
}

void Variables::set_name (char n)
{
  this->nombre = n;
}

int Variables::get_val ()
{
  return this->valor;
}

void Variables::set_val (int v)
{
  this->valor = v;
}

bool Variables::esnulo ()
{
  return nombre == -1;
}