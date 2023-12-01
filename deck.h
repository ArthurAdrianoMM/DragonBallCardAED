#ifndef DECK_H
#define DECK_H
#include "filastruct.h"

void criar_deck(tp_pilha *deck){

    Carta soco,chute, barreira, Kienzan, kamehameha, explosao, barreiraex, finalflash;

    soco=criarcarta("Soco",4,0,1,0,0);
    push(deck, soco);
    push(deck, soco);
    push(deck, soco);

    chute=criarcarta("Chute",5,0,1,0,0);
    push(deck, chute);
    push(deck, chute);

    barreira=criarcarta("Barreira",0,5,1,0,0);
    push(deck, barreira);
    push(deck, barreira);
    push(deck, barreira);

    Kienzan=criarcarta("Kienzan",10,0,2,0,0);
    push(deck, Kienzan);   

    kamehameha=criarcarta("Kamehameha",12,0,2,0,0);
    push(deck, kamehameha);   

    explosao=criarcarta("Explosao de ki",8,0,1,0,0);
    push(deck, explosao); 
    push(deck, explosao); 

    barreiraex=criarcarta("Barreira explosiva", 4,4,1,0,0);
    push(deck, barreiraex);
    push(deck, barreiraex);

    finalflash=criarcarta("Resplandor final", 15,0,1,0,0);
    push(deck, finalflash);
    }

void cartas_especiais(int numero, tp_pilha *deck){
  
    Carta regeneracao, supersayajin, Tiro, Controlada, Gigante;

    Controlada=criarcarta("Explosao de Energia Controlada", 20,0,1,0,0);
    supersayajin=criarcarta("Super sayajin", 0,0,3,0,5);
    Tiro=criarcarta("Tiro Preciso", 4,4,1,0,0);
    regeneracao=criarcarta("Regeneraçao", 0,0,1,3,0);
    Gigante=criarcarta("Gigantificacao",0,0,0,0,3);
    

    switch (numero)
    {
    case 1:
    push(deck, supersayajin);
    exibirCarta(&supersayajin);
      break;

    case 2:
    push(deck, Tiro);
    exibirCarta(&Tiro);
      break;

    case 3:
    push(deck, Controlada);
    exibirCarta(&Controlada);
      break;

    case 4:
      push(deck, regeneracao);
      exibirCarta(&regeneracao);
      break;

    case 5:
      push(deck, Gigante);
      exibirCarta(&Gigante);
      break;
    
    default:
    printf("\nok\n");
      break;
    }

  }

#endif
