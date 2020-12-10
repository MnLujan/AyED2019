//
// Created by mlujan on 6/7/19.
//

#include "StructureNodo.h"

StructureNodo::StructureNodo ()
{
  Data = new Palabra ();
  l_nextAlf = nullptr;
  l_nextRep = nullptr;
  ABB_der = nullptr;
  ABB_izq = nullptr;
}

StructureNodo::StructureNodo (string a)
{
  Data = new Palabra (a);
  l_nextAlf = nullptr;
  l_nextRep = nullptr;
  ABB_der = nullptr;
  ABB_izq = nullptr;
}

void StructureNodo::set_nextAlf (StructureNodo *n)
{
  l_nextAlf = n;
}

void StructureNodo::set_nextRep (StructureNodo *n)
{
  l_nextRep = n;
}

StructureNodo *StructureNodo::get_nextAlf ()
{
  return l_nextAlf;
}

StructureNodo *StructureNodo::get_nextRep ()
{
  return l_nextRep;
}

unsigned int StructureNodo::get_rep ()
{
  return Data->get_rep ();
}

string StructureNodo::GetDataPal ()
{
  return Data->get_dato ();
}

void StructureNodo::IncreaseRep ()
{
  Data->IncrementarNumRep ();
}

StructureNodo* StructureNodo::GetDerABB ()
{
  return this->ABB_der;
}

void StructureNodo::set_der (StructureNodo *d)
{
  this->ABB_der = d;
}

void StructureNodo::set_izq (StructureNodo *i)
{
  this->ABB_izq = i;
}

StructureNodo* StructureNodo::GetIzqABB ()
{
  return this->ABB_izq;
}