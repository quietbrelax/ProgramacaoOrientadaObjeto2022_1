#ifndef LOGLEITURA_H
#define LOGLEITURA_H

#include "Log.hpp"
#include "Data.hpp"
#include <string.h>
#include <iostream>

class LogLeitura: public Log
{
  
public:
  LogLeitura(std::string, std::string, Data, std::string, std::string);
  void printLog();

private:
  std::string _informacaoAcessada;
  std::string _entidadeAcessada;
};

#endif