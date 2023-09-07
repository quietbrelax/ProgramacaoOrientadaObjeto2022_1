#ifndef LIGACAO_H
#define LIGACAO_H

#include "Servico.hpp"
#include "Cliente.hpp"
#include "UC.hpp"
#include "Permissao.hpp"

class Ligacao : public Servico
{

public:
  Ligacao(bool, int, Cliente*, int);
	void servicoFeito(Permissao, Usuario, Data);
  void servicoFeito(float, Permissao, Usuario, Data);
  void servicoFeito(Permissao, std::string, int, Usuario, Data);

private:
  bool tipoLigacao;

};

#endif