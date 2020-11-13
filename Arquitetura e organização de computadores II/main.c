//Franciuíne B. da S. de Almeida
//franciuine@gmail.com

#include <stdio.h>
#include <stdlib.h>
#include "projetoaoc2.h"

int main(){
	int op;

	do{
		printf("\n");
		printf("|=======================SELECIONE==OPERAÇÃO======================|\n");
		printf("| 1- Calcular tempo efetivo de acesso                            |\n");
		printf("| 2- Calcular tamanho de Cache (em KB)                           |\n");
		printf("| 3- Calcular tamanho de Cache (em KB) tendo tamanho do bloco    |\n");
		printf("| 4- Calcular tamanho de bloco (em bytes)                        |\n");
		printf("| 5- Calcular CPI sob influência de falhas                       |\n");
		printf("| 6- Calcular tamanho de Cache multivias (em KB)                 |\n");
		printf("| 7- Contabilizar número de acertos e falhas para acesso à cache |\n");
		printf("| 8- RAID 3 x RAID 4                                             |\n");
		printf("| 9- Handshake                                                   |\n");
		printf("| 0- Sair                                                        |\n");
		printf("|================================================================|\n| ");
		scanf("%i", &op);
		printf("\n");
		
		switch(op){
			case 0:
				exit(1);
				break;
			case 1:
				TempoDeAcesso();
				break;
			case 2:
				TamanhoCache();
				break;
			case 3:
				TamanhoCacheBloco();
				break;
			case 4:
				TamanhoBloco();
				break;
			case 5:
				CPI();
				break;
			case 6:
				TamanhoCacheVias();
				break;
			case 7:
				MenuCaches();
				break;
			case 8:
				MenuRAIDs();
				break;
			case 9:
				Handshake();
				break;
			default:
				printf("| OPÇÃO INVÁLIDA!\n");
				break;
		}
		
	}while(op!=0);
	
	return 0;
}
