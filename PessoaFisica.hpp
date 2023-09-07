#ifndef PESSOAFISICA_H
#define PESSOAFISICA_H

#include "Cliente.hpp"
#include "Endereco.hpp"
#include "Permissao.hpp"
#include "LogLeitura.hpp"
#include <string>

class PessoaFisica : public Cliente
{
public:
	PessoaFisica(std::string, std::string, Endereco, std::string, std::string);// Construtor
	LogEscrita adicionarUC(int, Endereco, Permissao, int, Usuario, Data);
	LogLeitura listarUCS(Usuario, Data);
	std::string getCPF();

private:
		std::string _cpf;
};

#endif