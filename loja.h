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
    Carta carta[2];
    int nd;
    srand(time(NULL));

    for(int i=0; i<2; i++){
     carta[i] = banco_carta((rand() % 6 ) + 1);
     push(deck, carta[i]);
    }
    printf("As cartas recibidas no pacote foram:\ncarta 1:\n");
    
    exibirCarta(&carta[0]);
    printf("\n");
    exibirCarta(&carta[1]);
    system("pause");
}

void mostrar_menu(){
    printf("Bem vindo a loja!\n");
    printf("Escolha uma opcao para comprar:\n");
    printf("1. Pocao de cura 50 de vida - 150 de ouro\n");
    printf("2. Pocao de cura 70 de vida - 250 de ouro\n");
    printf("3. Pacote de 2 cartas - 450 de ouro\n");
    printf("voce ira receber 2 cartas aleatorias que serao implementadas a sua mao\n");
    printf("4. sair\n");
    
}

int comprar_na_loja(int* vida, int* gold, tp_pilha *deckj) {
    int escolha = 0;
    
    while (escolha != 4) {
        mostrar_menu();
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
        Sleep(2000);
         system("cls"); 
    } 
    return 1;
} 

void descanso(tp_pilha *deckaux, int *vida, int nm){
    int escolha, confirm;
    printf("Voce encontrou um cabana com um homem de cabelo grisalho deseja falar com ele(digite 1) ou descansar em outro lugar(outro)?\n");
    scanf("%d", &escolha);

    if(escolha==1){
        printf("Ola jovem viajente me chamo Marcio Kame, e vejo que voce tem um pontencial a ser libertado gostaria que libere para voce?\n");
        printf("Digite 1 para confirmar\n");
        scanf("%d", &confirm);
        if(confirm==1){ 
            cartas_especiais(nm, deckaux);
            }
        *vida +=25;
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


#endif