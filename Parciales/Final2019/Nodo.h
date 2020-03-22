//
// Created by mlujan on 3/21/20.
//

#ifndef _NODO_H_
#define _NODO_H_

#include <cstdlib>

template<class Tipe>
class Nodo {
 private:
  Tipe *dato;
  Nodo<Tipe> *next;
 public:
  Tipe getdato ();
  Tipe setdato ();
  Nodo ();
  Nodo (Tipe d);
  Nodo (Tipe d, Nodo<Tipe> *p);
  Nodo<Tipe> getnext ();
  void setnext (Nodo<Tipe> *p);
  void BorrarDato ();

};

/**
 * @brief Inicializa el nodo con la variable pasada por parametro. (Constructor 1).
 * @param d dato a almacenar.
 */
template<class Tipe>
Nodo<Tipe>::Nodo (Tipe d)
{
  dato = d;
  next = NULL;
}

/**
 * @brief Inicializa el objeto Nodo con un dato y el puntero al nodo siguiente de este. (Constructor 2).
 * @tparam Tipe
 * @param d dato a guardar.
 * @param p puntero al proximo nodo
 */
template<class Tipe>
Nodo<Tipe>::Nodo (Tipe d, Nodo<Tipe> *p)
{
  dato = d;
  next = p;
}

/**
 * @brief Me devuelve el dato almacenado en el nodo actual.
 * @return dato de Tipo.
 */
template<class Tipe>
Tipe Nodo<Tipe>::getdato ()
{
  return this->dato;
}

/**
 * @brief Devuelve el puntero al nodo proximo del actual.
 * @return Puntero al nodo
 */
template<class Tipe>
Nodo<Tipe> Nodo<Tipe>::getnext ()
{
  return next;
}

/**
 * @brief Recibe como parametro el puntero a un nodo y lo setea como el proximo al actual
 * @param p puntero a nodo
 */
template<class Tipe>
void Nodo<Tipe>::setnext (Nodo<Tipe> *p)
{
  this->next = p;
  return;
}

/**
 * @brief Borra el dato almacenado en el nodo. Libera memoria.
 */
template<class Tipe>
void Nodo<Tipe>::BorrarDato ()
{
  delete (this->dato);
}
#endif //_NODO_H_
