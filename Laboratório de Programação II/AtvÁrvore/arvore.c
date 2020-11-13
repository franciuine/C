#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"


arv *InsereArvore(arv *a, int x){
	if(a==NULL){                    //quando for folha, insere
		a=(arv*) malloc (sizeof(arv));
		a->info=x;
		a->esq=NULL;
		a->dir=NULL;
	}
	else{
		if(x < a->info){
			a->esq = InsereArvore(a->esq, x);
		}
		else{
			a->dir = InsereArvore(a->dir, x);
		}
	}
	return a;
}

void ImprimePreOrdem(arv *a){
	if(a!=NULL){
		printf("| %d\n", a->info);    
		ImprimePreOrdem(a->esq);      
		ImprimePreOrdem(a->dir);     
	}
}

void ImprimeSimetrica(arv *a){
	if(a!=NULL){
		ImprimeSimetrica(a->esq);    
		printf("| %d\n", a->info);
		ImprimeSimetrica(a->dir);
	}
}

void ImprimePosOrdem(arv *a){
	if(a!=NULL){
		ImprimePosOrdem(a->esq);
		ImprimePosOrdem(a->dir);
		printf("| %d\n", a->info);
	}
}

void BuscaArvore(arv *a, int x){
	if(a==NULL){
		printf("|Árvore não encontrada!\n\n");
		return;
	}
	arv *atual= a;
		while(atual!=NULL){         //enquanto não chegar nas folhas
			if(x == atual->info){
				printf("|Valor encontrado!\n\n");
			}
			if(x > atual->info){
				atual = atual->dir;
			}
			else{
				atual = atual->esq;
			}
		}
}

int Menor(arv *a){
	if((a->esq) && (a->esq->info < a->info)){
        return Menor(a->esq);
    }
	else{
		return a->info;
	}
}
	
int Maior(arv *a){
	if((a->dir) && (a->dir->info > a->info)){
        return Maior(a->dir);
    }
	else{
		return a->info;
	}
}

arv *RemocaoArvore(arv *a, int x){
	if(a==NULL){
		printf("|Árvore não encontrada!\n\n");
		return NULL;
	}
	else{
		if(x < a->info){
			a->esq = RemocaoArvore(a->esq,x);
		}
		else{
			if(x > a->info){
				a->dir = RemocaoArvore(a->dir,x);
			}
			else{      //achou nó a remover
				if(a->esq==NULL && a->dir==NULL){  //nó sem filhos
					free(a);
					return NULL;
				}
				else{                              //filhos só à esquerda
					if(a->dir==NULL){
						arv *aux=a;
						a=a->esq;
						free(aux);
					}
					else{                          //filhos só à direita
						if(a->esq==NULL){
							arv *aux=a;
							a=a->dir;
							free(aux);
						}
						else{                      //nó com dois filhos
							arv *tmp=a->esq;
							while(tmp->dir != NULL){
								tmp=tmp->dir;
							}
							a->info=tmp->info;
							tmp->info=x;
							a->esq=RemocaoArvore(a->esq,x);
						}
					}
				}
			}
		}
	}
	return a;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
