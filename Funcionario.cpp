#include "Funcionario.hpp"
#include "PessoaFisica.hpp"
#include "PessoaJuridica.hpp"
#include "Servico.hpp"
#include "Desligamento.hpp"
#include "Ligacao.hpp"
#include "Medicao.hpp"
#include "TMedidor.hpp"
#include "UC.hpp"
#include "Cliente.hpp"
#include "Usuario.hpp"
#include "Data.hpp"
#include "Permissao.hpp"
#include "Erro.hpp"

#include <iostream>
#include <list>
#include <string.h>

Funcionario::Funcionario(std::string nome, std::string cpf, int id, std::string email) : Usuario(nome, email)
{
  this -> IDFuncionario = id;
  this -> _nome = nome;
  this -> _cpf = cpf;
  this -> _email = email;

  Permissao permAux("Chefe");
  this -> _permissao = permAux;
}

Funcionario::Funcionario() : Usuario()
{
  this -> IDFuncionario = 0;
}
//int, Permissao, Data, Usuario, Data
LogEscrita Funcionario::registraServico(Servico* servico, Permissao permissao, Data planejada, Usuario user, Data registro)
{
  try{
    if (permissao.conferePermissao("Chefe") || permissao.conferePermissao("Eletricista"))
  {
    std::list<std::string> atributosAntes;
    std::list<std::string> atributosDepois;

    std::string aux;
    if(_filaServicos.size() < 8)
    {
      if(servico->getTipo() != 0){
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

int Funcionario::getId()
{
  return IDFuncionario;
}

std::string Funcionario::getNome()
{
  return _nome;
}

std::string Funcionario::getcpf()
{
  return _cpf;
}
//int, Permissao, Data, Usuario, Data
LogEscrita Funcionario::realizaServico(int id, Permissao permissao, Data execucao, Usuario usuario, Data registro, std::string nivelTensao, int tensao)
{
  try{
 if (permissao.conferePermissao("Eletricista"))
  {
    std::list<std::string> atributosAntes;
    std::list<std::string> atributosDepois;

    std::string aux;
    for(FSit = _filaServicos.begin(); FSit != _filaServicos.end(); FSit++)
    {
      if((*FSit) -> getId() == id){
        if((*FSit) -> getStatus())
        {
          throw Erro(8);
        }
        else{
          

          if((*FSit) -> getTipo() == 4 || (*FSit) -> getTipo() == 5){

            if(!(confereTensao(nivelTensao, tensao))){
                throw Erro(14);

            }
          aux = "Servico de " + this->_nome + ", ID servico: " + to_string((*FSit) -> getId()) + " com atributo 'Feito' igual a 0";
          atributosAntes.push_back(aux);
              (*FSit) -> servicoFeito(permissao, nivelTensao, tensao, usuario, registro);

          }
          else{
            aux = "Servico de " + this->_nome + ", ID servico: " + to_string((*FSit) -> getId()) + " com atributo 'Feito' igual a 0";
            atributosAntes.push_back(aux);
            (*FSit) -> servicoFeito(permissao, usuario, registro);
          }
          
          aux = "Servico de " + this->_nome + ", ID servico: " + to_string((*FSit) -> getId()) + " com atributo 'Feito' igual a 1";
          atributosDepois.push_back(aux);
       

          aux = "Servico de " + this->_nome + ", ID servico: " +to_string((*FSit) -> getId())+ " com atributo 'Data execucao' igual a NULL";
          atributosAntes.push_back(aux);

          (*FSit) -> defineDataHoraExecucao(execucao);

          aux = "Servico de " + this->_nome + ", ID servico: " + to_string((*FSit) -> getId()) + " com atributo 'Feito' igual a " + execucao.getData();
          atributosDepois.push_back(aux);

          
          _servicosFeitos.push_back(*FSit);
          std::cout<<"Registro de servico realizado feito com sucesso." << std::endl;
          return LogEscrita(usuario.getNome(), usuario.getEmail(), registro, "Servico", atributosAntes, atributosDepois);

        }
      }
      
    }
    throw Erro(7);
  }
  else
  {
    throw Erro(6);
  }  
  } catch(Erro _erro){
    _erro.out();
    if(_erro.what() == 6){
      geraLogErro(usuario.getNome(), usuario.getEmail(), usuario.getStringPermissao(), registro, "Realiza Servico", "Funcionario");
    }

    std::list<std::string> atributosAntes;
    std::list<std::string> atributosDepois;

    atributosAntes.push_back("NULL");
    atributosDepois.push_back("NULL");

    return LogEscrita(usuario.getNome(), usuario.getEmail(), registro, "Realiza Servico - ERRO", atributosAntes, atributosDepois);
  }
 
}
//Usuario, Data
LogEscrita Funcionario::limpaFila(Usuario usuario, Data data)
{

  std::list<std::string> atributosAntes;
  std::list<std::string> atributosDepois;

  std::string aux;

  while (!_filaServicos.empty())
  {
    aux = "Lista do funcionario " + this -> _nome + " com o lugar %d ocupado", 8 - _filaServicos.size(); 
    atributosAntes.push_back(aux);

    _filaServicos.pop_front();
    
    aux = "Lista do funcionario " + this -> _nome + " com o lugar %d vazio", 8 - _filaServicos.size(); 
    atributosDepois.push_back(aux);

  }
  std::cout<< std::endl <<"Fim do dia: Lista de Funcionario limpa." << std::endl; 
  return LogEscrita(usuario.getNome(), usuario.getEmail(), data, "Funcionario", atributosAntes, atributosDepois);
}


LogLeitura Funcionario::printFila(Usuario usuario, Data data)
{
  
  int posicao = 1;
  std::cout << std::endl << "Lista de Servicos Planejados para Hoje:" << std:: endl;
  std::cout << std::endl << _nome << std::endl;
  for(FSit = _filaServicos.begin(); FSit != _filaServicos.end(); FSit++)
  {
    if((*FSit) -> getStatus()){
      std::cout << " Servico Feito. ";
    }
    std::cout << posicao << "- Servico do tipo ";
    (*FSit) -> listaTipoServico((*FSit) -> getTipo());
    std::cout << " na Unidade Consumidora ";
    (*FSit) -> printUC();
    
    posicao++;

  }

  return LogLeitura(usuario.getNome(), usuario.getEmail(), data, "Servicos", "Funcionario");
}

LogLeitura Funcionario::printServicosFeitos(Usuario usuario, Data data)
{
  int posicao = 1;
  std::cout << std::endl << "Lista de Servicos Feitos:" << std:: endl;
  std::cout << std::endl << _nome << std::endl;
  for(FSit = _servicosFeitos.begin(); FSit != _servicosFeitos.end(); FSit++)
  {
      std::cout << posicao << "- Servico do tipo ";
      (*FSit) ->listaTipoServico((*FSit) -> getTipo());
      std::cout << " realizado em ";
      (*FSit) -> printDataHora();
      std::cout << std:: endl; 
      posicao++;
  }

  return LogLeitura(usuario.getNome(), usuario.getEmail(), data, "Servicos feitos", "Funcionario");
}

LogEscrita Funcionario::tiraServicoFila(int id, Permissao permissao, Usuario usuario, Data registro)
{
  try{
if (permissao.conferePermissao("Chefe") || permissao.conferePermissao("Eletricista") || permissao.conferePermissao("Leiturista"))
  {
    std::list<std::string> atributosAntes;
    std::list<std::string> atributosDepois;

    std::string aux;
    for(FSit = _filaServicos.begin(); FSit != _filaServicos.end(); FSit++)
    {
      if((*FSit) -> getId() == id){
        
        aux = "Servico com identificador %d na lista do funcionario " + this -> _nome, id;
        atributosAntes.push_back(aux);

        std::cout << "- Servico do tipo ";
        (*FSit) -> listaTipoServico((*FSit)->getTipo());
        std::cout << " retirado da lista de tarefas.";
        _filaServicos.erase(FSit);

        aux = "Servico retirado da lista do funcionario " + this -> _nome;
        atributosDepois.push_back(aux);

        return LogEscrita(usuario.getNome(), usuario.getEmail(), registro, "Funcionario", atributosAntes, atributosDepois);
  
      } 
    }
    throw Erro(7);
  }
  else
  {
    throw Erro(6);
  }
  } catch(Erro _erro){
    _erro.out();
    if(_erro.what() == 6){
      geraLogErro(usuario.getNome(), usuario.getEmail(), usuario.getStringPermissao(), registro, "Tira Servico Fila", "Funcionario");
    }

    std::list<std::string> atributosAntes;
    std::list<std::string> atributosDepois;

    atributosAntes.push_back("NULL");
    atributosAntes.push_back("NULL");

    return LogEscrita(usuario.getNome(), usuario.getEmail(), registro, "Tira Servico Fila - ERRO", atributosAntes, atributosDepois);
  }
  
}

bool Funcionario::confereTensao(std:: string nivelTensao, int tensao){
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