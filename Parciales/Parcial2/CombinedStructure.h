//
// Created by mlujan on 6/7/19.
//

#ifndef _STRUCTRECOMBINED_H_
#define _STRUCTRECOMBINED_H_
#include <iostream>
#include "StructureNodo.h"

using namespace std;

/**
 * @brief Estructura combinada, la cual esta constituida por punteros a nodos. En conjunto se forma
 * 2 listas y un ABB. Tambien se almacena la cantidad de nodos que forman la estructura.
 */
class CombinedStructure {
 private:

  ///@brief Puntero a objeto Nodo
  /* Lista ordenada Alfabeticamente */
  StructureNodo *czo;
  /* Arbol binario */
  StructureNodo *raiz;
  /* Lista Ordenada por numero de repeticiones */
  StructureNodo *czoRep;
  ///@brief Cantidad de nodos existentes dentro de la estructura
  unsigned int size;

 public:
  CombinedStructure ();
  CombinedStructure (string x);
  int GetSizeStruct () const;

  ///@brief Comparaciones utilizadas para Quicksort y por insercion, para arbor y lista.
  unsigned int compQS, compLIST, compABB;

  /* Metodos de lista */
  ///@brief Se encarga de ver si la estructura esta vacia y llama a los metodos correspondientes
  void AddPal (string);
  ///@brief Inserta el nodo en la lista ordenado alfabeticamente o incrementa el numero de palabras repetidas
  void InserList (string);
  ///@brief Ordena las los nodos por numero de veces que esta repetida cada palabra
  void QuickSort (int, int);
  ///@brief Devuelve el puntero al nodo con la palabra que se le paso como parametro
  StructureNodo *GetNodo (string);
  ///@brief Devuelve el puntero a un nodo especifico de la lista ordenada por numero de repeticiones
  StructureNodo *GetNodoSwap (int);
  ///@brief Devuelve un puntero
  StructureNodo *GetNodoAlf(int);
  ///@brief Metodo encargado de llamar al metodo Quicksort y pasarle los parametros necesarios
  void OrdenaQS ();
  ///@brief Metodo utilizado en el algoritmos QuickSort
  void Swap (int, int);
  ///@brief Metodo encargado de devolver el numero de veces que esta repetida la palabra, almacenada en un nodo.
  unsigned int GetNumRep (int);

  /* Metodos de Arbol */
  ///@brief Inserta el nodo en el ABB
  void InserABB (string);

  ///@brief El metodo devolvera el nodo siguiente izquierdo, en caso q sea el ultimo retornara NULL
  StructureNodo *Izq ();

  ///@brief El metodo devolvera el nodo siguiente derecho, caso que sea el ultimo retornara NULL
  StructureNodo *Der ();
};

#endif //_STRUCTRECOMBINED_H_
