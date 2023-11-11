#ifndef MAO_H
#define MAO_H
#include "deck.h"
#define MAX_MAO 10

// struct da mao
typedef struct {
    Carta cartas[MAX_MAO];
    int tamanho;
} Mao;

//cria uma mao sem nada
Mao criar_mao() {
    Mao mao;
    mao.tamanho = 0;
    return mao;
}

// Função para adicionar uma carta à mão do jogador
void adicionar_carta(Mao *mao, tp_pilha *deck, int Qnt) { // Mao, o deck, e a quantidade de cartas a cavar
    Carta Carta;
    if(mao->tamanho < MAX_MAO) {
        for(int i=0; i<Qnt; i++){
            pop(deck, &Carta); // retira a carta do topo do deck 
            mao->cartas[mao->tamanho] = Carta; // acessa a struct mao, aponta pra array cartas e joga la
            mao->tamanho++;  // "aumenta" o tamanho da array, para percorrer a array
        }              
    } else {
        printf("Mao cheia\n");
    }
}

// Função para adicionar uma carta ao descarte
void adicionar_ao_descarte(Descarte *descarte, Carta carta) { 
    if (descarte->topo < MAX- 1) {
        descarte->topo++;
        descarte->cartas[descarte->topo] = carta;
    } else {
        printf("O descarte está cheio. O deck será embaralhado.\n");
        // Implemente a lógica para embaralhar o descarte e colocá-lo de volta no deck aqui
        // Neste exemplo, apenas esvaziamos o descarte.
        descarte->topo = -1;
    }
}

// Função para exibir a mão do jogador
void mostrar_mao(Mao mao) { 
    printf("Sua mão:\n");
    for (int i = 0; i < mao.tamanho; i++) {
        printf("%d. %s\n", i + 1, mao.cartas[i].nome);
    }
}

// basicamente e so um scanf grande
int escolher_carta(Mao *mao) {
    int escolha;
    printf("Escolha uma carta para jogar (1-10): ");
    scanf("%d", &escolha);
    if (escolha >= 1 && escolha <= mao->tamanho) {
        return escolha - 1; // Retorna o índice da carta escolhida
    } else {
        printf("Escolha inválida. Tente novamente.\n");
        return -1; // Retorna -1 para indicar uma escolha inválida
    }
}


// Atualize a função jogar_carta para adicionar a carta ao descarte
void jogar_carta(Mao *mao, tp_pilha *deck, Descarte *descarte) {
    int escolha = escolher_carta(mao);
    if (escolha >= 0) {
        printf("Você jogou: %s\n", mao->cartas[escolha].nome);

        // Adicione a carta ao descarte em vez de devolvê-la ao deck
        adicionar_ao_descarte(descarte, mao->cartas[escolha]);

        // Remova a carta da mão do jogador
        for (int i = escolha; i < mao->tamanho - 1; i++) {
            mao->cartas[i] = mao->cartas[i + 1];
        }
        mao->tamanho--;
    }
}


#endif

