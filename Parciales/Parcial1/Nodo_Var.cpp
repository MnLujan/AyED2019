//
// Created by mlujan on 5/5/19.
//

#include "Nodo_Var.h"

Nodo_Var::Nodo_Var ()
{
  var = new Variables();
  next = NULL;
}

Nodo_Var::Nodo_Var (char n, int v)
{
  var = new Variables(n, v);
  next = NULL;
}

void Nodo_Var::set_next (Nodo_Var *n)
{
  next = n;
}

Nodo_Var* Nodo_Var::get_next ()
{
  return next;
}

bool Nodo_Var::es_vacio ()
{
  return var->esnulo ();
}

char Nodo_Var::get_nombre ()
{
  return var->get_name ();
}

int Nodo_Var::get_valor ()
{
  return var->get_val ();
}

void Nodo_Var::set_val (int a)
{
  var->set_val (a);
}