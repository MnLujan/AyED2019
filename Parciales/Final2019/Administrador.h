//
// Created by mlujan on 5/17/20.
//

#ifndef _ADMINISTRADOR_H_
#define _ADMINISTRADOR_H_
#include "Router.h"
#include "Maquina.h"
#include "Lista.h"
#include "NodoGrafo.h"
#include <fstream>
#include <cstring>
#include <cstdint>
#include "Mpls.h"
#include "Logger.h"

class Administrador {
 private:
  Lista<Lista<NodoGrafo *> *> *links;
  Lista<Router *> *routers;
  uint16_t addressAvailabe[65600];
  int quantAddres = 0;
  int pagReceive;
  int pagtoSend;
  Mpls *route;
  Logger *log;

  Lista<string> *ReadFile ();
  void BuildGraph ();
  void ListRouter (uint16_t, uint16_t);
  void linkMachines (uint16_t, uint16_t, uint16_t, uint16_t);
  void pag2Send ();
  vector<uint16_t> getRoad (int, int);
 public:
  Administrador (Logger*);
  void printGraph ();
  void weighing ();
};

#endif //_ADMINISTRADOR_H_
