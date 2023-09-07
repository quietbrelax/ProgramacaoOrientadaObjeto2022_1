#ifndef PERMISSAO_H
#define PERMISSAO_H

#include <string>

class Permissao
{

  public:
    Permissao(std::string); //construtor
    Permissao();
    std::string retornaPermissao();
    bool conferePermissao(std::string);
  
  private:
    std::string _tipoUsuario;

};

#endif