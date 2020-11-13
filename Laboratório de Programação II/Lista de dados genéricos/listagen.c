#include <stdio.h>
#include <stdlib.h>
#include "listagen.h"

struct lista{
	void *info;
	struct lista *prox;
}; 

lst *Cria(){
	return NULL;
}

void Percorre(lst *l, void (*cb)(void*)){
	lst *p;
	for (p=l; p!=NULL; p=p->prox){
		cb(p->info);
	}
}

lst *InsereGen(lst *l, void *novo){
	lst *n = (lst*) malloc (sizeof(lst));
	n->info=novo;
	n->prox=l;
	return n;
}

void Busca(lst *l, int(*cb)(void*,void*), void* m){
	lst *b;
	int cmp;
    
    for(b=l; b!=NULL; b=b->prox){
        cmp = cb(b->info, m);
        if(cmp==0){
            printf("xxx ALUNO NÃO ENCONTRADO! xxx\n\n");
        }
    }
}

lst *Remove(lst *l, int(*cb)(void*,void*), void *m){

	lst* p;
	lst* ant=NULL;
	int x;

	for(p=l; p!=NULL; p=p->prox){
		x = cb(m, p->info);
		if(x==1){
		    if(ant==NULL){
		        l=p->prox;
		    }
		    else{
                ant->prox = p->prox;
		    }
		    free(p);
            printf("--- ALUNO REMOVIDO! ---\n\n");
            return l;
		}

		else{
            ant=p;
		}
	}
	printf("xxx ALUNO NÃO ENCONTRADO! xxx\n\n");
	return l;
}

void Vazia (lst *l){
	
	if(l==NULL){
		printf("xxx LISTA VAZIA xxx\n");
	}
	else{
		printf("xxx LISTA NÃO VAZIA xxx\n");
	}
}
