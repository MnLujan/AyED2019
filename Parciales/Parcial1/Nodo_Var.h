//
// Created by mlujan on 5/5/19.
//

#ifndef _NODO_VAR_H_
#define _NODO_VAR_H_
#include "Variables.h"
#include <cstdlib>

class Nodo_Var {

 private:
  Variables* var;
  Nodo_Var* next;

 public:

  Nodo_Var();

  Nodo_Var (char, int);

  void set_next (Nodo_Var *n);

  Nodo_Var *get_next ();

  bool es_vacio ();

  char get_nombre();

  int get_valor();

  void set_val(int);

};

#endif //_NODO_VAR_H_
