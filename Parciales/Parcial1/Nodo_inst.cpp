//
// Created by mlujan on 5/4/19.
//

#include "Nodo_inst.h"

Nodo_inst::Nodo_inst (string a)
{
  dato = a;
  next = nullptr;
}

void Nodo_inst::set_next (Nodo_inst *n)
{
  next = n;
}

string Nodo_inst::get_dato ()
{
  return dato;
}

Nodo_inst *Nodo_inst::get_next ()
{
  return next;
}

bool Nodo_inst::es_vacio ()
{
  return next == nullptr;
}