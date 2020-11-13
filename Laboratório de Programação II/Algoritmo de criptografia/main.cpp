// Prova 5
// 30/10/2017
// Franciuíne Almeida (franciune@gmail.com)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cripto.h"

int main(){
	
	printf("\n");
	printf("| Para a execução do programa, os textos devem já estar escritos nos seus respectivos arquivos .txt.\n");
	printf("| Escreva em 'descriptografado.txt' para ter seu texto criptografado.\n");
	printf("| Escreva em 'criptografado.txt' para ter seu texto descriptografado.\n");

	int op;

	do{
		printf("\n");
		printf("|1 Criptografar\n");
		printf("|2 Descriptografar\n");
		printf("|3 Sair\n");
		scanf("%i", &op);
		
		switch(op){
			case 1:
				Criptografa();
				break;
			case 2:
				Descriptografa();
				break;
			case 3:
				exit(1);
				break;
			default:
				printf("| Opção inválida!\n");
				break;
		}
		
	} while (op!=3);

return 0;
}
