//
// Created by mlujan on 3/30/20.
//

#ifndef _MAQUINA_H_
#define _MAQUINA_H_
#include "Pagina.h"
#include "Lista.h"

class Maquina {
 private:
  uint8_t IpMaquina;
  int PaginasEnviadas;
  int BW;
  Lista<string> envio;
  Lista<string> recep;
  int cantPag;
  void CrearPalabras();

 public:
  Pagina* SendPage();

};

#endif //_MAQUINA_H_
