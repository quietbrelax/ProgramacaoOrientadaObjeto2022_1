#include "Desligamento.hpp"
#include <iostream>
#include "Permissao.hpp"
#include "Erro.hpp"

Desligamento::Desligamento(bool tipo, int uc, Cliente* cliente, int tipoServico) : Servico(uc, cliente, tipoServico){
  this -> tipoDesligamento = tipo;

  //desligar por dívida e por pedido
  this -> _clienteBeneficiado = cliente;
  this -> _UC = _clienteBeneficiado -> getUC(uc);

}

void Desligamento::servicoFeito(Permissao permissao, Usuario user, Data data){
  try{
    if(!(permissao.conferePermissao("Eletricista")))
  {
    throw Erro(6);
  }
  else
  {
    this -> _UC -> desligaUC();
    this -> realizaServico();
  
    std::cout << std:: endl << "Unidade Consumidora desligada por ";
    if(this -> tipoDesligamento)
    {
      std::cout << "pedido do cliente. A UC foi apenas desligada, nao excluida completamente do registro." << std::endl;
    }
    else
    {
      std::cout << "multas. A UC foi apenas desligada, nao excluida completamente do registro." << std::endl;
    }
  }
  } catch(Erro _erro){
    _erro.out();
    if(_erro.what() == 6){
      geraLogErro(user, data, "Troca de Medidor", "Unidade Consumidora");
    }
  }
  
}
  

void Desligamento::servicoFeito(float leitura, Permissao permissao, Usuario user, Data data){
  try{
    throw Erro(9);
  }
  catch(Erro _erro){
    _erro.out();
  }
  
}