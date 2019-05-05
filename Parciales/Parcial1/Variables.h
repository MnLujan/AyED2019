//
// Created by mlujan on 5/5/19.
//

#ifndef _VARIABLES_H_
#define _VARIABLES_H_

/**
 * Clase Variables, utilizada para el almacenamiento de dos parametros en cada un de los objetos que se crea.
 */
class Variables {

 private:
  char nombre;
  int valor;

 public:

  Variables ();
  Variables (char n, int v);
  void set_name (char);
  char get_name ();
  void set_val (int);
  int get_val ();
  bool esnulo();
};

#endif //_VARIABLES_H_
