//
// Created by mlujan on 5/9/19.
//

#include "Pila.h"

/**
 * @TODO Preguntar sobre el constructor Pila(char)
 */
Pila::Pila ()
{
  pos = -1;
}

Pila::Pila (char x)
{
  pos = 0;
  apilar (x);
}

void Pila::imprimir() {

  if(pilavacia()){
      cout<<"Pila vacia, nada que imprimir"<<endl;
      return;
    }else{
      for(int i = pos; i>=0; i--){
          cout<<arreglo[i]<<" - ";
        }
      cout<<endl;
    }
}
void Pila::apilar(char x) {
  if(pos != n) {
      pos++;
      arreglo[pos] = x;
    }else{
      cout<<"La pila esta llena"<<endl;
    }
}

char Pila::tope() {

  /* Recordar que es de tipo LIFO */
  return arreglo[pos];
}

void Pila::desapilar() {
  if (pilavacia()) {
      cout<<"Error, pila vacia" << endl;
    } else {
      pos--;
    }
}

bool Pila::pilavacia() {
  return pos == -1;
}
