#include<stdio.h>
#include<stdlib.h>

struct lista{
    void *info;
    struct lista *prox;
};typedef struct lista ListaGen;

ListaGen *cria_lista(){
    return NULL;
}

ListaGen *lista_insere(ListaGen *l, void *p){
    ListaGen *novo=(ListaGen*)malloc(sizeof(ListaGen));
    novo->info=p;
    novo->prox=l;
    return novo;
}

void percorre(ListaGen *l, void(*cb)(void*)){
ListaGen *p;
    for(p=l; p!=NULL; p=p->prox){
        cb(p->info);
    }
}

void vazia(ListaGen *l){
    if(l==NULL){
        printf("Lista Vazia\n");
    }
    else{
        printf("A lista contem elementos!\n");
    }
}
void lgen_busca(ListaGen *l,int(*cb)(void*,void*),void* dado){
ListaGen *p;
    for(p=l; p!=NULL; p=p->prox){
        int i;
        i =cb(p->info,dado);
        if(i==1){
            break;
        }else{
            printf("Aluno não encontrado!\n");
            break;
        }
    }
}

ListaGen* lgen_exclui (ListaGen* l,int (*cb)(void*,void*),void* dado){
	ListaGen* p;
	ListaGen* ant=NULL;
	int r;

	if(p==NULL){
        printf("Lista Vazia");
        return p;
	}

	for(p=l;p!=NULL;p=p->prox){
		r = cb(dado,p->info);
		if(r==1){
		    if(ant==NULL){
		        l=p->prox;
		    }
		    else{
                ant->prox=p->prox;
		    }
		    free(p);
            printf("Elemento excluido.\n\n");
            return l;
		}

		else{
            ant=p;
		}
	}
	printf("Elemento nao encontrado.\n\n");
	return l;
}

ListaGen* libera (ListaGen* l){
    ListaGen* p=l;
    ListaGen* aux;
    while (p!=NULL)
    {
        aux=p;
        p=p->prox;
        free(aux);
    }
    return NULL;
}
