#ifndef LISTASE_H
#define LISTASE_H
#include "monstros.h"

typedef struct no_mao {
    Carta info;
    struct no_mao *prox;
} Mao;

// Inicialização da lista
Mao *inicializa_mao() {
    return NULL;
}

int mao_vazia(Mao *lista) {
    if (lista == NULL)
        return 1;
    return 0;
}

Mao *aloc_mao() {
    Mao *novo_no;
    novo_no = (Mao *)malloc(sizeof(Mao));
    return novo_no;
}


int mao_insere_no_fim(Mao **lista, Carta e) {
    Mao *novo_no, *atu;
    novo_no = aloc_mao();
    if (novo_no == NULL)
        return 0;
    novo_no->info = e;
    novo_no->prox = NULL;
    if (mao_vazia(*lista)) {
        *lista = novo_no;
    } else {
        atu = *lista;
        while (atu->prox != NULL) {
            atu = atu->prox;
        }
        atu->prox = novo_no;
    }
    return 1;
}

void mostra_mao(Mao *lista) {
    Mao *atu;
    atu = lista;
    printf("----------------------\n");
    while (atu != NULL) { 
        exibirCarta(&atu->info);
        printf("----------------------\n");
        atu = atu->prox;
    }
}

int remove_mao(Mao **lista, Carta e) {
    Mao *ant, *atu;
    atu = *lista;
    ant = NULL;
    while ((atu != NULL) && (memcmp(&(atu->info), &e, sizeof(Carta)) != 0)) {
        ant = atu;
        atu = atu->prox;
    }
    if (atu == NULL)
        return 0;
    if (ant == NULL) {
        *lista = atu->prox;
    } else {
        ant->prox = atu->prox;
    }
    free(atu);
    atu = NULL;
    return 1;
}

Mao *busca_mao(Mao *lista, Carta e) {
    Mao *atu;
    atu = lista;
    while ((atu != NULL) && (memcmp(&(atu->info), &e, sizeof(Carta)) != 0)) {
        atu = atu->prox;
    }
    if (atu == NULL)
        return NULL;
    return atu;
}

int tamanho_mao(Mao *lista) {
    int cont = 0;
    Mao *atu;
    atu = lista;
    while (atu != NULL) {
        cont++;
        atu = atu->prox;
    }
    return cont;
}

void destroi_mao(Mao **lista) {
    Mao *atu;
    atu = *lista;
    while (atu != NULL) {
        *lista = atu->prox;
        free(atu);
        atu = *lista;
    }
    *lista = NULL;
}

// Remoção de Elemento na Posição
int remove_elemento_posicao(Mao **lista, int posicao) {
    if (mao_vazia(*lista) || posicao < 0) {
        return 0; // Não é possível remover de lista vazia ou posição inválida.
    }

    if (posicao == 0) {
        Mao *temp = *lista;
        *lista = (*lista)->prox;
        free(temp);
        return 1; // Remoção bem-sucedida.
    }

    Mao *anterior = NULL;
    Mao *atu = *lista;
    int contador = 0;

    while (atu != NULL && contador < posicao) {
        anterior = atu;
        atu = atu->prox;
        contador++;
    }

    if (atu == NULL) {
        return 0; // Posição inválida.
    }

    anterior->prox = atu->prox;
    free(atu);

    return 1; // Remoção bem-sucedida.
}

void mostrar_mao_posicao(Mao *lista, int posicao) {

    // atu aponta pra carta na posição q passo como parametro
    int contador = 0;
    Mao *atu = lista;
    while (atu != NULL && contador < posicao) {
        atu = atu->prox;
        contador++;
    }

    if (atu != NULL) {
        printf("Carta na posição %d: ", posicao + 1);
        exibirCarta(&atu->info);
    } else {
        printf("Posição inválida.\n");
    }
}

// basicamente e so um scanf grande
int escolher_carta(Mao *lista) {
    int tamanho=tamanho_mao(lista), escolha;
    printf("Escolha uma carta para jogar ( 1 - %d) 0 para encerrar turno : ", tamanho); 

    scanf("%d", &escolha);
    if (escolha >= 0 && escolha <= tamanho) {
        return escolha - 1; // Retorna o índice da carta escolhida
    } else {
        printf("Escolha invalida. Tente novamente.\n");
        return -1; // Retorna -1 para indicar uma escolha inválida
    }
}

// Função para adicionar uma carta à mão do jogador
void adicionar_carta(Mao **mao, tp_pilha *deck, int Qnt) { // Mao, o deck, e a quantidade de cartas a cavar
    Carta Carta;
    for(int i=0; i<Qnt; i++){
        pop(deck, &Carta); // retira a carta do topo do deck 
        mao_insere_no_fim(mao, Carta); // joga no final da mao
    }              
}

void joga_carta(Mao **lista, int posicao, tp_pilha *descarte, Monstro *monstro, personagem *personagem, FILE **arqv) {
    // atu aponta pra carta na posição q passo como parametro
    // para acessar a carta usa-se atu->info
    int contador = 0;
    Mao *atu ;
    atu = *lista;
    while (atu != NULL && contador < posicao) { // loop para igualar contador a posicao, assim fazendo atu apontar pra posição que quer
        atu = atu->prox;
        contador++;
    }

    if (atu != NULL) {
        Carta carta = atu->info; // faz uma "copia" da carta
        fprintf(*arqv, "%s\n", carta.nome);
        if(carta.energia<=personagem->ki){
            printf("%s \n", carta.nome);
            monstro->vida-=carta.ataque;
            personagem->def+=carta.defesa;
            personagem->ki-=carta.energia;
            push(descarte,carta); // joga a carta no descarte
            remove_elemento_posicao(lista, contador); // tira a carta da mao
        }else{
            printf("----- KI INSUFICIENTE ------\n");
            Sleep(2000);
        }
    }
}

void descartar(Mao **lista, tp_pilha *descarte, int posicao) {
    // atu aponta pra carta na posição q passo como parametro
    // para acessar a carta usa-se atu->info
    
    int contador = 0;
    Mao *atu ;
    atu = *lista;

    while (atu != NULL && contador < posicao) { // loop para igualar contador a posicao, assim fazendo atu apontar pra posição que quer
        atu = atu->prox;
        contador++;
    }

    if (atu != NULL) {

        Carta carta = atu->info; // faz uma "copia" da carta
        
        push(descarte,carta); // joga a carta no descarte
        remove_elemento_posicao(lista, contador); // tira a carta da mao
        
    }
}






#endif