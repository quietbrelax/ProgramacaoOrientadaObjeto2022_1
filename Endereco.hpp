#ifndef ENDERECO_H
#define ENDERECO_H

#include "LG.hpp"
#include <string>

class Endereco : public LocalizacaoGeografica
{
  public:

    //Endereco (float, float);
    void printEndereco();
    void setEndereco(std::string, std::string, std::string, std::string, std::string, std::string, std::string);
   Endereco();
  private:

    std::string _logradouro;
    std::string _numero;
    std::string _bairro;
    std::string _complemento;
    std::string _cep;
    std::string _cidade;
    std::string _estado;
  

};

#endif