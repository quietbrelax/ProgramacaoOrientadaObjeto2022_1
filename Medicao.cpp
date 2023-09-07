#include "Medicao.hpp"
#include <string>
#include <iostream>
#include "Registro.hpp"
#include "Permissao.hpp"
#include "Erro.hpp"

Medicao::Medicao(int uc, Cliente* cliente, int tipoServico) : Servico(uc, cliente, tipoServico){

  //desligar por dívida e por pedido
  this -> _clienteBeneficiado = cliente;
  this -> _UC = _clienteBeneficiado -> getUC(uc);

}

void Medicao::servicoFeito(float leitura, Permissao permissao, Usuario user, Data data)
{
  try{
if(!(permissao.conferePermissao("Leiturista")))
  {
    throw Erro(6);
  }
  else
  {
    this -> _medicao = leitura;
    this -> _UC -> novaLeitura(this->_medicao);
    this -> _clienteBeneficiado -> geraFatura(this -> _UC -> getID(), permissao, user, data);
    this -> realizaServico();
    std::cout << std::endl << "Leitura registrada com sucesso" << std::endl;
  }
  } catch(Erro _erro){
    _erro.out();
    if(_erro.what() == 6){
      geraLogErro(user, data, "Troca de Medidor", "Unidade Consumidora");
    }
  }
  
}

void Medicao::servicoFeito(Permissao permissao, Usuario user, Data data){
  try{
    throw Erro(10);
  } catch(Erro _erro){
    _erro.out();
  }
  
}