#ifndef MAPA
#define MAPA

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//media de 12 inimigos antes do boss/ 0=descanso, 1=loja, 2 até 21=inimigos(20 possiveis inimigos), 30=boss
//boa sorte

typedef int tp_item; //o nodo armazena um numero que identifica se é um descanso, loja ou inimigo, e ser for inimigo, qual


typedef struct tp_no
{
    tp_item fase;//a fase é um numero que determina se é uma loja, descanso, boss, ou confronto com um inimigo comum. E se for, qual inimigo
    int contno;//conta a quantidade de nodos precedentes
    struct tp_no *cam1, *cam2;
}tp_nodo;

tp_nodo* aloca_memo()//alocando memoria para o nodo
{   
    tp_nodo *novo_no;
    novo_no=(tp_nodo*) malloc(sizeof(tp_nodo));
    return novo_no;
}

tp_nodo* cria_nodo(tp_nodo *atu)
{
    tp_nodo *novo_no;
    novo_no=aloca_memo();
    novo_no->contno=atu->contno+1;//incrementando o contador de nos predecessores
    novo_no->cam1=NULL;
    //printf("teste\n");

    if(atu->contno==19)//esse numero mais 1 é a quantidade de nodos que serao criados ate ser criado o nodo que sera um boss, e portanto o fim do jogo
    {
        novo_no->fase=30;
        novo_no->cam1=novo_no;
        novo_no->cam2=novo_no;
        return novo_no;
    }
    
    if((rand() % 4) == 0)// isso da 25% de chance de haver um caminho alternativo nesse no
    {
        novo_no->cam2=NULL;
    }
    else
    {
        novo_no->cam2=novo_no;//significa que não ha caminho alternativo, ele aponta pra si mesmo
    }
    
    
    if((rand() % 5) == 0) //isso da uma chance de 20% de o nodo ser um descanso ou loja
    {
        
        novo_no->fase=rand() % 2;//há 50% de chance de retornar 0, tornando o nodo um descanso, e 50% de retornar 1 tornando-o uma loja
        return novo_no;
    }
    else
    {
        novo_no->fase=(rand() % 20) + 2;//o 20 é a quantidade de inimigos possiveis a serem escolhidos, o 2 é para evitar conflito com loja ou descanso
        return novo_no;
    }
}

void inicializa_mapa(tp_nodo *mapa)//o primeiro no, cam1 aponta para o inicio verdadeiro do mapa, e o cam2 aponta para a posição do jogador
{
    mapa->fase=-1;//apenas pra preencher
    mapa->contno=-1;
    tp_nodo *primeiro;
    primeiro=cria_nodo(mapa);
    mapa->cam1=primeiro;//o cam1 agora aponta pro inicio do mapa
    mapa->cam2=mapa;//o cam2  é o ponteiro da posição do jogador
}


void montagem_geral(tp_nodo *atu)//isso é uma função recursiva, ela monta a arvore de possibilidades com a condição de parada sendo o tamanho do caminho determinado implicitamente pelo contno
{
    tp_nodo *novo_no;

    if(atu->cam1==NULL)
    {
        novo_no=cria_nodo(atu);
        atu->cam1=novo_no;
        montagem_geral(atu->cam1);
    }
    
    if(atu->cam2==NULL)//é muito ponteiro  e logica implicita pra explicar em comentarios simples, melhor perguntar pra mim e eu reservar 20 minutos para explicar, eu amo e odeio programar isso
    {
        novo_no=cria_nodo(atu);
        atu->cam2=novo_no;
        montagem_geral(atu->cam2);
    }
    //printf("final alcancado\n");
}


void prepara_mapa(tp_nodo *mapa)
{
    srand(time(NULL));//o srand deve ficar aqui, senao o valor de retorno dos rands se torna igual
    inicializa_mapa(mapa);
    montagem_geral(mapa->cam1);
}

tp_item navega_mapa(tp_nodo *mapa)
{
    if(mapa==mapa->cam2)
    {
        mapa->cam2=mapa->cam1;//move o jogador
        return mapa->cam2->fase;
    }
    if(mapa->cam2==mapa->cam2->cam2)//só há um caminho a frente
    {
        mapa->cam2=mapa->cam2->cam1;//move o jogador
        printf("so ha um caminho a frente\n");
        return mapa->cam2->fase;
    }
    else//há 2 caminhos a frente
    {
        int esc1, esc2, decisao;
        esc1=mapa->cam2->cam1->fase;
        esc2=mapa->cam2->cam2->fase;
        
        printf("ha dois caminhos a frente, um leva para um ");//isso é pra ser temporario, depois incorpa melhor no teatro

        switch (esc1)
    {
    case 0:
    printf("descanso, e o outro para um ");
        break;
    case 1:
    printf("loja, e o outro para um ");
        break;
    case 30:
    printf("Boss, e o outro para um ");
        break;
    default:
    printf("inimigo, e o outro para um ");
        break;
    }

    switch (esc2)
    {
    case 0:
    printf("descanso. Voce toma o caminho 1 ou 2?\n");
        break;
    case 1:
    printf("loja. Voce toma o caminho 1 ou 2?\n");
        break;
    case 30:
    printf("Boss. Voce toma o caminho 1 ou 2?\n");
        break;
    default:
    printf("inimigo. Voce toma o caminho 1 ou 2?\n");
        break;
    }
        
        scanf("%d", &decisao);
        if(decisao==1)
        {
            mapa->cam2=mapa->cam2->cam1;
            return mapa->cam2->fase;
        }
        if(decisao==2)
        {
            mapa->cam2=mapa->cam2->cam2;
            return mapa->cam2->fase;
        }
  }
}

void verificaFase(int fase){
    if(fase>1 && fase<30) printf("Inimigo\n");
        if(fase==0) printf("Descanso\n");
        if(fase==1) printf("Loja\n");
        if(fase==30) printf("Boss\n");
}


#endif