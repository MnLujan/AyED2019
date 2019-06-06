#include <cstdlib>
#include <iostream>
#include <sstream>
#include <cstring>
#include "Lista_inst.h"
#include "Simulador.h"
#define MAX 200

using namespace std;

int main ()
{

  FILE *inst;
  char cadena[MAX];
  Lista_inst *l = new Lista_inst ();

  inst = fopen ("secuencia", "r");

  if (inst == NULL)
    {
      printf ("Error [%s] \n", strerror (errno));
    }
  else
    {
      /* Guardado de instrucciones en la lista */
      while (fgets (cadena, MAX, inst) != NULL)
        {
          l->add (cadena);
        }
      fclose (inst);
    }
  Simulador *s = new Simulador (l);
  s->simular ();

  return EXIT_SUCCESS;
}