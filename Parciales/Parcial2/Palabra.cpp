//
// Created by mlujan on 6/7/19.
//

#include "Palabra.h"

Palabra::Palabra ()
{
  rep = 0;
}

Palabra::Palabra (string a)
{
  dato = a;
  rep = 0;
}

string Palabra::get_dato ()
{
  return dato;
}

int Palabra::get_rep ()
{
  return rep;
}

void Palabra::set_dato (string a)
{
  dato = a;
  rep = 0;
}

void Palabra::IncrementarNumRep ()
{
  rep ++;
}
