#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

plh *CriaPilha(){
	
	plh *p = (plh*) malloc (sizeof (plh));
	p->topo=NULL;
	return p;

}

plh *PushPilha (plh *p){
	
	lst *novo = (lst*) malloc (sizeof (lst));
        
	printf("Digite nome: \n");
	scanf("%s", novo->nome);
	printf("Digite nota: \n");
	scanf("%f", &novo->nota);
        printf("\n");
	
	novo->prox = p->topo;
	p->topo=novo;
	
	return p;
}

void ImprimePilha (plh *p){
	
	lst *t;
	
	for(t=p->topo; t!=NULL; t=t->prox){
                printf("\n");
		printf("Aluno: %s \n", t->nome);
		printf("Nota: %.2f \n", t->nota);
	}
}