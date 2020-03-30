//
// Created by mlujan on 3/30/20.
//

#ifndef _PAGINA_H_
#define _PAGINA_H_
#include <string>

using namespace std;

class Pagina {
 private:
  string dato;
  u_int8_t Origen;
  u_int8_t Destino;

 public:
  Pagina();
  Pagina(char, u_int8_t, u_int8_t);
  u_int8_t getOrigen();
  u_int8_t getDestino();
  string getDato();

};

#endif //_PAGINA_H_
