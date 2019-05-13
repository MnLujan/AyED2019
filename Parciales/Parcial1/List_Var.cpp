//
// Created by mlujan on 5/5/19.
//

#include "List_Var.h"

/**
 * Constructor de lista de variables.
 */
List_Var::List_Var ()
{
  czo = new Nodo_Var();
  size = 0;
}

/**
 * Constructor de lista de variables.
 * @param n nombre de la variable a crear.
 * @param v valor numerico a asignar.
 */
List_Var::List_Var (char n, int v)
{
  czo = new Nodo_Var (n, v);
  size = 1;
}

/**
 * Metodo que agrega nodos a la lista de variables.
 * @param n nombre de la variable
 * @param v valor de la variable. En caso que no este definido se pasa 0 como predeterminado.
 */
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

int List_Var::get_size ()
{
  return size;
}

/**
 * Me devuelve un nodo particular. El cual se pasa como parametro.
 * @param a numero de nodo que se necesita.
 * @return puntero a un Nodo_Var.
 */
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

/**
 * Metodo que devuelve el nombre de una variable, almacenada en un nodo especifico.
 * @param a numero de nodo.
 * @return tipo char, nombre de la variable
 */
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

/**
 * Metodo que devuelve el valor de una variable, almacenada en un nodo especifico
 * @param a numero de nodo
 * @return valor entero, de la variable almacenada.
 */
int List_Var::get_val (int a)
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
      return temp->get_valor ();
    }
}

/**
 * Version 2 del metodo anterior, este busca dentro de la lista de variables una con el nombre que se le
 * pasa por parametro. En caso de encontrarla se devuelve su valor.
 * @param a nombre de la variable
 * @return valor de la variable almacenada
 */
int List_Var::get_val_2 (char a)
{
   int b = get_size ();
  Nodo_Var *temp = czo;
  for (int i = 0; i < b; i++)
    {
      if(a == temp->get_nombre ()){
          return temp->get_valor ();
      }
      temp = temp->get_next ();
    }
  return EXIT_FAILURE;

}

/**
 * Setea el valor de una variable especifica.
 * @param a numero de nodo donde se encuenta la variable a setear
 * @param b valor a setear
 */
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