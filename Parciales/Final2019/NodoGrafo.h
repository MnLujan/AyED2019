//
// Created by mlujan on 5/23/20.
//

#ifndef _NODOGRAFO_H_
#define _NODOGRAFO_H_
#include "Router.h"

/**
 * V = vertices, es decir plazas (estados, nodos)
 * E = Arcos, se marca con (origen, destino)
 *
 */

class NodoGrafo {
 private:
  Router *R;
  int peso;
  uint8_t BW;
 public:
  NodoGrafo (Router*, int);
  void setRouter (Router *p);
  Router *getRouter ();
  void setPeso (int);
  int getPeso ();
  uint8_t getBW();
};

#endif //_NODOGRAFO_H_
