//
// Created by mlujan on 4/3/20.
//

#ifndef _ROUTER_H_
#define _ROUTER_H_
#include "Buffer.h"
#include "Pagina.h"
#include "Packages.h"
#include "Maquina.h"

class Router {
 private:
  uint8_t IPRouter;
  Lista<Packages *> *paquetes = nullptr;
  Lista<Pagina *> *Pag = nullptr;
  Lista<Maquina *> *Maqui = nullptr;
  Lista<Router *> *Rvecinos = nullptr;
  uint8_t N_R;
 public:
  Router();
  Router(uint8_t, uint8_t);
  uint8_t getIpRouter ();
  uint8_t getN_R();
  Lista<Pagina *> *getPagList ();
  Lista<Packages *> *getPackList ();
  Lista<Maquina *> *getMaquiList ();
  Lista<Router *> *getRouterList ();
  void toRecivePag (Pagina *);


};

#endif //_ROUTER_H_
