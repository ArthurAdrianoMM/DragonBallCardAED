#include "loja.h"



int main() { 
    
    personagem jogador;
    definir_personagem(&jogador);
    DadosPersonagem(&jogador);
    system("pause");
    system("cls");

    tp_pilha descarte;
    tp_pilha deck;
    tp_nodo mapa;
    Mao *mao = inicializa_mao();

    prepara_mapa(&mapa);
    inicializa_pilha(&descarte); // para depois printar o descarte, basta adicionar depois da luta imprime_pilha(&descarte);
    inicializa_pilha(&deck);
    criar_deck(&deck);
    embaralhar_pilha(&deck);

    FILE *arq;
    char nome_arq[20];
    int cont=1, nivel=0; 

    registra(&arq, cont, nome_arq);//salva o nivel alcançado pelo jogador

    //Monstro inimigo = BancoBoss((rand() % 3) + 1); // na biblioteca monstro há varios monstros, para lutar contra outro basta mudar o ID
    Monstro inimigo = BancoBoss((rand() % 3) + 1);

    int escolha, turno, i=0 ; int fase=-1; // i e apenas um contador para as acoes do monstro

    while(fase!=11){
                fase=navega_mapa(&mapa);
                verificaFase(fase);   
            
    switch (fase)
    {
        case 0:
            descanso(&deck, &jogador.vida, jogador.n);
        break;

        case 1:
            comprar_na_loja(&jogador.vida, &jogador.gold, &deck);
        break;

        case 11:
            inimigo = BancoBoss((rand() % 3) + 1);
        break;

        default:   
            inimigo = BancoDeDados((rand() % 10) + 1);
        break;

    }
        while(inimigo.vida>0 && jogador.vida>0){    // enquanto algum dois estiverem vivos

                jogador.ki=jogador.ki_maximo; // reseta o ki do personagem a cada fim de round
                turno=1; 
                
                while(!mao_vazia(mao)){
                    descartar(&mao, &deck, 0);
                }

                if(altura_pilha(&deck) <= 4){
                    empilha_pilha(&deck, &descarte);
                    adicionar_carta(&mao, &deck, 5);
                }else{
                    adicionar_carta(&mao, &deck, 5);
                }   
                
                while(turno!=0 && inimigo.vida>0 && jogador.vida>0){
                    system("cls");// se estiver no windows
                    mostra_mao(mao); // imprime as opcoes de carta, ainda nao implementei para cavar mais cartas, ent por enquanto sao apenas estas 6
                    printf("%s  vida: %d   ki: %d  defesa: %d\n\n",jogador.nome, jogador.vida, jogador.ki , jogador.def);
                    printf("%s  vida: %d \n\n",inimigo.nome,inimigo.vida);
                    escolha = escolher_carta(mao); // retorna o numero digitado -1
                    if(escolha == -1){ // caso digite 0 no terminal
                        printf("Fim de turno \n");
                        turno=0; // finaliza o round
                    }else{
                        joga_carta(&mao, escolha, &descarte, &inimigo, &jogador);
                    }
                }
                if(inimigo.vida<=0) break;;

                system("cls"); // se estiver no windows

                printf("%s  vida: %d   ki: %d  defesa: %d\n\n",jogador.nome, jogador.vida, jogador.ki , jogador.def);
                printf("%s  vida: %d \n\n",inimigo.nome,inimigo.vida);
                printf("     %s, usou    %s    %d de dano\n\n\n",inimigo.nome, inimigo.acoes.items[i].nome, inimigo.acoes.items[i].dano);
                system("pause");// se estiver no windows

                if(inimigo.acoes.items[i].dano<jogador.def){ // caso a defesa do personagem seja maior que o dano do ataque
                    jogador.def-=inimigo.acoes.items[i].dano;
                }else{
                    jogador.vida -= (inimigo.acoes.items[i].dano - jogador.def);
                    jogador.def-=inimigo.acoes.items[i].dano;
                }
                if(jogador.def < 0) jogador.def = 0; // caso a defesa seja negativa, reseta para 0
                
                i++ ; if(i>(inimigo.acoes.fim)) i=0;   // caso o contador i seja maior que o numero de acoes

                if(inimigo.vida<=0 && jogador.vida<=0){
                    while(!mao_vazia(mao)){
                    descartar(&mao, &deck, 0);
                    }
                    empilha_pilha(&deck, &descarte);
                }
            }

            system("cls"); // se estiver no windows

            
            if(jogador.vida<0){
                printf("muito ruim, perdeu \n");
                system("pause");
            }else{
                printf(" GANHOU , parabens por ter derrotado o inimigo \n");
                system("pause");
                system("cls"); // se estiver no windows
                
            }

        fprintf(arq, "fase = %d\n", nivel);
        nivel++; //contador de fases que percorre
    }
    return 0;
}
