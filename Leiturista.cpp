#include "Leiturista.hpp"
#include "Medicao.hpp"
#include "Cliente.hpp"
#include "Permissao.hpp"
#include "Erro.hpp"
#include <iostream>
#include <list>

Leiturista::Leiturista(std::string nome, std::string cpf, int id, std::string email): Funcionario(nome, cpf, id, email)
{
  this -> _nome = nome;
  this -> _cpf = cpf;
  this -> IDFuncionario = id;
  this -> _email = email;

  Permissao permAux("Leiturista");
  this -> _permissao = permAux;
}

LogEscrita Leiturista::realizaServico(int id, float leitura, Permissao permissao, Data execucao, Usuario user, Data registro)
{
  try{
    if(!(permissao.conferePermissao("Leiturista")))
  {
    throw Erro(6);
  }
  else
  {
    for(FSit = _filaServicos.begin(); FSit != _filaServicos.end(); FSit++)
    {
      std::list<std::string> atributosAntes;
      std::list<std::string> atributosDepois;

      std::string aux;

      if((*FSit) -> getId() == id){
        if((*FSit) -> getStatus())
        {
          throw Erro(8);
        }

        aux = "Servico de " + this->_nome + ", ID servico: " + to_string((*FSit) -> getId())+ " com atributo 'Feito' igual a 0";
        atributosAntes.push_back(aux);
        aux = "Servico de " + this->_nome + ", ID servico: " + to_string((*FSit) -> getId())+ " com atributo de leitura igual a 0";
        atributosAntes.push_back(aux);

        (*FSit) -> servicoFeito(leitura, permissao, user, registro);

        aux = "Servico de " + this->_nome + ", ID servico: "+ to_string((*FSit) -> getId())+" com atributo 'Feito' igual a 1";
        atributosDepois.push_back(aux);
        aux = "Servico de " + this->_nome + ", ID servico: "+ to_string((*FSit) -> getId())+" com atributo de leitura igual a " + to_string(leitura);
        atributosDepois.push_back(aux);
       
        aux = "Servico de " + this->_nome + ", ID servico: "+ to_string((*FSit) -> getId())+" com atributo 'Data execucao' igual a NULL";
        atributosAntes.push_back(aux);

        (*FSit) -> defineDataHoraExecucao(execucao);

        aux = "Servico de " + this->_nome + ", ID servico: "+ to_string((*FSit) -> getId())+" com atributo 'Feito' igual a " + execucao.getData();
        atributosDepois.push_back(aux);
        
        _servicosFeitos.push_back(*FSit);
        std::cout<<"Registro de servico realizado feito com sucesso." << std::endl;
        return LogEscrita(user.getNome(), user.getEmail(), registro, "Servico", atributosAntes, atributosDepois);
      }
    }
    throw Erro(7);
  } 
  } catch(Erro _erro){
    _erro.out();
    if(_erro.what() == 6){
      geraLogErro(user.getNome(), user.getEmail(), user.getStringPermissao(), registro, "Realiza Servico", "Funcionario");
    }
    std::list<std::string> atributosAntes;
    std::list<std::string> atributosDepois;

    atributosAntes.push_back("NULL");
    atributosDepois.push_back("NULL");

    return LogEscrita(user.getNome(), user.getEmail(), registro, "Realiza Servico - ERRO", atributosAntes, atributosDepois);
  }
  
}

LogEscrita Leiturista::registraServico(Servico* servico, Permissao permissao, Data planejada, Usuario user, Data registro)
{
  try{
    if (permissao.conferePermissao("Chefe") || permissao.conferePermissao("Leiturista"))
  {
    std::list<std::string> atributosAntes;
    std::list<std::string> atributosDepois;

    std::string aux;
    if(_filaServicos.size() < 8)
    {
      if(servico->getTipo() == 0){
        aux = "Lista de " + this->_nome + " com "+ to_string(_filaServicos.size())+" servicos";
      atributosAntes.push_back(aux);

      _filaServicos.push_back(servico);

      aux = "Servico do tipo "+ to_string(servico -> getTipo())+" adicionado a lista do Funcionario " + this->_nome + ". Tamanho da lista de Servicos atual: " + to_string(_filaServicos.size());
      atributosDepois.push_back(aux);

      aux = "Data planejada do servico: NULL";
      atributosAntes.push_back(aux);

      servico -> dataPlanejada(planejada);

      aux = "Data planejda do servico: " + planejada.getData();
      atributosDepois.push_back(aux);

      aux = "Numero de Sequencia do servico: NULL";
      atributosAntes.push_back(aux);

      _filaServicos.back() -> colocaSequencia(_filaServicos.size() - 1);

      aux = "Numero de Sequencia do servico: " + to_string(_filaServicos.size() - 1);
      atributosDepois.push_back(aux);

      std::cout<<"Servico adicionado."<< std::endl;

      return LogEscrita(user.getNome(), user.getEmail(), registro, "Funcionario", atributosAntes, atributosDepois);
      }

      else{
        throw Erro(16);
      }
      
      
      }
      else
      {
        throw Erro(5); 
      }
  }
  else 
  {
    throw Erro(6);
  }
  } catch(Erro _erro){
    _erro.out();
    if(_erro.what() == 6){
      geraLogErro(user.getNome(), user.getEmail(), user.getStringPermissao(), registro, "Registra Servico", "Funcionario");
    }
    std::list<std::string> atributosAntes;
    std::list<std::string> atributosDepois;

    atributosAntes.push_back("NULL");
    atributosDepois.push_back("NULL");

    return LogEscrita(user.getNome(), user.getEmail(), registro, "Registra Servico - ERRO", atributosAntes, atributosDepois);
  }
  
}
