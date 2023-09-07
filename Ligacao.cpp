#include "Ligacao.hpp"
#include "UC.hpp"
#include "Cliente.hpp"
#include "Permissao.hpp"
#include "Erro.hpp"
#include <iostream>

Ligacao::Ligacao(bool tipo, int uc, Cliente* cliente, int tipoServico) : Servico(uc, cliente, tipoServico){
  
  this -> tipoLigacao = tipo;
  this -> _clienteBeneficiado = cliente;
  this -> _UC = _clienteBeneficiado -> getUC(uc);
  this -> _tipo = tipoServico;

}

void Ligacao::servicoFeito(Permissao permissao, std::string nivelTensao, int tensao, Usuario user, Data data)
{
  try {
if(permissao.conferePermissao("Eletricista"))
  {
    this -> _UC -> ligaUC(nivelTensao, tensao);
    this -> realizaServico();
  
    std::cout << std:: endl << "Unidade Consumidora ligada por ";
    if(this -> tipoLigacao)
    {
      std::cout << "novo cadastro. Unidade habilitada para o uso." << std::endl;
    }
  
    else
    {
      std::cout << "pagamento devido de multas. Unidade habilitada para o uso." << std::endl;
    }
    
  }
  else
  {
    throw Erro(6);
  }  
  } catch(Erro _erro){
    _erro.out();
    if(_erro.what() == 6){
      geraLogErro(user, data, "Troca de Medidor", "Unidade Consumidora");
    }
  }
  
}

void Ligacao::servicoFeito(float leitura, Permissao permissao, Usuario user, Data data){
  try{
    throw Erro(9);
  } catch(Erro _erro){
    _erro.out();
  }
  
}

void Ligacao::servicoFeito(Permissao permissao, Usuario user, Data data){
  try{
    throw Erro(10);
  } catch(Erro _erro){
    _erro.out();
  }
  
}