
#include "Servico.hpp"
#include "PessoaFisica.hpp"
#include "PessoaJuridica.hpp"
#include "UC.hpp"
#include <iostream>
#include <string>
#include "Data.hpp"
#include "Erro.hpp"
#include "Permissao.hpp"
#include "LogLeitura.hpp"
#include "LogErro.hpp"

Servico::Servico(int uc, Cliente* cliente, int tipo)
{

  this->_tipo = tipo;
  
  this -> _sequencia = 0;
  this -> _clienteBeneficiado = cliente;
  this -> _UC = _clienteBeneficiado -> getUC(uc);
  this -> _servicoFeito = 0;

  std::string tiposServicos[6] = {"0 - Medicao", "1 - Troca do medidor", "2 - Desligamento por encerramento", 
  "3 - Desligamento por inadimplencia", "4 - Nova ligacao", "5 - Religacao"};
  for (int i = 0; i < 6; i++)
	{
		this ->listaTiposServicos[i] = tiposServicos[i];
	}

}

int Servico::getId()
{
  return _sequencia;
}
int Servico::getTipo()
{
  return _tipo;
}

void Servico::defineDataHoraExecucao(Data data){
  //this -> _Data = _Data.dateNow();
  //this -> _data = _Data.getData();
  try{
  if(data > this ->_planejamento || data == this -> _planejamento){
    this -> _Data = data;
    this -> _data = _Data.getData();
  }
  else{
    throw Erro(15);
  }
  } catch(Erro _erro){
    _erro.out();
  }
  
  
}

void Servico::realizaServico()
{
  this -> _servicoFeito = 1;
}

LogLeitura Servico::listarTiposServico(Usuario usuario, Data data)
{
  std::cout <<std::endl<<"\t----------Tipos de Servico----------" << std::endl;
  for (int i = 0; i<6; i++)
  {
    std::cout<<std::endl<<"\t"<<listaTiposServicos[i];
  }
  return LogLeitura(usuario.getNome(), usuario.getEmail(), data, "Lista de tipos de servicos", "Servicos");
}

 void Servico::listaTipoServico(int i)
 {
   std::cout<<listaTiposServicos[i];
 }


//virtual void Servico::servicoFeito(Permissao permissao); //const = 0; 

//virtual void Servico::servicoFeito(float leitura, Permissao permissao); //const = 0;

void Servico::printDataHora()
{
  std::cout<< _data;
}

void Servico::printUC()
{
  this -> _UC ->printUC();
}

bool Servico::getStatus()
{
  return _servicoFeito;
}

void Servico::colocaSequencia(int sequencia){
  this -> _sequencia = sequencia;
}

void Servico::dataPlanejada(Data planejada){
  try{
   Data dataAux = this -> _planejamento.dateNow();
  if(planejada > dataAux || planejada == dataAux){
    this -> _planejamento = planejada;
  }
  else{
    throw Erro(15);
  }
  } catch(Erro _erro){
      _erro.out();
    }
   
    
}

void Servico::geraLogErro(Usuario user, Data data, std::string funcionalidadeAcessada, std::string entidadeAcessada){
  LogErro PN(user.getNome(), user.getEmail(), user.getStringPermissao(), data, funcionalidadeAcessada, entidadeAcessada);
  _listaErros.push_back(PN);
  
}

void Servico::servicoFeito(Permissao permissao, std::string nivelTensao, int tensao, Usuario user, Data data){

    std::cout << "Servico de ligacao pai" << std::endl;

}

std::list<LogErro> Servico::getListaErro(){
  return _listaErros;
}