//
// Created by mlujan on 5/4/19.
//

#ifndef _LISTA_INST_H_
#define _LISTA_INST_H_
#include "Nodo_inst.h"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class Lista_inst {

 private:

  Nodo_inst *czo;
  int size;

 public:
  Lista_inst (string);

  //Lista_inst (Nodo_inst *n);

  void add (string);

  bool esvacia (void);

  string cabeza (void);

  Nodo_inst *get_nodo (int);

  //Lista_inst *resto (void);

  //std::string toPrint (std::string p);

  int get_size ();
};

#endif //_LISTA_INST_H_
