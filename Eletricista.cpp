#include "Eletricista.hpp"
#include "Servico.hpp"
#include "Desligamento.hpp"
#include "TMedidor.hpp"
#include "Ligacao.hpp"
#include "Funcionario.hpp"
#include "Permissao.hpp"
#include "Erro.hpp"
#include <iostream>
#include <list>

Eletricista::Eletricista(std::string nome, std::string cpf, int id, std::string email): Funcionario(nome, cpf, id, email)
{
  this -> _nome = nome;
  this -> _cpf = cpf;
  this -> IDFuncionario = id;
  this -> _email = email;
  Permissao permAux("Eletricista");
  this -> _permissao = permAux;
}