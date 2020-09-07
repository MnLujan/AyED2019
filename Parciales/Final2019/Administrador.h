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
#include <iostream>
#include "Mpls.h"
#include "Logger.h"

class Administrador {
 private:

  /* Variables */
  Lista<Lista<NodoGrafo *> *> *links;
  Lista<Router *> *routers;
  uint16_t addressAvailabe[65600];
  int quantAddres = 0;
  int pagReceive;
  int pagtoSend;
  Mpls *route;
  Logger *log;

  /* Metodos privado usados solo por la clase */
  Lista<string> *ReadFile ();
  void BuildGraph ();
  void ListRouter (uint16_t, uint16_t);
  void linkMachines (uint16_t, uint16_t, uint16_t, uint16_t, Logger *);
  void pag2Send ();
  vector<uint16_t> getRoad (int, int);
  void SendPag (Maquina *);
  Router *getRouter (uint16_t);
  void RouterToMachine (Router *);
  void InputToOutput (Router *, int);
  void RouterToRouter (Router *);
  uint8_t getlinksBW (uint16_t, uint16_t);
  bool match(Lista<uint16_t>*, uint16_t);
  void weighing ();

 public:
  /* Metodo publicos llamados desde el Main */
  Administrador (Logger *);
  void printGraph ();
  void Simulate ();
  bool Finalize ();
};

#endif //_ADMINISTRADOR_H_
