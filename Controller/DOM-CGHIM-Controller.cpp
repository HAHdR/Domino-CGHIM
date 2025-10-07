/*
DOM-CGHIM-Controller.cpp - Projeto Domino - Etapa 2
22/08/2024 - Grupo: CGHIM
Carolina Olmos Gracio Castanho
Geovanna Cristina Brezinger 
Henrique Abreu Hollanda da Rocha
Isabela Nunes dos Santos
Matheus Guido Noronha Moreira Passos
*/

#include "View/Dom_CGHIM_View.cpp"
#include "Dom_CGHIM_Controller.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>




void fMenu(tipopeca p[28]){
	int op;
	do{
		Index();
		scanf("%d", &op);
		switch(op){
			case 0:{
				fMsgOut();
				exit(0);
				break;
			}
			
			case 1: {
				fInicializaPecas(p);
				fImprimeOrd();
				fMsgOrddenada();
				break;
			}
			
			case 2: {
				fEmbaralhar(p);
				fImprimeEmb(p);
				fMsgEmb();
				break;
			}
			
			case 3:{
				fMsgEmb();
				fImprimeEmb(p);
				fInicializaPecas(p);
				fMsgOrddenada();
				fImprimeOrd();
				break;
			}
			
			case 4: {
				fImprimePeca();
				break;
			}
			case 5: {
				fRegras();
				break;
			}
			
			case 6: {
				fEmbaralhar(p);
				fImprimeEmb(p);
				fMsgEmb();
				break;
			}
			
			default: {
				fMsgInvalida();
				break;
			}
		}			
			
	}while(op != -1);
}

void fInicializaPecas(tipopeca p[28]){
	int k = 0;
    
    for (int i = 0; i <= 6; i++) {
        for (int j = i; j <= 6; j++) {
            p[k].lado1 = i;
            p[k].lado2 = j; 
            k++;
        }
    }
}

void fEmbaralhar(tipopeca p[28]){
	srand(time(NULL));
    
    for (int x = 27; x > 0; x--) {
        int z = rand() % (x + 1);
        
        tipopeca ptemp = p[x];
        p[x] = p[z];
        p[z] = ptemp;
    }
    
}

void fImprimeEmb(tipopeca p[28]){
	for(int i = 0; i < 28; i++){
    	printf("[%d|%d] ", p[i].lado1, p[i].lado2);
	}
	printf("\n");
	
}

int fDistribuirPecas(int n) {
  int i, j;
  if (n==1) {
    for(i=0;i<7;i++) {
      printf("\nPeca %d: ",i+1);
      pecas[i].status1 = '1';
      pecas[i].status2 = '1';
      printf("[%d|%d]", pecas[i].Lado1, pecas[i].Lado2);
      printf("\n\n");
    }
  } else {
    printf("Jogador 1: \n");
    for(i=0;i<7;i++) {
      printf("\nPeca %d: ",i+1);
    pecas[i].status1 = '1';
      pecas[i].status2 = '1';
      printf("[%d|%d]", pecas[i].Lado1, pecas[i].Lado2);
      printf("\n\n");
    }
    printf("\n\n");
    printf("Jogador 2: \n");
    for(i=8;i<15;i++) {
      printf("\nPeca %d: ",i);
    pecas[i].status1 = '2';
      pecas[i].status2 = '2';
      printf("[%d|%d]", pecas[i].Lado1, pecas[i].Lado2);
      printf("\n\n");
    }
  }
}

