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
  Lista_inst *l;

  inst = fopen ("secuencia", "r");

  if (inst == NULL)
    {
      printf ("Error [%s] \n", strerror (errno));
    }
  else
    {
      l = new Lista_inst ();
      while (fgets (cadena, MAX, inst) != NULL)
        {
          l->add (cadena);
        }
      fclose (inst);
      cout << l->cabeza ();
    }
  Simulador *s = new Simulador (l);
  s->ejecutar ();

  return EXIT_SUCCESS;
}