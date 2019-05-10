//
// Created by mlujan on 5/10/19.
//

#ifndef _SIMULADOR_H_
#define _SIMULADOR_H_
#include "List_Var.h"
#include "Lista_inst.h"

class Simulador {
 private:
  int pc;
  List_Var *v;
  Lista_inst *p;
  void declaracion(char);
  void asignacion(char, string);
  void jump (int);
  void show(char);
 public:

  Simulador (Lista_inst*);

  void ejecutar();



};

#endif //_SIMULADOR_H_
