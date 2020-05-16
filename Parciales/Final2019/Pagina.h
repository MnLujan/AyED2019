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
  uint8_t Origen;
  uint8_t Destino;
  uint8_t IDpag;

 public:
  Pagina ();
  Pagina (string, uint8_t, uint8_t, uint8_t);
  uint8_t getOrigen ();
  uint8_t getDestino ();
  string getDato ();
  uint8_t getIDpag();

};

#endif //_PAGINA_H_
