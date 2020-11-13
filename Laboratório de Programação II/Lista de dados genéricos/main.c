// Prova 1
// 17/08/2017
// Franciuíne Almeida (franciuine@gmail.com)
#include <stdio.h>
#include <stdlib.h>
#include "listagen.h"

struct aluno{
	int mat;
	char nome[50];
}; typedef struct aluno aln;

lst *Insere(lst *l);

int Igual(void* al, void* info);

void Imprime(void *al);

int RemoveGen(void* al, void*info);

int main(){
	
	lst *l = Cria();
	int op;
	int m;
	int cf;
	void (*cb)(void*);
	
	do{
		printf("\n");
		printf("====================================\n");
		printf("|1- Inserir aluno                  |\n");
		printf("|2- Buscar aluno                   |\n");
		printf("|3- Imprimir lista de alunos       |\n");
		printf("|4- Remover aluno                  |\n");
		printf("|5- Verificar se a lista está vazia|\n");
		printf("|6- Sair                           |\n");
		printf("====================================\n|");
		scanf("%i", &op);
		printf("\n");
		
		switch(op){
			case 1:
				l= Insere(l);
				printf("--- ALUNO INSERIDO! ---\n");
				cf++;				
				break;
			case 2:
				if(cf>=1){
					printf("| Digite matrícula:\n| ");
					scanf("%i", &m);
					Busca(l, Igual, m);
			    }
			    else{
					printf(" xxx LISTA VAZIA! xxx\n");
				}	
				break;
			case 3:
				if(cf>=1){
					Percorre(l,Imprime);
				}
				else{
					printf(" xxx LISTA VAZIA! xxx\n");
				}	
				break;
			case 4:
				if(cf>=1){
					printf("| Digite matrícula:\n| ");
					scanf("%i", &m);
					l = Remove(l, RemoveGen, m);
					cf--;
				}
				else{
					printf(" xxx LISTA VAZIA! xxx\n");
				}					
				break;
			case 5:
				Vazia(l);
				break;
			case 6:
				exit(1);
				break;
			default:
				printf("xxx OPÇÃO INVÁLIDA! xxx\n");
			}
	}while(op!=6);
	

return 0;
}

lst *Insere(lst *l){
	aln *novo = (aln*) malloc (sizeof(aln));
	printf("| Digite nome:\n| ");
	scanf("%s", novo->nome);
	printf("| Digite matrícula:\n| ");
	scanf("%i", &novo->mat);
	
	return InsereGen(l, novo);
}

int Igual(void* al, void* info){
    int *m = (int*)info;
    aln *a =(aln*)al;
    
    if(a->mat == (*m)){
        printf("--- ALUNO ENCONTRADO! ---\n\n");
        Imprime(a);
        return 1;
    }
    return 0;
}

void Imprime(void *al){
	aln *a = (aln*)al;
	printf("| Nome: %s\n", a->nome);
	printf("| Matricula: %i\n", a->mat);
	printf("\n");
}

int RemoveGen(void* al, void*info){
	int *m = (int*)info;
    aln *a =(aln*)al;
    
    if(a->mat == (*m)){
		free(a);
		return 1;
	}
	return 0;
}
