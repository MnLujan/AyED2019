//
// Created by mlujan on 3/21/20.
//

#ifndef _LISTA_H_
#define _LISTA_H_
#include "Nodo.h"

template<class Tipe>
class Lista {
 private:
  Nodo<Tipe> *czo;
  unsigned int size;
 public:
  Lista ();
  Lista (Tipe p);
  bool esvacia ();
  Tipe get_dato ();
  Nodo<Tipe> *get_nodo (int);
  Nodo<Tipe> *get_next ();
  void Add (Tipe);
  int get_size ();
  void borrarCabeza ();
  void DeleteList (Lista<Tipe> *);
  Nodo<Tipe> *getCabeza ();
  Tipe Pop ();
  void Swap (int, int);
};

/**
 * @brief Constructor sin parametros de entrada. (Constructor 1)
 * @tparam Tipe
 */
template<class Tipe>
Lista<Tipe>::Lista ()
{
  czo = NULL;
  size = 0;
}

/**
 * @brief Constructor de lista con parametros de entrada, de Tipe que sera definido posteriormente. (Constructor 2)
 * @tparam Tipe
 * @param p dato a almacenar.
 */
template<class Tipe>
Lista<Tipe>::Lista (Tipe p)
{
  czo = new Nodo<Tipe> (p);
  size = 1;
}

/**
 * @brief Metodo que devuelve el tamaño de lista, es decir la cantidad de nodos que la conforman.
 * @tparam Tipe
 * @return numero entero, tamaño de la lista.
 */
template<class Tipe>
int Lista<Tipe>::get_size ()
{
  return size;
}

/**
 * @brief Metodo que devuelve un puntero al nodo siguiente del actual.
 * @tparam Tipe
 * @return puntero al Nodo.
 */
template<class Tipe>
Nodo<Tipe> *Lista<Tipe>::get_next ()
{
  return czo->getnext ();
}

/**
 * @brief Metodo que devuelve puntero a un nodo especifico de la lista, el numero del nodo se pasa como parametro.
 * @tparam Tipe
 * @param a valor entero del nodo
 * @return Puntero al nodo de tipo Nodo<Tipe>
 */
template<class Tipe>
Nodo<Tipe> *Lista<Tipe>::get_nodo (int a)
{
  if (a > size)
    {
      EXIT_FAILURE;
    }

  Nodo<Tipe> *temp = czo;

  for (int i = 0; i < a; i++)
    {
      temp = temp->getnext ();
    }
  return temp;
}

/**
 * @brief Metodo que devuelve un dato de tipo booleano que nos indica si la lista se encuentra vacia o no.
 * @return true en el caso de que este vacia o false en caso contrario
 */
template<class Tipe>
bool Lista<Tipe>::esvacia ()
{
  return czo == NULL;
}

/**
 * @brief Metodo que devuelve el dato del nodo actual.
 * @return dato de tipo Tipe que sera especificado en la declaracion.
 */
template<class Tipe>
Tipe Lista<Tipe>::get_dato ()
{
  return czo->getdato ();
}

/**
 * @brief Metodo para agregar un dato a la lista que lo invoca, en caso de que se encuentre vacia lo colocara al comienzo,
 * si no, al final de esta.
 * @param a dato a agregar a la lista
 */
template<class Tipe>
void Lista<Tipe>::Add (Tipe a)
{
  if (!esvacia ())
    {
      Nodo<Tipe> *temp = new Nodo<Tipe> (a);
      Nodo<Tipe> *temp2 = czo;
      while (temp2->getnext () != NULL)
        {
          temp2 = temp2->getnext ();
        }
      temp2->setnext (temp);
      size++;
    }
  else
    {
      czo = new Nodo<Tipe> (a);
      size++;
    }
  return;
}

/**
 * @brief Metodo encargado de borrar el primer nodo de la lista
 * @tparam Tipe tipo designado en la construccion de la lista.
 */
template<class Tipe>
void Lista<Tipe>::borrarCabeza ()
{
  Nodo<Tipe> *temp = czo->getnext ();
  delete (czo);
  czo = temp;
}

/**
 * Metodo encargado de retornar un puntero al primer nodo de la lista
 * @tparam Tipe tipo designado en la construccion de la lista
 * @return puntero al nodo Nodo<Tipe>
 */
template<class Tipe>
Nodo<Tipe> *Lista<Tipe>::getCabeza ()
{
  return this->czo;
}

/**
 * @brief Metodo que elimina la lista por completo de la memoria.
 * @tparam Tipe tipo designado en la construccion de la lista.
 */
template<class Tipe>
void Lista<Tipe>::DeleteList (Lista<Tipe> *)
{
  if (this->esvacia ())
    {
      return;
    }

  Nodo<Tipe> *temp;
  while (czo != NULL)
    {
      czo->BorrarDato ();
      temp = czo->getnext ();
      delete (czo);
      czo = temp;
    }
  return;
}

template<class Tipe>
Tipe Lista<Tipe>::Pop ()
{
  Tipe temp = czo->getdato ();
  Nodo<Tipe> *temp2 = czo->getnext ();
  delete (czo);
  czo = temp2;
  return temp;
}

/**
 * @brief Metodo encargado de intercambiar 2 nodos pasados como parametro
 * @param a numero de nodo a cambiar
 * @param b numero de nodo a cambiar
 * @tparam Tipe tipo designado en la construccion de la lista.
 */
template<class Tipe>
void Lista<Tipe>::Swap (int a, int b)
{
  Nodo<Tipe> *pos1 = this->get_nodo (a);
  auto *pos2 = this->get_nodo (b);

  if (a != 0)
    {
      auto *auxPos1 = this->get_nodo (a - 1);
      auto *nextPos2 = pos2->get_next ();

      //Swap
      pos1->setnext (nextPos2);
      pos2->senext (pos1);
      auxPos1->senext (pos2);
    }
  else
    {
      auto *nextPos2 = pos2->get_next ();

      //Swap
      this->czo = pos2;
      pos2->setnext (pos1);
      pos1->setnext (nextPos2);
    }
}

#endif //_LISTA_H_
