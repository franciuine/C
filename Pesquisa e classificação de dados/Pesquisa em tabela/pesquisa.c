#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "pesquisa.h"

long int Insere (rgst *tabela, long int n){
	
	tabela[n].matricula = n+1;
	printf("| Digite nome:\n| ");
	scanf("%s", tabela[n].nome);
	printf("| Digite número de faltas:\n| ");
	scanf("%i", &tabela[n].faltas);
	printf("| Digite nota:\n| ");
	scanf("%f", &tabela[n].nota);
	printf("\n");
	
	n++;
	
	return n;
}

void Remove (rgst *tabela){
	long int mat;
	int x;
	
	printf("| Digite matrícula para remoção:\n| ");
	scanf("%ld", &mat);
	printf("\n");
	
	tabela[mat-1].matricula = 0;
	strcpy(tabela[mat-1].nome, "null");
	tabela[mat-1].faltas = 0;
	tabela[mat-1].nota = 0;
}

void Imprime (rgst *tabela, long int n){
    int x;
    
    for(x=0; x<n; x++){
		printf("\n");
        printf("| Matrícula: %ld\n", tabela[x].matricula);
        printf("| Nome: %s\n", tabela[x].nome);
        printf("| Faltas: %d\n", tabela[x].faltas);
        printf("| Nota: %.2f\n", tabela[x].nota);
    }
    printf("\n");
}

int PesquisaSequencial (rgst *tabela, long int n, int q){
	long int mat;
	int x;
	
	printf("| Digite matrícula para busca:\n| ");
	scanf("%ld", &mat);
	
	for(x=0; x<n; x++){
		q++;
		if(tabela[x].matricula == mat){
			printf("\n");
			printf("| ALUNO ENCONTRADO!\n");
			printf("\n");
			printf("| Matrícula: %ld\n", tabela[x].matricula);
			printf("| Nome: %s\n", tabela[x].nome);
			printf("| Faltas: %d\n", tabela[x].faltas);
			printf("| Nota: %.2f\n", tabela[x].nota);
			printf("\n");
			return q;
			break;
		}
	}
	printf("\nXXX ALUNO NÃO ENCONTRADO! XXX\n\n");
	return q;
}

int PesquisaBinaria (rgst *tabela, long int n, int q){
	long int ini, fim, meio, mat;
	ini = 0;
	fim = n;
	
	printf("| Digite matrícula para busca:\n| ");
	scanf("%ld", &mat);
	
	while(ini <= fim){
		q++;
		meio = (ini+fim)/2;
		if(mat < tabela[meio].matricula){
			fim = meio - 1;
		}
		if(mat > tabela[meio].matricula){
			ini = meio + 1;
		}
		if(mat == tabela[meio].matricula){
			printf("\n");
			printf("| ALUNO ENCONTRADO!\n");
			printf("\n");
			printf("| Matrícula: %ld\n", tabela[meio].matricula);
			printf("| Nome: %s\n", tabela[meio].nome);
			printf("| Faltas: %d\n", tabela[meio].faltas);
			printf("| Nota: %.2f\n", tabela[meio].nota);
			printf("\n");
			return q;
			break;
		}
	}
	
	printf("\nXXX ALUNO NÃO ENCONTRADO! XXX\n\n");
	return q;
}

rgst *Random (long int tam){
	int x, y, z;

	rgst *tabela = (rgst*) malloc (sizeof(rgst) * tam);
	
	for(x=0; x<tam; x++){
		tabela[x].matricula = x + 1;
		z = rand() % (40-3) + 3;
		for(y=0; y<z; y++){
			tabela[x].nome[y] = (char) (rand() % 26 + 65);
			tabela[x].faltas = rand() % 60;
			tabela[x].nota = (float) rand() / RAND_MAX * 10.0;
        }
	}
	return tabela;	
}
