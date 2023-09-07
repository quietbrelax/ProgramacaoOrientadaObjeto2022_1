#include "Permissao.hpp"

Permissao::Permissao(std::string tipo){
  this->_tipoUsuario = tipo;
}

Permissao::Permissao(){
  this -> _tipoUsuario = "Padrao";
}

std::string Permissao::retornaPermissao(){
  return this -> _tipoUsuario;
}

bool Permissao::conferePermissao(std::string permissao){
  
  if(this -> _tipoUsuario == permissao){
    return true;
  }

  return false;
}

