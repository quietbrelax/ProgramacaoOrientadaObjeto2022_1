#include <iostream>
#include <list>
#include <ctime>
#include <string>

#include "Cliente.hpp"
#include "Fatura.hpp"
#include "Registro.hpp"
#include "UC.hpp"
#include "PessoaFisica.hpp"
#include "PessoaJuridica.hpp"
#include "Endereco.hpp"
#include "Leiturista.hpp"
#include "Eletricista.hpp"
#include "Medicao.hpp"
#include "TMedidor.hpp"
#include "Ligacao.hpp"
#include "Desligamento.hpp"
#include "Login.hpp"
#include "Erro.hpp"


int main() {
	/*-----------------------------------Cabeçalho------------------------------------*/
	std::cout << std::endl << "Testes referentes ao Projeto OO - Modulo FINAL" << std::endl
	<< "Disciplina Programacao Orientada a Objeto, 2022/01" << std::endl
	<< "Alunos: " << std::endl
	<< "-Luiz Henrique Gariglio dos Santos" << std::endl
	<< "-Maria Clara Oliveira Domingos Ruas" << std::endl
	<< "-Maria Luisa do Nascimento Lima" << std::endl
	<< "==================== Inicio dos Testes =========================" << std::endl;
	/*----------------------Fim do cabeçalho------------------------------*/
  
	/*-----------------Dados para Testes---------------------------------*/
	Funcionario chefe("Anya Forger", "65642372009", 0, "ForgerThelepathy@gmail.com");
    
	// Os primeiros de cada item sao invalidos, (cpf e cnpj)
	std::string CPFSCadastro[6] = { "11444958634", "34885898897",
	"45238423969", "67974070102", "26687076175", "11444958658" };
	
	std::string CNPJSCadastro[6] = { "17217985000156",
	"66939729000136", "05503159000142","90907731000108",
	"06834973000102", "17217985000104" };

	std::string NomesPessoasFisicas[6] = { "Wagner","Mariana","Juliana",
	"Mario", "Ava", "Clauber"};
	std::string NomesPessoasJuridicas[6] = { "Minas Siderurgia",
	"Locadora Relampago Marquinhos","Bazar da Ju", "Aquario do Mario",
	"Ava Lanches", "Belo Horizonte Prefeitura"};

  std::string Telefones[12] = {"998256314", "982635471", "998723654", "985632147", "945632174", "985632147", "34152687", "23258965", "31478524", "33458741", "33217965", "24263285"};

  std::string Email[12] = {"a","b","c","d","e","f","g","h","i","j","k","l"};

	int numInst = 10001;

	/*Datas*/

	Data dataUm(2022, 7, 9, 20, 0, 0), dataDois(2022, 7, 10, 20, 0, 0), dataTres(2022, 7, 11, 20, 0, 0), dataQuatro(2022, 7, 12, 20, 0, 0), dataCinco(2022, 7, 13, 20, 0, 0), dataSeis(2022, 7, 14, 20, 0, 0), dataSete(2022, 7, 15, 20, 0, 0), dataOito(2022, 7, 16, 20, 0, 0), dataNove(2022, 7, 17, 20, 0, 0), dataDez(2022, 7, 18, 20, 0, 0), data11(2022, 7, 19, 20, 0, 0), data12(2022, 7, 20, 20, 0, 0), data13(2022, 7, 21, 20, 0, 0), data14(2022, 8, 20, 8, 0, 0), data15(2022, 8, 20, 9, 0, 0), data16(2022, 8, 20, 10, 0, 0), data17(2022, 7, 22, 20, 0, 0), data18(2022, 7, 23, 20, 0, 0), data19(2022, 7, 24, 20, 0, 0), data20(2022, 7, 25, 20, 0, 0), data21(2022, 7, 26, 20, 0, 0), data22(2022, 7, 27, 20, 0, 0), data23(2023, 7, 20, 20, 0, 0);

	Data datas[30] = {dataUm, dataDois, dataTres, dataQuatro, dataCinco, dataSeis, dataSete, dataOito, dataNove, dataDez, data11, data12, data13, data14, data15, data16, data17, data18, data19, data20, data21, data22};
  /* -------Endereco----------*/
	Endereco endUm, endDois, endTres, endQuatro, endCinco, endSeis, endSete, endOito, endNove, endDez, endOnze, endDoze;

	Endereco ends[12] = {endUm, endDois, endTres, endQuatro, endCinco, endSeis, endSete, endOito, endNove, endDez, endOnze, endDoze};

  std::string Logradouros[12] = {"Rua Luis Rabelo", "Rua Olimpio de Assis", "Rua Trinta", "Rua Jacinto Ferreira", "Avenida Jose Vallim de Mello", "Rua Cento e Quarenta e Dois - A", "Avenida Rebeliao Praieira", "Rua Oninda Carvalheira Peixoto", "Rua Senhora do Rosario", "Rua Jose Soares Dumont", "Rua Geraldo Costa", "Rua Joao Osorio Proenca"};
  std::string Numeros[12] = {"189", "1313", "932", "576", "9123", "888", "456", "130", "183", "624", "026", "530"};
  std::string Bairros[12] = {"Interlagos", "Cidade Jardim", "Cidade de Deus", "Havai", "Conjunto Chica Ferreira", "Conjunto Habitacional Vale do Jatoba (Barreiro)", "Noassa Senhora das Gracas", "Chacaras Palmeiras", "Barreiro de Baixo", "Dona Clara", "Independencia (Barreiro)", "Joao Paulo II"};
  std::string Complementos[12] = {"Casa", "Apartamento 201", "Casa", "Apartamento 107", "Casa", "Casa", "Casa", "Apartamento 503", "Apartamento 214", "Apartamento 606", "Casa", "Casa"};
  std::string Ceps[12] = {"35500471", "30380150", "35703285", "30570290", "38037580", "30664315", "38402306", "36774550", "35703721", "31260005", "30672720", "37901358"};
  std::string Cidades[12] = {"Divinopolis", "Belo Horizonte", "Sete Lagoas", "Belo Horizonte", "Uberaba", "Belo Horizonte", "Uberlandia", "Cataguases", "Sete Lagoas", "Belo Horizonte", "Belo Horizonte", "Passos"};
  std::string Estados[12] = {"MG", "MG", "MG", "MG", "MG", "MG", "MG", "MG", "MG", "MG", "MG", "MG"};

	for (int i = 0; i < 12; i++)
	{
		ends[i].setEndereco(Logradouros[i], Numeros[i], Bairros[i], Complementos[i], Ceps[i], Cidades[i], Estados[i]);
	}

   /* -------Endereco UC----------*/
	Endereco endUmUC, endDoisUC, endTresUC, endQuatroUC, endCincoUC, endSeisUC, endSeteUC, endOitoUC, endNoveUC, endDezUC, endOnzeUC, endDozeUC;

	Endereco endsUC[12] = {endUmUC, endDoisUC, endTresUC, endQuatroUC, endCincoUC, endSeisUC, endSeteUC, endOitoUC, endNoveUC, endDezUC, endOnzeUC, endDozeUC};
  std::string LogradourosUC[12] = {"Rua Lon Gidimais",
	"Avenida Radiator Springs","Alameda Lugar legal", "Rua Guen Toma Isnao",
	"Avenida Tudo de Bom", "Rua Da Prefeitura", "Alameda das Flores", "Rua Favo de Mel", "Rua Marcelo Pedro Andes", "Avenida dos Tucanos", "Avenida Mil e Uma Noites", "Alameda dos Jacintos"};
  std::string NumerosUC[12] = {"189", "1313", "932", "576", "9123", "888", "456", "130", "183", "624", "026", "530"};
  std::string BairrosUC[12] = {"Maria Candido", "Jorge Mario Lima", "Santa Barbara", "Mar Azul", "Riachinho", "Lagoa Serena", "Sol Poente", "Via Lactea", "Andromeda", "Apolo XV", "Vale dos Coqueiros", "Pitangueira"};
  std::string ComplementosUC[12] = { "Casa", "Casa", "Casa", "Apartamento 503", "Casa", "Apartamento 201", "Casa", "Apartamento 107", "Apartamento 214", "Apartamento 606", "Casa", "Casa"};
  std::string CepsUC[12] = {"35500471", "31260005", "30672720", "37901358" "30380150", "35703285", "30570290", "38037580", "30664315", "38402306", "36774550", "35703721"};
  std::string CidadesUC[12] = {"Divinopolis", "Belo Horizonte", "Sete Lagoas", "Belo Horizonte", "Uberaba", "Belo Horizonte", "Uberlandia", "Cataguases", "Sete Lagoas", "Belo Horizonte", "Belo Horizonte", "Passos"};
  std::string EstadosUC[12] = {"MG", "MG", "MG", "MG", "MG", "MG", "MG", "MG", "MG", "MG", "MG", "MG"};

	for (int i = 0; i < 12; i++)
	{
		endsUC[i].setEndereco(LogradourosUC[i], NumerosUC[i], BairrosUC[i], ComplementosUC[i], CepsUC[i], CidadesUC[i], EstadosUC[i]);
	}
	

  std::string NomesFuncionarios[3] = {"Roberto", "Maria", "Gustavo"};
  std::string CpfFuncionarios[3] = {"21774234572", "30377371661", "43966321778"};
  std::string EmailFuncionarios[2] = {"emailforwork@gmail.com", "StarlightGathering@gmail.com"};




/*-----------------Criando Listas de Log------------------*/
	std::list<LogEscrita> _filaLogEscrita;

	std::list<LogLeitura> _filaLogLeitura;

	std::list<LogErro> _filaLogErros;
  
  
	Registro registroGeral(chefe);

  /* ---------------------Primeiro Login ------------------------------*/

	std::cout << std::endl << "------------------- Primeiro Login --------------------" << std::endl;
  
  Login* login= Login::getInstance(&chefe);
  Usuario* user = login -> getUsuario();
  std::cout << "Endereco do Login: " << login << std::endl << "Usuario logado no momento: "<< user -> getNome() << std::endl;
  
	/*------------------------------Cadastro de Clientes--------------------------*/

	std::cout << std::endl << " ----------Cadastro de Clientes---------" << std::endl
	<< std::endl <<" + Cadastro do Cliente Fisico (com CPF correto): " << std::endl << std::endl ;

		_filaLogEscrita.push_back(registroGeral.cadastrarCliente(NomesPessoasFisicas[0], CPFSCadastro[1], true, ends[0], Telefones[0], Email[0], login -> getUsuario() -> getPermissao(), *(login -> getUsuario()), datas[0]));

	std::cout << "+ Cadastro de Clientes Juridicos (com CNPJ's corretos): " << std::endl << std::endl;

	_filaLogEscrita.push_back(registroGeral.cadastrarCliente(NomesPessoasJuridicas[0], CNPJSCadastro[1], false, ends[1], Telefones[1], Email[1], login -> getUsuario() -> getPermissao(), *(login -> getUsuario()), datas[1]));
	_filaLogEscrita.push_back(registroGeral.cadastrarCliente(NomesPessoasJuridicas[1], CNPJSCadastro[2], false, ends[2], Telefones[2], Email[2], login -> getUsuario() -> getPermissao(), *(login -> getUsuario()), datas[2]));

	std::cout << "+ Cadastro de Cliente Fisico e Juridico com credenciais invalidas: " << std::endl << std::endl;

	_filaLogEscrita.push_back(registroGeral.cadastrarCliente(NomesPessoasFisicas[1], CPFSCadastro[0], true, ends[3], Telefones[3], Email[3], login -> getUsuario() -> getPermissao(), *(login -> getUsuario()), datas[3]));
	_filaLogEscrita.push_back(registroGeral.cadastrarCliente(NomesPessoasJuridicas[3], CNPJSCadastro[0], false, ends[4], Telefones[4], Email[4], login -> getUsuario() -> getPermissao(), *(login -> getUsuario()), datas[4]));

	/* --------------------- Cadastro de Funcionarios ------------------------------*/

	std::cout << std::endl << "------------------- Cadastro de Funcionarios --------------------" << std::endl;

	std::cout << "+ Cadastro de Eletricista: " << std::endl << std::endl;
			_filaLogEscrita.push_back(registroGeral.cadastrarFuncionario(NomesFuncionarios[0], CpfFuncionarios[0], EmailFuncionarios[0], false, login -> getUsuario() -> getPermissao(), *(login -> getUsuario()), datas[5]));

	std::cout << "+ Cadastro de Leiturista: " << std::endl << std::endl;

	_filaLogEscrita.push_back(registroGeral.cadastrarFuncionario(NomesFuncionarios[1], CpfFuncionarios[1], EmailFuncionarios[1], true, login -> getUsuario() -> getPermissao(), *(login -> getUsuario()), datas[6]));


	/* --------------------- Cadastro de Unidades Consumidoras ------------------------------*/

	std::cout << std::endl << "------------------- Cadastro de Unidades consumidoras --------------------" << std::endl;
	//ATENCAO!! A REGRA DE NEGOCIO É CHECADA NO MOMENTO DE LIGAR A UNIDADE CONSUMIDORA, E NÃO NO CADASTRO!!
	PessoaFisica* clienteFisicoNovaUC;
	PessoaJuridica* clienteJuridicoUmNovaUC;
	PessoaJuridica* clienteJuridicoDoisNovaUC;

	clienteFisicoNovaUC = registroGeral.clienteFisico(CPFSCadastro[1]);
	clienteJuridicoUmNovaUC = registroGeral.clienteJuridico(CNPJSCadastro[1]);
	clienteJuridicoDoisNovaUC = registroGeral.clienteJuridico(CNPJSCadastro[2]);

	std::cout << "+ Cadastro de Unidades Consumidoras para o Cliente Fisico: " << std::endl << std::endl;

	_filaLogEscrita.push_back(clienteFisicoNovaUC -> adicionarUC(1, endsUC[0], login -> getUsuario() -> getPermissao(), numInst, *(login -> getUsuario()), datas[7]));
	numInst ++;

	std::cout << "+ Cadastro de Unidades Consumidoras para os Clientes Juridicos: " << std::endl << std::endl;

	_filaLogEscrita.push_back(clienteJuridicoUmNovaUC -> adicionarUC(3, endsUC[1], login -> getUsuario() -> getPermissao(), numInst, *(login -> getUsuario()), datas[8]));
	numInst++;
	_filaLogEscrita.push_back(clienteJuridicoDoisNovaUC -> adicionarUC(4, endsUC[2], login -> getUsuario() -> getPermissao(), numInst, *(login -> getUsuario()), datas[9]));
	numInst++;

	std::cout << "+ Mostrando todas as Unidades Consumidoras cadastradas: " << std::endl << std::endl;

	_filaLogLeitura.push_back(clienteFisicoNovaUC ->listarUCS(*(login -> getUsuario()), datas[10]));
	_filaLogLeitura.push_back(clienteJuridicoUmNovaUC ->listarUCS(*(login -> getUsuario()), datas[11]));
	_filaLogLeitura.push_back(clienteJuridicoDoisNovaUC ->listarUCS(*(login -> getUsuario()), datas[12]));


	/* --------------------- Passagem de Servicos para os Funcionarios ------------------------------*/

	/*-----------------Criando Serviços------------------*/

	Medicao med1(0, clienteFisicoNovaUC, 0), med2(0, clienteJuridicoUmNovaUC, 0), med3(0, clienteJuridicoDoisNovaUC, 0);
	Medicao _filaMedicao[3] = {med1, med2, med3};
  
	Ligacao lig1(true, 0, clienteFisicoNovaUC, 4), lig2(true, 0, clienteJuridicoUmNovaUC, 4), lig3(true, 0, clienteJuridicoDoisNovaUC, 4);
	Ligacao _filaLigacao[3] = {lig1, lig2, lig3};
  
  float leituras[6] = {1000, 2563, 2014, 302, 240, 5263};

	Leiturista* funcionarioAtivoL = registroGeral.leiturista(CpfFuncionarios[1]);
	Eletricista* funcionarioAtivoE = registroGeral.eletricista(CpfFuncionarios[0]);

	std::cout << std::endl << "------------------- Passagem de Servicos para os Funcionarios --------------------" << std::endl;

	for (int i = 0; i < 3; i++)
	{
		_filaLogEscrita.push_back(funcionarioAtivoE ->registraServico(&(_filaLigacao[i]), login -> getUsuario() -> getPermissao(), datas[13 + i],  *(login -> getUsuario()), datas[16+i]));
	}

	for (int i = 0; i < 3; i++)
	{
		_filaLogEscrita.push_back(funcionarioAtivoL ->registraServico(&(_filaMedicao[i]), login -> getUsuario() -> getPermissao(), datas[13 + i],  *(login -> getUsuario()), datas[19+i]));
	}

	std::cout << std::endl << " + Tentando adicionar um servico de um leiturista para um eletricista" << std::endl;

	_filaLogEscrita.push_back(funcionarioAtivoE -> registraServico(&(_filaMedicao[0]), login -> getUsuario() -> getPermissao(), datas[1],  *(login -> getUsuario()), datas[0]));


	/* --------------------- Segundo Login ------------------------------*/

	std::cout << std::endl << "------------------- Segundo Login --------------------" << std::endl;

	login -> atualizaUsuario(registroGeral.eletricista(CpfFuncionarios[0]));
	user = login -> getUsuario();

	std::cout << "Endereco do Login: " << login << std::endl << "Usuario logado no momento: "<< user -> getNome() << std::endl;

	/* --------------------- Ativando Unidades Consumidoras ------------------------------*/

	std::cout << std::endl << "------------------- Ativando Unidades Consumidoras --------------------" << std::endl;

	std::cout << "+ Imprimindo servicos planejados: " << std::endl << std::endl;

	_filaLogLeitura.push_back(funcionarioAtivoE -> printFila(*(login -> getUsuario()), datas[2]));

	std::cout << "+ Unidades Consumidoras seguindo a regra de negocio: " << std::endl << std::endl;

		_filaLogEscrita.push_back(funcionarioAtivoE -> realizaServico(0, login -> getUsuario() -> getPermissao(), datas[13], *(login -> getUsuario()), datas[20], "BT", 500));
		_filaLogEscrita.push_back(funcionarioAtivoE -> realizaServico(1, login -> getUsuario() -> getPermissao(), datas[14], *(login -> getUsuario()), datas[21], "BT", 500));


	std::cout << "+ Unidade Consumidora que nao segue a regra de negocio: " << std::endl << std::endl;

	_filaLogEscrita.push_back(funcionarioAtivoE -> realizaServico(2, login -> getUsuario() -> getPermissao(), datas[2], *(login -> getUsuario()), datas[22], "AT", 500));

	std::cout << "+ Imprimindo servicos feitos: " << std::endl << std::endl;

	_filaLogLeitura.push_back(funcionarioAtivoE -> printServicosFeitos(*(login -> getUsuario()), datas[2]));


	/* --------------------- Terceiro Login ------------------------------*/

	std::cout << std::endl << "------------------- Terceiro Login --------------------" << std::endl;

	login -> atualizaUsuario(registroGeral.leiturista(CpfFuncionarios[1]));
	user = login -> getUsuario();

	std::cout << "Endereco do Login: " << login << std::endl << "Usuario logado no momento: "<< user -> getNome() << std::endl;

	/* --------------------- Realizando Medicoes ------------------------------*/

	std::cout << std::endl << "------------------- Realizando Medicoes --------------------" << std::endl;

	std::cout << "+ Medicoes Base: " << std::endl << std::endl;

	_filaLogEscrita.push_back(funcionarioAtivoL -> realizaServico(0, leituras[0], login -> getUsuario() -> getPermissao(), datas[13], *(login -> getUsuario()), datas[9]));
	_filaLogEscrita.push_back(funcionarioAtivoL -> realizaServico(1, leituras[1], login -> getUsuario() -> getPermissao(), datas[14], *(login -> getUsuario()), datas[9]));

	std::cout << "+ Adicionando dias de atraso: " << std::endl << std::endl << "Fatura antes: " << std::endl;

	UnidadeConsumidora* UCClienteFisico = clienteFisicoNovaUC -> getUC(0);
	Fatura* FaturaClienteFisico = UCClienteFisico -> getFatura(0);

	FaturaClienteFisico -> printFatura();

	std::cout << std::endl << "Adicionando 15 dias de atraso ao Cliente Fisico." << std::endl;

	FaturaClienteFisico -> adicionaDiasAtraso(15, login -> getUsuario() -> getPermissao());

	FaturaClienteFisico -> printFatura();

	std::cout << std::endl << "Colocando ambos clientes com 30 dias de atrasdo no total. Taxa mensal de: 0.01." << std::endl;

	FaturaClienteFisico -> adicionaDiasAtraso(30, login -> getUsuario() -> getPermissao());

	FaturaClienteFisico -> printFatura();

	std::cout << std::endl << "+ Tentando pagar uma fatura: " << std::endl << std::endl;

	_filaLogEscrita.push_back(clienteJuridicoUmNovaUC ->pagarFaturas(0, 0, login -> getUsuario() -> getPermissao(), *(login -> getUsuario()), datas[7]));

	/* --------------------- Impressao de Logs ------------------------------*/

	std::cout << std::endl << "------------------- Impressao de Logs --------------------" << std::endl;

	for (std::list<LogEscrita>::iterator it = _filaLogEscrita.begin(); it != _filaLogEscrita.end(); it++)
	{
		it -> printLog();
	}

	for (std::list<LogLeitura>::iterator it = _filaLogLeitura.begin(); it != _filaLogLeitura.end(); it++)
	{
		it -> printLog();
	}

	_filaLogErros = clienteJuridicoUmNovaUC -> getListaErro();

	for (std::list<LogErro>::iterator it = _filaLogErros.begin(); it != _filaLogErros.end(); it++)
	{
		it -> printLog();
	}
	
	

	std::cout << std::endl << "===================== Fim dos Testes ======================= " << std::endl;

	return 0;
}


//g++ Cliente.cpp Data.cpp Desligamento.cpp Erro.cpp Eletricista.cpp Endereco.cpp  Fatura.cpp Formato.cpp Funcionario.cpp Leiturista.cpp LG.cpp Ligacao.cpp Log.cpp LogErro.cpp LogEscrita.cpp Login.cpp LogLeitura.cpp main.cpp Medicao.cpp Permissao.cpp PessoaFisica.cpp PessoaJuridica.cpp Registro.cpp Servico.cpp TMedidor.cpp UC.cpp Usuario.cpp -o cemig