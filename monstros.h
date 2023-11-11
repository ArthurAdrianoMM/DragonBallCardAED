#ifndef MONSTROS_H
#define MONSTROS_H
#include "filastruct.h"
#define TAM_NOME 50

// Defina uma estrutura para representar um monstro
typedef struct{
	char nome[TAM_NOME];
	int vida;
	tp_fila acoes;
}Monstro;

Monstro CriarMonstro(const char *nome, int vida){
	Monstro monstro;
	monstro.vida=vida;
	strncpy(monstro.nome, nome, TAM_NOME);
	inicializa_fila(&monstro.acoes);
	return monstro;
}

//função para criar uma ação
Acao CriarAcao(Monstro *monstro, const char* nome, int dano){
	Acao acao;
	strncpy(acao.nome, nome, TAM_NOME);
	acao.dano = dano;
	insere_fila(&monstro->acoes, acao);
	return acao;	
}

//função para imprimir os dados do monstro
void DadosMonstro(Monstro *monstro){
	using namespace std; /*se nao colocar using namespace std, o vscode fica falando q tem erro, 
		porem ainda assim funciona na main, add por convêniencia pro vscode nao ficar vermelho*/ 
	cout<<"------- "<<monstro->nome<<" -------"<<endl;
    cout<<monstro->vida<<" HP"<<endl;
	cout<<"Ataques: "<<endl;
	imprime_fila(monstro->acoes);
}

void Ataque(Monstro *monstro){
	
}

//funcao para escolher um mosntro dentro de um banco de dados

Monstro BancoDeDados(int ID) {
	Monstro monstro;
    switch (ID) {
        case 1:
            monstro = CriarMonstro("Demonio", 100); 
            CriarAcao(&monstro, "Arranhao", 10); 
            CriarAcao(&monstro, "Mordida", 20); 
			break;
        case 2:
            monstro = CriarMonstro("ZezinhoDaMassa", 100); 
            CriarAcao(&monstro, "Porrada", 10); 
            CriarAcao(&monstro, "Tiro", 20);
            break;
        default:
            cout << "Opção inválida" << endl;
            break;
    }
	return monstro;
}


#endif

