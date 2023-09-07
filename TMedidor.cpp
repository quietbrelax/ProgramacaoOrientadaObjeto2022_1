#include "TMedidor.hpp"
#include "Erro.hpp"
#include <string>
#include <iostream>

TMedidor::TMedidor(int uc, Cliente* cliente, int tipoServico) : Servico(uc, cliente, tipoServico){

  //desligar por dívida e por pedido

  this -> _clienteBeneficiado = cliente;
  this -> _UC = _clienteBeneficiado -> getUC(uc);

}

void TMedidor::servicoFeito(Permissao permissao, Usuario usuario, Data data)
{
  try{
    if(!(permissao.conferePermissao("Eletricista")))
  {
    throw Erro(6);
  }
  else
  {
    this -> realizaServico();
    this -> _UC -> resetaUltimoConsumo();
  
    std::cout << std::endl << "Medidor Trocado com sucesso" << std::endl;
  }
  } catch(Erro _erro){
    _erro.out();
    if(_erro.what() == 6){
      geraLogErro(usuario, data, "Troca de Medidor", "Unidade Consumidora");
    }
  }

}


void TMedidor::servicoFeito(float leitura, Permissao permissao, Usuario user, Data data){
  try{
    throw Erro(9);
  } catch(Erro _erro){
    _erro.out();
  }
  
}