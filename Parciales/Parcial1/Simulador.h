//
// Created by mlujan on 5/10/19.
//

#ifndef _SIMULADOR_H_
#define _SIMULADOR_H_
#include "List_Var.h"
#include "Lista_inst.h"
#include "Expresaritmetica.h"
#define MAX3 20

class Simulador {
 private:
  int pc;
  List_Var *v;
  Lista_inst *p;
  void declaracion (char);
  void asignacion (char, int);
  void jump (int);
  void show (char);
  void ejecutar (string);
 public:

  Simulador (Lista_inst *);
  void simular();

};

#endif //_SIMULADOR_H_
