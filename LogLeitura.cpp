#include "Log.hpp"
#include "LogLeitura.hpp"
#include "Data.hpp"
#include <iostream>
#include <string.h>

LogLeitura::LogLeitura(std::string userName, std::string userEmail, Data data, std::string informacaoAcessada, std::string entidadeAcessada): Log(userName, userEmail, data, entidadeAcessada){

  this -> _entidadeAcessada = entidadeAcessada;
  this -> _informacaoAcessada = informacaoAcessada;

}

void LogLeitura::printLog()
{
    std::cout << "Log Leitura - USUARIO: " << this -> _userName << this -> _userEmail << " DATA: ";
    this -> _data.printData();
    std::cout << " ENTIDADE ACESSADA: " << this -> _entidadeAcessada << " INFORMACAO ACESSADA: "<< this -> _informacaoAcessada << std::endl;
}
