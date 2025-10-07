/*
DOM-CGHIM - Projeto Dominío - Etapa 1
14/08/2024 - Grupo: CGHIM
Carolina Olmos Gracio Castanho
Geovanna Cristina Brezinger 
Henrique Abreu Hollanda da Rocha
Isabela Nunes dos Santos
Matheus Guido Noronha Moreira Passos
*/

#include <stdio.h> 
#include <time.h>
#include <stdlib.h>
#include <locale.h>



typedef struct domino {
    int Lado1;
    int Lado2;
  char status1;  //'','1','2','M'
  char status2;
} tipoPecas;

tipoPecas pecas[28];
tipoPecas pecastemp;
int op, n, pescolha, ladoO, ladoE, x;


void fCriarPecas()
{
  int i, j;
  int h = 0;   

  for(i = 0; i <= 6; i++)
  {
    for(j = i; j <= 6; j++)
    {
      pecas[h].Lado1 = i;
      pecas[h].Lado2 = j;
      h++;
    }
  }        
}

void fEmbaralhaPecas()
{
  int x, z;

  srand(time(NULL));

  for(x=0;x<28;x++)
  {
    z = rand()%28;
    pecastemp = pecas[x];
    pecas[x] = pecas[z];
    pecas[z] = pecastemp;
  }
}

