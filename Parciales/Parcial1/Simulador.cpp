//
// Created by mlujan on 5/10/19.
//

#include "Simulador.h"

Simulador::Simulador (Lista_inst *l)
{
  pc = 1;
  v = new List_Var ();
  p = l;

}

void Simulador::ejecutar ()
{
  int size = p->get_size ();
  while (pc < size + 1)
    {
      char a;
      int i;
      char cadena[20];
      if (sscanf (p->get_dato (pc - 1).c_str (), "INT %c", &a) == 1)
        {
          declaracion (a);
        }
      else if (sscanf (p->get_dato (pc - 1).c_str (), "%c = %19s", &a, cadena) > 1)
        {
          asignacion (a, cadena);
        }
      else if (sscanf (p->get_dato (pc - 1).c_str (), "JUMP %i", &i) == 1)
        {
          if (i > size || i == 0)
            {
              printf ("Error: %i y tamaño del programa %i \n", i, size);
            }
          else
            {
              jump (i);
              continue;
            }

        }
      else if (sscanf (p->get_dato (pc - 1).c_str (), "SHOW %c", &a) == 1)
        {
          show (a);
        }
      pc = pc + 1;
    }
}

void Simulador::declaracion (char b)
{
  if (v->esvacia ())
    {
      v->addVar (b, 0);
    }
  else
    {
      for (int i = 0; i < v->get_size (); i++)
        {
          if (v->get_name (i) == b)
            {
              printf ("Ya existe una variable con el nombre %c", b);
              return;
            }
        }
      v->addVar (b, 0);
    }

}

void Simulador::asignacion (char c, string cadena)
{
  if (v->esvacia ())
    {
      printf ("No hay variables que asignar");
      return;
    }
  else
    {
      for (int i = 0; i < v->get_size (); i++)
        {
          if (v->get_name (i) == c)
            {
              v->set_val (i, i);
              return;
            }
        }
      return;
    }
}

void Simulador::jump (int i)
{
  pc = i;
  return;

}

void Simulador::show (char a)
{
  for (int i = 0; i < v->get_size (); i++)
    {
      if (v->get_name (i) == a)
        {
          printf ("%c = %i \n", a, v->get_val (i));
          return;
        }
    }
  printf ("No existe la variable %c \n", a);
  return;
}