#ifndef LOGESCRITA_H
#define LOGESCRITA_H

#include "Log.hpp"
#include "Data.hpp"
#include <string.h>
#include <iostream>
#include <list>

class LogEscrita: public Log
{
  
public:
  LogEscrita(std::string, std::string, Data, std::string, std::list<std::string>, std::list<std::string>);
  void printLog();

private:
  std::string _entidadeAcessada;
  std::list<std::string> atributoAntes;
  std::list<std::string> atributoDepois;

};

#endif