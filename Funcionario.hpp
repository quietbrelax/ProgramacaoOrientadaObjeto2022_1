#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <string>
#include <list>
#include "Servico.hpp"
#include "UC.hpp"
#include "PessoaFisica.hpp"
#include "PessoaJuridica.hpp"
#include "Data.hpp"
#include "Permissao.hpp"
#include "Log.hpp"
#include "LogErro.hpp"
#include "LogLeitura.hpp"
#include "LogEscrita.hpp"

class Funcionario : public Usuario 
{
public:
	Funcionario(std:: string, std::string, int, std::string); // Construtor
  Funcionario();
	virtual LogEscrita registraServico(Servico*, Permissao, Data, Usuario, Data);
	LogLeitura imprimeServicoFeito(Usuario, Data);
  LogEscrita realizaServico(int, Permissao, Data, Usuario, Data, std::string = " ", int = 0);
  int getId();
  std::string getNome();
  std::string getcpf();
  LogEscrita limpaFila(Usuario, Data);
  LogLeitura printFila(Usuario, Data);
  LogLeitura printServicosFeitos(Usuario, Data);
  LogEscrita tiraServicoFila(int, Permissao, Usuario, Data);
  bool confereTensao(std:: string, int);


protected:
		int IDFuncionario;
    std::string _cpf;

    std::list<Servico*> _filaServicos;
    std::list<Servico*>:: iterator FSit;
    std::list<Servico*> _servicosFeitos;
};

#endif