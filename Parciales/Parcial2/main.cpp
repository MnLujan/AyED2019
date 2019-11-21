#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include "StructreCombined.h"

using namespace std;
/**
 * @TODO Lograr que pueda enviar todas las palabras pero en minuscula para poder ordenarlas.
 * @return
 */

int main ()
{
  StructreCombined *l = new StructreCombined ();
  fstream input;
  string line;
  input.open ("texto");

  /* Lista ordenada alfabeticamente */
  while (input >> line)
    {
      l->AddPal (line);
    }
  input.close ();

  return EXIT_SUCCESS;
}