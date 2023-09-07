#include "Cliente.hpp"
#include "Endereco.hpp"
#include "Usuario.hpp"
#include "Permissao.hpp"
#include "Erro.hpp"
#include "Log.hpp"
#include "LogErro.hpp"
#include "LogLeitura.hpp"
#include "LogEscrita.hpp"
#include <iostream>

Cliente::Cliente(std::string nome, Endereco endereco, std::string telefone, std::string email) : Usuario(nome, email)
{
  this -> _nome = nome;
  this -> _situacao = 0;
  this -> _endereco = endereco;
  this -> _telefone = telefone;
  this -> _email = email;
  Permissao permAux("Cliente");
  this -> _permissao = permAux;
  //permissaoAux != permissao
}

std::string Cliente::getNome()
{
	return this -> _nome;
}

bool Cliente::getSituacao()
{
	return this -> _situacao;
}

UnidadeConsumidora* Cliente::getUC(int idUC){
  //Pega uma unidade consumidora baseada no ID
  try{
    for (std::list<UnidadeConsumidora>::iterator it = _UC.begin(); it != _UC.end(); it++)
	  {
		  if(it -> getID() == idUC){
				  return &(*it);
		  }
	  }
    throw Erro(1);
  } catch(Erro _erro){
    _erro.out();
    
  }
  
}

LogLeitura Cliente::visualizarFaturasPendentes(Permissao permissao, Usuario usuario, Data data) {
 //imprime todas as faturas com o estado pago como falso
  try{
    if(!(permissao.conferePermissao("Cliente")))
  {
    throw Erro(6);
  }
  else
  {
    for (std::list<UnidadeConsumidora>::iterator it = _UC.begin(); it != _UC.end(); it++)
  	{
  		std::cout << std::endl;
  		it -> printUC();
  		it -> printFaturas(0);
  	}
    return LogLeitura(usuario.getNome(), usuario.getEmail(), data, "Faturas Pendentes", "Unidade Consumidora");
  }
  } catch(Erro _erro){
    _erro.out();
    if(_erro.what() == 6){
      geraLogErro(usuario.getNome(), usuario.getEmail(), usuario.getStringPermissao(), data, "Vizualizar Faturas Pendentes", "Cliente");
    }
  }
  
}

LogLeitura Cliente::visualizarHistoricoFaturas(Permissao permissao, Usuario usuario, Data data){
	//imprime todas as faturas com o estado pago
  try{
    if(!(permissao.conferePermissao("Cliente")))
  {
    throw Erro(6);
  }
  else
  {
    for (std::list<UnidadeConsumidora>::iterator it = _UC.begin(); it != _UC.end(); it++)
  	{
  		std::cout << std::endl;
  		it -> printUC();
  		it -> printFaturas(1);
  	}
    return LogLeitura(usuario.getNome(), usuario.getEmail(),  data, "Historico Faturas", "Unidade Consumidora");
  }
  }
  catch(Erro _erro){
    _erro.out();
    if(_erro.what() == 6){
      geraLogErro(usuario.getNome(), usuario.getEmail(), usuario.getStringPermissao(), data,  "Vizualizar Historico de Faturas", "Cliente");
    }
  }
  
	
}

LogLeitura Cliente::checaPagamentos(Permissao permissao, Usuario usuario, Data data){
	//checa pra ver se cada fatura tem algm atraso, se tiver, muda a situação pra 1
  try{
if(!(permissao.conferePermissao("Cliente")))
  {
    throw Erro(6);
  }
  else
  {
    int faturasPendentes = 0;
  	for (std::list<UnidadeConsumidora>::iterator it = _UC.begin(); it != _UC.end(); it++)
  	{	
  		std::cout << this -> _nome << ", voce tem: " << it ->confereFaturas() 
  				<< " fatura(s) pendente(s), referente a Unidade: " << it -> getID()<< std::endl;
  		faturasPendentes += it -> confereFaturas();
  		if(it -> faturasAtrasadas() > 0){
  			std:: cout << "Atencao! Voce tem " << it -> faturasAtrasadas() << " fatura(s) atrasada(s)!" << std::endl; 
  			this -> _situacao = 1;
  		}
  	}
  	if(faturasPendentes == 0){
  			std::cout << this -> _nome << ", voce nao tem faturas pendentes. " << std::endl;
  		}
    return LogLeitura(usuario.getNome(), usuario.getEmail(), data, "Faturas Pendentes", "Unidade Consumidora");
  }	
  } catch(Erro _erro){
    _erro.out();
    if(_erro.what() == 6){
      geraLogErro(usuario.getNome(), usuario.getEmail(), usuario.getStringPermissao(), data, "Checa Pagamentos", "Cliente");
    }
  }
   
}

