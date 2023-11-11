#include <iostream>
#include "monstros.h"
#include "deck.h"
//personagem.h->cartas.h->pilhastruct.h->(deck.h)(filastruct.h)->monstros.h

int main() {

    Monstro Demonio = BancoDeDados(1);

    DadosMonstro(&Demonio);



    return 0;
}