//
// Created by mlujan on 6/7/19.
//

#ifndef _NODOSTRUCTURE_H_
#define _NODOSTRUCTURE_H_
#include "Palabra.h"

class NodoStructure{
 private:
  /**@brief Puntero a objeto Palabra*/
  Palabra *Data;
  
  ///@brief Puntero al siguiente nodo de lista ordenada alfabeticamente
  NodoStructure *l_nextAlf;
  
  ///@brief Puntero al siguiente nodo de lista ordenada por Repeticiones
  NodoStructure *l_nextRep;
  
  ///@brief Puntero a nodo derecho del ABB
  NodoStructure *ABB_der;
  
  ///@brief Puntero a nodo izquierdo del ABB
  NodoStructure *ABB_izq;
 public:
  ///@brief Constructor sin parametros
  NodoStructure ();
  NodoStructure (string);

  ///@brief Posiciona el nodo en la posicion deseada de la lista ordenada alfabeticamente
  void set_nextAlf (NodoStructure *); //cambiar nombre despues

  ///@brief Posiciona el nodo en la posicion deseada de la lista ordenada por cantidad de repeticiones
  void set_nextRep (NodoStructure *);

  ///@brief Devuelve el nodo de la lista deseada
  NodoStructure *get_nextAlf ();
  NodoStructure *get_nextRep ();

  unsigned int get_rep ();
  string GetDataPal ();

  ///@brief Incrementa el numero de repeticiones de la plabra
  void IncreaseRep ();

  void set_der (NodoStructure *);
  NodoStructure *GetDerABB ();
  void set_izq (NodoStructure *);
  NodoStructure *GetIzqABB ();

};

#endif //_NODOSTRUCTURE_H_
