//
// Created by mlujan on 4/3/20.
//

#ifndef _BUFFER_H_
#define _BUFFER_H_
#include "Lista.h"
#include "Pagina.h"

class Buffer {
 private:
  Lista<Pagina *> *cola;
  uint8_t ID;
 public:
  Buffer (Lista<Pagina *> *, uint8_t);
  uint8_t getID ();
  Lista<Pagina *> *getLista ();
  void AddListPag(Lista<Pagina*>*);
};

#endif //_BUFFER_H_
