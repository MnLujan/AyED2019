#include <cstdlib>
#include <iostream>
#include <sstream>
#include <cstring>
#include "Lista_inst.h"
#include "List_Var.h"
#include "Pila.h"

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
      Lista_inst *l = new Lista_inst ();
      while (fgets (cadena, MAX, inst) != NULL)
        {
          l->add (cadena);
        }
      fclose (inst);
      cout << l->cabeza ();
    }
  List_Var *v = new List_Var ();
  v->addVar ('a', 20);
  v->addVar ('b', 15);
  v->addVar ('c', 90);
  cout << "Primer valor guardado:" << v->cabeza ()->get_valor ();
  cout << "Tamaño de la lista: " << v->get_size () << endl;
  cout << "Valor del ultimo: " << v->get_nodo (v->get_size () - 1)->get_valor ();
  return EXIT_SUCCESS;
}