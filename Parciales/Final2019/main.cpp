#include <iostream>
#include <stdlib.h>
#include "Administrador.h"
#include "Logger.h"
using namespace std;

int main ()
{

  auto log = new Logger ();

  auto *admin = new Administrador (log);

  //admin->weighing();
  admin->printGraph ();

  log->close_Log ();

  return EXIT_SUCCESS;
}