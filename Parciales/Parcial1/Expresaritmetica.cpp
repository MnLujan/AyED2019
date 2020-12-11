//
// Created by mlujan on 5/10/19.
//

#include "Expresaritmetica.h"

/**
 * Constructor sin parametros.
 */
Expresaritmetica::Expresaritmetica ()
{
  p = nullptr;
  V = nullptr;

}

/**
 * Constructor con parametros.
 * @param n cadena de caracteres a resolver
 * @param aux puntero a lista de variables
 */
Expresaritmetica::Expresaritmetica (List_Var *aux)
{
  p = new Pila ();
  V = aux;
}

/**
 * Metodo que evalua una expresion y la resuelve
 * @return resultado de tipo int
 */
int Expresaritmetica::resultado (string cadena)
{
  char d;
  char p_1;
  for (int j = 0; j < cadena.length (); j++)
    {
      d = cadena.at (j);
      if ((d >= '0' && d <= '9'))
        {
          pf.push_back (d);
        }
      else if ((d >= 'a') && (d <= 'z'))
        {
          /* envio el caracter y busco su nombre en la lista de variables, para despues reemplzara el valor */

          pf.push_back (V->get_val_2 (d) + '0');

        }
      else
        {
          while ((!p->pilavacia ()) && (prcd (p->tope (), d)))
            {
              p_1 = p->tope ();
              p->desapilar ();
              pf.push_back (p_1);
            }
          if ((p->pilavacia ()) || (d != ')')) p->apilar (d);
          else p->desapilar ();
        }
    }
  while (!p->pilavacia ())
    {
      p_1 = p->tope ();
      p->desapilar ();
      pf.push_back (p_1);
    }

/* Evaluacion de la expresion en posfijo */
  int o_1, o_2;

  for (int i = 0; (i < pf.length ()); i++)
    {
      d = pf.at (i);

      /* El programa queda limitado hasta el calculo del numero 122, por la implementacion */
      if ((d >= '0' && d <= '9') || (d>=':' && d<='z')) p->apilar (d - '0');
      if (d == '+')
        {
          o_2 = p->tope ();
          p->desapilar ();
          o_1 = p->tope ();
          p->desapilar ();
          p->apilar (o_1 + o_2);
        }
      if (d == '-')
        {
          o_2 = p->tope ();
          p->desapilar ();
          o_1 = p->tope ();
          p->desapilar ();
          p->apilar (o_1 - o_2);
        }
      if (d == '*')
        {
          o_2 = p->tope ();
          p->desapilar ();
          o_1 = p->tope ();
          p->desapilar ();
          p->apilar (o_1 * o_2);
        }
    }
  return p->tope ();
}

/**
 * Funcion precedencia
 * prcd(o1,'(') = 0 para todo o1 != de ')'
 * prcd(o1,')') = 1 para todo o1 != de '('
 * prcd('(',o2) = 0 para todo 02
 * prcd(o1,o2)  = 1 para todo o1 >= precedencia que o2
 */

int Expresaritmetica::prcd (int o1, int o2)
{
  if (o2 == '(')
    if (o1 == ')') return 1;
    else return 0;
  if (o2 == ')')
    if (o1 == '(') return 0;
    else return 1;
  if (o1 == '(') return 0;

  if ((o1 == '*') || (o1 == '/')) return 1;
  if (((o1 == '+') || (o1 == '-')) && ((o2 == '+') || (o2 == '-'))) return 1;
  else return 0;
}

/**
 * Metodo que evalua una condicion.
 * @return true en caso de que se cumpla la condicion. False caso contrario.
 */
bool Expresaritmetica::evaluacion (string cadena)
{
  char d;
  char p_1;

  for (int j = 0; j < cadena.length (); j++)
    {
      d = cadena.at (j);
      if ((d >= '0') && (d <= '9'))
        {
          pf.push_back (d);
        }
      else if ((d >= 'a') && (d <= 'z'))
        {
          /* envio el caracter y busco su nombre en la lista de variables, para despues reemplzara el valor */

          pf.push_back (V->get_val_2 (d) + '0');

        }
      else
        {
          while ((!p->pilavacia ()) && (prcd (p->tope (), d)))
            {
              p_1 = p->tope ();
              p->desapilar ();
              pf.push_back (p_1);
            }
          if ((p->pilavacia ()) || (d != ')')) p->apilar (d);
          else p->desapilar ();
        }
    }
  while (!p->pilavacia ())
    {
      p_1 = p->tope ();
      p->desapilar ();
      pf.push_back (p_1);
    }

/* Evaluacion de la expresion en posfijo */
  int o_1, o_2;

  for (int i = 0; (i < pf.length ()); i++)
    {
      d = pf.at (i);
      if (d >= '0' && d <= '9') p->apilar (d - '0');
      if (d == '=' && p_1 == '=')
        {
          o_2 = p->tope ();
          p->desapilar ();
          o_1 = p->tope ();
          p->desapilar ();
          if (o_1 == o_2)
            {
              return true;
            }
        }
      if (d == '<')
        {
          o_2 = p->tope ();
          p->desapilar ();
          o_1 = p->tope ();
          p->desapilar ();
          if (o_1 < o_2)
            {
              return true;
            }
        }
      if (d == '>')
        {
          o_2 = p->tope ();
          p->desapilar ();
          o_1 = p->tope ();
          p->desapilar ();
          if (o_1 > o_2)
            {
              return true;
            }
        }
      if (d == '!' && p_1 == '!')
        {
          o_2 = p->tope ();
          p->desapilar ();
          o_1 = p->tope ();
          p->desapilar ();
          if (o_1 != o_2)
            {
              return true;
            }
        }
    }
  return false;
}