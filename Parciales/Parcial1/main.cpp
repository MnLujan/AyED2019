#include <cstdlib>
#include <iostream>
#include <sstream>
#include <cstring>
#include "Lista_inst.h"

#define MAX 200

using namespace std;

int main ()
{

  FILE *inst;
  char cadena[MAX];

  inst = fopen ("secuencia", "r");

  if (inst == NULL)
    {
      printf ("Error [%s] \n", strerror (errno));
    }
  else
    {
      Lista_inst *l = new Lista_inst();
      while (fgets (cadena, MAX, inst) != NULL)
        {
              l->add (cadena);
        }
      fclose (inst);
      cout<<l->cabeza ();
    }

  return EXIT_SUCCESS;
}