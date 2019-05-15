//
// Created by mlujan on 5/9/19.
//

#ifndef _PILA_H_
#define _PILA_H_
#include <iostream>
#include <sstream>
#define MAX2 100
using namespace std;

class Pila {

 private:
  char arreglo[MAX2];
  int pos;

 public:
  Pila ();
  Pila(char x);
  void apilar (char x);

  char tope ();

  void desapilar ();

  bool pilavacia ();
};


#endif //_PILA_H_
