//
// Created by mlujan on 6/7/19.
//

#include "StructreCombined.h"

StructreCombined::StructreCombined ()
{
  czo = NULL;
  raiz = NULL;
  czoRep = NULL;
  size = 0;
}

StructreCombined::StructreCombined (string x)
{
  czo = new NodoStructure (x);
  size = 1;
}

/**
 * Busca en la list ordenada alfabeticamente el nodo donde se encuentra la palabra pasada como parametro
 * @param p: palabra a buscar en la lista
 * @return Puntero al nodo encontrado
 */
NodoStructure *StructreCombined::GetNodo (string p)
{
  NodoStructure *temp = czo;
  while (temp->GetDataPal () != p)
    {
      temp = temp->get_nextAlf ();
    }
  return temp;
}

int StructreCombined::GetSizeStruct ()
{
  return size;
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
  if (size != 0)
    {
      InserList (x);
      InserABB (x);
    }
  else
    {
      /* Si no hay ningun nodo lo crea y lo inserta al comienzo */
      NodoStructure *nuevo = new NodoStructure (x);
      czo = nuevo;
      raiz = nuevo;
      czoRep = nuevo;
      size++;
    }

}

/**
 * @brief Se encarga de insertar el nodo en el lugar correspondiente de la lista ordenando alfabeticamente.
 * Posteriormente, insertale el nodo en un segunda lista, sin respetar ningun orden, solo lo insertara al final
 * de esta.
 * @param pal: Se envia la palabra a insertar en el nodo
 */
void StructreCombined::InserList (string pal)
{
  int size_struct = this->GetSizeStruct ();
  NodoStructure *nuevo = new NodoStructure (pal);
  NodoStructure *temp = czo;
  NodoStructure *temp_2 = czo;
  NodoStructure *anterior = NULL;

  for (int i = 0; i < size_struct; i++)
    { /* En caso que la palabra se deba ordenar antes que la actual */
      if (czo->GetDataPal ().compare (pal) > 0)
        {
          if (temp_2 != czo)
            {
              temp_2->set_nextAlf (nuevo);
              nuevo->set_nextAlf (temp);
            }
          else
            {
              czo = nuevo;
              czo->set_nextAlf (temp);
            }
          size = size + 1;
          break;
        } /* Si es igual incrementa el numero de repeticiones */
      else if ((temp->GetDataPal ().compare (pal)) == 0)
        {
          delete nuevo;
          temp->IncreaseRep ();
          break;
        } /* Si se llego al final de la lista se crea un nuevo nodo y se lo inserta */
      else if (temp->get_nextAlf () == NULL)
        {
          temp->set_nextAlf (nuevo);
          size = size + 1;
          break;
        }
      else
        {
          temp_2 = temp;
          temp = temp->get_nextAlf ();
        }
    }

  if (size_struct != size)
    {
      while (temp != NULL)
        {
          anterior = temp;
          temp = temp->get_nextRep ();
        }
      anterior->set_nextRep (nuevo);
    }
  return;
}

NodoStructure *StructreCombined::Der ()
{
  return raiz->GetDerABB ();
}

NodoStructure *StructreCombined::Izq ()
{
  return raiz->GetIzqABB ();
}

/**
 * @brief Metodo encargado de la insercion de nodos en el ABB, con sus respectivas restricciones
 * @param pal: Dato de tipo string que contiene la palabra a agregar.
 */
void StructreCombined::InserABB (string pal)
{
  NodoStructure *temp = raiz;
  NodoStructure *anterior = NULL;
  while (temp != NULL)
    {
      anterior = temp;

      if (temp->GetDataPal ().compare (pal) > 0)
        {
          temp = temp->GetIzqABB ();
        }
      else if (temp->GetDataPal ().compare (pal) == 0)
        { /* No incremento el valor de rep porque ya se hizo desde el metodo de lista */
          temp = NULL;
          anterior = NULL;
        }
      else
        {
          temp = temp->GetDerABB ();
        }
    }
  if (anterior != NULL)
    {
      if (anterior->GetDataPal ().compare (pal) > 0)
        {
          anterior->set_izq (this->GetNodo (pal));
        }
      else
        {
          anterior->set_der (this->GetNodo (pal));
        }
    }
  else
    {
      return;
    }

  return;
}

/**
 * Algoritmo de ordenamiento QuickSort, el mismo devuelva la lista ordenada de mayor a menor
 * teniendo en cuenta la cantidad de veces que se encuentra repetida cada palabra
 * @param l puntero a estructura combinada a ordenar.
 */
void StructreCombined::QuickSort (NodoStructure *, int start, int end)
{

}