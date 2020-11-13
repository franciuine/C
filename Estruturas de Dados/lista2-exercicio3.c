// Lista 2 exercício 3
// 06/02/2017
// Andrew Pacheco Silveira (andrew-pacheco@hotmail.com), Franciuíne Barbosa da Silva de Almeida (franciuine@gmail.com)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data{
	int dia, mes, ano, i;
}DATA;

typedef struct aluno{
	char nome[80];
	DATA *nascimento;
}ALUNO;

typedef struct lista{
	ALUNO *pessoa;
	struct lista *prox;
	struct lista *ant;
}LISTA;

LISTA *criar(void){
	printf("\n| Lista criada \n");
	return NULL;
}

LISTA *inserir(LISTA *lst){
	printf("\n| Entre com os dados do novo aluno \n\n");
	ALUNO *a = (ALUNO*)malloc(sizeof(ALUNO));
	printf("Nome: "); 
	scanf("%s", a->nome);
	a->nascimento=(DATA*)malloc(sizeof(DATA));
	printf("Dia de nascimento: ");
	scanf("%i", &a->nascimento->dia);
	printf("Mes de nascimento: ");
	scanf("%i", &a->nascimento->mes);
	printf("Ano de nascimento: ");
	scanf("%i", &a->nascimento->ano);
		
	LISTA *novo = (LISTA*)malloc(sizeof(LISTA));
	novo->pessoa =a;
	novo->prox = lst;
	novo->ant = NULL;
	
	if(lst != NULL){
		lst->ant = novo;
	}
	
	printf("\n| Aluno inserido com sucesso \n");
	
	return novo;
}

void imprimir(LISTA *lst){
	if(lst != NULL){
		printf("\n  %s - %i/%i/%i\n", lst->pessoa->nome, lst->pessoa->nascimento->dia, lst->pessoa->nascimento->mes, lst->pessoa->nascimento->ano);
		imprimir(lst->prox);
	}
}

void aoinverso(LISTA *lst){
	if(lst != NULL){
		aoinverso(lst->prox);
		printf("\n  %s - %i/%i/%i\n", lst->pessoa->nome, lst->pessoa->nascimento->dia, lst->pessoa->nascimento->mes, lst->pessoa->nascimento->ano);
	}
}

int nalunos(LISTA *lst){
	int x = 0;
	while(lst != NULL){
		x++;
		lst = lst->prox;
	}
	return x;
}

void maisnovo(LISTA *lst){
	int i, h, dh = 7, mh = 2, ah = 2017;
	LISTA *p1 = lst;
	LISTA *p2 = lst->prox;
	LISTA *p3 = lst;
	LISTA *p4 = lst;
	while(lst != NULL){
		i = lst->pessoa->nascimento->dia + lst->pessoa->nascimento->mes*30 + lst->pessoa->nascimento->ano*365;
		h = dh + mh*30 + ah*365; 
		lst->pessoa->nascimento->i = h-i;
		lst = lst->prox;
	}
	while(p1 != NULL){
		while(p2 != NULL){
			if(p1->pessoa->nascimento->i > p2->pessoa->nascimento->i){
				p3 = p2;										
			}
			p2 = p2->prox;
		}
		p2 = p4;	
		p1 = p1->prox;
	}
	printf("\n| Aluno mais novo \n");
	printf("\n  %s - %i/%i/%i\n", p3->pessoa->nome, p3->pessoa->nascimento->dia, p3->pessoa->nascimento->mes, p3->pessoa->nascimento->ano);
}

LISTA *remover(LISTA *lst, char *n){
	LISTA *p = lst;
	while(p != NULL && strcmp(p->pessoa->nome, n) != 0){
		p->ant = p;
		p = p->prox;
	}
	if(p == NULL){
		printf("\n| Aluno não encontrado \n\n");
		return lst;
	}
	if(lst == p){
		lst = p->prox;
	}else{
		p->ant->prox = p->prox;
	}
	if(p->prox != NULL){
		p->prox->ant = p->ant;
	}
	printf("\n| Aluno removido \n");
	free(p);
	return lst;
}

