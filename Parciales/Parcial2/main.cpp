#include <iostream>
#include <cstdlib>
#include <fstream>
#include <jmorecfg.h>
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
  string tmp;
  input.open ("texto");

  /* Se arma la estrucutra combinada */
  while (input >> line)
    {
      /* Paso el string a minuscula */
      for (int i = 0; i < line.length (); i++)
        {
          line[i] = tolower (line[i]);
        }
      /* Agrego la palabra a la estructura */
      l->AddPal (line);
    }

  input.close ();

  /* Llamo al metodo QuickSort */
  l->OrdenaQS ();

  /* Creo el texto con las palabras ordenadas alfabeticamente y por numero de repeticiones */
  ofstream fs ("Texto Ordenado.txt");
  fs << "Alfabeticamente:" << endl;
  for (int i = 0; i < l->GetSizeStruct (); i++)
    {
      fs << l->GetNodoAlf (i)->GetDataPal () << " ";
    }
  fs << endl;
  fs << "Repeticiones:" << endl;
  for (int j = 0; j < l->GetSizeStruct (); ++j)
    {
      fs << l->GetNodoSwap (j)->GetDataPal () << " ";
    }
  fs << endl;
  fs << "Comparaciones: \nInsercion por lista: " << l->compLIST << " / Insercsion ABB: " << l->compABB
     << " / Quicksort: " << l->compQS << endl;
  fs.close ();

  return EXIT_SUCCESS;
}