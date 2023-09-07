#ifndef SERVICO_H
#define SERVICO_H

#include <string>
#include "Cliente.hpp"
#include "PessoaFisica.hpp"
#include "PessoaJuridica.hpp"
#include "UC.hpp"
#include "Data.hpp"
#include "LogLeitura.hpp"
#include "Usuario.hpp"
#include "LogErro.hpp"

class Servico{
public:
	Servico(int, Cliente*, int);
  void defineDataHoraExecucao(Data); 
  void realizaServico();
  LogLeitura listarTiposServico(Usuario, Data);
  int getId();
  int getTipo();
  bool getStatus();
  virtual void servicoFeito(Permissao, Usuario, Data) = 0; //const = 0;
  virtual void servicoFeito(float, Permissao, Usuario, Data) = 0; //const = 0;
  virtual void servicoFeito(Permissao, std::string, int, Usuario, Data);
  void listaTipoServico(int);
  void printDataHora();
  void printUC();
  void colocaSequencia(int);
  void dataPlanejada(Data);
  void geraLogErro(Usuario, Data, std::string, std::string);
  std::list<LogErro> getListaErro();
  
protected:
  std:: string _data;
  Data _Data;
  Data _planejamento;
  int _Funcionario;
  
  int _sequencia;
  bool _servicoFeito;
  int _tipo;
  Cliente* _clienteBeneficiado;
  UnidadeConsumidora* _UC;

  std::string listaTiposServicos[6];
  std::list<LogErro> _listaErros;
  
};

#endif