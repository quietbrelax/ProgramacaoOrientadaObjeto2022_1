#include "Registro.hpp"
#include "PessoaFisica.hpp"
#include "PessoaJuridica.hpp"
#include "Cliente.hpp"
#include "Funcionario.hpp"
#include "Leiturista.hpp"
#include "Eletricista.hpp"
#include "Permissao.hpp"
#include "Erro.hpp"
#include "LogLeitura.hpp"
#include <iostream>



Registro ::Registro(Funcionario chefe)
{
	std::string tiposUCS[4] = {"Residencial", "Comercial", "Industrial", "Iluminacao Publica"};
	for (int i = 0; i < 4; i++)
	{
		listaTiposUC[i] = tiposUCS[i];
	}
	this -> _chefe = chefe;
  
}

LogEscrita Registro::cadastrarCliente(std::string nome, std::string id, bool tipo, Endereco endereco, std::string telefone, std:: string email, Permissao permissao, Usuario user, Data data)
{
	try{
if(permissao.conferePermissao("Chefe"))
  {
    int valido = 0;
		std::list<std::string> atributosAntes;
    std::list<std::string> atributosDepois;

    std::string aux;
   
      if(tipo)
    	{
        valido = validarCPF(id);
    		if(valido)
        {
					aux = "Novo espaco para Cliente Fisico vazio";
    			atributosAntes.push_back(aux);

          listaPessoaFisica.push_back(PessoaFisica(nome, id, endereco, telefone, email));
    		  std::cout << "Cliente '" << nome 	<< "' cadastrado com sucesso." << std::endl;

					aux = "Novo espaco para Cliente fisico ocupado por: " + nome;
    			atributosDepois.push_back(aux);

					return LogEscrita(user.getNome(), user.getEmail(), data, "Cadastrar Cliente - Registro ", atributosAntes, atributosDepois);
        }
    		else
        {
          throw Erro(4);
        }
    	}
      else
    	{
    		valido = validarCNPJ(id);
        if (valido)
        {
					aux = "Novo Espaco para Cliente Juridico vazio";
    			atributosAntes.push_back(aux);

          listaPessoaJuridica.push_back(PessoaJuridica(nome, id, endereco, telefone, email));
    		  std::cout << "Cliente '" << nome << "' cadastrado com sucesso." << std::endl;
					
					aux = "Novo espaco para Cliente Juridico ocupado por: " + nome;
    			atributosDepois.push_back(aux);

					return LogEscrita(user.getNome(), user.getEmail(), data, "Cadastrar Cliente - Registro ", atributosAntes, atributosDepois);
        }
        else
        {
          throw Erro(4);
        }
    	}
    }
  
	else
  {
    throw Erro(6);
  }
	} catch(Erro _erro){
    _erro.out();
		if(_erro.what() == 6){
      geraLogErro(user.getNome(), user.getEmail(), user.getStringPermissao(), data, "Cadastrar cliente", "Registro");
    }
		std::list<std::string> atributosAntes;
    std::list<std::string> atributosDepois;

    atributosAntes.push_back("NULL");
    atributosDepois.push_back("NULL");

    return LogEscrita(user.getNome(), user.getEmail(), data, "Cadastrar Cliente - ERRO ", atributosAntes, atributosDepois);
  }
  
}

bool Registro::validarCPF(std::string cpf)
{
	int CPF[11];
	char cpf_char[11];

	for (char i = 0; i < cpf.size(); i++)
	{
		cpf_char[i] = cpf[i];
	}
	for (char i = 0; i < cpf.size(); i++)
	{
		CPF[i] = static_cast<int>(cpf_char[i] - 48); // converte string para int
	}

	int soma1 = 0, soma2 = 0;
	int resto1 = 0, resto2 = 0;

	// Parte 1 validação, primeiro dígito

	for (int i = 0; i < cpf.size() - 2; i++)
	{
		soma1 += CPF[i] * (10 - i);
	}
	soma1 = soma1 * 10;
	resto1 = soma1 % 11;
	if (resto1 == 10)
	{
		resto1 = 0;
	}

	// Parte 2 validação, segundo dígito
	for (int i = 0; i < cpf.size() - 1; i++)
	{
		soma2 += CPF[i] * (11 - i);
	}
	soma2 = soma2 * 10;
	resto2 = soma2 % 11;

	if (resto2 == 10)
	{
		resto2 = 0;
	}
	if (resto1 == CPF[9] && resto2 == CPF[10])
	{
		// cpf valido
		return 1;
	}
	else
	{
		// cpf invalido
    return 0;
	}
}

