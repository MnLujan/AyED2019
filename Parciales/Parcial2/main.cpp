#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include "StructCombined.h"

using namespace std;
/**
 * @TODO Lograr que pueda enviar todas las palabras pero en minuscula para poder ordenarlas.
 * @return
 */

int main ()
{
  StructCombined *l = new StructCombined ();
  fstream input;
  string line;
  input.open ("texto");

  /* Almacenamiento de datos */
   while (input >> line)
    {
      l->AddPal (line);
    }
  input.close ();

  return EXIT_SUCCESS;
}