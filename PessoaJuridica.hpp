#ifndef PESSOAJURIDICA_H
#define PESSOAJURIDICA_H

#include "Cliente.hpp"
#include "Endereco.hpp"
#include "LogLeitura.hpp"
#include <string>

class PessoaJuridica : public Cliente
{
public:
	PessoaJuridica(std::string, std::string, Endereco, std::string, std::string);// Construtor
	LogEscrita adicionarUC(int, Endereco, Permissao, int, Usuario, Data);
	std::string getCNPJ();
  LogLeitura listarUCS(Usuario, Data);

private:
		std::string _cnpj;
};

#endif