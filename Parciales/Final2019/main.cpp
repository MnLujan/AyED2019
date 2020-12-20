#include <iostream>
#include <stdlib.h>
#include "Administrador.h"
#include "Logger.h"
using namespace std;

int main ()
{
  Logger *log = new Logger ();

  auto *admin = new Administrador (log);

  /* Imprimo grafo */
  admin->printGraph ();

  /* Simulacion */
  while (!admin->Finalize ())
    {
      admin->Simulate ();
    }

  /* Cierro LOG */
  log->close_Log ();

  return EXIT_SUCCESS;
}