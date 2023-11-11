#ifndef CARTAS_H
#define CARTAS_H
#include "personagem.h"

// Definir a estrutura de uma carta
typedef struct {
char nome[50];
int ataque=0, defesa=0, energia=0, cura=0, buff=0;
} Carta;

// Função para criar uma carta
Carta criarcarta(const char *nome, int ataque, int defesa, int energia, int cura, int buff) {
    Carta carta;
    strcpy(carta.nome, nome);

    carta.ataque = ataque;
    carta.defesa = defesa;
    carta.energia = energia;
    carta.cura= cura;
    carta.buff=buff;
return carta;
}

// Função para exibir uma carta
void exibirCarta(const Carta *e) {
    printf("Nome: %s\n", e->nome);
    if(e->ataque>0) printf("Ataque: %d\n", e->ataque);
    if(e->defesa>0)printf("Defesa: %d\n", e->defesa);
    printf("Custo de energia: %d\n", e->energia);
    if(e->buff>0)printf("Buff: %d\n", e->buff);
    if(e->cura>0)printf("Cura: %d\n", e->cura);
    printf("\n");
}

void exibir_mao(Carta mao[5]) {
    for(int i=0; i<5; i++){
        exibirCarta(&mao[i]);  
    }
}

#endif