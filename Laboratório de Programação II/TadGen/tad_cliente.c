#include<stdio.h>
#include<stdlib.h>
#include "tad_generico.h"

void* achou =NULL;

struct aluno{
    char nome[50];
    int mat;
};typedef struct aluno Aluno;

ListaGen *insere(ListaGen *l){
    Aluno *a= (Aluno*)malloc(sizeof(Aluno));
    printf("Informe nome\n");
    scanf(" %[^\n]", a->nome);
    printf("Infome matricula\n");
    scanf("%d", &a->mat);
    return lista_insere(l,a);
}

static void imprime (void* valor) {
    Aluno *a=(Aluno*)valor;
    printf("Nome:%s\n", a->nome);
    printf("Matricula:%d\n", a->mat);
    printf("\n\n");
}

static int igualdade(void* info, void* dado){
    int* m = (int*)dado;
    Aluno* a =(Aluno*)info;
    if(a->mat == (*m)){
        printf("Aluno Encontrado!\n");
        imprime(a);
        return 1;
    }
    return 0;
}

static int compara (void* dado, void* info){
    int * a=(int*)dado;
    Aluno* b=(Aluno*)info;
    if((*a)==b->mat){
        free(b);
        return 1;
    }
    return 0;
}

static ListaGen* excluir (ListaGen* l){
    int dado;
    printf("Informe a matricula: ");
    scanf("%d",&dado);
    l= lgen_exclui(l,compara,&dado);
    return l;
}

int main(void){
int op;
ListaGen *l;
int mat;

    printf("Informe a opção\n");
    printf("1-Criar Lista\n");
    printf("2-Inserir na Lista\n");
    printf("3-Imprime Lista\n");
    printf("4-Excluir da Lista[Mátricula]\n");
    printf("5-Liberar Lista\n");
    printf("6-Buscar\n");
    printf("7-Verificar se Lista Vazia\n");
    scanf("%d", &op);

while(op<8){
    switch(op){
            case 1:
                l=cria_lista();
                printf("Lista Criada!\n");
                printf("\n\n");
                break;

            case 2:
                l=insere(l);
                printf("\n\n");
                break;
            case 3:
                percorre(l, imprime);
                printf("\n");
                break;
            case 4:
                l=excluir(l);
                printf("\n\n");
                break;
            case 5:
                l = libera(l);
                printf("\n\n");
                break;
            case 6:
                 printf("Informe a matricula\n");
                 scanf("%d",&mat);
                 lgen_busca (l,igualdade,&mat);
                 printf("\n\n");
                 break;
            case 7:
                 vazia(l);
                 printf("\n\n");
                 break;


    }
printf("Informe a opção\n");
printf("1-Criar Lista\n");
printf("2-Inserir na Lista\n");
printf("3-Imprime Lista\n");
printf("4-Excluir da Lista[Mátricula]\n");
printf("5-Liberar Lista\n");
printf("6-Buscar\n");
printf("7-Verificar se Lista Vazia\n");
scanf("%d", &op);
}
}
