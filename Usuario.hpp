#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include "Permissao.hpp"
#include "LogErro.hpp"
#include <list>

class Usuario
{
  public:
    Usuario(std::string, std::string);
    Usuario();
    std::string getNome();
    std::string getEmail();
    Permissao getPermissao();
    std::string getStringPermissao();
    void geraLogErro(std::string, std::string, std::string, Data, std::string, std::string);
    std::list<LogErro> getListaErro();

  protected:
    std::string _nome;
    std::string _email;  
    Permissao _permissao;
    std::list<LogErro> _listaErros;
};

#endif