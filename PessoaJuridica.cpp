#include "PessoaJuridica.hpp"
#include "Permissao.hpp"
#include "Erro.hpp"
#include "LogLeitura.hpp"
#include <string>
#include <iostream>

PessoaJuridica::PessoaJuridica(std::string nome, std::string cnpj, Endereco endereco, std::string telefone, std::string email) : Cliente(nome, endereco, telefone, email)
{
	this -> _cnpj = cnpj;
	this -> _nome = nome;
  this -> _endereco = endereco;
  this -> _telefone = telefone;
  this -> _email = email;
  
}

std::string PessoaJuridica::getCNPJ()
{
	return _cnpj;
}

LogEscrita PessoaJuridica::adicionarUC(int tipo, Endereco endereco, Permissao permissao, int nInst, Usuario user, Data data) 
{
  try{
    if(permissao.conferePermissao("Chefe"))
  {
    if(4 < tipo || tipo < 2) 
    {
      throw Erro(13);
    }

    std::list<std::string> atributosAntes;
    std::list<std::string> atributosDepois;

    std::string aux;

    aux = "Cliente " + this -> _nome + " com " + to_string(_UC.size()) + " Unidade(s) Consumidora(s) cadsatradas";
    atributosAntes.push_back(aux);

    UnidadeConsumidora novaUC(tipo, endereco, this -> _cnpj, _UC.size(), nInst);
    _UC.push_back(novaUC);
    std:: cout << std::endl << "Unidade Consumidora do tipo: " << tipo << " cadastrada com sucesso."<< std::endl;

    aux = "Cliente " + this -> _nome + " com " + to_string(_UC.size())+ " Unidade(s) Consumidora(s) cadsatradas";
    atributosDepois.push_back(aux);
    
    return LogEscrita(user.getNome(), user.getEmail(), data, "Adicionar Unidade Consumidora", atributosAntes, atributosDepois);

  }
  else
  {
    throw Erro(6);
  } 
  } catch(Erro _erro){
    _erro.out();
    if(_erro.what() == 6){
      geraLogErro(user.getNome(), user.getEmail(), user.getStringPermissao(), data, "Adicionar Unidade Consumidora", "Pessoa Juridica");
    }
    std::list<std::string> atributosAntes;
    std::list<std::string> atributosDepois;

    atributosAntes.push_back("NULL");
    atributosAntes.push_back("NULL");

    return LogEscrita(user.getNome(), user.getEmail(), data, "Adicionar Unidade Consumidora - ERRO", atributosAntes, atributosDepois);
  }
  
}

LogLeitura PessoaJuridica::listarUCS(Usuario usuario, Data data){
  std::cout << std::endl << this -> _nome << " Identificacao: " << this -> _cnpj << std::endl;
  for (std::list<UnidadeConsumidora>::iterator it = _UC.begin(); it != _UC.end(); it++)
	{
		it -> printUC();
	}
  return LogLeitura(usuario.getNome(), usuario.getEmail(), data, "Listar Unidades Consumidoras", "Pessoa Juridica");
}