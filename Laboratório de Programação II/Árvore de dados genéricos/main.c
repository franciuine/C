// Prova 2
// 30/08/2017
// Franciuíne Almeida (franciuine@gmail.com)

#include <stdio.h>
#include <stdlib.h>
#include "arvoregen.h"

int main(){

	int v;
	int op1;
	int op2;
	int cf=0;
	avl *a=NULL;
	
	do{
		printf("\n");
		printf("|==================================|\n");
		printf("|1- Inserir elemento               |\n");
		printf("|2- Remover elemento               |\n");
		printf("|3- Imprimir árvore                |\n");
		printf("|4- Menor valor                    |\n");
		printf("|5- Maior valor                    |\n");
		printf("|6- Altura                         |\n");
		printf("|7- Sair                           |\n");
		printf("|==================================|\n|");
		scanf("%i", &op1);
		printf("\n");

		switch(op1){
			case 1:
				a = Insere (a);
				printf("--- INSERIDO! ---\n");
				cf++;
				break;
			case 2:
				if(cf>=1){
					printf("| Digite valor: \n| ");
					scanf("%i", &v);
					a = Remove(a, Compara, &v);
					printf("--- REMOVIDO! ---\n");
					cf--;
				}
				else{
					printf(" xxx NENHUM ITEM NA ÁRVORE! xxx\n");
				}
				break;
			case 3:
				if(cf>=1){
					printf("\n");
					printf("==========================\n");
					printf("|1- Imprimir na tela     |\n");
					printf("|2- Imprimir em aquivo   |\n");
					printf("==========================\n");
					scanf("%i", &op2);

					switch(op2){
						case 1:
							printf("------------PRÉ-ORDEM-----------\n");
							ImprimePreOrdemTela (a, ImprimeTela);
							printf("------------SIMÉTRICA-----------\n");
							ImprimeSimetricaTela (a, ImprimeTela);
							printf("------------PÓS-ORDEM-----------\n");
							ImprimePosOrdemTela (a, ImprimeTela);
							break;
						case 2:
							ImprimeArquivo(a);
							break;
						default:
							printf(" xxx OPÇÃO INVÁLIDA! xxx\n");
							break;
					}
				}
				else{
					printf(" xxx NENHUM ITEM NA ÁRVORE! xxx\n");
				}
				break;
			case 4:
				if(cf>=1){
					printf(" --- MENOR ELEMENTO ---\n");
					Menor(a, ImprimeTela);

				}
				else{
					printf(" xxx NENHUM ITEM NA ÁRVORE! xxx\n");
				}
				break;
			case 5:
				if(cf>=1){
                    printf(" --- MAIOR ELEMENTO ---\n");
					Maior(a, ImprimeTela);
				}
				else{
					printf(" xxx NENHUM ITEM NA ÁRVORE! xxx\n");
				}
				break;
			case 6:
				if(cf>=1){
					printf("| Altura da árvore: %i\n\n", a->altura);
				}
				else{
					printf(" xxx NENHUM ITEM NA ÁRVORE! xxx\n");
				}
				break;
			case 7:
				exit(1);
				break;
			default:
				printf(" xxx OPÇÃO INVÁLIDA! xxx\n");
				break;
		}
	}while (op1!=7);

	return 0;
}