LogEscrita Cliente::pagarFaturas(int idUC, int idFatura, Permissao permissao, Usuario usuario, Data data) {
	//precisa do id da UC e da fatura, muda o estado da fatura pra pago
  try{
    if(!(permissao.conferePermissao("Cliente")))
  {
    throw Erro(6);
  }
  else
  {
    std::list<std::string> atributosAntes;
    std::list<std::string> atributosDepois;

    std::string aux;

    for (std::list<UnidadeConsumidora>::iterator it = _UC.begin(); it != _UC.end(); it++)
  	{
      
  		if(it -> getID() == idUC){
        aux = "Atributo 'pago' da fatura %d da Unidade Consumidora %d igual a 0", idFatura, idUC;
        atributosAntes.push_back(aux);
  				it -> pagarFatura(idFatura);
        aux = "Atributo 'pago' da fatura %d da Unidade Consumidora %d igual a 1", idFatura, idUC;
        atributosDepois.push_back(aux);
  				std::cout << "Fatura " << idFatura << " referente a Unidade Consumidora " << idUC << " paga." << std::endl;
  				if(it -> faturasAtrasadas() == 0 && this -> _situacao == 1){
  					std:: cout << "Voce quitou sua divida" << std::endl;
            aux = "Atributo 'situacao' do cliente igual a 1";
            atributosAntes.push_back(aux);
  					this -> _situacao = 0;
            aux = "Atributo 'situacao' do cliente igual a 0";
            atributosDepois.push_back(aux);
  				}
  		}
  		
  	}

  	std::cout << "Conferindo sua situacao atual" << std::endl;
  	checaPagamentos(permissao, usuario, data);
  	std::cout << "Exibindo historico de pagamentos" << std::endl;
  	visualizarHistoricoFaturas(permissao, usuario, data);

    return LogEscrita(usuario.getNome(), usuario.getEmail(), data, "Pagar Faturas", atributosAntes, atributosDepois);
    }  	
  } catch(Erro _erro){
    _erro.out();
    if(_erro.what() == 6){
      geraLogErro(usuario.getNome(), usuario.getEmail(), usuario.getStringPermissao(), data, "Pagar Faturas", "Cliente");
    }

    std::list<std::string> atributosAntes;
    std::list<std::string> atributosDepois;

    atributosAntes.push_back("NULL");
    atributosDepois.push_back("NULL");

    return LogEscrita(usuario.getNome(), usuario.getEmail(), data, "Pagar Faturas - ERRO", atributosAntes, atributosDepois);
  }
  
}

void Cliente::geraFatura(int idUC, Permissao permissao, Usuario usuario, Data data){
  try{
     if(!(permissao.conferePermissao("Leiturista")))
  {
    throw Erro(6);
  }
  else
  {
    for (std::list<UnidadeConsumidora>::iterator it = _UC.begin(); it != _UC.end(); it++)
	{
		if(it -> getID() == idUC){
        it -> geraFatura();
				std:: cout << "Fatura referente a Unidade Consumidora "<< idUC << " disponivel para pagamento." << std::endl;
				return;
		}
	}
    throw Erro(1);
  }
  }
  catch(Erro _erro){
    _erro.out();
    if(_erro.what() == 6){
      geraLogErro(usuario.getNome(), usuario.getEmail(), usuario.getStringPermissao(), data, "Vizualizar Faturas Pendentes", "Cliente");
    }
    
  }
  

}
