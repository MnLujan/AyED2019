//
// Created by mlujan on 3/30/20.
//

#ifndef _PAGINA_H_
#define _PAGINA_H_
#include <string>
#include <stdint.h>

using namespace std;

class Pagina {
 private:
  string dato;
  uint16_t Origen;
  uint16_t Destino;
  uint8_t IDpag;

 public:
  Pagina ();
  Pagina (string, uint16_t, uint16_t, uint8_t);
  uint16_t getOrigen ();
  uint16_t getDestino ();
  string getDato ();
  uint8_t getIDpag();

};

#endif //_PAGINA_H_
