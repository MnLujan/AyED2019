//
// Created by mlujan on 5/9/19.
//

#include "Pila.h"


Pila::Pila ()
{
  pos = -1;
}

Pila::Pila (char x)
{
  pos = 0;
  apilar (x);
}

void Pila::apilar (char x)
{
  if (pos != MAX2)
    {
      pos++;
      arreglo[pos] = x;
    }
  else
    {
      cout << "La pila esta llena" << endl;
    }
}

char Pila::tope ()
{

  /* Recordar que es de tipo LIFO */
  return arreglo[pos];
}

void Pila::desapilar ()
{
  if (pilavacia ())
    {
      cout << "Error, pila vacia" << endl;
    }
  else
    {
      pos--;
    }
}

bool Pila::pilavacia ()
{
  return pos == -1;
}
