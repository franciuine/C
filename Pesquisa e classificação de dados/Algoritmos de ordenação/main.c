#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include "atividade02.h"

int main (){
	FILE *entrada;
	FILE *merge;
	FILE *quick;
	int x, tam, op;
	time_t tIni, tFim;
	entrada = fopen ("entrada.txt", "w");
	if (entrada == NULL){
		printf("| Não foi possível abrir o arquivo!\n");
		exit(1);
	}
	
	printf("| Informe o tamanho do vetor:\n| ");
	scanf("%d", &tam);
	
	//cria vetor
	int *vet = (int*) malloc (sizeof(int) * tam);
	
	//preenche vetor
	srand(time(NULL));
	for(x=0; x<tam; x++){
		vet[x] = rand() % (tam);
	}
	
	//imprime vetor na tela
	printf("\n");
	for (x=0; x<tam; x++){
		printf("%d\t", vet[x]);
	}
	printf("\n");
	
	//armazena valores no arquivo de entrada
	for(x=0; x<tam; x++){
		fprintf(entrada, "%d\t", vet[x]);
	}
	
	fclose(entrada);

	do{
		printf("\n");
		printf("|========SELECIONE=OPERAÇÃO========|\n");
		printf("|1- Shell Sort                     |\n");
		printf("|2- Merge Sort                     |\n");
		printf("|3- Quick Sort                     |\n");     
		printf("|0- Sair                           |\n");
		printf("|==================================|\n|");
		scanf("%i", &op);
		printf("\n");
		
		switch(op){
			case 1:
				*vet = LeEntrada(entrada, tam);
				ShellSort(vet, tam);
				break;
			case 2:
				*vet = LeEntrada(entrada, tam);
				tIni = time(NULL);
				MergeSort(vet, 0, tam);
				tFim = time(NULL);
				
				merge = fopen ("mergesort.txt", "w");
				if (merge == NULL){
					printf("| Não foi possível abrir o arquivo!\n");
					exit(1);
				}
				
				printf("| Tempo de Ordenação: %ld segundos\n\n", tFim - tIni);

				for (x=0; x<tam; x++){
					fprintf(merge, "%d\t", vet[x]);
				}

				fclose(merge);

				printf("| Imprimir valores na tela?\n");
				printf("| 1- Sim\n");
				printf("| 2- Não\n| ");
				scanf("%i", &op);

				if(op==1){
					printf("\n");
					for (x=0; x<tam; x++){
						printf("%d\t", vet[x]);
					}
				}
				printf("\n");
				if((op!=1) && (op!=2)){
					printf("| OPÇÃO INVÁLIDA!\n");
				}
				
				break;
			case 3:
				*vet = LeEntrada(entrada, tam);
				tIni = time(NULL);
				QuickSort(vet, tam);
				tFim = time(NULL);
				
				quick = fopen ("quicksort.txt", "w");
				if (quick == NULL){
					printf("| Não foi possível abrir o arquivo!\n");
					exit(1);
				}
				
				printf("| Tempo de Ordenação: %ld segundos\n\n", tFim - tIni);

				for (x=0; x<tam; x++){
					fprintf(quick, "%d\t", vet[x]);
				}

				fclose(quick);

				printf("| Imprimir valores na tela?\n");
				printf("| 1- Sim\n");
				printf("| 2- Não\n| ");
				scanf("%i", &op);

				if(op==1){
					printf("\n");
					for (x=0; x<tam; x++){
						printf("%d\t", vet[x]);
					}
				}
				printf("\n");
				if((op!=1) && (op!=2)){
					printf("| OPÇÃO INVÁLIDA!\n");
				}
				break;
			case 0:
				exit(1);
				break;
			default:
				printf("| OPÇÃO INVÁLIDA!\n");
				break;
		}
	}while (op!=0);

	return 0;
}

