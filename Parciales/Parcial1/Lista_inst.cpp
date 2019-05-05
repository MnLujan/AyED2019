//
// Created by mlujan on 5/4/19.
//

#include "Lista_inst.h"

Lista_inst::Lista_inst (string a)
{
  czo = new Nodo_inst (a);
  size = 1;
}

/*
Lista_inst::Lista_inst (Nodo_inst *n)
{
  czo = new Nodo_inst();
}
 */

void Lista_inst::add (string d)
{
  Nodo_inst *nuevo = new Nodo_inst (d);
  nuevo->set_next (czo);
  czo = nuevo;
  size = size + 1;
}

bool Lista_inst::esvacia (void)
{
  return czo->es_vacio ();
}

string Lista_inst::cabeza (void)
{
  if (esvacia ())
    {
      cout << " Error, Cabeza de lista vacia";
    }
  else
    {
      return czo->get_dato ();
    }

}

/*
Lista_inst *Lista_inst::resto (void) //me devuelve el resto de la lista despues de la cabeza.
{
  Lista_inst *l = new Lista_inst (czo->get_next ()); //genera un puntero local, q crea una sub lista.
  return (l);
}

string Lista_inst::toPrint (string p)
{
  if (this->esvacia ())
    {
      return p;
    }
  else
    {
      std::ostringstream stm; //stm puede ser cualquier numero. En esta linea se define un buffer, sera util para mandarle info. Actua igual q un cout.
      stm << this->cabeza () << "-" << this->resto ()->toPrint (p);
      //cout<<endl<<" stm.str()= "<<stm.str()<<endl;
      return stm.str ();
    }
}
*/

int Lista_inst::get_size ()
{
  return size;
}

Nodo_inst *Lista_inst::get_nodo (int a)
{
  if (a > get_size ())
    {
      cout << "Error, instruccion inexistente" << endl;
      return NULL;
    }
  else
    {
      Nodo_inst *temp = czo;
      for (int i = 0; i < a; i++)
        {
          temp = temp->get_next ();
        }
      return temp;
    }
}