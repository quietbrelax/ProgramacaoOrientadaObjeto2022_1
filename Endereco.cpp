#include "LG.hpp"
#include "Endereco.hpp"
#include <string>
#include <iostream>

Endereco::Endereco():LocalizacaoGeografica(){}

void Endereco :: setEndereco(std::string logradouro, std::string numero, std::string bairro, std::string complemento, std::string cep, std::string cidade, std::string estado)
{
  this-> _logradouro = logradouro;
  this-> _numero = numero;
  this-> _bairro = bairro;
  this-> _complemento = complemento;
  this-> _cep = cep;
  this-> _cidade = cidade;
  this-> _estado = estado;
}

void Endereco :: printEndereco()
{
  std::cout << "\nLocalizado em: " << _logradouro << ", " << _numero << ".\n" << _bairro << ", " << _cidade << ", " << _estado << std::endl;
}