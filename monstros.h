#ifndef MONSTROS_H
#define MONSTROS_H
#include "deck.h"
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
            CriarAcao(&monstro, "Golpe", 4); 
            CriarAcao(&monstro, "Bafo de Ki", 10);
            CriarAcao(&monstro, "Explosao", 13);
            break;
        case 3:
            monstro = CriarMonstro("Zarbon", 100); 
            CriarAcao(&monstro, "Golpe", 5); 
            CriarAcao(&monstro, "Disparo elegante", 12);
            CriarAcao(&monstro, "Multiplos chutes", 10);
            break;
        case 4:
        monstro = CriarMonstro("Recoome", 100); 
            CriarAcao(&monstro, "Golpe", 5); 
            CriarAcao(&monstro, "Golpe destruidor Recoome", 18);
             CriarAcao(&monstro, "Mega-soco", 12);
            break;
        case 5:
            monstro = CriarMonstro("Androide 16", 100); 
            CriarAcao(&monstro, "Golpe", 7); 
            CriarAcao(&monstro, "Soco voador", 12);
            CriarAcao(&monstro, "Hell's Flash ", 20);
            break;
        case 6:
            monstro = CriarMonstro("Burter", 100); 
            CriarAcao(&monstro, "Golpe", 5); 
            CriarAcao(&monstro, "Furacao azul", 13);
            break;
        case 7:
            monstro = CriarMonstro("Jeice", 100); 
            CriarAcao(&monstro, "Golpe", 5); 
            CriarAcao(&monstro, "Raio vermelho destruidor", 14);
            break;
        case 8:
            monstro = CriarMonstro("Capitao Ginyu", 100); 
            CriarAcao(&monstro, "Golpe", 6); 
            CriarAcao(&monstro, "Esfera omega", 16);
            CriarAcao(&monstro, "Rajada de disparos", 9);
            break;
        case 9:
            monstro = CriarMonstro("Guldo", 100); 
            CriarAcao(&monstro, "Golpe", 4); 
            CriarAcao(&monstro, "Estacas da morte", 10);
            break;
        default:
            cout << "Opção inválida" << endl;
            break;
    }
	return monstro;
}

Monstro BancoBoss(int id){
    Monstro Boss;
    switch (id)
    {
    case 1:
        Boss = CriarMonstro("Cell Perfeito", 180); 
            CriarAcao(&Boss, "Golpe", 9); 
            CriarAcao(&Boss, "Kamehameha Perfeito", 20);
            CriarAcao(&Boss, "Makankosappo", 12);
            CriarAcao(&Boss, "Kienzan", 10);
            CriarAcao(&Boss, "Sugar energia vital", 8);
            break;
    case 2:
        Boss = CriarMonstro("Freza", 150); 
            CriarAcao(&Boss, "Golpe", 7); 
            CriarAcao(&Boss, "Enforcar com cauda", 8);
            CriarAcao(&Boss, "Raio da Morte", 15);
            CriarAcao(&Boss, "Supernova", 25);
            break;
    case 3:
    Boss = CriarMonstro("Majin boo", 200); 
            CriarAcao(&Boss, "Golpe", 7); 
            CriarAcao(&Boss, "Onda de Ki", 8);
            CriarAcao(&Boss, "Kamehameha Majin", 12);
            CriarAcao(&Boss, "Bola de Choque", 18);
            CriarAcao(&Boss, "Chuva de energia", 25);
            CriarAcao(&Boss, "Explosão Planetária", 30);
    default:
    printf("Esse monstro nao existe!!\n");
        break;
    }
    return Boss;
}

#endif

