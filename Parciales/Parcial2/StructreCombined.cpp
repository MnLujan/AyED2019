//
// Created by mlujan on 6/7/19.
//

#include "StructreCombined.h"

StructreCombined::StructreCombined ()
{
  czo = NULL;
  size = 0;
}

StructreCombined::StructreCombined (string x)
{
  czo = new NodoStructure (x);
  size = 1;
}

int StructreCombined::get_NumRep (int a)
{
  if (a > this->GetSizeStruct ())
    {
      cout << "Error, dato inexistente" << endl;
      return EXIT_FAILURE;
    }
  else
    {
      NodoStructure *temp = czo;
      for (int i = 0; i < a; i++)
        {
          temp = temp->get_nextRep ();
        }
      return temp->get_rep ();
    }

}

int StructreCombined::GetSizeStruct ()
{
  return size;
}

bool StructreCombined::l_AlfEsVacia ()
{
  return czo->get_nextAlf () == NULL;
}

/**
 * @brief AddPal se encarga de insertar un nodo a la lista ordenada alfabeticamente y luego al ABB respetando el
 * ordenamiento de este mismo
 * @param x palabra a agregar.
 * @TODO Reescribir metodo para poder insertar en la lista y ABB al mismo tiempo, se aconseja divirlo en dos metods
 * mas pequeños. Primero ver si existe la palabra recorriendo el arbol
 */
void StructreCombined::AddPal (string x)
{
  NodoStructure *nuevo = new NodoStructure (x);
  if (this->l_AlfEsVacia ())
    {
      czo = nuevo;
      size++;
    }
  else
    {
      NodoStructure *temp = czo;
      NodoStructure *temp_2 = czo;
      int b = this->GetSizeStruct ();
      for (int i = 0; i < b; i++)
        {
          if ((czo->GetDataPal ().compare (x)) > 0)
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
          else if ((temp->GetDataPal ().compare (x)) == 0)
            {
              temp->IncreaseRep ();
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
void StructreCombined::QuickSort (StructreCombined *l, int start, int end)
{

}