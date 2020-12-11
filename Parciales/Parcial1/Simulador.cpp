//
// Created by mlujan on 5/10/19.
//

#include <cstring>
#include "Simulador.h"

/**
 * Constructor de la calse Simulador
 * @param l puntero a lista de instrucciones
 */
Simulador::Simulador (Lista_inst *l)
{
  pc = 1;
  v = new List_Var ();
  p = l;

}

/**
 * Simular se encarga de llamar iterativas veces al metodo ejecutar, hasta que se
 * termine la cantidad de instrucciones a ejecutar.
 */
void Simulador::simular ()
{
  int size = p->get_size ();
  while (pc < size + 1)
    {
      this->ejecutar (p->get_dato (pc - 1));
      pc = pc + 1;
    }
}

/**
 * Metodo que ejecuta las instrucciones una a una, tomando dichas instrucciones desde
 * la Lista_inst pasada como parametro.
 */
void Simulador::ejecutar (string aux)
{
  int size = p->get_size ();

  char a;
  int i;
  char cadena[MAX3];
  char cadena_2[MAX3];
  char cadena_3[MAX3];
  if (sscanf (aux.c_str (), "INT %c", &a) == 1)
    {
      declaracion (a);
    }
  else if (sscanf (aux.c_str (), "%c = %19s", &a, cadena) > 1)
    {
      Expresaritmetica *e = new Expresaritmetica (v);
      asignacion (a, e->resultado (cadena));
    }
  else if (sscanf (aux.c_str (), "JUMP %i", &i) == 1)
    {
      if (i > size || i == 0)
        {
          printf ("Error: %i y tamaño del programa %i \n", i, size);
        }
      else
        {
          jump (i);
          return;
        }

    }
  else if (sscanf (aux.c_str (), "SHOW %c", &a) == 1)
    {
      show (a);
    }
  else if (sscanf (aux.c_str (), "IF ( %19s ) THEN %19s %19s", cadena, cadena_2, cadena_3) > 1)
    {
      auto *k = new Expresaritmetica (v);
      if (k->evaluacion (cadena))
        {
          strcat(cadena_2, " ");
          strcat(cadena_2, cadena_3);
          this->ejecutar (cadena_2);
          return;
        }
    }

}

/**
 * Metodo que ejecuta la instruccion de declaracion de variable. Corrobora si la variable
 * ya existe.
 * @param b nombre de la variable
 */
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

/**
 * Ejecuta la instruccion de asignacion de varaibles, corroborando antes si existen variables
 * para asignar.
 * @param c nombre de la variable a asignar un valor
 * @param re resultado de la expresion aritmetica ingresada
 */
void Simulador::asignacion (char c, int re)
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
              v->set_val (i, re);
              return;
            }
        }
      return;
    }
}

void Simulador::jump (int i)
{
  /* Le resto 1 ya que cuando vuelvo de ejecutar el pc de aumenta en 1 */
  pc = i - 1 ;
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