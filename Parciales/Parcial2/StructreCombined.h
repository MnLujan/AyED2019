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

  ///@brief Puntero a objeto palabra
  NodoStructure *czo;

  ///@brief Cantidad de nodos existentes, vale para listas y ABB
  unsigned int size;
 public:
  StructreCombined();
  StructreCombined(string x);

  ///@brief Pregunta si la lista alfabeticamente esta vacia
  bool l_AlfEsVacia(); //Ver si cambiar el tipo que devuelve por uno de tipo nodo
  int GetSizeStruct();
  void AddPal(string);
  void QuickSort(StructreCombined*, int, int);
};

#endif //_STRUCTRECOMBINED_H_
