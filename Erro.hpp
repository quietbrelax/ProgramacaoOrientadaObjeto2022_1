//não encontrar cliente - 0
//não encontrar uc - 1
//não encontrar funcionario - 2
//não encontrou fatura - 3
//cpf/cnpj invalido - 4
//serviço em excesso - 5
//permissão!!!!!!!!!!!! - permissaoNegada - 6
//não encontrar serviço - 7
//Serviço já realizado - 8
//parametro invalido (mto parametro) - 9
//parametro invalido (pouco parametro) - 10
//uc desligada - 11
//erro desconhecido - 12
//tipo de uc inválido - 13
//tensão inválida - 14

/*void semCliente(){
  std::cout  << "Cliente não encontrado......" << std::endl;
}*/

#ifndef ERRO_H
#define ERRO_H
#include <exception>
#include <string.h>

using namespace std;

class Erro : public exception
{
protected:
	int _tipo;

public:
	Erro(int tipo);
	virtual const int what();
	void out();
};

#endif // ERRO_H

