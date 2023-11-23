#include "mao.h"

void descarta(Mao **lista, int tamanho, tp_pilha *descarte) {
    Mao *atu;
    atu = *lista;
    Carta carta; 

    int i = 0;

    while (atu != NULL && i < tamanho) { 
        carta = atu->info; 
        push(descarte,carta); // joga a carta no descarte
        remove_elemento_posicao(lista, 0); // tira a carta da mao
        atu = atu->prox;
        i++;
    }
}


int main() { 

    tp_pilha descarte;
    tp_pilha deck;
  
    Carta carta=criarcarta("Soco",4,0,1,0,0);
    Mao *mao = inicializa_mao();

  
    inicializa_pilha(&descarte); // para depois printar o descarte, basta adicionar depois da luta imprime_pilha(&descarte);
    inicializa_pilha(&deck);
    criar_deck(&deck);
    embaralhar_pilha(&deck);


    // mao_insere_no_fim(&mao, carta);
    // adicionar_carta(mao, &deck, 4);

    // mostra_mao(mao);
    // descarta(&mao, tamanho_mao(mao), &descarte);
    // printf("---------------");
    printf("fjpaojfoahjfoasofapfjaofhoahfjo");
    imprime_pilha(deck);
    printf("fjpaojfoahjfoasofapfjaofhoahfjo");
    imprime_pilha(descarte);
    printf("fjpaojfoahjfoasofapfjaofhoahfjo");
    printf("fjpaojfoahjfoasofapfjaofhoahfjo");
    imprime_pilha(deck);
    printf("fjpaojfoahjfoasofapfjaofhoahfjo");
    imprime_pilha(descarte);
    printf("fjpaojfoahjfoasofapfjaofhoahfjo");


    return 0;
}
