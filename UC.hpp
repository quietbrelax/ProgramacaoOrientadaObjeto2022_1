#ifndef UC_H
#define UC_H

#include "Fatura.hpp"
#include "Endereco.hpp"
#include <string>
#include <list>
#include "LogEscrita.hpp"
#include "LogLeitura.hpp"

class UnidadeConsumidora
{
public:
  UnidadeConsumidora(int, Endereco, std::string, int, int);// Construtor
  void printUC();
  void geraFatura();
  void printFaturas(bool);
  Fatura* getFatura(int);
  int getID();
  int confereFaturas();
  int faturasAtrasadas();
  void pagarFatura(int);
  void desligaUC();
  void ligaUC(std::string, int);
  void novaLeitura(float);
  void resetaUltimoConsumo();
  bool confereTensao(std::string, int);

private:
  int _tipo;
  std::string _titular; 
  Endereco _endereco;
  int _UCID;
  std::list<Fatura> _faturas;
  bool _ligada;
  float _leitura;
  float _ultimoConsumo;
  float _consumo;

  Endereco loc_Uc;
  std::string _nivelTensao;
  int _tensao;
  int _nInstalacao;
};

#endif