//
// Created by mlujan on 5/10/19.
//

#ifndef _EXPRESARITMETICA_H_
#define _EXPRESARITMETICA_H_
#include "Pila.h"
#include "List_Var.h"

class Expresaritmetica {
 private:
  string cadena;
  string pf;
  Pila *p;
  List_Var *V;
 public:
  Expresaritmetica();
  Expresaritmetica(string, List_Var*);
  int resultado();
  bool evaluacion();
  int prcd(int, int);
  void reemplazar();

};

#endif //_EXPRESARITMETICA_H_
