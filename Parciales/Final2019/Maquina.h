//
// Created by mlujan on 3/30/20.
//

#ifndef _MAQUINA_H_
#define _MAQUINA_H_
#include "Pagina.h"
#include "Lista.h"

class Maquina {
 private:
  uint16_t IpMaquina;
  int PaginasEnviadas;
  int BW;
  Lista<string> *envio;
  Lista<Pagina> *recep;
  int cantPag;
  void CrearDatos();
  void CrearAux();

 public:
  Maquina(uint16_t, int);
  int GetCantPag();
  int GetBW();
  uint16_t getIP();
  void setBW(int);
  void toReceive(Pagina*);
  int cantPagReceive();
  bool Pending();
  Pagina* CreatedPage(const uint16_t [], int);

};

#endif //_MAQUINA_H_
