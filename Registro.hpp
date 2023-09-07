//lembra de colocar o construtor default aqui
#ifndef REGISTRO_H
#define REGISTRO_H

#include <list>
#include "Cliente.hpp"
#include "PessoaFisica.hpp"
#include "PessoaJuridica.hpp"
#include "Funcionario.hpp"
#include "Leiturista.hpp"
#include "Eletricista.hpp"
#include "Endereco.hpp"
#include "Permissao.hpp"
#include "Log.hpp"
#include "LogLeitura.hpp"
#include <string>



class Registro {
public:

	Registro(Funcionario);// Construtor

	//Metodos de cadastro
	bool validarCPF(std::string);
	bool validarCNPJ(std::string);
	LogEscrita cadastrarCliente(std::string, std::string, bool,         
  Endereco, std::string, std::string, Permissao, Usuario, Data);
  LogEscrita cadastrarFuncionario(std::string, std::string, 
  std::string, bool, Permissao, Usuario, Data);
	void geraLogErro(std::string, std::string, std::string, Data, std::string, std::string);
  std::list<LogErro> getListaErro();

	//Metodos de Listar
	
	LogLeitura listarInadimplentes(Usuario, Data);
	LogLeitura listarTiposUC(Usuario, Data);
  LogLeitura listarFuncionarios(Usuario, Data);
  LogLeitura listarClientes(Usuario, Data);
	
	//Metodos de acesso 
	PessoaFisica* clienteFisico(std::string);
	PessoaJuridica* clienteJuridico(std::string);
  Funcionario* funcionario(std::string);
  Leiturista* leiturista(std::string);
  Eletricista* eletricista(std::string);

	//Metodos de busca
	std::list<Log*> buscaLog(std::list<Log*>, std::string);
	std::list<Log*> buscaLog(std::list<Log*>, Data data, std::string = " ");

private:
	std::list<PessoaFisica> listaPessoaFisica; 
	std::list<PessoaFisica>::iterator it;

	std::list<PessoaJuridica> listaPessoaJuridica;
	std::list<PessoaJuridica>::iterator PJit;

  std::list<Leiturista> listaLeituristas;
  std::list<Leiturista>::iterator FLit;

  std::list<Eletricista> listaEletricistas;
  std::list<Eletricista>::iterator FEit;


  Funcionario _chefe;

	std::string listaTiposUC[4];

	std::list<LogErro> _listaErros;

};

#endif

