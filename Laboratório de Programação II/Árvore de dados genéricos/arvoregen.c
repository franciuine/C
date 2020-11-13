#include <stdio.h>
#include <stdlib.h>
#include "arvoregen.h"

avl *RotacaoDireita (avl *a){
	avl *aux = a->esq;
	a->esq = aux->dir;
	aux->dir = a;
	a->altura = 1 + Max (RetornaAltura(a->esq), RetornaAltura(a->dir));
	aux->altura = 1 + Max (RetornaAltura(a->esq), RetornaAltura(a->dir));
	return aux;
}

avl *RotacaoEsquerda (avl *a){
	avl *aux = a->dir;
	a->dir = aux->esq;
	aux->esq = a;
	a->altura = 1 + Max (RetornaAltura(a->esq), RetornaAltura(a->dir));
	aux->altura = 1 + Max (RetornaAltura(a->esq), RetornaAltura(a->dir));
	return aux;
}

avl *RotacaoDireitaEsquerda (avl *a){
	a->dir = RotacaoDireita (a->dir);
	a = RotacaoEsquerda (a);
	return a;
}

avl *RotacaoEsquerdaDireita (avl *a){
	a->esq = RotacaoEsquerda (a->esq);
	a = RotacaoDireita (a);
	return a;
}

int Max (int a, int b){
	return ( a > b ) ? a : b;
}

int RetornaAltura (avl *a){
	if (a == NULL){
		return -1;
	}
	else{
		return a->altura;
	}
}

int Compara (void* info, void* dado){

	int *a = (int*) info;
	int *b = (int*) dado;

	if((*b)<(*a)){
		return 1;
	}else{
		return -1;
	}
}

avl *InsereGen (avl *a, int(*cb)(void*,void*), void *dado){

	int cmp;

	if(a == NULL){
		a = (avl*) malloc (sizeof(avl));
		a->info = dado;
		a->dir = NULL;
		a->esq = NULL;
		a->altura = 0;
		return a;
	}
	else{
		cmp = cb (a->info, dado);
		if(cmp == 1){
			a->esq = InsereGen (a->esq, cb, dado);
			if (RetornaAltura(a->esq) - RetornaAltura(a->dir) == 2){
				if (RetornaAltura(a->esq->esq) - RetornaAltura(a->esq->dir) == 1){
					a = RotacaoDireita(a);
				}
				else{
					a = RotacaoEsquerdaDireita(a);
				}
			}
		}
		else{
			a->dir = InsereGen (a->dir, cb, dado);
			if (RetornaAltura(a->esq) - RetornaAltura(a->dir) == -2){
				if (RetornaAltura(a->dir->esq) - RetornaAltura (a->dir->dir) == -1){
					a = RotacaoEsquerda(a);
				}
				else{
					a = RotacaoDireitaEsquerda(a);
				}
			}
		}

		a->altura = 1 + Max (RetornaAltura(a->esq), RetornaAltura(a->dir));
	}
	return a;
}

avl *Insere (avl *a){
	int *v = (int*) malloc (sizeof(int));
	printf("| Digite valor:\n| ");
	scanf("%i", v);

	return InsereGen (a,Compara, v);
}

void Menor (avl *a, void (*cb)(void*)){
    while (a->esq !=NULL){
		a->esq;
	}
	cb(a->info);
}

void Maior (avl *a, void (*cb)(void*)){
    while (a->dir !=NULL){
		a->dir;
	}
	cb(a->info);
}

void ImprimeTela (void *dado){
	int *info = (int*) dado;
	printf("| %i\n", *info);
}

void ImprimePreOrdemTela (avl *a, void (*cb)(void*)){
	if(a!=NULL){
		cb(a->info);
		ImprimePreOrdemTela(a->esq, cb);
		ImprimePreOrdemTela(a->dir, cb);
	}
}

void ImprimeSimetricaTela (avl *a, void (*cb)(void*)){
	if(a!=NULL){
		ImprimeSimetricaTela(a->esq, cb);
		cb(a->info);
		ImprimeSimetricaTela(a->dir, cb);
	}
}

void ImprimePosOrdemTela (avl *a, void (*cb)(void*)){
	if(a!=NULL){
		ImprimePosOrdemTela(a->esq, cb);
		ImprimePosOrdemTela(a->dir, cb);
		cb(a->info);
	}
}

void ImprimePreOrdemArquivo (avl *a, FILE *impressao){
	int *info = (int*) a->info;
	if(a!=NULL){
		fprintf(impressao, "| %d\n", *info);
		ImprimePreOrdemArquivo(a->esq, impressao);
		ImprimePreOrdemArquivo(a->dir, impressao);
	}
}

void ImprimeSimetricaArquivo (avl *a, FILE *impressao){
	int *info = (int*) a->info;
	if(a!=NULL){
		ImprimeSimetricaArquivo(a->esq, impressao);
		fprintf(impressao, "| %d\n", *info);
		ImprimeSimetricaArquivo(a->dir, impressao);
	}
}

void ImprimePosOrdemArquivo (avl *a, FILE *impressao){
	int *info = (int*) a->info;
	if(a!=NULL){
		ImprimePosOrdemArquivo(a->esq, impressao);
		ImprimePosOrdemArquivo(a->dir, impressao);
		fprintf(impressao, "| %d\n", *info);
	}
}

void ImprimeArquivo (avl *a){
	FILE *impressao;
	
	impressao = fopen ("imprimearvore.txt", "w");

	if (impressao == NULL){
		printf("xxx NÃO FOI POSSÍVEL ABRIR O ARQUIVO! xxx\n");
		exit(1);
	}

	fprintf(impressao, "------------PRÉ-ORDEM-----------\n");
	ImprimePreOrdemArquivo(a, impressao);

	fprintf(impressao, "------------SIMÉTRICA-----------\n");
	ImprimeSimetricaArquivo(a, impressao);

	fprintf(impressao, "------------PÓS-ORDEM-----------\n");
	ImprimePosOrdemArquivo(a, impressao);
	
	fclose(impressao);
}

avl *Remove(avl *a, int(*cb)(void*,void*), int *v){
	avl *temp;
	int cmp;
	cmp = cb (a->info, v);
	if (cmp == 1){
		a->esq = Remove (a->esq, cb, v);
		if(RetornaAltura(a->esq) - RetornaAltura(a->dir) == -2){
			if(RetornaAltura(a->dir->esq) - RetornaAltura(a->dir->dir) == -1){
				a=RotacaoEsquerda(a);
			}
			else{
				a=RotacaoDireitaEsquerda(a);
			}
		}
	}
	else{
		if(cmp == 0){
			a->dir = Remove (a->dir, cb, v);
			if(RetornaAltura(a->esq) - RetornaAltura(a->dir) == 2){
				if(RetornaAltura(a->esq->esq) - RetornaAltura(a->esq->dir) == 1){
					a=RotacaoDireita(a);
				}
				else{
					a=RotacaoEsquerdaDireita(a);
				}
			}
		}
		else{
			if((a->esq == NULL) && (a->dir == NULL)){
				free(a);
				a=NULL;
			}
			else{
				if(a->dir == NULL){
					avl *aux = a;
					a=a->esq;
					free(aux);
				}
				else{
					if(a->esq == NULL){
						avl *aux = a;
						a=a->dir;
						free(aux);
					}
					else{
						temp = a->esq;
						while (temp->dir!=NULL){
							temp = temp->dir;
						}
						a->info=temp->info;
						temp->info = v;
						a->esq = Remove (a->esq, cb, v);
					}
				}
			}
		}
		return a;
	}
}
