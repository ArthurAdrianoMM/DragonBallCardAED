#ifndef PILHA_H
#define PILHA_H

#include "cartas.h"
#define MAX 100

typedef struct {
int topo;
Carta item[MAX];
} tp_pilha;

void inicializa_pilha(tp_pilha* p) {
p->topo = -1;
}

int pilha_vazia(tp_pilha* p) {
if (p->topo == -1)
return 1;
return 0;
}

int pilha_cheia(tp_pilha* p) {
if (p->topo == MAX - 1)
return 1;
return 0;
}

int push(tp_pilha* p, Carta e) {
if (pilha_cheia(p))
return 0;
p->topo++;
p->item[p->topo] = e;
return 1;
}

int pop(tp_pilha* p, Carta* e) {
if (pilha_vazia(p))
return 0;
*e = p->item[p->topo];
p->topo--;
return 1;
}

int top(tp_pilha* p, Carta* e) {
if (pilha_vazia(p))
return 0;
*e = p->item[p->topo];
return 1;
}

int altura_pilha(tp_pilha* p) {
return p->topo + 1;
}

void imprime_pilha(tp_pilha p) {
Carta e;
printf("\n");
while (!pilha_vazia(&p)) {
pop(&p, &e);
printf("Nome: %s\n", e.nome);
if(e.ataque>0) printf("Ataque: %d\n", e.ataque);
if(e.defesa>0)printf("Defesa: %d\n", e.defesa);
printf("Custo de energia: %d\n", e.energia);
if(e.buff>0)printf("Buff: %d\n", e.buff);
if(e.cura>0)printf("Cura: %d\n", e.cura);
printf("\n");

}
}

void retira_impares(tp_pilha* p) {
tp_pilha p_aux;
inicializa_pilha(&p_aux);
Carta e;

while (!pilha_vazia(p)) {
    pop(p, &e);
    if (e.ataque % 2 == 0) { // Você pode usar qualquer campo da struct para verificar paridade
        push(&p_aux, e);
    }
}
while (!pilha_vazia(&p_aux)) {
    pop(&p_aux, &e);
    push(p, e);
}
}

int compara_pilha(tp_pilha p1, tp_pilha p2) {
Carta e1, e2;
if (altura_pilha(&p1) != altura_pilha(&p2)) {
return 0;
} else {
while (!pilha_vazia(&p1)) {
pop(&p1, &e1);
pop(&p2, &e2);

        if (strcmp(e1.nome, e2.nome) != 0 || e1.ataque != e2.ataque || e1.defesa != e2.defesa ||
            e1.energia != e2.energia || e1.cura != e2.cura || e1.buff != e2.buff) {
            return 0;
        }
    }
    return 1;
}
}

int empilha_pilha(tp_pilha* p1, tp_pilha* p2) {
tp_pilha p_aux;
Carta e;

if (altura_pilha(p1) + altura_pilha(p2) > MAX) {
    return 0;
} else {
    while (!pilha_vazia(p2)) {
        pop(p2, &e);
        push(&p_aux, e);
    }
    while (!pilha_vazia(&p_aux)) {
        pop(&p_aux, &e);
        push(p1, e);
    }
    return 1;
}
}

void embaralhar_pilha(tp_pilha* p) {
    // Inicializa o gerador de números aleatórios com uma semente diferente a cada execução
    srand(time(NULL));
    
    int n = altura_pilha(p);
    
    // Embaralhamento Fisher-Yates
    for (int i = n - 1; i > 0; i--) {
        // Escolhe um índice aleatório entre 0 e i
        int j = rand() % (i + 1);
        
        // Troca as cartas nos índices i e j
        Carta temp = p->item[i];
        p->item[i] = p->item[j];
        p->item[j] = temp;
    }
}


void CartaMao(tp_pilha *p, Carta mao[5]){
    for(int i=0; i<5; i++){
        pop(p, &mao[i]);
    }
}

 
 
#endif