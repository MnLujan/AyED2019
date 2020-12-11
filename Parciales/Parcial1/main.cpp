#include <cstdlib>
#include <iostream>
#include <cstring>
#include "Lista_inst.h"
#include "Simulador.h"
#define MAX 200

using namespace std;

int main ()
{

  FILE *inst;
  char cadena[MAX];
  auto *l = new Lista_inst ();

  inst = fopen ("instrucciones", "r");

  if (inst == nullptr)
    {
      printf ("Error [%s] \n", strerror (errno));
    }
  else
    {
      /* Guardado de instrucciones en la lista */
      while (fgets (cadena, MAX, inst) != nullptr)
        {
          l->add (cadena);
        }
      fclose (inst);
    }
  auto *s = new Simulador (l);
  s->simular ();

  return EXIT_SUCCESS;
}