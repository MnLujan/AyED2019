//
// Created by mlujan on 5/10/19.
//

#ifndef _EXPRESARITMETICA_H_
#define _EXPRESARITMETICA_H_
#include "Pila.h"
#include "List_Var.h"

class Expresaritmetica {
 private:
  string pf;
  Pila *p;
  List_Var *V;
 public:
  Expresaritmetica();
  Expresaritmetica(List_Var*);
  int resultado(string);
  bool evaluacion(string);
  int prcd(int, int);

};

#endif //_EXPRESARITMETICA_H_
