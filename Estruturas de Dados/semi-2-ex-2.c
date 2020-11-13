// Lista 2 - Exercício 2
// 03/02/2017
// Andrew Pacheco Silveira (andrew-pacheco@hotmail.com) / Franciuíne Barbosa da Silva de Almeida (franciuine@gmail.com)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lista{
    struct lista *prox;
    struct lista *ant;
    int info;
}; typedef struct lista lst;

lst *CriaLista(){
    return NULL;
}

int n=0;

lst *BuscaLista(lst *l, int x){
    lst *p;
    for(p=l; p!=NULL; p=p->prox){
        if(p->info==x){
            return p;
        }
    }
    return NULL;
}

lst *Insere(lst *l, int x){
    lst* novo = (lst*) malloc (sizeof(lst));
    novo->info=x;
    novo->prox=l;
    novo->ant=NULL;

    if(l!=NULL){
        l->ant=novo;
    }
    n++;
    return novo;
}

lst *ApagaLista(lst *l, int x){
    lst *p=BuscaLista(l, x);

    if(p==NULL){
        return l;
    }
    if(p==l){
        l=p->prox;
    }
    else{
        p->ant->prox=p->prox;
    }

    if(p->prox!=NULL){
        p->prox->ant=p->ant;
    }
    free(p);
    n--;
    return l;
}

lst *LiberaLista(lst *l){
    lst *aux=l;
    while(aux!=NULL){
        lst *temp= aux->prox;
        free(aux);
        aux=temp;
    }
    free(l);
}

void ImprimeLista(lst* l){
  if(l!=NULL){
    ImprimeLista(l->prox);
    printf(" %i\n", l->info);
  }
}

int main(){
    lst *l;
    int x;
    int op=0;
    int cf=0;

    do{
        printf("\n");
        printf(" 1: Criar uma lista\n");
        printf(" 2: Inserir elemento na lista\n");
        printf(" 3: Excluir elemento da lista\n");
        printf(" 4: Imprimir lista\n");
        printf(" 5: Número de nós na lista\n");
        printf(" 6: Liberar lista\n");
        printf(" 7: Sair do programa\n");
        printf("\n");
        printf("");
        scanf("%i", &op);

        switch(op){
            case 1:
                l= CriaLista();
                cf=1;
                break;
            case 2:
                if(cf>=1){
                    printf("\nInserir na lista: \n");
                    scanf("%i", &x);
                    l= Insere(l, x);
                    cf=2;
                }
                else{
                    printf("\nA lista ainda não foi criada!\n");
                }
                break;
            case 3:
                if(cf>=2){
                    printf("\nApagar da lista:\n");
                    scanf("%i", &x);
                    l= ApagaLista(l, x);
                    cf=3;
                }
                else{
                    printf("\nA lista ainda no foi criada ou ainda não há elementos na lista.\n");
                }
                break;
            case 4:
                if(cf>1){
                    ImprimeLista(l);
                }
                else{
                    printf("\nA lista ainda não foi criada!\n");
                }
                break;
            case 5:
                printf("\nNúmero de nós na lista: %i \n", n);
                break;
            case 6:
                if(cf>=2){
                    LiberaLista(l);
                }
                else{
                    printf("\nA lista ainda no foi criada ou ainda não há elementos na lista.\n");
                }
                break;
            case 7:
                exit(1);
                break;
            default:
                printf("\nOpção inválida!\n");
                break;
        }
    }while(op!=7);

return 0;
}

