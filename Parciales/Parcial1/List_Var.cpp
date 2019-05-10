//
// Created by mlujan on 5/5/19.
//

#include "List_Var.h"

List_Var::List_Var ()
{
  czo = new Nodo_Var();
  size = 0;
}

List_Var::List_Var (char n, int v)
{
  czo = new Nodo_Var (n, v);
  size = 1;
}

void List_Var::addVar (char n, int v)
{
  Nodo_Var *nuevo = new Nodo_Var (n, v);
  if (czo->es_vacio ())
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

Nodo_Var *List_Var::cabeza (void)
{
  if (esvacia ())
    {
      cout << "Error, lista vacia" << endl;
      return NULL;
    }
  else
    {
      return czo;
    }

}

int List_Var::get_size ()
{
  return size;
}

Nodo_Var *List_Var::get_nodo (int a)
{
  if (a > get_size ())
    {
      cout << "Error, nodo inexistente" << endl;
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

char List_Var::get_name (int a)
{
  if (a > get_size ())
    {
      cout << "Error, nodo inexistente" << endl;
      return EXIT_FAILURE;
    }
  else
    {
      Nodo_Var *temp = czo;
      for (int i = 0; i < a; i++)
        {
          temp = temp->get_next ();
        }
      return temp->get_nombre ();
    }
}

int List_Var::get_val (int a)
{
  if (a > get_size ())
    {
      cout << "Error, nodo inexistente" << endl;
      return 1;
    }
  else
    {
      Nodo_Var *temp = czo;
      for (int i = 0; i < a; i++)
        {
          temp = temp->get_next ();
        }
      return temp->get_valor ();
    }
}
void List_Var::set_val (int a, int b)
{
  if (a > get_size ())
    {
      cout << "Error, nodo inexistente" << endl;
      return;
    }
  else
    {
      Nodo_Var *temp = czo;
      for (int i = 0; i < a; i++)
        {
          temp = temp->get_next ();
        }
       temp->set_val (b);
      return;
    }
}