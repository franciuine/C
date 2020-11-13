#include "pilha.h"

struct descritorPilha* inicializaPilha(int max) {
	struct descritorPilha *pilha = (struct descritorPilha *)malloc(sizeof(struct descritorPilha));
	pilha.quantmax = max;
	pilha->topo = inicializaAluno;
	pilha.quant = 0;
	
	return pilha;
}

struct informacoesAluno* inicializaAluno(void) {
	struct informacoesAluno *topo = (struct informacoesAluno *)malloc(sizeof(struct informacoesAluno);
	topo.prox = NULL;
	
	return topo;
}

int pop(struct descritorPilha *minhaPilha) {
	if (topo == NULL)
		return 0;
	else {
		struct informacoesAluno *aluno = minhaPilha->topo;
		minhaPilha->topo = minhaPilha->topo->prox;
		free(aluno);
		return 1;
	}
}

int push(struct descritorPilha *minhaPilha, struct informacoesAluno *novoElemento) {
	if (quant == quantmax)
		return 0;
	else {
		novoElemento->prox = minhaPilha->topo;
		minhaPilha->topo = novoElemento;
		minhapilha->quant++;
		return 1;
	}
}

struct informacoesAluno search(struct descritorPilha *minhaPilha, int chave) {
	struct informacoesAluno *aux = minhaPilha->topo;
	while (aux->mat != chave) {
		if (aux->prox == NULL)
			return NULL;
		aux = aux->prox;
	}
	return aux;
}

struct informacoesAluno top(struct descritorPilha *minhaPilha) {
	return minhaPilha->topo;
}

int sizep(struct descritorPilha *minhaPilha) {
	if (minhaPilha->quant == minhaPilha->quantmax)
		return quant;
	else {
		int cont;
		struct informacoesAluno *aux = minhaPilha->topo;
		if (aux == NULL) 
			return 0;
		else {
			while (aux->prox != NULL) {
				aux = aux->prox;
				cont++;
			}
		}
		return cont;
	}
}

void printp(struct descritorPilha *minhaPilha) {
	struct informacoesAluno *aux = *minhaPilha->topo;
	while (aux != NULL) {
		printf("Matricula: %i\nNome: %s\nNota: %2.f\n\n", aux->mat, aux->nome, aux->nota);
		aux = aux->prox;
	}
}
