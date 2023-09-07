#include "Log.hpp"
#include "LogErro.hpp"
#include <iostream>
#include <string.h>

LogErro::LogErro(std::string userName, std::string userEmail, std::string userPermissao, Data data, std::string funcionalidadeAcessada, std::string entidadeAcessada): Log(userName, userEmail, data, entidadeAcessada){

  this -> _entidadeAcessada = entidadeAcessada;
  this -> _funcionalidadeAcessada = funcionalidadeAcessada;
  this -> _userPermissao = userPermissao;

}

void LogErro::printLog()
{
    std::cout << "Log Acesso Negado - USUARIO: " << this -> _userName << " EMAIL: " << this -> _userEmail << " PERMISSAO DO USUARIO: " << this -> _userPermissao;
    std::cout << " DATA: ";
    this -> _data.printData();
    std::cout << " ENTIDADE ACESSADA: " << this -> _entidadeAcessada << " FUNCIONALIDADE ACESSADA: "<< this -> _funcionalidadeAcessada << std::endl;
}
