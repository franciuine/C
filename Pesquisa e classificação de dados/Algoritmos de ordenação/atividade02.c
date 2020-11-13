#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include "atividade02.h"

int *LeEntrada(FILE *entrada, int tam){

	int x, y;
	char q[100];
	
	int *vet = malloc(sizeof(int) * tam);

	entrada = fopen ("entrada.txt", "r");
	if (entrada == NULL){
		printf("| Não foi possível abrir o arquivo!\n");
		exit(1);
	}

	for(x=0; x<tam; x++){
		y=0;
		while((q[y] = getc(entrada))!='\t'){
			y++;
		}
		vet[x] = atoi(q);
	}
	printf("\n");
	
	fclose(entrada);

	return *vet;
}

void ShellSort (int *vet, int tam){
    time_t tIni, tFim;
    int x, y, valor, op;
    int h = 1;
    FILE *shell;
    
    shell = fopen ("shellsort.txt", "w");
	if (shell == NULL){
		printf("| Não foi possível abrir o arquivo!\n");
		exit(1);
	}

	tIni = time(NULL);
    while(h < tam) {
        h = 3 * tam + 1;
    }
    while (h > 1){
        h /= 3;
        for(x=h; x<tam; x++){
            valor = vet[x];
            y = x;
            while(y >= h && valor < vet[y-h]){
                vet[y] = vet [y-h];
                y = y - h;
            }
            vet[y] = valor;
        }
    }
    tFim = time(NULL);
	
	printf("| Tempo de Ordenação: %ld segundos\n\n", tFim - tIni);

	for (x=0; x<tam; x++){
		fprintf(shell, "%d\t", vet[x]);
	}

	fclose(shell);

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
}

void Merge(int *vet, int comeco, int meio, int fim) {
     int com1 = comeco, com2 = meio+1, comAux = 0, tam = fim-comeco+1;
     int *vetAux;
     vetAux = (int*)malloc(tam * sizeof(int));
 
     while(com1<=meio && com2<=fim){
         if(vet[com1] <= vet[com2]){
             vetAux[comAux] = vet[com1];
             com1++;
         }else{
             vetAux[comAux] = vet[com2];
             com2++;
         }
         comAux++;
     }
     while(com1<=meio){
         vetAux[comAux] = vet[com1];
         comAux++;com1++;
     }
     while(com2<=fim){
         vetAux[comAux] = vet[com2];
         comAux++;com2++;
     }
 
     for(comAux=comeco;comAux<=fim;comAux++){
         vet[comAux] = vetAux[comAux-comeco];
     }
     
     free(vetAux);
 }
 
void MergeSort(int *vet, int comeco, int fim){
	if(comeco < fim){
		int meio = (fim+comeco)/2;
 
		MergeSort(vet, comeco, meio);
        MergeSort(vet, meio+1, fim);
		Merge(vet, comeco, meio, fim);
     }
}

void Particao(int esq, int dir, int *x, int *y, int *vet){
	
	int pivo, *aux;
	*x = esq; 
	*y = dir;
	pivo = vet[(*x + *y)/2];
 
	do{
		while(vet [*x] < pivo){
			(*x)++;
		}
		while(vet [*y] > pivo){
			(*y)--;
		}
		if (*x <= *y){
			aux = vet[*x]; 
			vet[*x] = vet[*y]; 
			vet[*y] = aux;
			(*x)++; 
			(*y)--;
		}
	} while (*x <= *y);
}

void Ordena(int esq, int dir, int *vet){
	int x, y;
	
	Particao(esq, dir, &x, &y, vet);
	if (esq < y){
		Ordena(esq, y, vet);
	}
	if (x < dir){
		Ordena(x, dir, vet);
	}
}

void QuickSort(int *vet, int tam){
	Ordena(0, tam-1, vet);
}