bool Registro::validarCNPJ(std::string cnpj)
{
	int soma1 = 0, soma2 = 0, resto1 = 0, resto2 = 0;
	int CNPJ[14];
	int multiplicadores[13] = { 6,5,4,3,2,9,8,7,6,5,4,3,2 };

	for (char i = 0; i < 14; i++)
	{
		CNPJ[i] = static_cast<int>(cnpj[i] - 48); // converte string para int
	}

	//Primeiro digito verificador

	for (int i = 0; i < 12; i++)
	{
		soma1 += CNPJ[i] * multiplicadores[i + 1];
	}
	resto1 = soma1 % 11;

	if (resto1 < 2)
	{
		resto1 = 0;
	}
	else {
		resto1 = 11 - resto1;
	}
	//Segundo digito verificador
	for (int i = 0; i < 13; i++)
	{
		soma2 += CNPJ[i] * multiplicadores[i];
	}
	resto2 = soma2 % 11;
	if (resto2 < 2)
	{
		resto2 = 0;
	}
	else {
		resto2 = 11 - resto2;
	}
	if (resto1 == CNPJ[12]&& resto2 == CNPJ[13])
	{
		// cnpj válido
		return 1;
	}
	else
	{
		// cnpj inválido
    return 0;
	}
}

LogLeitura Registro::listarClientes(Usuario usuario, Data data)
{
	try
  {
  	std::cout << std::endl << "\tClientes Fisicos:" << std::endl;
  	for (it = listaPessoaFisica.begin(); it != listaPessoaFisica.end(); it++)
  	{
  		std::string nome = it->getNome();
  		std::string cpf = it->getCPF();
  		std::cout << "\t" << cpf << "\t" << nome << std::endl;
  	}
  
  	std::cout << std::endl << "\tClientes Juridicos:" << std::endl;
  	for (PJit = listaPessoaJuridica.begin(); PJit != listaPessoaJuridica.end(); PJit++)
  	{
  		std::string nome = PJit->getNome();
  		std::string cnpj = PJit->getCNPJ();
  		std::cout << "\t" << cnpj << "\t" << nome << std::endl;
  	}
    return LogLeitura(usuario.getNome(), usuario.getEmail(), data, "Lista de clientes", "Registro");

	} catch(Erro _erro){
    _erro.out();
  }
	
}

LogLeitura Registro::listarInadimplentes(Usuario usuario, Data data)
{
	std::cout << "\n\tClientes Fisicos Inadimplentes:";
	for (it = listaPessoaFisica.begin(); it != listaPessoaFisica.end(); it++)
	{
		if(it-> getSituacao()){
			std::string nome = it->getNome();
		std::string cpf = it->getCPF();
		std::cout << std::endl
							<< "\t" << cpf << "\t" << nome;
		}
	}

	std::cout << std::endl << "\tClientes Juridicos Inadimplentes:";
	for (PJit = listaPessoaJuridica.begin(); PJit != listaPessoaJuridica.end(); PJit++)
	{
		if(PJit-> getSituacao()){
			std::string nome = PJit->getNome();
		std::string cnpj = PJit->getCNPJ();
		std::cout << std::endl
							<< "\t" << nome << "\t" << cnpj;
		}
		
	}
	std::cout << std::endl;
  return LogLeitura(usuario.getNome(), usuario.getEmail(), data, "Lista de clientes inadimplentes", "Registro");
}

PessoaFisica* Registro::clienteFisico(std::string cpf){
	try{
		for (it = listaPessoaFisica.begin(); it != listaPessoaFisica.end(); it++)
	{
		if(it -> getCPF() == cpf){
				return &(*it);
		}
	}
	throw Erro(0); 
	} catch(Erro _erro){
    _erro.out();
  }
	
}
PessoaJuridica* Registro::clienteJuridico(std::string cnpj){
	try{
		for (PJit = listaPessoaJuridica.begin(); PJit != listaPessoaJuridica.end(); PJit++)
	{
		if(PJit -> getCNPJ() == cnpj){
				return &(*PJit);
		}
	}
	throw Erro(0);
	} catch(Erro _erro){
    _erro.out();
  }
	
}

LogLeitura Registro::listarTiposUC(Usuario usuario, Data data)
{
	std::cout << std::endl;
	for (int i = 0; i < 4; i++)
	{
		std::cout << i + 1 << " - " << listaTiposUC[i] << std::endl;
	}
  return LogLeitura(usuario.getNome(), usuario.getEmail(), data, "Lista de tipos de Unidades Consumidoras", "Registro");
}

