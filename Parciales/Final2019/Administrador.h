//
// Created by mlujan on 5/17/20.
//

#ifndef _ADMINISTRADOR_H_
#define _ADMINISTRADOR_H_
#include "Router.h"
#include "Maquina.h"
#include "Lista.h"
#include "NodoGrafo.h"
#include <fstream>
#include <string.h>
#include <cstdint>
#include <vector>


class Administrador {
 private:
    Lista<Lista<NodoGrafo*>*> *links;
    Lista<Router*> *routers;
    uint16_t addressAvailabe;
    int quantAddres = 0;
    int pagReceive;
    int pag2Send;
    Lista<string>* ReadFile();
    void BuildGraph();
 public:
    Administrador();
    Router *getRouter(uint16_t);
    vector<uint16_t> getRoute(int, int);
};

#endif //_ADMINISTRADOR_H_
