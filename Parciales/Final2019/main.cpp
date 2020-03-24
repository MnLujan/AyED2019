#include <iostream>
#include <stdlib.h>
#include "Lista.h"
using namespace std;

int main ()
{

  Lista<int> *l = new Lista<int>(2);
  Lista<string> *r = new Lista<string>("hola");
  l->Add(2);
  l->Add(5);
  l->Add (10);
  r->Add("puto");
  r->Add("jeje");
  return 0;
}