void fMostraPecas()
{
  int r;

  for(r=0;r<28;r++)
  {
    printf("[%d|%d]", pecas[r].Lado1, pecas[r].Lado2);
    printf("\t");
  }
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

void fMenu ()
{
    printf("\n\n");
    printf("1 - Gerar as pecas ordenadas\n");
    printf("2 - Embaralhar pecas\n");
    printf("3 - Comecar o jogo \n");
    printf("4 - Mostrar Embaralhado e Ordenado\n");
    printf("5 - Regras do Jogo\n");
    printf("6 - Recomecar o jogo (Reembaralhar)\n");
    printf("0 - Encerrar a partida\n\n");

    printf("Digite a opcao desejada:\t");
}

int main()
{
  int op, n, pescolha, ladoO, ladoE, x, j;

  do
  {
    fMenu();
    scanf("%d", &op);

    switch(op)
    {

      case 0:
      {
        printf("\n\nPROGRAMA FINALIZADO!\n\n");
        exit(0);
      }
      case 1:
      {
        fCriarPecas();
        printf("\n\nOrdenamento concluido!\n\n");
        fMostraPecas();
        break;
      }
      case 2:
      {
        fCriarPecas();
        fEmbaralhaPecas();
        printf("\n\nEmbaralhamento bem sucedido!\n\n");
        fMostraPecas();
        break;
      }
      case 3:
      {
        printf("Selecione a quantidade de jogadores (1 ou 2 pessoas): ");
            scanf("%d", &n);
            if(n==1){
            printf("\nJogo solo selecionado. Vamos comecar!\n");
            fCriarPecas();
            fEmbaralhaPecas();
            fDistribuirPecas(n);
            fQmComc();
            do {
              printf("Por favor, escolha uma peça para jogar: ");
              scanf("%d", &pescolha);
              printf("Por favor, escolha um lado da peça escolhida para jogar (1 para esquerda e 2 para direita): ");
              scanf("%d", &ladoE);
              printf("Por favor, escolha um lado da peça que esta no tabuleiro para posicionar (1 para esquerda e 2 para direita): ");
              scanf("%d", &ladoO);
              fEscolhaPeca(pescolha, ladoO, ladoE, x);
              } while(pescolha!=-1);
              } else if (n==2){
                  printf("\nJogo em dupla selecionado. Vamos comecar!\n");
                  fCriarPecas();
                  fEmbaralhaPecas();
                  fDistribuirPecas(n);
                  j=fQmComc();
				
            do {
              if(pecas[j].status1 == '2') {
                printf("\nJogador 1, por favor, escolha uma peça para jogar: ");
                scanf("%d", &pescolha);
                printf("Jogador 1, por favor, escolha um lado da peça escolhida para jogar (1 para esquerda e 2 para direita): ");
                scanf("%d", &ladoE);
                printf("Jogador 1, por favor, escolha um lado da peça que esta no tabuleiro para posicionar (1 para esquerda e 2 para direita): ");
                scanf("%d", &ladoO);
                fEscolhaPeca(pescolha, ladoO, ladoE, x);

                printf("Jogador 2, por favor, escolha uma peça para jogar: ");
                scanf("%d", &pescolha);
                printf("Jogador 2, por favor, escolha um lado da peça escolhida para jogar (1 para esquerda e 2 para direita): ");
                scanf("%d", &ladoE);
                printf("Jogador 2, por favor, escolha um lado da peça que esta no tabuleiro para posicionar (1 para esquerda e 2 para direita): ");
                scanf("%d", &ladoO);
                fEscolhaPeca(pescolha, ladoO, ladoE, x);
              } else {
                printf("Jogador 2, por favor, escolha uma peça para jogar: ");
                scanf("%d", &pescolha);
                printf("Jogador 2, por favor, escolha um lado da peça escolhida para jogar (1 para esquerda e 2 para direita): ");
                scanf("%d", &ladoE);
                printf("Jogador 2, por favor, escolha um lado da peça que esta no tabuleiro para posicionar (1 para esquerda e 2 para direita): ");
                scanf("%d", &ladoO);
                fEscolhaPeca(pescolha, ladoO, ladoE, x);
                printf("Jogador 1, por favor, escolha uma peça para jogar: ");
                scanf("%d", &pescolha);
                printf("Jogador 1, por favor, escolha um lado da peça escolhida para jogar (1 para esquerda e 2 para direita): ");
                scanf("%d", &ladoE);
                printf("Jogador 1, por favor, escolha um lado da peça que esta no tabuleiro para posicionar (1 para esquerda e 2 para direita): ");
                scanf("%d", &ladoO);
                fEscolhaPeca(pescolha, ladoO, ladoE, x);
              }
            } while(pescolha!=-1);
                } else {
                  printf("Número de jogadores invalido!\n");
                }
            break;
      }
      case 4:
      {
        printf("\n\n");
        printf("PECAS EMBARALHADAS:\n");
        fCriarPecas();
        fEmbaralhaPecas();
        fMostraPecas();
        printf("\n");
        printf("\n-----------------------------------------------------------------------------------------------------------------------");
        printf("\n\n");
        printf("PECAS ORDENADAS:\n");
        fCriarPecas();
        fMostraPecas();
        break;
      }
      case 5:
      {
        printf("\n\n");
        printf("REGRAS:\n");
        printf("Este Domino comporta ate 2 jogadores. Cada jogador inicia a partida com 7 pecas, devendo jogar pecas cuja extremidade\n");
        printf("contenha o mesmo numero da extremidade de uma peca que ja esteja no tabuleiro. A partida comeca com o jogador que tiver\n");
        printf("a peca [6|6]. Caso nenhum dos jogadores a possua, o inicio da partida sera determinado por quem tiver\n");
        printf("a peca [5|5], [4|4], etc. Se niniguem possuir extremidades iguais, comecara o jogo aquele que portar a\n");
        printf("peca cujas extremidades possuam a maior somatoria. Caso o jogador nao tenha uma extremidade compativel,\n");
        printf("deve comprar uma peca no Monte. O ganhador sera quem for o primeiro a conseguir se livrar das\n");
        printf("proprias pecas. Se nao houver mais extremidades compativeis disponiveis, ganhara aquele que\n");
        printf("possuir a menor quantidade de pecas. Se as quantidades forem iguais, a vitoria sera dada\n");
        printf("ao jogador que deter a menor somatoria dos numeros das pecas.\n\n");
        break;
      }
      case 6:
      {
        printf("\n\n");
        fCriarPecas();
        fEmbaralhaPecas();
        fMostraPecas();
        break;
      }
      default:
      {
        printf("\n\nERRO! ESSA OPCAO NAO EXISTE! ESCOLHA NOVAMENTE!\n\n");
        break;
      }
    }
  }while(op != 0);	
}       
