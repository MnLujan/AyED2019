//
// Created by mlujan on 6/7/19.
//

#include "NodoStructure.h"

NodoStructure::NodoStructure ()
{
  Data = new Palabra ();
  l_nextAlf = nullptr;
  l_nextRep = nullptr;
  ABB_der = nullptr;
  ABB_izq = nullptr;
}

NodoStructure::NodoStructure (string a)
{
  Data = new Palabra (a);
  l_nextAlf = nullptr;
  l_nextRep = nullptr;
  ABB_der = nullptr;
  ABB_izq = nullptr;
}

void NodoStructure::set_nextAlf (NodoStructure *n)
{
  l_nextAlf = n;
}

void NodoStructure::set_nextRep (NodoStructure *n)
{
  l_nextRep = n;
}

NodoStructure *NodoStructure::get_nextAlf ()
{
  return l_nextAlf;
}

NodoStructure *NodoStructure::get_nextRep ()
{
  return l_nextRep;
}

unsigned int NodoStructure::get_rep ()
{
  return Data->get_rep ();
}

string NodoStructure::GetDataPal ()
{
  return Data->get_dato ();
}

void NodoStructure::IncreaseRep ()
{
  Data->IncrementarNumRep ();
}

NodoStructure* NodoStructure::GetDerABB ()
{
  return this->ABB_der;
}

void NodoStructure::set_der (NodoStructure *d)
{
  this->ABB_der = d;
}

void NodoStructure::set_izq (NodoStructure *i)
{
  this->ABB_izq = i;
}

NodoStructure* NodoStructure::GetIzqABB ()
{
  return this->ABB_izq;
}