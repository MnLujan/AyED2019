//
// Created by mlujan on 4/3/20.
//

#ifndef _ROUTER_H_
#define _ROUTER_H_
#include "Buffer.h"
#include "Pagina.h"
#include "Packages.h"
#include "Maquina.h"
/***
 * @TODO enviarpaquetes
 */
class Router {
 private:
  uint16_t IPRouter;
  Lista<Packages *> *Input = nullptr;
  Lista<Pagina *> *Pag = nullptr;
  Lista<Maquina *> *Maqui = nullptr;
  Lista<Router *> *Rvecinos = nullptr;
  Lista<Buffer *> *BuffersSalida = nullptr;
  Lista<Lista<Packages *> *> *package2pag = nullptr;
  uint8_t N_R;
 public:
  Router ();
  Router (uint16_t, uint8_t);
  uint16_t getIpRouter () const;
  uint8_t getN_R ();
  Lista<Pagina *> *getPagList ();
  Lista<Packages *> *getInputList ();
  Lista<Maquina *> *getMaquiList ();
  Lista<Router *> *getRouterList ();
  void toRecivePag (Pagina *);
  void linkMachine (Maquina *);
  void linkRouter (Router *);
  bool StateInput ();
  void toRecivePackage (Packages *);
  void encolar (Packages *, int);


};

#endif //_ROUTER_H_
