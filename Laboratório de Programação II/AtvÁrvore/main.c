#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main (){
	
	int x;
	int op;
	int opp;
	arv *a;
	int menor;
	int maior;
	
	a = NULL;

	do{
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("|1- Inserir elemento        |\n");
		printf("|2- Mostrar árvore          |\n");
		printf("|3- Buscar elemento         |\n");
		printf("|4- Menor elemento          |\n");
		printf("|5- Maior elemento          |\n");
		printf("|6- Remover elemento        |\n");
		printf("|7- Sair                    |\n");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n|");
		scanf("%d", &op);
	
		switch(op){
			case 1:
				printf("\n|Digite valor: \n|");
				scanf("%d", &x);
				a = InsereArvore(a,x);
				printf("\n");
				break;
			case 2:
				printf("\n");
				printf("|1- Pré-Ordem   |\n");
				printf("|2- Simétrica   |\n");
				printf("|3- Pós-Ordem   |\n");
				scanf("%d", &opp);
				printf("\n");
				
				switch(opp){
					case 1:	
						ImprimePreOrdem(a);
						break;
					case 2:
						ImprimeSimetrica(a);
						break;
					case 3:
						ImprimePosOrdem(a);
						break;
					default:
						printf(" xxx Opção inválida! xxx");
						break;
				}		
				break;
			case 3:
				printf("\n|Digite valor: \n|");
				scanf("%d", &x);
				BuscaArvore(a,x);
				break;
			case 4:
				menor = Menor(a);
				printf("\n|Menor valor encontrado: %d\n\n", menor);
				break;
			case 5:
				maior = Maior(a);
				printf("\n|Maior valor encontrado: %d\n\n", maior);
				break;
			case 6:
				printf("\n|Digite valor: \n|");
				scanf("%d", &x);
				a = RemocaoArvore(a,x);
				printf("\n|Removido!\n");
			case 7:
				exit(1);
				break;
			default:
				printf("xxx Opção inválida! xxx");
				break;
		}
	} while (op!=7);
	
	return 0;
}
