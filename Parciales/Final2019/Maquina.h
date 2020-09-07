//
// Created by mlujan on 3/30/20.
//

#ifndef _MAQUINA_H_
#define _MAQUINA_H_
#include <stdint.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "Pagina.h"
#include "Lista.h"
#include "Logger.h"

class Maquina {
 private:
  uint16_t IpMaquina;
  int PaginasEnviadas;
  int BW;
  Lista<string> *envio;
  Lista<Pagina *> *recep;
  int cantPag;
  Logger *log;
  void CrearDatos ();
  void CrearAux ();

 public:
  Maquina (uint16_t, int, Logger *);
  int GetCantPag () const;
  uint16_t getIP () const;
  void toReceive (Pagina *);
  int cantPagReceive ();
  bool Pending ();
  Pagina *CreatedPage (const uint16_t [], int);

};

#endif //_MAQUINA_H_
