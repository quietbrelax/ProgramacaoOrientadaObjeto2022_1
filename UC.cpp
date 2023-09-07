#include "UC.hpp"
#include "Endereco.hpp"
#include "Erro.hpp"
#include <list>
#include <iostream>

UnidadeConsumidora::UnidadeConsumidora(int tipo, Endereco endereco, std::string clienteID, int UCID, int NumInstalacao)
{
  this->_tipo = tipo - 1;
  this->_endereco = endereco;
  this-> _titular = clienteID;
  this->_UCID = UCID;
  this -> _ultimoConsumo = 0;
  this -> _ligada = 0;
  this -> _nInstalacao = NumInstalacao;
  this -> _nivelTensao = "Indefinido";
  this -> _tensao = 0;
}

void UnidadeConsumidora::printUC(){
  std::string tiposUCS[4] = {"Residencial", "Comercial", "Industrial", "Iluminacao Publica"};
  std::cout << this -> _UCID << "- Tipo: " << tiposUCS[this -> _tipo] << " Endereco: ";
    this -> _endereco.printEndereco();
    std::cout << " Status: ";
  if(this -> _ligada){
    std::cout << "Ligada"<< std::endl;
  }
  else if(!this ->_ligada){
    std::cout << "Desligada"<< std::endl;
  }
}

void UnidadeConsumidora::printFaturas(bool tipoFatura){
  //faturas pagas
  try{
if(!(this -> _ligada))
  {
    throw Erro(11);
  }
  else{
    if(tipoFatura){
      for (std::list<Fatura>::iterator it = _faturas.begin(); it != _faturas.end(); it++)
	    {
        if(it -> getSituacaoPagamento())
		      it -> printFatura();
	    }
    }

    else{
      for (std::list<Fatura>::iterator it = _faturas.begin(); it != _faturas.end(); it++)
	    {
        if(!(it -> getSituacaoPagamento()))
		      it -> printFatura();
	    }
    }
  }
  } catch(Erro _erro){
    _erro.out();
  }
  
  

}

void UnidadeConsumidora::geraFatura(){
  try
  {
    if(!(this -> _ligada))
      {
        throw Erro(11);
      }
      else
      {
        this -> _consumo = this -> _leitura - this -> _ultimoConsumo;
        this -> _ultimoConsumo += this -> _consumo;
        Fatura novaFatura(this -> _consumo, _faturas.size());
        _faturas.push_back(novaFatura);
      }
  } catch(Erro _erro){
    _erro.out();
  }
  
}

Fatura* UnidadeConsumidora::getFatura(int idFatura){
  try{
if(!(this -> _ligada))
  {
    throw Erro(11);
  }
  //pega a fatura baseada no id da fatura
  else{
    for (std::list<Fatura>::iterator it = _faturas.begin(); it != _faturas.end(); it++)
	  {
		  if(it -> getID() == idFatura)
      {
				  return &(*it);
		  }
	  }
  }
	throw Erro(3);
  return nullptr;
  } catch(Erro _erro){
    _erro.out();
    return nullptr;
  }
  
}

int UnidadeConsumidora::getID(){
    return this -> _UCID;
}

int UnidadeConsumidora::confereFaturas(){
  int faturasPendentes = 0;
  for (std::list<Fatura>::iterator it = _faturas.begin(); it != _faturas.end(); it++)
	{
		if(!(it -> getSituacaoPagamento())){
				faturasPendentes++;
		}
	}
  return faturasPendentes;
}

int UnidadeConsumidora::faturasAtrasadas(){
  int faturasAtrasadas = 0;
  for (std::list<Fatura>::iterator it = _faturas.begin(); it != _faturas.end(); it++)
	{
		if(it -> getSituacao()){
				faturasAtrasadas++;
		}
	}
  return faturasAtrasadas;
}

void UnidadeConsumidora::pagarFatura(int idFatura){
  for (std::list<Fatura>::iterator it = _faturas.begin(); it != _faturas.end(); it++)
	{
		if(it -> getID() == idFatura){
				it -> pagaFatura();
		}
	}
}

void UnidadeConsumidora::desligaUC( ){
   this -> _ligada = 0;
}
bool UnidadeConsumidora::confereTensao(std:: string nivelTensao, int tensao){
  if(nivelTensao == "BT" && tensao < 1000)
  {
    return true;
  }
  else if(nivelTensao == "MT" && tensao <= 36000 && tensao >= 1000)
  {
    return true;
  }
  else if(nivelTensao == "AT" && tensao > 36000){
    return true;
  }
  else
  {
    return false;
  }
}

void UnidadeConsumidora::ligaUC(std:: string nivelTensao, int tensao){
  try{
if(!(this -> confereTensao(nivelTensao, tensao))){
    throw Erro(14);
  }
  else{
    this -> _ligada = 1;
    this -> _tensao = tensao;
    this -> _nivelTensao = nivelTensao;    
  }
  } catch(Erro _erro){
    _erro.out();
  }
  
}



void UnidadeConsumidora::novaLeitura(float leitura){
  try{
    if(!(this -> _ligada))
  {
    throw Erro(11);
  }
  else{
    this -> _leitura = leitura;
  }
  }
  catch(Erro _erro){
    _erro.out();
  }


}

void UnidadeConsumidora::resetaUltimoConsumo( ){
   this -> _ultimoConsumo = 0;
}

