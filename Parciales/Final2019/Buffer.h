//
// Created by mlujan on 4/3/20.
//

#ifndef _BUFFER_H_
#define _BUFFER_H_
#include "Lista.h"
#include "Packages.h"

class Buffer {
 private:
  Lista<Packages *> *cola;
  uint16_t ID;
 public:
  Buffer (Lista<Packages *> *, uint16_t);
  uint16_t getID ();
  Lista<Packages *> *getLista ();
  void AddListPag(Lista<Packages*>*);
};

#endif //_BUFFER_H_
