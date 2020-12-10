//
// Created by mlujan on 6/7/19.
//

#ifndef _NODOSTRUCTURE_H_
#define _NODOSTRUCTURE_H_
#include "Palabra.h"

class StructureNodo{
 private:
  /**@brief Puntero a objeto Palabra*/
  Palabra *Data;
  
  ///@brief Puntero al siguiente nodo de lista ordenada alfabeticamente
  StructureNodo *l_nextAlf;
  
  ///@brief Puntero al siguiente nodo de lista ordenada por Repeticiones
  StructureNodo *l_nextRep;
  
  ///@brief Puntero a nodo derecho del ABB
  StructureNodo *ABB_der;
  
  ///@brief Puntero a nodo izquierdo del ABB
  StructureNodo *ABB_izq;
 public:
  ///@brief Constructor sin parametros
  StructureNodo ();
  StructureNodo (string);

  ///@brief Posiciona el nodo en la posicion deseada de la lista ordenada alfabeticamente
  void set_nextAlf (StructureNodo *); //cambiar nombre despues

  ///@brief Posiciona el nodo en la posicion deseada de la lista ordenada por cantidad de repeticiones
  void set_nextRep (StructureNodo *);

  ///@brief Devuelve el nodo de la lista deseada
  StructureNodo *get_nextAlf ();
  StructureNodo *get_nextRep ();

  unsigned int get_rep ();
  string GetDataPal ();

  ///@brief Incrementa el numero de repeticiones de la plabra
  void IncreaseRep ();

  void set_der (StructureNodo *);
  StructureNodo *GetDerABB ();
  void set_izq (StructureNodo *);
  StructureNodo *GetIzqABB ();

};

#endif //_NODOSTRUCTURE_H_
