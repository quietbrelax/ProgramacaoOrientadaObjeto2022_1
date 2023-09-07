#ifndef CLIENTE_H
#define CLIENTE_H

#include <list>
#include <string>

#include "Endereco.hpp"
#include "UC.hpp"
#include "Usuario.hpp"
#include "Permissao.hpp"
#include "Log.hpp"
#include "LogErro.hpp"
#include "LogLeitura.hpp"
#include "LogEscrita.hpp"

class Cliente : public Usuario
{
public:

    Cliente(std ::string, Endereco, std::string, std::string); // Construtor
    
    //Metodos de acesso a atributos
    std::string getNome();
    bool getSituacao();
    void geraFatura(int, Permissao, Usuario, Data);
    UnidadeConsumidora* getUC(int);

    //Metodos funcionais para clientes no geral
    LogLeitura visualizarFaturasPendentes(Permissao, Usuario, Data);
    LogLeitura visualizarHistoricoFaturas(Permissao, Usuario, Data);
    LogLeitura checaPagamentos(Permissao, Usuario, Data);
    LogEscrita pagarFaturas(int, int, Permissao, Usuario, Data);
    virtual LogEscrita adicionarUC(int, Endereco, Permissao, int, Usuario, Data) = 0; //const = 0;

protected:
    std::list<UnidadeConsumidora> _UC;
    bool _situacao;
    Endereco _endereco;
    std::string _telefone;
    
};
                                                                  
#endif
