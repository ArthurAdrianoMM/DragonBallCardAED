#ifndef FILA_H
#define FILA_H
#include "pilhastruct.h"

#define MAX_SIZE 10

typedef struct{
	char nome[20];
	int dano;
}Acao;

typedef struct {
    Acao items[MAX_SIZE];
    int ini, fim;
} tp_fila;

// Inicializa a fila.
void inicializa_fila(tp_fila *f) {
    f->ini = f->fim = -1;
}

// Verifica se a fila está vazia.
int fila_vazia(tp_fila *f) {
    return (f->ini == -1);
}

// Verifica se a fila está cheia.
int fila_cheia(tp_fila *f) {
    return ((f->fim + 1) % MAX_SIZE == f->ini);
}

// Insere um elemento na fila.
int insere_fila(tp_fila *f, Acao e) {
    
    if (fila_cheia(f)) {
        printf("A fila está cheia. Não é possível inserir.\n");
        return 0;
    }

    if (fila_vazia(f)) {
        f->ini = f->fim = 0;
    } else {
        f->fim = (f->fim + 1) % MAX_SIZE;
    }

    f->items[f->fim] = e;

    return 1;
}

// Remove um elemento da fila.
int remove_fila(tp_fila *f, Acao *e) {

    if (fila_vazia(f)) {
        printf("A fila está vazia. Não é possível remover.\n");
        return 0;
    }

    *e = f->items[f->ini];

    if (f->ini == f->fim) {
        f->ini = f->fim = -1;
    } else {
        f->ini = (f->ini + 1) % MAX_SIZE;
    }

    return 1;
}

// Imprime os elementos da fila.
void imprime_fila(tp_fila f) {
    Acao e;
    while (!fila_vazia(&f)) {
        remove_fila(&f, &e);
        printf("%s %d\n", e.nome, e.dano);
    }
}

#endif