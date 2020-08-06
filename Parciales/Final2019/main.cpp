#include <iostream>
#include <stdlib.h>
#include "Administrador.h"
using namespace std;

int main ()
{
  Administrador *admin = new Administrador();
  admin->weighing();

  return EXIT_SUCCESS;
}