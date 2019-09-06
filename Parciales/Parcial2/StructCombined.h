//
// Created by mlujan on 6/7/19.
//

#ifndef _STRUCTCOMBINED_H_
#define _STRUCTCOMBINED_H_
#include <iostream>
#include "Nodo_Struc.h"

using namespace std;

class StructCombined {
 private:
  Nodo_Struc *czo;
  int size;
 public:
  StructCombined();
  StructCombined(string x);
  bool esvacia();
  int get_size();
  int get_NumRep(int);
  void AddPal(string);
  void QuickSort(StructCombined*, int, int);
  void Divide(StructCombined*, int, int);
  string get_palabra();
  void LlamadoABB(string); //hacer
  void Arbol_ABB (string); //terminar

};

#endif //_STRUCTCOMBINED_H_
