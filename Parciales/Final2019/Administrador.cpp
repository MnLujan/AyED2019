//
// Created by mlujan on 5/17/20.
//

#include "Administrador.h"

/**
 * @brief Constructor de la clase
 */
Administrador::Administrador ()
{
  this->links = new Lista<Lista<NodoGrafo *> *> ();
  this->routers = new Lista<Router *> ();
  this->pag2Send = 0;
  this->pagReceive = 0;
  //Ver si poner aca el metodo de construir el grafo
}

/**
 * @brief Metodo encargado de la generacion del grafo que representa la red, apartir de un archivo.
 */
void Administrador::BuildGraph() {

  /* Leo los datos */
  Lista<string>* info = ReadFile();

  /* Routers-Host */
  uint8_t N_R;
  uint8_t Host;
  uint8_t BW;
  uint16_t Ip_R = 0;

  /* Router-Router */
  uint8_t N_R1;
  uint8_t N_R2;
  uint8_t BW_R;
  uint16_t Ip_R1 = 0;
  uint16_t Ip_R2 = 0;



}

/**
 * @brief Metodo en encargado de leer el archivo parametrizador armando una lista con todos los datos.
 * @return characters. Puntero a Lista.
 */
Lista<string>* Administrador::ReadFile ()
{
  string file = "ConfigRed";
  ifstream fi(file);

  Lista<string> *characters = new Lista<string>();
  char *ptr;
  char del[4] = " \n\t";

  //Leo el archivo para la construccion del Grafo
  while(!fi.eof()){
    char arr[10000];
    fi.getline(arr, 10000);
    if(arr[0] == '\0'){
        continue;
    }
    ptr = strtok(arr, del);
    string aux(ptr);
    //Lo agrego a la lista
    characters->Add(aux);
    while((ptr = strtok(NULL, del)) != NULL){
      string aux2(ptr);
      characters->Add(aux2);
    }
  }

  return characters;
}

