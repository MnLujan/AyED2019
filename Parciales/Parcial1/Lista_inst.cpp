//
// Created by mlujan on 5/4/19.
//

#include "Lista_inst.h"

Lista_inst::Lista_inst ()
{
  czo = nullptr;
  size = 0;
}

Lista_inst::Lista_inst(string a)
{
  czo = new Nodo_inst (a);
  size = 1;
}

void Lista_inst::add (string d)
{
  auto *nuevo = new Nodo_inst (d);
  if (czo == nullptr)
    {
      czo = nuevo;
    }
  else if (get_size () < 2)
    {
      czo->set_next (nuevo);
    }
  else
    {
      Nodo_inst *temp = get_nodo (get_size () - 1);
      temp->set_next (nuevo);
    }

  size = size + 1;
}

bool Lista_inst::esvacia ()
{
  return czo->es_vacio ();
}

string Lista_inst::cabeza ()
{
  if (esvacia ())
    {
      return " Error, Cabeza de lista vacia";

    }
  else
    {
      return czo->get_dato ();
    }

}

int Lista_inst::get_size ()
{
  return size;
}

Nodo_inst *Lista_inst::get_nodo (int a)
{
  if (a > get_size ())
    {
      cout << "Error, instruccion inexistente" << endl;
      return nullptr;
    }
  else
    {
      Nodo_inst *temp = czo;
      for (int i = 0; i < a; i++)
        {
          temp = temp->get_next ();
        }
      return temp;
    }
}

string Lista_inst::get_dato (int a)
{
  if (a > get_size ())
    {
      cout << "Error, instruccion inexistente" << endl;
      return nullptr;
    }
  else
    {
      Nodo_inst *temp = czo;
      for (int i = 0; i < a; i++)
        {
          temp = temp->get_next ();
        }
      return temp->get_dato ();
    }
}