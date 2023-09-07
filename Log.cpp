#include "Log.hpp"
#include <iostream>
#include <string.h>

Log::Log(std::string userName, std::string userEmail, Data data, std::string entidadeAcessada){

  this -> _userName = userName;
  this -> _userEmail = userEmail;
  this -> _data = data;
  this -> _entidadeAcessada = entidadeAcessada;

}

Data Log:: getData(){
  return this -> _data;
}

std::string Log:: getUsuario(){
  return this -> _userName;
}
