#include <stdio.h>
#include <stdlib.h>

struct data{
int dia;
int mes;
int ano;
}; typedef struct data Data;

struct pessoa{
char nome[20];
int idade;
Data *nasc;
}; typedef struct pessoa Pessoa;

struct lista{
Pessoa *p;
struct lista *prox;
}; typedef struct lista Lista;

struct fila{
Lista *ini;
Lista *fim;
}; typedef struct fila Fila;

Fila *fila_cria(void){
    Fila *f= (Fila*) malloc (sizeof(Fila));
    f->ini=f->fim=NULL;
    return f;
}

int fila_vazia(Fila *f){
    return (f->ini==NULL);
}

void *fila_insere(Fila *f, int a){

    Lista *l= (Lista*) malloc (sizeof(Lista));
    l->p = (Pessoa*)malloc(sizeof(Pessoa));
    l->p->nasc=(Data*)malloc(sizeof(Data));
    printf("Digite nome: \n");
    scanf("%s", l->p->nome);

    printf("Digite dia de nascimento: \n");
    scanf("%i", &l->p->nasc->dia);

    printf("Digite mês de nascimento: \n");
    scanf("%i", &l->p->nasc->mes);

    printf("Digite ano de nascimento: \n");
    scanf("%i", &l->p->nasc->ano);

    l->p->idade= a -(l->p->nasc->ano);

    l->prox=NULL;

    if(f->fim!=NULL){
        f->fim->prox=l;
    }
    else{
        f->ini=l;
    }
    f->fim=l;

    return f;
}

Fila *fila_retira(Fila *f){
    Lista *aux= f->ini;
    int x;
    
    x= aux->p;

    f->ini=f->ini->prox;

    if(f->ini == NULL){
        f->fim = NULL;
    }

    free(aux);

    printf("Item retirado!");

    return f;
}

void fila_libera(Fila *f){
    Lista *aux1= f->ini;
    while(aux1!=NULL){
        Lista *aux2= aux1->prox;
        free(aux1);
        aux1=aux2;
    }
    free(f);
}

void fila_imprime(Fila *f){
    Lista *aux;
    for(aux=f->ini; aux!=NULL; aux=aux->prox){
        printf("Nome: %s\n", aux->p->nome);
        printf("Idade: %i\n", aux->p->idade);
        printf("Data de nascimento: %i / %i/ %i\n", aux->p->nasc->dia, aux->p->nasc->mes, aux->p->nasc->ano);
    }
}

void fila_imprime_maiores(Fila *f, int d, int m){
    Lista *aux;
    for(aux=f->ini; aux!=NULL; aux=aux->prox){
        if(aux->p->idade >= 18 && aux->p->nasc->mes >= m && aux->p->nasc->dia >= d){
            printf("Nome: %s\n", aux->p->nome);
            printf("Idade: %i\n", aux->p->idade);
            printf("Data de nascimento: %i / %i/ %i\n", aux->p->nasc->dia, aux->p->nasc->mes, aux->p->nasc->ano);
        }
    }
}

void fila_imprime_especial(Fila *f){
    int d, m, a;
    int op;
    Lista *aux;
    
    printf("1- Buscar por dia\n2- Buscar por mês\n3-Buscar por ano\n");
    scanf("%i", &op);
    
    switch(op){
        case 1:
            printf("Digite dia: \n");
            scanf("%i", &d);
            for(aux=f->ini; aux!=NULL; aux=aux->prox){
                 if(aux->p->nasc->dia == d){
                 printf("Nome: %s\n", aux->p->nome);
                 printf("Idade: %i\n", aux->p->idade);
                 printf("Data de nascimento: %i / %i/ %i\n", aux->p->nasc->dia, aux->p->nasc->mes, aux->p->nasc->ano);
            }
    }
            break;
        case 2:
            printf("Digite mês: \n");
            scanf("%i", &m);
            for(aux=f->ini; aux!=NULL; aux=aux->prox){
                 if(aux->p->nasc->mes == m){
                 printf("Nome: %s\n", aux->p->nome);
                 printf("Idade: %i\n", aux->p->idade);
                 printf("Data de nascimento: %i / %i/ %i\n", aux->p->nasc->dia, aux->p->nasc->mes, aux->p->nasc->ano);
            }
    }
            break;
        case 3:
            printf("Digite ano: \n");
            scanf("%i", &a);
            for(aux=f->ini; aux!=NULL; aux=aux->prox){
                 if(aux->p->nasc->ano == a){
                 printf("Nome: %s\n", aux->p->nome);
                 printf("Idade: %i\n", aux->p->idade);
                 printf("Data de nascimento: %i / %i/ %i\n", aux->p->nasc->dia, aux->p->nasc->mes, aux->p->nasc->ano);
            }
    }
            break;
        default:
            printf("Opção inválida");
            fila_imprime_especial(f);
            break;
    
    }
}

int main(){
    int d, m, a;
    int v;
    printf("Insira o atual dia, mês e ano, respectivamente:\n");
    scanf("%i %i %i", &d, &m, &a);
    Fila *f;
    
    do{
    int cf=0;
    int op;
    printf("_____________MENU_____________\n\n");
    printf("1- Criar fila\n");
    printf("2- Inserir pessoa na fila\n");
    printf("3- Retirar pessoa da fila\n");
    printf("4- Mostrar conteúdo da fila\n");
    printf("5- Mostrar maiores de 18 anos\n");
    printf("6- Busca especial\n");
    printf("7- Limpar fila\n");
    printf("8- Sair do programa\n");
    scanf("%i", &op);

    switch(op){
        case 1:
            fila_cria();
            cf=1;
            break;
    
        case 2:
            if(cf>=1){
                f= fila_insere(f, a);
                cf=2;
            }
            else{
                printf("A fila ainda não foi criada!\n");
            }
            break;
    
        case 3:
            v= fila_vazia(f);
            if(v==0){
                f= fila_retira(f);
            }
            else{
                printf("A fila está vazia!\n");
            }
            break;
    
        case 4:
            if(cf>=2){
                fila_imprime(f);
            }
            else{
                printf("A fila ainda não foi criada ou ainda não possui itens!\n");
            }
            break;
        
        case 5:
            if(cf>=2){
                fila_imprime_maiores(f, d, m);
            }
            else{
                printf("A fila ainda não foi criada ou ainda não possui itens!\n");
            }
            break;
            
        case 6:
            if(cf>=2){
                fila_imprime_especial(f);
            }
            else{
                printf("A fila ainda não foi criada ou ainda não possui itens!\n");
            }
            break;
            
        case 7:
            if(cf>=2){
                fila_libera(f);
            }
            else{
                printf("A fila ainda não foi criada ou ainda não possui itens!\n");
            }
            break;
            
        case 8:
            exit(1);
            break;
            
        default:
            printf("Opção inválida!\n");
            break;
    }while(op!=8);

return 0;
}