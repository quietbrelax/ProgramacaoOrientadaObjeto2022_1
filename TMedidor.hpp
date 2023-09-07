#ifndef TMEDIDOR_H
#define TMEDIDOR_H

#include "Servico.hpp"
#include "UC.hpp"
#include "Cliente.hpp"

class TMedidor : public Servico
{
	public:
  
	TMedidor(int, Cliente*, int);
  void servicoFeito(Permissao, Usuario, Data);
  void servicoFeito(float, Permissao, Usuario, Data);

};

#endif