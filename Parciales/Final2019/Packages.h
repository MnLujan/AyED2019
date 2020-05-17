//
// Created by mlujan on 4/2/20.
//

#ifndef _PACKAGES_H_
#define _PACKAGES_H_
#include "Pagina.h"

class Packages {
 private:
  char letra;
  uint16_t origen;
  uint16_t destino;
  int frame;
  int frameTotal;
  uint8_t idpag;
 public:
  Packages(char, uint16_t, uint16_t, int, int, uint8_t);
  uint16_t getOrigen();
  uint16_t getDestino();
  int getFrame();
  int getFrameTotal();
  char getletra();
  uint8_t getIdPag();

};

#endif //_PACKAGES_H_
