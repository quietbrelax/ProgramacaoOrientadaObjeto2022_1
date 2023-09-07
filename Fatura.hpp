#ifndef FATURA_H
#define FATURA_H

#include "Fatura.hpp"
#include "Permissao.hpp"
#include "Data.hpp"
#include "Permissao.hpp"
#include <string>
#include "Log.hpp"
#include "LogErro.hpp"
#include "LogLeitura.hpp"
#include "LogEscrita.hpp"
#include "Usuario.hpp"
#include "Data.hpp"


class Fatura
{
public:
  Fatura(float, int); // Construtor
  void printFatura();
  void adicionaDiasAtraso(int, Permissao);
  bool getSituacaoPagamento();
  int getID();
  bool getSituacao();
  void pagaFatura();
  void calculoJuros();


private:
  int _idFatura;
  float _taxaJuros;
  float _consumo;
  float _valorFatura;
  bool _atrasada;
  bool _pago;
  int _diasAtraso;
  float _valorInicial;

  Data _emissao;

};

#endif