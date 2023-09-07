#ifndef MEDICAO_H
#define MEDICAO_H

#include <string>
#include "Servico.hpp"
#include "UC.hpp"
#include "Cliente.hpp"
#include "Permissao.hpp"

class Medicao : public Servico
{

public:
  
	Medicao(int, Cliente*, int);
  void servicoFeito(float, Permissao, Usuario, Data);
  void servicoFeito(Permissao, Usuario, Data);

private:
  float _medicao;
};

#endif