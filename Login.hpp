#ifndef LOGIN_H
#define LOGIN_H

#include "Usuario.hpp"

class Login
{
   public:
      static Login* getInstance(Usuario*);
      Usuario* getUsuario();
      void atualizaUsuario(Usuario*);
      
       ~Login( );
   private:
        Login(Usuario*);
        static Login* login;
        Usuario* usuario;
        
};

#endif