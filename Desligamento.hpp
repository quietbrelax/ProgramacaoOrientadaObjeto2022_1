#ifndef DESLIGAMENTO_H
#define DESLIGAMENTO_H

#include "Servico.hpp"
#include "Cliente.hpp"
#include "UC.hpp"
#include "Permissao.hpp"
#include "Log.hpp"
#include "LogErro.hpp"
#include "LogLeitura.hpp"
#include "LogEscrita.hpp"

class Desligamento : public Servico
{

public:

  Desligamento(bool, int, Cliente*, int);
	void servicoFeito(Permissao, Usuario, Data);
  void servicoFeito(float, Permissao, Usuario, Data);

private:
  
  bool tipoDesligamento;

};

#endif