void liberar(LISTA *lst){
	LISTA *p = lst;
	while(p != NULL){
		LISTA *t = p->prox; 
		free(p); 
		p = t; 
	}
}

int main(void){
	LISTA *lst;
	char n[80];
	int na = 0;
	int op = 1;
	int cf = 1;
	do{
	printf("\n|   -- Menu --  				\n");
	printf("|  0  -  Sair      				\n");
	printf("|  1  -  Criar lista     		\n");
	printf("|  2  -  Inserir aluno na lista \n");
	printf("|  3  -  Imprimir alunos  		\n");
	printf("|  4  -  Imp. ao inverso   		\n");
	printf("|  5  -  Imp. n de alunos    	\n");
	printf("|  6  -  Imp. aluno mais novo   \n");
	printf("|  7  -  Remover aluno    		\n");
	printf("|  8  -  Liberar lista    		\n");
	printf("Op.: "); 
	scanf("%d", &op);
	system("@cls||clear");
	switch(op){
		case 0:	//encerra programa
				if(cf != 2){
					printf("\n| Programa encerrado \n");
				}else{
					liberar(lst);
					printf("\n| Lista liberada e programa encerrado \n");
				}
			break;
		case 1: // criar lista
				if(cf != 1){
					printf("\n| A lista já foi criada \n");
				}
				if(cf == 1){
					cf=2;	
					lst = criar();
				}
			break;
		case 2:	// inserir nos na lista
				if(cf != 2){
					printf("\n| A lista não foi criada \n");
				}
				if(cf == 2){
					lst = inserir(lst);
				}
			break;
		case 3: // mostrar lista na seguencia em que os nos foram adicionados
				if(cf != 2){
					printf("\n| A lista não foi criada \n");
				}
				if(lst == NULL){
					printf("\n| Lista vazia \n");
				}
				if(cf == 2 && lst != NULL){
					printf("\n| Imprimindo lista de alunos \n");
					imprimir(lst);
				}
			break;	
		case 4: // mostrar lista na seguencia inversa
				if(cf != 2){
					printf("\n| A lista não foi criada \n");
				}
				if(lst == NULL){
					printf("\n| Lista vazia \n");
				}
				if(cf == 2 && lst != NULL){
					printf("\n| Imprimindo lista de alunos ao inverso \n");
					aoinverso(lst);
				}
			break;	
		case 5: // mostrar numero de nos da lista
				if(cf != 2){
					printf("\n| A lista não foi criada \n");
				}
				if(lst == NULL){
					printf("\n| Lista vazia \n");
				}
				if(cf == 2 && lst != NULL){
					na = nalunos(lst);		
					if(na == 1){
						printf("\n| Existe %i aluno na lista \n", na);
					}
					if(na > 1){
						printf("\n| Existem %i alunos na lista \n", na);
					}
				}
			break;
		case 6:	// mostra aluno mais novo
				if(cf != 2){
					printf("\n| A lista não foi criada \n");
				}
				if(lst == NULL){
					printf("\n| Lista vazia \n");
				}
				if(cf == 2 && lst != NULL){
					maisnovo(lst);
				}
			break;
		case 7:	// remover no da lista
				if(cf != 2){
					printf("\n| A lista não foi criada \n");
				}
				if(lst == NULL){
					printf("\n| Lista vazia \n");
				}
				if(cf == 2 && lst != NULL){
					printf("\n| Qual aluno deseja remover? \n\n");
					printf("Nome: ");
					scanf("%s", n);
					lst = remover(lst, n);
				}
			break;
		case 8:	// liberar lista
				if(cf != 2){
					printf("\n| A lista não foi criada \n");
				}
				if(cf == 2){
					cf = 1;
					liberar(lst);
					printf("\n| Lista liberada \n");
				}
			break;
		default:
			printf("\n| Opção invalida\n");
	}
	}while(op);
return 0;
}

