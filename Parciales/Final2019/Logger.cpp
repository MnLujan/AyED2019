//
// Created by mlujan on 8/10/20.
//

#include "Logger.h"

/**
 * Constructor de la clase, crea el archivo LOG.
 */
Logger::Logger ()
{
  this->file = fopen ("Log.txt", "w+");
}

/**
 * @brief Metodo encargado de escribir en el Log.
 * @param msj recive como parametro el msj en string con el formato deseado
 */
void Logger::write (string msj)
{

  fwrite (msj.c_str (), sizeof (char), msj.size (), file);

}

/**
 * @brief Metodo encargado de cerrar el archivo una vez finalizada la ejecucion del programa.
 */
void Logger::close_Log ()
{
  fclose (file);
}