LogEscrita Registro::cadastrarFuncionario(std::string nome, std::string cpf, std::string email, bool tipo, Permissao permissao, Usuario user, Data data)
{
try{
if(permissao.conferePermissao("Chefe"))
  {  
		std::list<std::string> atributosAntes;
    std::list<std::string> atributosDepois;

    std::string aux;

  	int valido = 0;
    valido = validarCPF(cpf);
    if (valido)
    {
      if(!(tipo))
      {

				aux = "Novo Espaco para Funcionario Eletricista vazio";
    		atributosAntes.push_back(aux);
				
        Eletricista novoFuncionario(nome, cpf, listaEletricistas.size(), email);
        listaEletricistas.push_back(novoFuncionario);
        std::cout << std::endl << "Eletricista '" << nome 
            << "' cadastrado com sucesso." << std::endl;

				aux = "Novo espaco para Funcionario Eletricista ocupado por: " + nome;
    		atributosDepois.push_back(aux);

				return LogEscrita(user.getNome(), user.getEmail(), data, "Cadastrar funcionario", atributosAntes, atributosDepois);
      }
      else
      {

				aux = "Novo Espaco para Funcionario Leiturista vazio";
    		atributosAntes.push_back(aux);

        Leiturista novoFuncionario(nome, cpf, listaLeituristas.size(), email);
        listaLeituristas.push_back(novoFuncionario);
        std::cout << std::endl << "Leiturista '" << nome 
            << "' cadastrado com sucesso." << std::endl;

				aux = "Novo espaco para Funcionario Leiturista ocupado por: " + nome;
    		atributosDepois.push_back(aux);

				return LogEscrita(user.getNome(), user.getEmail(), data, "Cadastrar funcionario", atributosAntes, atributosDepois);
      }
    }
    else
    {
      throw Erro(4);
    }
    
  }
  else
  {
    throw Erro(6);
  }
} catch(Erro _erro){
    _erro.out();
		if(_erro.what() == 6){
      geraLogErro(user.getNome(), user.getEmail(), user.getStringPermissao(), data, "Cadastrar Funcionario", "Registro");
    }
		std::list<std::string> atributosAntes;
    std::list<std::string> atributosDepois;

    atributosAntes.push_back("NULL");
    atributosDepois.push_back("NULL");

    return LogEscrita(user.getNome(), user.getEmail(), data, "Cadastrar Funcionario - ERRO ", atributosAntes, atributosDepois);
  }
  
}

Funcionario* Registro::funcionario(std::string cpf)
{
	return &(this -> _chefe); 
}

Eletricista* Registro::eletricista(std::string cpf)
{
	try{
	for (FEit = listaEletricistas.begin(); FEit != listaEletricistas.end(); FEit++)
	{
		if(FEit -> getcpf() == cpf){
				return &(*FEit);
		}
	}
	throw Erro(2);
	return nullptr;
	} catch(Erro _erro){
    _erro.out();
  }
	
}

Leiturista* Registro::leiturista(std::string cpf)
{
	try{
for (FLit = listaLeituristas.begin(); FLit != listaLeituristas.end(); FLit++)
	{
		if(FLit -> getcpf() == cpf){
				return &(*FLit);
		}
	}
	throw Erro(2);
	return nullptr;
	} catch(Erro _erro){
    _erro.out();
  }
	
}


LogLeitura Registro::listarFuncionarios(Usuario usuario, Data data)
{
	std::cout << std::endl << "\tChefe:" << "\t" << _chefe.getcpf() << "\t" << _chefe.getNome() << std::endl << "\tEletricistas:";
	for (FEit = listaEletricistas.begin(); FEit != listaEletricistas.end(); FEit++)
	{
		std::string nome = FEit -> getNome();
		std::string cpf = FEit -> getcpf();
    int id = FEit-> getId();
		std::cout << "\t" << cpf << "\t" << nome << "\t" << id << std::endl;
	}
  std::cout << std::endl << "\tLeituristas:";;
  for (FLit = listaLeituristas.begin(); FLit != listaLeituristas.end(); FLit++)
	{
		std::string nome = FLit -> getNome();
		std::string cpf = FLit -> getcpf();
    int id = FLit -> getId();
		std::cout << "\t" << cpf << "\t" << nome << "\t" << id << std::endl;
	}
  return LogLeitura(usuario.getNome(), usuario.getEmail(), data, "Lista Funcionarios", "Registro");
}

std::list<Log*>  Registro::buscaLog(std::list<Log*> listaBusca, std::string usuario){
  std::list<Log*> retornoLogs;
  for (std::list<Log*>::iterator it = listaBusca.begin(); it != listaBusca.end(); it++)
	{
		if((*it) ->getUsuario() == usuario){
			retornoLogs.push_back(*it);
		}
	}
  return retornoLogs;
}

std::list<Log*> Registro::buscaLog(std::list<Log*> listaBusca, Data data, std::string usuario){
  std::list<Log*> retornoLogs;
  if(usuario == " "){
     for (std::list<Log*>::iterator it = listaBusca.begin(); it != listaBusca.end(); it++)
	  {
		  if((*it) -> getData() == data){
			  retornoLogs.push_back(*it);
		  }
	  }
  }

  else {
    for (std::list<Log*>::iterator it = listaBusca.begin(); it != listaBusca.end(); it++)
	  {
		  if((*it) -> getData() == data && (*it) -> getUsuario() == usuario){
			  retornoLogs.push_back(*it);
		  }
	  }
  }
 
  return retornoLogs;
}

void Registro::geraLogErro(std::string userName, std::string userEmail, std::string userPermissao, Data data, std::string funcionalidadeAcessada, std::string entidadeAcessada){
  LogErro PN(userName, userEmail, userPermissao, data, funcionalidadeAcessada, entidadeAcessada);
  _listaErros.push_back(PN);
  
}

std::list<LogErro> Registro::getListaErro(){
  return _listaErros;
}