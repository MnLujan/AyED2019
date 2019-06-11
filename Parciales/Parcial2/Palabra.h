//
// Created by mlujan on 6/7/19.
//

#ifndef _PALABRA_H_
#define _PALABRA_H_
#include <string>
using namespace std;

class Palabra {
 private:
  string dato;
  int rep;
 public:
  Palabra();
  Palabra(string);
  string get_dato();
  int get_rep();
  void set_dato(string);
  void set_rep();
  void incrementar();

};

#endif //_PALABRA_H_
