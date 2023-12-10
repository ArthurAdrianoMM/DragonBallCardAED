#ifndef LOJA_H
#define LOJA_H
#include "mao.h"


void comprapocao50(int* vida, int* gold){
    if(*gold >= 150){
        *vida += 50;
        *gold -= 150;
        printf("Compra realizada com sucesso!\n");
        }
    else printf("Gold insuficiente para comprar este item!\n");
    
}
void comprapocao70(int* vida, int* gold){
    if(*gold >= 300){
          *vida += 70;
        *gold -= 300;
        printf("Compra realizada com sucesso!\n");
    }
    else printf("Gold insuficiente para comprar este item!\n");
}

Carta banco_carta(int numero){
    Carta abobrinha;
    switch (numero)
    {
    case 1:
        abobrinha = criarcarta("Kamehameha avancado", 30,0,2,0,0);
        break;
    case 2:
        abobrinha = criarcarta("Mega-barreira", 0,15,1,0,0);
        break;
    case 3:
        abobrinha = criarcarta("Ataque de furia",8,0,0,0,0);
        break;
    case 4:
        abobrinha = criarcarta("Refelexo Instintivo",0,8,0,0,0);
        break;
    case 5:
        abobrinha = criarcarta("Big-Bang Ataque",18,0,1,0,0);
        break;
    case 6:
        abobrinha = criarcarta("Masenko ", 18, 0,1,0,0);
        break;
    
    default:
    printf("abobrinha!!!!! hahahahahahahahha\n");
        break;
    }
    
return abobrinha;
    
}

void pacotinho(tp_pilha *deck) {
    Carta carta[3];

    for(int i=0; i<3; i++){
     carta[i] = banco_carta((rand() % 6 ) + 1 );
     push(deck, carta[i]);
    }
    
}

void mostrar_menu(){
    printf("Bem vindo a loja!\n");
    printf("Escolha uma opcao para comprar:\n");
    printf("1. Pocao de cura 50 de vida - 150 de ouro\n");
    printf("2. Pocao de cura 70 de vida - 250 de ouro\n");
    printf("3. Pacote de 3 cartas - 450 de ouro\n");
    printf("voce ira receber 3 cartas aleatorias que serao implementadas a sua mao\n");
    printf("4. sair\n");
    
}

int comprar_na_loja(int* vida, int* gold, tp_pilha *deckj) {
    int escolha = 0;
    while (escolha != 4) {

        scanf("%d", &escolha);
        switch (escolha) {
            case 1:
                comprapocao50(vida, gold);
                break;
            case 2:
                comprapocao70(vida, gold);
                break;
            case 3: {
                if(*gold>450){
                    *gold -= 450;
                pacotinho(deckj);
                }
                else printf("Gold insuficiente para comprar este item!\n");
                break;
            }
            case 4:
                return 0; 
            default:
                printf("Opcao Invalida!\n");
                break;
        }
        
    }
    system("cls");
    return 1;
} 


#endif