#ifndef ELETRICISTA_H
#define ELETRICISTA_H

#include <string>
#include "Data.hpp"
#include "Cliente.hpp"
#include "Funcionario.hpp"
#include "Servico.hpp"
#include <list>
#include "Log.hpp"
#include "LogErro.hpp"
#include "LogLeitura.hpp"
#include "LogEscrita.hpp"

class Eletricista: public Funcionario
{

  public:
    Eletricista(std::string, std::string, int, std::string);

};

#endif