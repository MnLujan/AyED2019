//
// Created by mlujan on 6/7/19.
//

#ifndef _STRUCTRECOMBINED_H_
#define _STRUCTRECOMBINED_H_
#include <iostream>
#include "NodoStructure.h"

using namespace std;

/**
 * @brief Estructura combinada, la cual esta constituida por punteros a nodos. En conjunto se forma
 * 2 listas y un ABB. Tambien se almacena la cantidad de nodos que forman la estructura.
 *
 * @TODO implementar QuickSort para ordenar por cantidad de palabras repetidas (ultimo)
 * @TODO Borre varios metodos
 * @TODO Implementar QuickSort aca
 */
class StructreCombined {
 private:

  ///@brief Puntero a objeto Nodo
  NodoStructure *czo;
  NodoStructure *raiz;
  ///@brief Cantidad de nodos existentes, vale para listas y ABB
  unsigned int size;

 public:
  StructreCombined();
  StructreCombined(string x);
  int GetSizeStruct();

  /* Metodos de lista */
  ///@brief Se encarga de ver si la estructura esta vacia y llama a los metodos correspondientes
  void AddPal(string);
  ///@brief Inserta el nodo en la lista ordenado alfabeticamente o incrementa el numero de palabras repetidas
  void InserList(string);
  ///@brief Ordena las los nodos por numero de veces que esta repetida cada palabra
  void QuickSort(StructreCombined*, int, int);
  ///@brief Devuelve el puntero al nodo con la palabra que se le paso como parametro
  NodoStructure* GetNodo(string);


  ///@brief Pregunta si la lista alfabeticamente esta vacia
  bool l_AlfEsVacia(); //Ver si cambiar el tipo que devuelve por uno de tipo nodo

  /* Metodos de Arbol */
  ///@brief Inserta el nodo en el ABB
  void InserABB(string);

  ///@brief El metodo devolvera el nodo siguiente izquierdo, en caso q sea el ultimo retornara NULL
  NodoStructure* Izq();

  ///@brief El metodo devolvera el nodo siguiente derecho, caso que sea el ultimo retornara NULL
  NodoStructure* Der();
};

#endif //_STRUCTRECOMBINED_H_
