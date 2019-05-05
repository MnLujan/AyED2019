//
// Created by mlujan on 5/5/19.
//

/**
 * @TODO Corregir metodo cabeza y terminar lista.
 * @TODO Agregar metodos que faltan
 */
#include "List_Var.h"

List_Var::List_Var ()
{
  czo = NULL;
  size = 0;
}

List_Var::List_Var(char n, int v)
{
  czo = new Nodo_Var (n,v);
  size = 1;
}

void List_Var::add (char n, int v)
{
  Nodo_Var *nuevo = new Nodo_Var (n,v);
  if (czo == NULL)
    {
      czo = nuevo;
    }
  else if (get_size () < 2)
    {
      czo->set_next (nuevo);
    }
  else
    {
      Nodo_Var *temp = get_nodo (get_size () - 1);
      temp->set_next (nuevo);
    }

  size = size + 1;
}

bool List_Var::esvacia (void)
{
  return czo->es_vacio ();
}

/*
Nodo_Var* List_Var::cabeza (void)
{
  if (esvacia ())
    {
      return " Error, Cabeza de lista vacia";

    }
  else
    {
      return ;
    }

}
*/

int List_Var::get_size ()
{
  return size;
}

Nodo_Var *List_Var::get_nodo (int a)
{
  if (a > get_size ())
    {
      cout << "Error, instruccion inexistente" << endl;
      return NULL;
    }
  else
    {
      Nodo_Var *temp = czo;
      for (int i = 0; i < a; i++)
        {
          temp = temp->get_next ();
        }
      return temp;
    }
}