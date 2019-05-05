//
// Created by mlujan on 5/4/19.
//

#ifndef PARCIAL1_NODO_INST_H
#define PARCIAL1_NODO_INST_H
#include <cstdlib>
#include <string>

using namespace std;

class Nodo_inst {

 private:
  string dato;
  Nodo_inst *next;

 public:

  Nodo_inst (string);

  void set_next (Nodo_inst *n);

  string get_dato ();

  Nodo_inst *get_next ();

  bool es_vacio ();
};

#endif //PARCIAL1_NODO_INST_H
