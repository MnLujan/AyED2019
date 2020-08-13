//
// Created by mlujan on 8/7/20.
//
#ifndef _MPLS_H_
#define _MPLS_H_

#include <stdio.h>
#include <vector>
#include <queue>
#include "Lista.h"
#include "NodoGrafo.h"

using namespace std;
#define MAX 65000 //Maximo numero de vertices (vantidad maxima de routers)
#define Node pair<int, int>

/* Se define un valor grande para que represente la distancia infinita inicial (40000000)*/
#define INF 1<<30

struct cmp {
    bool operator() (const Node &a, const Node &b)
    {
      return a.second > b.second;
    }
};

class Mpls {
 private:
  Lista<Lista<NodoGrafo *> *> *links;
  vector<Node > adyacen[MAX];
  int distancia[MAX];
  bool isVisited[MAX];
  priority_queue<Node, vector<Node >, cmp> Queue;
  int routers;
  int prev[MAX];
  vector<uint16_t> route;
 public:
  Mpls (Lista<Lista<NodoGrafo *> *> *);
  void constAdyacen ();
  void relax (int, int, int);
  void Print (int);
  void Dijkstra (int);
  void SeeRoute (int, int);
  void BuildRoute (int);
  vector<uint16_t> getRoute ();
  void reboot();
};

#endif //_MPLS_H_
