#include "Login.hpp"

Login *Login::login = nullptr;

Login::Login(Usuario* user){
  /*                   ^^
      Entra endereço de user

      e armazena na variavel instance do tipo Usuario*
  */
  this -> usuario = user;
};

Login* Login::getInstance(Usuario* user){

/*     
      Retorna instancia de usuario
  */
  if(login == nullptr)
  {
    login = new Login(user);
  }
  return login;
};

Usuario* Login::getUsuario(){

  return this->usuario;
};

void Login::atualizaUsuario(Usuario* user){
  this -> usuario = user;
}



