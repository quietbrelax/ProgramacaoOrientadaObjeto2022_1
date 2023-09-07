#include "PessoaFisica.hpp"
#include "Permissao.hpp"
#include "Endereco.hpp"
#include "Erro.hpp"
#include "LogLeitura.hpp"
#include <string.h>
#include <iostream>

PessoaFisica::PessoaFisica(std::string nome, std::string cpf, Endereco endereco, std::string telefone, std::string email) : Cliente(nome, endereco, telefone, email)
{
	this -> _cpf = cpf;
	this -> _nome = nome;
  this -> _endereco = endereco;
  this -> _telefone = telefone;
  this -> _email = email;
  
}

std::string PessoaFisica::getCPF()
{
	return _cpf;
}

LogEscrita PessoaFisica::adicionarUC(int tipo, Endereco endereco, Permissao permissao, int nInst, Usuario user, Data data) 
{
 try{
if(permissao.conferePermissao("Chefe"))
  {
    if(2 < tipo || tipo < 1) 
    {
     throw Erro(13);
    }
    std::list<std::string> atributosAntes;
    std::list<std::string> atributosDepois;

    std::string aux;


    aux = "Cliente " + this -> _nome + " com "+ to_string(_UC.size()) +" Unidade(s) Consumidora(s) cadsatradas";
    atributosAntes.push_back(aux);

    UnidadeConsumidora novaUC(tipo, endereco, this -> _cpf, _UC.size(), nInst);
    _UC.push_back(novaUC);
    std:: cout << std::endl << "Unidade Consumidora do tipo: " << tipo << " cadastrada com sucesso."<< std::endl;

    aux = "Cliente " + this -> _nome + " com "+ to_string(_UC.size())+" Unidade(s) Consumidora(s) cadsatradas";
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
      geraLogErro(user.getNome(), user.getEmail(), user.getStringPermissao(), data, "Adicionar Unidade Consumidora", "Pessoa Fisica");
    }
    std::list<std::string> atributosAntes;
    std::list<std::string> atributosDepois;

    atributosAntes.push_back("NULL");
    atributosAntes.push_back("NULL");

    return LogEscrita(user.getNome(), user.getEmail(), data, "Adicionar Unidade Consumidora - ERRO", atributosAntes, atributosDepois);
  }
  
}

LogLeitura PessoaFisica::listarUCS(Usuario usuario, Data data){
  std::cout << std::endl << this -> _nome << " Identificacao: " << this -> _cpf << std::endl;
  for (std::list<UnidadeConsumidora>::iterator it = _UC.begin(); it != _UC.end(); it++)
	{
		it -> printUC();
	}
  return LogLeitura(usuario.getNome(), usuario.getEmail(), data, "Lista de Unidades Consumidoras", "Pessoa Fisica");

}