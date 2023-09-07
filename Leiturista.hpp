#ifndef LEITURISTA_H
#define LEITURISTA_H

#include "Data.hpp"
#include "Cliente.hpp"
#include "Funcionario.hpp"
#include "Medicao.hpp"
#include "Permissao.hpp"
#include <list>

class Leiturista: public Funcionario
{

public:
Leiturista(std::string, std::string, int, std::string);
LogEscrita realizaServico(int, float, Permissao, Data, Usuario, Data);
LogEscrita registraServico(Servico*, Permissao, Data, Usuario, Data);

private:

};

#endif