#ifndef personagem_h
#define personagem_h

#include<iostream>
#include<Windows.h>
#include<Time.h>
#include<stdlib.h>
#include <locale.h>
#include <string.h>
#include "mapa.h"

using namespace std;

typedef struct{
    char nome[15];
    int vida = 0, ki_maximo, ki = 0, def = 0, gold = 0, n = 0;
} personagem;

void definir_personagem(personagem *j){
    int p = 0, continuar = 0;
    char raca[15];
    setlocale(LC_ALL, "Portuguese");
    do{
        system("cls");
        printf("Crie seu personagem:\n");

        printf("|Sayajin(1)|   |Humano(2)|   |Arcosia(3)|   |Majin(4)|   |Namekuseijin(5)|\nDigite o numero referente ao seu personagem: ");
        p = 0;
        scanf("%d", &p);
        fflush(stdin);

        switch (p){
        case 1: 
            strcpy(raca, "Sayajin");
            printf("\"Sayajins sao combatentes natos!! Possuem aparencia humana com cabelos pretos e capacidade de se transformar para aumentar seu poder.\"\n");
            printf("Habilidade: transformacoes duram ate o final do combate\n");
            printf("Vida:80   Ki:4   Gold:80\n");
            printf("Deseja continuar? digite \"1\" para sim e qualquer outro valor para voltar\n");
            scanf(" %d", &continuar);

            break;
        case 2:
            strcpy(raca, "Humano");
            printf("\"Humanos sao uma raca comum e diversificada que habita varios planetas, eles nao possuem habilidades especiais como outras racas, mas sao notaveis por sua tenacidade, inteligencia e espirito de luta\"\n");
            printf("Habilidade: recebe mais 2 tecnicas novas a cada combate.\n");
            printf("Vida:100   Ki:3   Gold:100\n");
            printf("Deseja continuar? digite \"1\" para sim e qualquer outro valor para voltar\n");
            scanf(" %d", &continuar);
            break;
        case 3:
            strcpy(raca, "Arcosiano");
            printf("\"os Arcosianos, tambem conhecidos como Frost Demons, sao uma raca alienigena extremamente poderosa. Possuem forma humanoide com pele colorida, tendem a ser crueis\"\n");
            printf("Vida:75   Ki:3   Gold:80\n");
            printf("Habilidade: 10%% de chance de desviar do golpe.\n");
            printf("Deseja continuar? digite \"1\" para sim e qualquer outro valor para voltar\n");
            scanf(" %d", &continuar);
            break;
        case 4:
            strcpy(raca, "Majin");
            printf("\"Os Majins sao uma raca de seres magicos tem habilidades regenerativas e a capacidade de absorver e transformar outros seres, ganhando suas habilidades.\"\n");
            printf("Vida:90   Ki:3   Gold:120\n");
            printf("Habilidade: Absorve inimigos derrotados e rouba suas tecnicas.\n");
            printf("Deseja continuar? digite \"1\" para sim e qualquer outro valor para voltar\n");
            scanf(" %d", &continuar);
            break;
        case 5:
            strcpy(raca, "Namekuseijin");
            printf("\"Os Namekuseijins sao uma raca alienigena, originaria do planeta Namek. Possuem aparencia humanoide com pele verde, antenas na cabeca e habilidades unicas de regeneracao se curarando rapidamente.\"\n");
            printf("Vida:110   Ki:3   Gold:100\n");
            printf("Habilidade: cura 10 de vida ao final do combate");
            printf("Deseja continuar? digite \"1\" para sim e qualquer outro valor para voltar\n");
            scanf(" %d", &continuar);
            break;
        default:
            printf("Opcao invalida tente novamente\n");
            Sleep(2000);
            continuar = 0;
            system("cls");
            break;
        }
    } while (continuar != 1);

    switch (p){
        case 1:
            j->ki_maximo = 4;
            j->vida = 80;
            j->gold = 80;
            j->n = 1;
            break;
        case 2:
            j->ki_maximo = 3;
            j->vida = 100;
            j->gold = 100;
            j->n = 2;
            break;
        case 3:
            j->ki_maximo = 3;
            j->gold = 80;
            j->vida = 80;
            j->n = 3;
            break;
        case 4:
            j->ki_maximo = 3;
            j->vida = 90;
            j->gold = 120;
            j->n = 4;
            break;
        case 5:
            j->ki_maximo = 3;
            j->vida = 130;
            j->gold = 100;
            j->n = 5;
            break;
    }
    system("cls");
    printf("Legal entao voce escolheu %s, agora escolha o nome de seu personagem:\n", raca);
    scanf(" %s", j->nome);
    printf("\nOla, %s espero que esteja preparado para aventura\n", j->nome);
    system("pause");
    system("cls");
}

void DadosPersonagem(personagem *personagem){
    cout << "-------- " << personagem->nome << " --------" << endl;
    cout << "HP: " << personagem->vida << endl;
    cout << "KI: " << personagem->ki_maximo << endl;
    cout << "DEF: " << personagem->def << endl;
    cout << "GOLD: " << personagem->gold << endl;
}

#endif

