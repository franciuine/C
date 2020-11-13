// Pesquisa e Classificação de Dados - Atividade Semi-Presencial 03
// 10/05/2018
// Franciuíne Almeida (francuine@gmail.com)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "pesquisa.h"

int main(){
	rgst *tabela;
	int op1, op2, q;
	long int n=0, tam;
	time_t tIni, tFim;
	
	printf("| Digite quantidade máxima de registros a serem gerados:\n| ");
	scanf("%ld", &tam);
	printf("\n");
	
	tabela = (rgst*) malloc (sizeof(rgst) * tam);
	
	do{
		printf("=============MENU=============\n");
		printf("| 1- Inserir registro        |\n");
		printf("| 2- Consultar registros     |\n");
		printf("| 3- Remover registro        |\n");
		printf("| 4- Exibir registros        |\n");
		printf("| 5- Gerar tabela randômica  |\n");
		printf("| 0- Encerrar                |\n");
		printf("==============================\n| ");
		scanf("%d", &op1);
		printf("\n");
		
		switch(op1){
			case 1:
				if(n>=tam){
					printf("| Tabela cheia!\n\n");
				}
				else{
					n = Insere(tabela, n);
				}
				break;
			case 2:
				if(tabela == NULL){
					printf("| Tabela vazia!\n");
				}
				else{
					printf("==========================\n");
					printf("| 1- Pesquisa sequencial |\n");
					printf("| 2- Pesquisa binária    |\n");
					printf("==========================\n| ");
					scanf("%d", &op2);
					printf("\n");
					
					switch(op2){
						case 1:
							q = 0;
							tIni = time(NULL);
							q = PesquisaSequencial(tabela, n, q);
							tFim = time(NULL);
							printf("| Tempo de busca: %ld segundos\n", (tFim - tIni));
							printf("| Total de comparações: %d\n\n", q);
							break;
						case 2:
							q = 0;
							tIni = time(NULL);
							q = PesquisaBinaria(tabela, n, q);
							tFim = time(NULL);
							printf("| Tempo de busca: %ld segundos\n", (tFim - tIni));
							printf("| Total de comparações: %d\n\n", q);
							break;
						default:
							printf("XXX OPÇÃO INVÁLIDA! XXX\n\n");
							break;
					}
				}
				break;
			case 3:
				if(tabela == NULL){
					printf("| Tabela vazia!\n");
				}
				else{
					Remove(tabela);
				}
				break;
			case 4:
				Imprime(tabela, n);
				break;
			case 5:
				tIni = time(NULL);
				tabela = Random(tam);
				tFim = time(NULL);
				printf("| Tabela gerada!\n");
				printf("| Tempo de geração: %ld segundos\n\n", (tFim - tIni));
				n = tam;
				break;
			case 0:
				exit(1);
				break;
			default:
				printf("XXX OPÇÃO INVÁLIDA! XXX\n\n");
				break;
		}
	} while(op1!=0);
	
	return 0;	
}

