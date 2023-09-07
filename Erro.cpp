#include <iostream>
#include <string.h>
#include "Erro.hpp"

Erro::Erro(int tipo){
		this -> _tipo = tipo;
}

const int Erro::what()
  {
		return this -> _tipo;
	}

void Erro::out(){
    std::string tiposErros[17] = {"Cliente nao encontrado", "Unidade Consumidora nao encontrada", "Funcionario nao encontrado", "Fatura nao encontrada", "Identificador - CPF/CNPJ - invalido", "Carga maxima de servico atingida", "Permissao negada", "Servico nao encontrado", "Servico ja realizado", "Muitos parametros para este servico", "Poucos parametros para este servico", "Unidade Consumidora desligada", "Erro desconhecido", "Tipo de Unidade Consumidora invalido", "Tensao invalida", "Data Invalida", "Tipo de Servivo Invalido"};
    std::cout << "Erro do tipo: '" << tiposErros[this -> _tipo] << "'." << std::endl ;

}