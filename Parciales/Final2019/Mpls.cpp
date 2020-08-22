//
// Created by mlujan on 8/7/20.
//
#include "Mpls.h"

/**
 * @brief constructor de la clase Mpls
 * @param auxlink puntero a Lista de Lista de conexiones, es decir, la topologia, los Routers y sus conexiones
 */
Mpls::Mpls (Lista<Lista<NodoGrafo *> *> *auxlink)
{
  this->links = auxlink;

  this->routers = this->links->get_size ();

  this->route.clear ();

//inicializamos los  campos
  for (int i = 0; i <= this->routers; ++i)
    {
      this->distancia[i] = INF;  //inicializamos todas las distancias con valor infinito
      this->isVisited[i] = false; //inicializamos todos los vértices como no visitados
      this->prev[i] = -1;      //inicializamos el previo del vertice i con -1
    }

}

/**
 * @brief Funcion encargada de reiniciar los valores por defecto para un proximo
 * calculo de ruta.
 */
void Mpls::reboot ()
{
  /* Limpio el camino */
  this->route.clear ();

  for (int i = 0; i <= this->routers; ++i)
    {
      this->distancia[i] = INF;  //inicializamos todas las distancias con valor infinito
      this->isVisited[i] = false; //inicializamos todos los vértices como no visitados
      this->prev[i] = -1;      //inicializamos el previo del vertice i con -1

    }
}

/**
 * @brief metodo auxiliar para la funcion de dijktra
 * @param actual step actual
 * @param adyacente step siguiente
 * @param peso peso de la conexion
 */
void Mpls::relax (int actual, int ady, int peso)
{
  //Si la distancia del origen al vertice actual + peso de su arista es menor a la distancia del origen al vertice adyacente
  if (this->distancia[actual] + peso < this->distancia[ady])
    {
      this->distancia[ady] = this->distancia[actual] + peso;  //relajamos el vertice actualizando la distancia
      this->prev[ady] = actual;                         //a su vez actualizamos el vertice previo
      this->Queue.push (Node (ady, this->distancia[ady])); //agregamos adyacente a la cola de prioridad
    }
}

/**
 * @brief Metodo auxiliar para la utilizacion de dijktra
 */
void Mpls::constAdyacen ()
{
  int NumR, origen, destino, peso, inicial;

  NumR = this->links->get_size ();

  for (int i = 0; i < NumR; i++)
    {
      origen = (this->links->get_nodo (i)->getdato ()->get_nodo (0)->getdato ()->getRouter ()->getN_R ()) & 0x00FF;
      for (int j = 1; j < this->links->get_nodo (i)->getdato ()->get_size (); j++)
        {
          destino = (this->links->get_nodo (i)->getdato ()->get_nodo (j)->getdato ()->getRouter ()->getN_R ()) & 0x00FF;
          peso = this->links->get_nodo (i)->getdato ()->get_nodo (j)->getdato ()->getPeso ();
          this->adyacen[destino].emplace_back (Node (origen, peso));
        }
    }
}

/**
 *  @brief Algoritmo encargado de calcular el camino mas optimo
 *  @param init punto inicial de donde calcular el mejor camino
 */
void Mpls::Dijkstra (int init)
{
  //construccion de lista de Ady con pesos actualizados
  this->constAdyacen ();

  this->Queue.push (Node (init, 0)); //Insertamos el vértice inicial en la Cola de Prioridad
  this->distancia[init] = 0;      //Este paso es importante, inicializamos la distancia del inicial como 0
  int actual, adyacente, peso;

  while (!this->Queue.empty ())
    {                         //Mientras cola no este vacia
      actual = this->Queue.top ().first;                  //Obtengo de la cola el nodo con menor peso, en un comienzo será el inicial
      this->Queue.pop ();                                 //Sacamos el elemento de la cola
      if (this->isVisited[actual]) continue;       //Si el vértice actual ya fue visitado entonces sigo sacando elementos de la cola
      this->isVisited[actual] = true;               //Marco como visitado el vértice actual

      for (int i = 0; i < this->adyacen[actual].size (); ++i)
        { //reviso sus adyacentes del vertice actual
          adyacente = this->adyacen[actual][i].first;          //id del vertice adyacente
          peso = this->adyacen[actual][i].second;              //peso de la arista que une actual con adyacente ( actual , adyacente )
          if (!this->isVisited[adyacente])
            {                  //si el vertice adyacente no fue visitado
              relax (actual, adyacente, peso);         //realizamos el paso de relajacion
            }
        }
    }
}

/**
 * @brief Imprime por pantalla los vertices hasta el destino.
 * @param dest
 */
void Mpls::Print (int dest)
{
  /* LLamo recursivamente al metodo hasta llegar al vertice de origen */
  if (prev[dest] != 1)
    {
      Print (prev[dest]);
    }
  printf ("%d ", dest);
}

/**
 * @brief Muestra por pantalla el maquino desde inicio a fin.
 * @param init Incio del camino
 * @param dest Final del camino
 */
void Mpls::SeeRoute (int init, int dest)
{
  printf ("Distancias mas cortas iniciando en vertice %d\n", init);
  for (int i = 1; i <= this->routers; ++i)
    {
      printf ("Vertice %d , distancia mas corta = %d\n", i, this->distancia[i]);
    }
  puts ("\n**************Impresion de camino mas corto**************");
  printf (" Vertice destino: %d\n", dest);

}

/**
 * @brief Metodo encargado de construir el camino mas corto.
 * @param dest destino al que quiero llegar
 */
void Mpls::BuildRoute (int dest)
{
  if (prev[dest] != -1)
    {
      BuildRoute (prev[dest]);
    }
  int newPush = dest;
  this->route.push_back (newPush);
}

/**
 * @brief Metodo encargado de devolver en un vector la ruta mas corta
 * @return vector con la ruta mas corta
 */
vector<uint16_t> Mpls::getRoute ()
{
  return this->route;
}