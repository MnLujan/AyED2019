//
// Created by mlujan on 6/7/19.
//

#include "StructCombined.h"
/**
 * @TODO implementar QuickSort para ordenar por cantidad de palabras repetidas (ultimo)
 */
StructCombined::StructCombined ()
{
  czo = NULL;
  size = 0;
}

StructCombined::StructCombined (string x)
{
  czo = new Nodo_Struc (x);
  size = 1;
}

int StructCombined::get_NumRep (int a)
{
  if (a > this->get_size ())
    {
      cout << "Error, dato inexistente" << endl;
      return EXIT_FAILURE;
    }
  else
    {
      Nodo_Struc *temp = czo;
      for (int i = 0; i < a; i++)
        {
          temp = temp->get_nextRep ();
        }
      return temp->get_rep ();
    }

}

int StructCombined::get_size ()
{
  return size;
}

bool StructCombined::esvacia ()
{
  return czo == NULL;
}

string StructCombined::get_palabra ()
{
  return czo->get_pal ();
}

/**
 * AddPal metodo que agrega una palabra a la lista, comprueba el orden alfabetico
 * o si se encuentra repetida.
 * @param x palabra a agregar.
 * @TODO Reescribir metodo para poder insertar en la lista y ABB al mismo tiempo, se aconseja divirlo en dos metods
 * mas pequeños. Primero ver si existe la palabra recorriendo el arbol
 */
void StructCombined::AddPal (string x)
{
  Nodo_Struc *nuevo = new Nodo_Struc (x);
  if (this->esvacia ())
    {
      czo = nuevo;
      size++;
    }
  else
    {
      Nodo_Struc *temp = czo;
      Nodo_Struc *temp_2 = czo;
      int b = this->get_size ();
      for (int i = 0; i < b; i++)
        {
          if ((czo->get_pal ().compare (x)) > 0)
            {
              if (temp_2 == czo)
                {
                  czo = nuevo;
                  nuevo->set_nextAlf (temp);

                }
              else
                {
                  temp_2->set_nextAlf (nuevo);
                  nuevo->set_nextAlf (temp);
                }
              size = size + 1;
              return;
            }
          else if ((temp->get_pal ().compare (x)) == 0)
            {
              temp->increment ();
              return;
            }
          else if (temp->get_nextAlf () == NULL)
            {
              temp->set_nextAlf (nuevo);
              size = size + 1;
              return;
            }
          else
            {
              temp_2 = temp;
              temp = temp->get_nextAlf ();
            }
        }
    }

}

/**
 * Algoritmo de ordenamiento llamado QuickSort, el mismo devuelva la lista ordenada de mayor a menor
 * teniendo en cuenta la cantidad de veces que se encuentra repetida cada palabra
 * @param l puntero a estructura combinada a ordenar.
 */
void StructCombined::QuickSort (StructCombined *l, int start, int end)
{

}