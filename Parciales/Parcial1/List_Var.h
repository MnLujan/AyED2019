//
// Created by mlujan on 5/5/19.
//

#ifndef _LIST_VAR_H_
#define _LIST_VAR_H_
#include "Nodo_Var.h"
#include <cstdlib>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class List_Var {
 private:
  Nodo_Var *czo;
  int size;
 public:
  List_Var ();

  List_Var (char, int);

  void addVar (char, int);

  bool esvacia (void);

  Nodo_Var *cabeza (void);

  Nodo_Var *get_nodo (int);

  char get_name(int);

  int get_val(int);

  int get_size ();

  void set_val(int,int);

};

#endif //_LIST_VAR_H_