int fQmComc() {
  int i, j, soma=0, m=0, e;
  for (i=0;i<14;i++) {
    if(pecas[i].Lado1==pecas[i].Lado2) {
      if(pecas[i].Lado1==6) {
        if(pecas[i].status1=='1') {
          printf("O jogador 1 inicia a rodada.");
          return i;
          break;
        } else {
          printf("O jogador 2 inicia a rodada.");
          return i;
          break;
        }
      } else if (pecas[i].Lado1==5) {
        if(pecas[i].status1=='1') {
          printf("O jogador 1 inicia a rodada.");
          return i;
          break;
        } else {
          printf("O jogador 2 inicia a rodada.");
          return i;
          break;
        }
      } else if (pecas[i].Lado1==4) {
        if(pecas[i].status1=='1') {
          printf("O jogador 1 inicia a rodada.");
          return i;
          break;
        } else {
          printf("O jogador 2 inicia a rodada.");
          return i;
          break;
        }
      } else if (pecas[i].Lado1==3) {
        if(pecas[i].status1=='1') {
          printf("O jogador 1 inicia a rodada.");
          return i;
          break;
        } else {
          printf("O jogador 2 inicia a rodada.");
          return i;
          break;
        }
      } else if (pecas[i].Lado1==2) {
        if(pecas[i].status1=='1') {
          printf("O jogador 1 inicia a rodada.");
          return i;
          break;
        } else {
          printf("O jogador 2 inicia a rodada.");
          return i;
          break;
        }
      } else if (pecas[i].Lado1==1) {
        if(pecas[i].status1=='1') {
          printf("O jogador 1 inicia a rodada.");
          return i;
          break;
        } else {
          printf("O jogador 2 inicia a rodada.");
          return i;
          break;
        }
      } else {
        if(pecas[i].status1=='1') {
          printf("O jogador 1 inicia a rodada.");
          return i;
          break;
        } else {
          printf("O jogador 2 inicia a rodada.");
          return i;
          break;
        }
      }
	    } else {
      for (j=0;j<14;j++) {
        soma = pecas[j].Lado1+pecas[j].Lado2;
        if (m<soma) {
          m = soma;
          e = j;
        }
      }
      if (pecas[e].status1 == '1') {
        printf("O jogador 1 inicia a rodada.");
        return e;
        break;
      } else {
        printf("O jogador 2 inicia a rodada.");
        return e;
        break;
      }
    }		
  }
}

int fEscolhaPeca(int pescolha, int ladoO, int ladoE, int x) {
  if(ladoO==1) {
    if (ladoE==1) {
      if(pecas[pescolha].Lado1==pecas[x].Lado1) {
        printf("\n\n [%d][%d] [%d][%d]\n\n" , pecas[pescolha].Lado2, pecas[pescolha].Lado1, pecas[x].Lado1, pecas[x].Lado2);
        pecas[pescolha].status1 = 'T';
      } else {
        printf("Jogada invalida\n");
      }
    } else if (ladoE==2) {
      if(pecas[pescolha].Lado2==pecas[x].Lado1) {
        printf("\n\n [%d][%d] [%d][%d]\n\n" , pecas[pescolha].Lado1, pecas[pescolha].Lado2, pecas[x].Lado1, pecas[x].Lado2);
        pecas[pescolha].status2 = 'T';
      } else {
        printf("Jogada invalida\n");
      }
    } else {
      printf("Peca invalida\n");
    }
  } else if (ladoO==2) {
    if (ladoE==1) {
      if(pecas[pescolha].Lado1==pecas[x].Lado2) {
        printf("\n\n [%d][%d] [%d][%d]\n\n" , pecas[x].Lado1, pecas[x].Lado2, pecas[pescolha].Lado1, pecas[pescolha].Lado2);
        pecas[pescolha].status1 = 'T';
      } else {
        printf("Jogada invalida\n");
      }
    } else if (ladoE==2) {
      if(pecas[pescolha].Lado2==pecas[x].Lado2) {
        printf("\n\n [%d][%d] [%d][%d]\n\n" , pecas[x].Lado1, pecas[x].Lado2, pecas[pescolha].Lado2, pecas[pescolha].Lado1);
        pecas[pescolha].status2 = 'T';
      } else {
        printf("Jogada invalida\n");
      }
    } else {
      printf("Peca invalida\n");
    }
  }
}
