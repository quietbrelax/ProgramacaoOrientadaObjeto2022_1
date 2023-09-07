#include "Usuario.hpp"
#include "Permissao.hpp"
#include "Data.hpp"
#include "LogErro.hpp"
#include "Erro.hpp"
#include <string>

Usuario::Usuario(std::string nome, std::string email)
{
  this -> _nome = nome;
  this -> _email = email;

}

Usuario::Usuario()
{
  this -> _nome = "nome";
  this -> _email = "email";
}

std::string Usuario::getNome()
{
  return _nome;
}

std::string Usuario::getEmail()
{
  return _email;
}

Permissao Usuario::getPermissao()
{
  return _permissao;
}

std::string Usuario::getStringPermissao(){

  return _permissao.retornaPermissao();
  
}

void Usuario::geraLogErro(std::string userName, std::string userEmail, std::string userPermissao, Data data, std::string funcionalidadeAcessada, std::string entidadeAcessada){
  LogErro PN(userName, userEmail, userPermissao, data, funcionalidadeAcessada, entidadeAcessada);
  _listaErros.push_back(PN);
  
}

std::list<LogErro> Usuario::getListaErro(){
  return _listaErros;
}