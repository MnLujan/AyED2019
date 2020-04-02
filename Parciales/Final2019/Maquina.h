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
  Lista<string> *envio;
  Lista<Pagina> *recep;
  int cantPag;
  void CrearDatos();
  void CrearAux();
 public:
  Pagina* CreatedPage(uint8_t);
  Maquina(uint8_t, int);
  int GetCantPag();
  int GetBW();
  uint8_t getIP();
  void setBW(int);
  void toReceive(Pagina*);

};

#endif //_MAQUINA_H_
