#ifndef LOGERRO_H
#define LOGERRO_H

#include "Log.hpp"
#include "Data.hpp"
#include <string.h>
#include <iostream>

class LogErro : public Log
{
  
public:
  LogErro(std::string, std::string, std::string, Data, std::string, std::string);
  void printLog();

private:
  std::string _funcionalidadeAcessada;
  std::string _entidadeAcessada;
  std::string _userPermissao;
};

#endif