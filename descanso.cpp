#include "deck.h"

void descanso(tp_pilha *deckaux, int *vida, int nm){
    int escolha;
    printf("Voce encontrou um cabana com um homem de cabelo grisalho deseja falar com ele(digite 1) ou descansar em outro lugar(outro)?\n");
    scanf("%d", &escolha);

    if(escolha==1){
        printf("Ola jovem viajente me chamo marcio rene vou dar uma ajuda na sua jornada despertando seu potencial\n");
        cartas_especiais(nm, deckaux);
        *vida +=15;
    }
    else{
        printf("Voce se afasta e decide descancar em outro lugar\n");
        switch (nm)
        {
        case 1:
            *vida=80;
            break;
        case 2:
            *vida=100;
            break;
        case 3:
            *vida=90;
            break;
        case 4:
            *vida=100;
            break;
        case 5:
            *vida= 120;
            break;
        default:
            break;
        }
    }
    }

//mostra como funciona na main
/*
int main(){
    tp_pilha deck;
    int din=50;
    criar_deck(&deck);

    descanso(&deck, &din, jogador->n); //"jogador->" nao funciona sem a personagem.h 
    printf("Sua vida atual: %d\n", din);
    
}*/