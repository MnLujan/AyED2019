#include <iostream>
#include <stdlib.h>
#include "Maquina.h"
using namespace std;

int main ()
{
  Maquina *m = new Maquina(245, 5);
  m->toReceive (m->CreatedPage (45));
  return EXIT_SUCCESS;
}