//
// Created by mlujan on 6/7/19.
//

#ifndef _PALABRA_H_
#define _PALABRA_H_
#include <string>
using namespace std;

/**
 * @brief Objeto utilizado para almacenar un dato de tipo String, y una variable entera que contendra la
 * cantidad de repeticiones de ese dato string
 */
class Palabra {
 private:
  string dato;
  unsigned int rep;

 public:
  Palabra();
  Palabra(string);
  string get_dato();
  int get_rep();
  void set_dato(string);
  void IncrementarNumRep();

};

#endif //_PALABRA_H_
