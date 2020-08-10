//
// Created by mlujan on 8/10/20.
//

#ifndef _LOGGER_H_
#define _LOGGER_H_
#include <fstream>
#include <iostream>

using namespace std;

class Logger {
 private:
  FILE *file;
 public:
  Logger();
  void write(string);
  void close_Log();
};

#endif //_LOGGER_H_
