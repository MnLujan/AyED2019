//
// Created by mlujan on 5/9/19.
//

#ifndef _PILA_H_
#define _PILA_H_
#include <iostream>
#include <sstream>
using namespace std;

const int n = 100;
class Pila {

 private:
  char arreglo[n];
  int pos;

 public:
  Pila ();
  Pila(char x);
  void apilar (char x);

  char tope ();

  void desapilar ();

  bool pilavacia ();
  void imprimir ();
};


#endif //_PILA_H_
