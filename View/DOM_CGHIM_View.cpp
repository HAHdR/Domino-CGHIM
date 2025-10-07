/*
DOM-CGHIM-View.cpp - Projeto Domino - Etapa 2
14/08/2024 - Grupo: CGHIM
Carolina Olmos Gracio Castanho
Geovanna Cristina Brezinger 
Henrique Abreu Hollanda da Rocha
Isabela Nunes dos Santos
Matheus Guido Noronha Moreira Passos
*/

#include "Dom_CGHIM_View.h"
#include <iostream>

void Index()
{
	printf("\n\n");
    printf("1 - Gerar as pecas ordenadas\n");
    printf("2 - Embaralhar pecas\n");
    printf("3 - Mostrar Embaralhado e Ordenado\n");
    printf("4 - Comecar o jogo \n");
    printf("5 - Regras do Jogo\n");
    printf("6 - Recomecar o jogo (Reembaralhar)\n");
    printf("0 - Encerrar a partida\n\n");

    printf("Digite a opcao desejada:\t");
}

void fImprimePeca() {
    for (int i = 0; i <= 6; i++) {
    	
        for (int j = i; j <= 6; j++) {

            printf("[%d|%d] ", i, j);
        }
        printf("\n");    
    }
	printf("\n");
}

void fImprimeOrd() {
    for (int i = 0; i <= 6; i++) {
    	
        for (int j = i; j <= 6; j++) {

            printf("[%d|%d] ", i, j);
        }
    }
	printf("\n");
  
}

void fRegras()
{
	printf("\n\n");
	printf("					        REGRAS:\n");
	printf("-------------------------------------------------------------------------------------------------------------------------\n");
    printf("|Este Domino comporta ate 2 jogadores. Cada jogador inicia a partida com 7 pecas, devendo jogar pecas cuja extremidade  |\n");
    printf("|contenha o mesmo numero da extremidade de uma peca que ja esteja no tabuleiro. A partida comeca com o jogador que tiver|\n");
    printf("|a peca [6|6]. Caso nenhum dos jogadores a possua, o inicio da partida sera determinado por quem tiver                  |\n");
    printf("|a peca [5|5], [4|4], etc. Se niniguem possuir extremidades iguais, comecara o jogo aquele que portar a                 |\n");
    printf("|peca cujas extremidades possuam a maior somatoria. Caso o jogador nao tenha uma extremidade compativel,                |\n");
    printf("|deve comprar uma peca no Monte. O ganhador sera quem for o primeiro a conseguir se livrar das                          |\n");
    printf("|proprias pecas. Se nao houver mais extremidades compativeis disponiveis, ganhara aquele que                            |\n");
    printf("|possuir a menor quantidade de pecas. Se as quantidades forem iguais, a vitoria sera dada                               |\n");
    printf("|ao jogador que deter a menor somatoria dos numeros das pecas.                                                          |\n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
}

void fMsgInvalida() {
	printf("\nOpcao Invalida!\n");
}

void fMsgEmb() {
	printf("\nPecas Embaralhadas!\n");
}

void fMsgOut() {
	printf("\nPrograma encerrado!\n");
}

void fMsgOrddenada() {
	printf("\nPecas Ordenadas!\n");
}
