#include "mao.h"

int main() { 
    
    personagem boneco;   
    scanf("%s", boneco.nome);
    boneco.def=0;
    boneco.ki_maximo=3;
    boneco.vida=80;

    tp_pilha descarte;
    tp_pilha deck;
    tp_nodo mapa;
    Carta carta=criarcarta("Soco",4,0,1,0,0);
    Mao *mao = inicializa_mao();

    prepara_mapa(&mapa);
    inicializa_pilha(&descarte); // para depois printar o descarte, basta adicionar depois da luta imprime_pilha(&descarte);
    inicializa_pilha(&deck);
    criar_deck(&deck);
    embaralhar_pilha(&deck);

    Monstro inimigo = BancoDeDados(1); // na biblioteca monstro há varios monstros, para lutar contra outro basta mudar o ID

    int escolha, turno, i=0 ; int fase=-1; // i e apenas um contador para as acoes do monstro
    while(inimigo.vida>0 && boneco.vida>0){    // enquanto algum dois estiverem vivos
        boneco.ki=boneco.ki_maximo; // reseta o ki do personagem a cada fim de round
        turno=1; 
        
        mao_insere_no_fim(&mao, carta);
        adicionar_carta(mao, &deck, 4);
        
        while(turno!=0 && inimigo.vida>0 && boneco.vida>0){
            system("cls");// se estiver no windows
            mostra_mao(mao); // imprime as opcoes de carta, ainda nao implementei para cavar mais cartas, ent por enquanto sao apenas estas 6
            printf("%s  vida: %d   ki: %d  defesa: %d\n\n",boneco.nome, boneco.vida, boneco.ki , boneco.def);
            printf("%s  vida: %d \n\n",inimigo.nome,inimigo.vida);
            escolha = escolher_carta(mao); // retorna o numero digitado -1
            if(escolha == -1){ // caso digite 0 no terminal
                printf("Fim de turno \n");
                turno=0; // finaliza o round
            }else{
                joga_carta(&mao, escolha, &descarte, &inimigo, &boneco);
            }
        }
        if(inimigo.vida<=0) break;;

        system("cls"); // se estiver no windows

        printf("%s  vida: %d   ki: %d  defesa: %d\n\n",boneco.nome, boneco.vida, boneco.ki , boneco.def);
        printf("%s  vida: %d \n\n",inimigo.nome,inimigo.vida);
        printf("     %s, usou    %s    %d de dano\n\n\n",inimigo.nome, inimigo.acoes.items[i].nome, inimigo.acoes.items[i].dano);
        system("pause");// se estiver no windows

        if(inimigo.acoes.items[i].dano<boneco.def){ // caso a defesa do personagem seja maior que o dano do ataque
            boneco.def-=inimigo.acoes.items[i].dano;
        }else{
            boneco.vida -= (inimigo.acoes.items[i].dano - boneco.def);
            boneco.def-=inimigo.acoes.items[i].dano;
        }
        if(boneco.def < 0) boneco.def = 0; // caso a defesa seja negativa, reseta para 0
        
        i++ ; if(i>(inimigo.acoes.fim)) i=0;   // caso o contador i seja maior que o numero de acoes
    }

    system("cls"); // se estiver no windows

    // versao precaria do mapa
    if(boneco.vida<0){
        printf("muito ruim, perdeu \n");
        system("pause");
    }else{
        printf(" GANHOU , parabens por ter derrotado o inimigo \n");
        system("pause");
        system("cls"); // se estiver no windows
        while(fase!=10){
            fase=navega_mapa(&mapa);
            verificaFase(fase);   
        }
    }


    return 0;
}
