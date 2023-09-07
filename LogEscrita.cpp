#include "Log.hpp"
#include "LogEscrita.hpp"
#include <iostream>
#include <list>
#include <string.h>

LogEscrita::LogEscrita(std::string userName, std::string userEmail, Data data, std::string entidadeAcessada, std::list<std::string> antes, std::list<std::string> depois): Log(userName, userEmail, data, entidadeAcessada){

  this -> _entidadeAcessada = entidadeAcessada;

  for (std::list<std::string>::iterator it = antes.begin(); it != antes.end(); it++)
  {
    atributoAntes.push_back(*it);
  }

  for (std::list<std::string>::iterator it = depois.begin(); it != depois.end(); it++)
  {
    atributoDepois.push_back(*it);
  }
}

void LogEscrita::printLog()
{
    std::cout << "Log Escrita - USUARIO: " << this -> _userName << " EMAIL: " << this -> _userEmail << " DATA: ";
    this -> _data.printData();
    std::cout << " ENTIDADE ALTERADA: " << this -> _entidadeAcessada <<       
    " INFORMACAO(OES) ANTERIORES: " << std:: endl;
    for (std::list<std::string>::iterator it = atributoAntes.begin(); it != atributoAntes.end(); it++)
  {
    std::cout << "\t"<< (*it) << std::endl;
  }
      
  std::cout << "INFORMACAO(OES) ALTERADA(S): " << std::endl;
  for (std::list<std::string>::iterator it = atributoDepois.begin(); it != atributoDepois.end(); it++)
  {
    std::cout << "\t"<< *it << std::endl;
  }
  
  
}
