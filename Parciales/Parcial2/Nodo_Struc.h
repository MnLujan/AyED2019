//
// Created by mlujan on 6/7/19.
//

#ifndef _NODO_STRUC_H_
#define _NODO_STRUC_H_
#include "Palabra.h"

/**
 *@TODO Renombrar para ser mas especifico a que pertenece cada metodo y variable
 * @TODO Documentar las descripciones para estar al tanto para q se usaba cada cosa
 */
class Nodo_Struc {
 private:
  Palabra *obj;
  /** \brief  nodo de la iq del arbol*/
  Nodo_Struc *nextAlf;
  Nodo_Struc *nextRep;
  Nodo_Struc *der;
  Nodo_Struc *izq;
 public:
  Nodo_Struc ();
  Nodo_Struc (string);
  void set_nextAlf (Nodo_Struc *);
  void set_nextRep (Nodo_Struc *);
  Nodo_Struc *get_nextAlf ();
  Nodo_Struc *get_nextRep ();
  int get_rep ();
  string get_pal ();
  void set_pal (string);
  void increment ();
  void set_der (Nodo_Struc *);
  Nodo_Struc *get_der ();
  void set_izq (Nodo_Struc *);
  Nodo_Struc *get_izq ();

};

#endif //_NODO_STRUC_H_
