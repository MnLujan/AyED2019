//
// Created by mlujan on 6/7/19.
//

#include "StructCombined.h"

StructCombined::StructCombined ()
{
  czo = NULL;
  size = 0;
}

StructCombined::StructCombined (string x)
{
  czo = new Nodo_Struc (x);
  size = 1;
}

int StructCombined::get_NumRep ()
{
  return czo->get_rep ();
}

int StructCombined::get_size ()
{
  return size;
}

bool StructCombined::esvacia ()
{
  return czo == NULL;
}

string StructCombined::get_palabra ()
{
  return czo->get_pal ();
}

/**
 * AddPal metodo que agrega una palabra a la lista, comprueba el orden alfabetico
 * o si se encuentra repetida.
 * @param x palabra a agregar.
 */
void StructCombined::AddPal (string x)
{
  Nodo_Struc *nuevo = new Nodo_Struc (x);
  if (this->esvacia ())
    {
      czo = nuevo;
      size++;
    }
  else
    {
      Nodo_Struc *temp = czo;
      Nodo_Struc *temp_2 = czo;
      int b = this->get_size ();
      for (int i = 0; i < b; i++)
        {
          if ((czo->get_pal ().compare (x)) > 0)
            {
              if (temp_2 == czo)
                {
                  czo = nuevo;
                  nuevo->set_nextAlf (temp);

                }
              else
                {
                  temp_2->set_nextAlf (nuevo);
                  nuevo->set_nextAlf (temp);
                }
              size = size + 1;
              return;
            }
          else if ((temp->get_pal ().compare (x)) == 0)
            {
              temp->increment ();
              return;
            }
          else if (temp->get_nextAlf () == NULL)
            {
              temp->set_nextAlf (nuevo);
              size = size + 1;
              return;
            }
          else
            {
              temp_2 = temp;
              temp = temp->get_nextAlf ();
            }
        }
    }

}
/**
 * @TODO Crear metodo que llame a este con el puntero czo. Asi se puede implementar de forma recursiva.
 * @param x
 */
void StructCombined::Arbol_ABB (string x) //modificar.
{
  if (esvacia ())
    {
      Nodo_Struc *nuevo = new Nodo_Struc (x);
      czo = nuevo;
      czo->set_der (NULL);
      czo->set_izq (NULL);
    }
  else
    {

    }
}