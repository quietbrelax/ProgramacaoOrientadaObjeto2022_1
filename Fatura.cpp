#include "Fatura.hpp"
#include "Permissao.hpp"
#include "Erro.hpp"
#include "LogLeitura.hpp"
#include <iostream>
#include <iomanip>
#include <math.h>


Fatura::Fatura(float consumo, int idFatura)
{
  this -> _idFatura = idFatura;
  this -> _taxaJuros = 0.01;//taxa arbitraria, pd escolher qlquer coisa
  this -> _consumo = consumo;
  this -> _valorFatura = 100 * consumo; //conta arbitraria pra calcular o valor, tem q mudar dps
  this -> _valorInicial = this -> _valorFatura;
  this -> _atrasada = 0;
  this -> _pago = 0;
  this -> _diasAtraso = 0;
  this -> _emissao = this -> _emissao.dateNow();
  
}

void Fatura::printFatura(){
  
  std::cout << std::setprecision(2) << std::fixed;
  std::cout << std::endl << "\tFatura " << this -> _idFatura << "\t"
  << "Consumo: " << this -> _consumo << "kWh\t"
  << "Valor: R$" << this ->_valorFatura << "\t"
  << "Dias de atraso: " << this -> _diasAtraso << " Data de emissao: " << _emissao.getDia() << "/ " << _emissao.getMes() << "/ " << _emissao.getAno() << std::endl;

}

void Fatura::calculoJuros(){
  
  float juros = pow(1 + this->_taxaJuros, this -> _diasAtraso/30.0);
  this ->_valorFatura = this -> _valorInicial*juros;
}

//Aqui, considere o parametro diasAtrasados contando sempre os dias atrasados total 
void Fatura::adicionaDiasAtraso(int diasAtrasados, Permissao permissao)
{
  try{
    if(!(permissao.conferePermissao("Leiturista")))
  {
    throw Erro(6);
  }
  else
  {
    this -> _atrasada = 1;
    //o + dias atrasados é porque como a fatura esta sendo emitida e calculada o juros no mesmo dia, por motivos de teste precisa de adicionar os dias atrasados desejados
    this -> _diasAtraso = _emissao.diffData(_emissao.dateNow()) + diasAtrasados;
    calculoJuros();
  }
  } catch(Erro _erro){
    _erro.out();
  }
  
} 

void Fatura::pagaFatura(){
  this -> _atrasada = 0;
  this -> _pago = 1;
}

bool Fatura::getSituacaoPagamento(){
  return this -> _pago;
}

int Fatura::getID(){
  return this -> _idFatura;
}

bool Fatura::getSituacao(){
  return this -> _atrasada;
}