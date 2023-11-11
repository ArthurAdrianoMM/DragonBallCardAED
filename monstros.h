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
            monstro = CriarMonstro("Saibaman", 20); 
            CriarAcao(&monstro, "golpe", 3); 
            CriarAcao(&monstro, "Rajada de ki", 7); 
            CriarAcao(&monstro, "Auto-explosao", 20);
			break;
        case 2:
            monstro = CriarMonstro("Nappa", 60); 
            CriarAcao(&monstro, "Golpe", 7); 
            CriarAcao(&monstro, "Bafo de Ki", 10);
            CriarAcao(&monstro, "Explosao", 15);
            break;
        case 3:
            monstro = CriarMonstro("Zarbon", 100); 
            CriarAcao(&monstro, "Golpe", 7); 
            CriarAcao(&monstro, "Disparo elegante", 15);
            CriarAcao(&monstro, "Rajada de chute", 10);
            break;
        case 4:
            monstro = CriarMonstro("Freza", 100); 
            CriarAcao(&monstro, "Golpe", 7); 
            CriarAcao(&monstro, "Raio da Morte", 15);
            CriarAcao(&monstro, "Supernova", 30);
            break;
        case 5:
            monstro = CriarMonstro("Androide 16", 100); 
            CriarAcao(&monstro, "Golpe", 7); 
            CriarAcao(&monstro, "Soco voador", 15);
            CriarAcao(&monstro, "Hell's Flash ", 30);
            break;
        case 6:
            monstro = CriarMonstro("Cell Perfeito", 120); 
            CriarAcao(&monstro, "Golpe", 9); 
            CriarAcao(&monstro, "Kamehameha Perfeito", 20);
            CriarAcao(&monstro, "Makankosappo", 12);
            CriarAcao(&monstro, "Kienzan", 10);
            break;
        case 7:
            monstro = CriarMonstro("Majin boo", 100); 
            CriarAcao(&monstro, "Golpe", 7); 
            CriarAcao(&monstro, "Chuva de energia", 25);
            CriarAcao(&monstro, "Bola da morte", 30);
            break;
        default:
            cout << "Opção inválida" << endl;
            break;
    }
	return monstro;
}


#endif

