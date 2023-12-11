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

Monstro BancoDeDados(int ID) {
	Monstro monstro;
    switch (ID) {
        case 1:
            monstro = CriarMonstro("Saibaman", 20);
            CriarAcao(&monstro, "Golpe", 3); 
            CriarAcao(&monstro, "Golpe", 3);
            CriarAcao(&monstro, "Rajada de ki",4);
            CriarAcao(&monstro, "Auto-explosao", 20);
			break;
        case 2:
            monstro = CriarMonstro("Nappa", 60); 
            CriarAcao(&monstro, "Soco desvastador", 4); 
            CriarAcao(&monstro, "Soco desvastador", 4); 
            CriarAcao(&monstro, "Bafo de Ki", 10);
            CriarAcao(&monstro, "Soco desvastador", 4); 
            CriarAcao(&monstro, "Soco desvastador", 4); 
            CriarAcao(&monstro, "Explosao", 13);
            break;
        case 3:
            monstro = CriarMonstro("Zarbon", 80);  
            CriarAcao(&monstro, "Golpe elegante", 5); 
            CriarAcao(&monstro, "Golpe elegante", 5); 
            CriarAcao(&monstro, "Golpe elegante", 5); 
            CriarAcao(&monstro, "Disparo elegante", 12);
            CriarAcao(&monstro, "Golpe elegante", 5); 
            CriarAcao(&monstro, "Multiplos chutes", 10);
            break;
        case 4:
        monstro = CriarMonstro("Recoome", 100);
            CriarAcao(&monstro, "Chute Recoome", 5);
            CriarAcao(&monstro, "Chute Recoome", 5);
            CriarAcao(&monstro, "Mega-soco", 12);
            CriarAcao(&monstro, "Chute Recoome", 5);
            CriarAcao(&monstro, "Golpe destruidor Recoome", 18);
             
            break;
        case 5:
            monstro = CriarMonstro("Androide 16", 100); 
            CriarAcao(&monstro, "Golpe", 7); 
            CriarAcao(&monstro, "Golpe", 7);
            CriarAcao(&monstro, "Soco voador", 12);
            CriarAcao(&monstro, "Golpe", 7);
            CriarAcao(&monstro, "Golpe", 7);
            CriarAcao(&monstro, "Hell's Flash ", 20);
            break;
        case 6://aprovado
            monstro = CriarMonstro("Burter", 100); 
            CriarAcao(&monstro, "Chute Veloz", 5); 
            CriarAcao(&monstro, "Contra-golpe veloz", 5); 
            CriarAcao(&monstro, "Soco Veloz", 5); 
            CriarAcao(&monstro, "Furacao azul", 13);
            break;
        case 7://
            monstro = CriarMonstro("Jeice", 100); 
            CriarAcao(&monstro, "Soco", 5);
            CriarAcao(&monstro, "Chute", 5);
            CriarAcao(&monstro, "Rajada de soco", 7);
            CriarAcao(&monstro, "Chute", 5);
            CriarAcao(&monstro, "Soco", 5);
            CriarAcao(&monstro, "Raio vermelho destruidor", 14);
            break;
        case 8:
            monstro = CriarMonstro("Capitao Ginyu", 100);
            CriarAcao(&monstro, "Galaxy Dynamite", 6);
            CriarAcao(&monstro, "Galaxy Dynamite", 6);
            CriarAcao(&monstro, "Galaxy Dynamite", 6);
            CriarAcao(&monstro, "Milky Cannon", 16);
            CriarAcao(&monstro, "Galaxy Dynamite", 6);
            CriarAcao(&monstro, "Ginyu Smash", 9);
            break;
        case 9:
            monstro = CriarMonstro("Guldo", 70); 
            CriarAcao(&monstro, "Soco com Tempo parado", 4);
            CriarAcao(&monstro, "Soco com Tempo parado", 4);
            CriarAcao(&monstro, "Soco com Tempo parado", 4);
            CriarAcao(&monstro, "Estacas da morte", 10);
            break;
        case 10:
            monstro = CriarMonstro("Cell.jr", 80);
            CriarAcao(&monstro, "Golpe", 4);
            CriarAcao(&monstro, "Golpe", 4);
            CriarAcao(&monstro, " Kiko-ho", 10);
            CriarAcao(&monstro, "Golpe", 4);
            CriarAcao(&monstro, "Roga Fufu Ken", 6);
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
            CriarAcao(&Boss, "Golpe Perfeito", 9); 
            CriarAcao(&Boss, "Sugar Energia Vital", 8);
            CriarAcao(&Boss, "Sequencia De Golpes Perfeito", 9);
            CriarAcao(&Boss, "Kamehameha Perfeito", 20);
            CriarAcao(&Boss, "Makankosappo", 12);
            CriarAcao(&Boss, "Esfera De Ki", 9);
            CriarAcao(&Boss, "Disco Da Morte", 10);
            
            break;
    case 2:
        Boss = CriarMonstro("Freeza", 150); 
            CriarAcao(&Boss, "Golpe", 7); 
            CriarAcao(&Boss, "Enforcar Com Cauda", 8);
            CriarAcao(&Boss, "Corte psiquico", 12);
            CriarAcao(&Boss, "Raio Da Morte", 15);
            CriarAcao(&Boss, "Supernova", 25);
            break;
    case 3:
    Boss = CriarMonstro("Kid boo", 200); 
            CriarAcao(&Boss, "Super Soco", 7);
            CriarAcao(&Boss, "Super Chute Majin", 7);
            CriarAcao(&Boss, "Onda De Ki", 8);
            CriarAcao(&Boss, "Kamehameha Majin", 12);
            CriarAcao(&Boss, "Bola De Choque", 18);
            CriarAcao(&Boss, "Chuva De Energia", 25);
            CriarAcao(&Boss, "Explosão Planetária", 30);
            break;
    default:
    printf("Esse monstro nao existe!!\n");
        break;
    }
    return Boss;
}


#endif
