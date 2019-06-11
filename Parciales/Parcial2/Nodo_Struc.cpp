//
// Created by mlujan on 6/7/19.
//

#include "Nodo_Struc.h"

Nodo_Struc::Nodo_Struc ()
{
  obj = new Palabra ();
  nextAlf = NULL;
  nextRep = NULL;
  der = NULL;
  izq = NULL;
}

Nodo_Struc::Nodo_Struc (string a)
{
  obj = new Palabra (a);
  nextAlf = NULL;
  nextRep = NULL;
  der = NULL;
  izq = NULL;
}

void Nodo_Struc::set_nextAlf (Nodo_Struc *n)
{
  nextAlf = n;
}

void Nodo_Struc::set_nextRep (Nodo_Struc *n)
{
  nextRep = n;
}

Nodo_Struc *Nodo_Struc::get_nextAlf ()
{
  return nextAlf;
}

Nodo_Struc *Nodo_Struc::get_nextRep ()
{
  return nextRep;
}

int Nodo_Struc::get_rep ()
{
  return obj->get_rep ();
}

string Nodo_Struc::get_pal ()
{
  return obj->get_dato ();
}

void Nodo_Struc::set_pal (string x)
{
  obj->set_dato (x);
}

void Nodo_Struc::increment ()
{
  obj->incrementar ();
}

Nodo_Struc* Nodo_Struc::get_der ()
{
  return der;
}

void Nodo_Struc::set_der (Nodo_Struc *d)
{
  this->der = d;
}

void Nodo_Struc::set_izq (Nodo_Struc *i)
{
  this->izq = i;
}

Nodo_Struc* Nodo_Struc::get_izq ()
{
  return izq;
}