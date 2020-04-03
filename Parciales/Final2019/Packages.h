//
// Created by mlujan on 4/2/20.
//

#ifndef _PACKAGES_H_
#define _PACKAGES_H_
#include "Pagina.h"

class Packages {
 private:
  char letra;
  uint8_t origen;
  uint8_t destino;
  int frame;
  int frameTotal;
 public:
  Packages(char, uint8_t, uint8_t, int, int);
  uint8_t getOrigen();
  uint8_t getDestino();
  int getFrame();
  int getFrameTotal();
  char getletra();

};

#endif //_PACKAGES_H_
