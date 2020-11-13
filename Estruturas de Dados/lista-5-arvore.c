// Lista 5
// 14/02/2017
// Andrew Pacheco Silveira (andrew-pacheco@hotmail.com) / Franciu�ne Barbosa da Silva de Almeida (franciuine@gmail.com)

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct pessoa{
	char nome[20];
	int idade;
}PESSOA;

typedef struct arvore{
	PESSOA *p;
	struct arvore *esq;
	struct arvore *dir;
}ARV;

ARV* criar(void){
	return NULL;
}

int vazia(ARV *a){
	return a==NULL;
}

ARV* inserir(ARV *a, PESSOA *p){
	if(a == NULL){
 		ARV *a = (ARV*) malloc(sizeof(ARV));
		a->p = p;
		a->dir = NULL;
 		a->esq = NULL;
	}else{
		if(p->idade > a->p->idade){
			a->dir = inserir(a->dir, p);
		}
		if(p->idade < a->p->idade){
			a->esq = inserir(a->esq, p);
		}
	}
	return a;
}

ARV* pertence(ARV *a, int i){
    if(a==NULL){
        return NULL;
    }
    else{
        if(a->p->idade > i){
            return pertence(a->esq,i);
        }
        else{
            if(a->p->idade < i){
                return pertence(a->dir, i);
            }
            else{
                return a;
            }

        }

    }

}

ARV* remove(ARV *a, int i){
    if(a == NULL){
        return NULL;
    }
    else{
        if(a->p->idade > i){
            a->esq = remove(a->esq, i);
        }
        else{
            if(a->p->idade < i){
                a->dir = remove(a->dir, i);
            }
            else{
                if(a->esq==NULL && a->dir == NULL){
                    free (a->p);
                    free (a);
                    a = NULL;
            }
                else{
                    if(a->esq==NULL){
                        ARV *t = a;
                        a = a->esq;
                        free(t->p);
                        free(t);
                    }
                    else{
                        if(a->dir==NULL){
                            ARV *t = a;
                            a = a->dir;
                            free(t->p);
                            free(t);
                        }
                        else{
                            ARV *f = a->esq;
                            while(f->dir != NULL){
                                f = f->dir;
                            }
                            a->p = f->p;
                            f->p->idade = i;
                            a->esq = remove(a->esq, i);
                        }
                    }
                }
            }
        }
    }
    return a;   
                
}

void preOrdem(ARV *a){
	if (a != NULL){
		printf("%s\n",a->p->nome);
		printf("%i\n",a->p->idade);
		preOrdem(a->esq);
		preOrdem(a->dir);
	}
}

void simetrico(ARV *a){
	if(a != NULL){
		simetrico(a->esq);
		printf("%s\n",a->p->nome);
		printf("%i\n",a->p->idade);
		simetrico(a->dir);
	}
}

void posOrdem(ARV *a){
	if (a != NULL){
		posOrdem(a->esq);
		posOrdem(a->dir);
		printf("%s\n",a->p->nome);
		printf("%i\n",a->p->idade);
	}
}

PESSOA *maior(ARV *a){
    if((a->dir) && (a->dir->p->idade > a->p->idade))
        return maior(a->dir);
    else{
        return a->p->idade;
    }
}

PESSOA *menor(ARV *a){
    if((a->esq) && (a->esq->p->idade > a->p->idade))
        return menor(a->esq);
    else{
        return a->p->idade;
    }
}

int max(int a, int b){
return ( a > b ) ? a : b;
}

int altura(ARV *a){
    if(vazia(a)){ 
        return -1;
    }
    else{
        return 1 + max(altura(a->esq),altura(a->dir));
    }
}

int main(void){
	setlocale(LC_ALL, "Portuguese");
	ARV *a;
	int op;
	int cf = 1;
	do{
	printf("\n|\t - MENU - \n");
	printf("|  0  Sair \n");
	printf("|  1  Criar ABB vazia \n");
	printf("|  2  Inserir \n");
	printf("|  3  Procurar \n");
	printf("|  4  Remover \n");
	printf("|  5  Imprimir \n");
	printf("|  6  Altura \n");
	printf("|  7  Mostrar a pessoa mais nova e a mais velha \n");
	printf("Op.: ");
	scanf("%d", &op);
	system("@cls||clear");
	switch(op){
		case 0:
			if(cf != 2){
				printf("\n| Programa encerrado \n");
			}else{
				
				printf("\n| Lista liberada e programa encerrado \n");
			}
			break;
		case 1:
			if(cf != 1){
				printf("\n| A �rvore j� foi criada \n");
			}
			if(cf == 1){
				printf("\n| �rvore criada \n");
				cf=2;
				a = criar();
			}
			break;
		case 2:
                        if(cf != 2){
                                printf("\n| A �rvore n�o foi criada \n");
                        }
                        if(cf == 2){
                                PESSOA *p = (PESSOA*) malloc(sizeof(PESSOA));
				printf("\n| Entre com os dados da nova pessoa: \n\n");
				printf("Nome: ");
				scanf("%s", p->nome);
				printf("Idade: ");
				scanf("%i", &p->idade);
                                a = inserir(a, p);
				}
			break;
		case 3:
				if(cf != 2){
					printf("\n| A �rvore n�o foi criada \n");
				}
				if(cf == 2){
					if(!vazia(a)){
						printf("\n| �rvore vazia \n");
					}else{
						int i = 0;
						printf("\n| Entre com os dados da pessoa: \n");
						printf("\nIdade: ");
						scanf("%i", &i);
						ARV *aux;
						aux = pertence(a, i);
						if(aux == NULL){
							printf("\n| N�o encontrado \n");
						}
						else{
							printf("\n| Encontrado \n\n");
							printf("Nome: %s", aux->p->nome);
							printf("Idade: %i", aux->p->idade);
						}
					}
				}
			break;
		case 4:
                                if(cf != 2){
                                    printf("\n| A �rvore n�o foi criada \n");
                                }
                                if(cf == 2){
                                    int i;
                                    printf("\n| Valor a ser removido: \n");
                                    scanf("%i", &i);                                    
                                    a= remove(a, i);
                                }
			break;
		case 5:
				if(cf != 2){
					printf("\n| A �rvore n�o foi criada \n");
				}
				if(cf == 2){
					if(!vazia(a)){
						printf("\n| �rvore vazia \n");
					}else{
						int opi = 0;
						printf("|  1  Pr�-ordem \n");
						printf("|  2  Sim�trico \n");
						printf("|  3  P�s-ordem \n");
						printf("Op.: ");
						scanf("%i", &opi);
						if(opi == 1){
							preOrdem(a);
						}
						if(opi == 2){
							simetrico(a);
						}
						if(opi == 3){
							posOrdem(a);
						}
					}
				}
			break;
                case 6:
                        if(cf != 2){
                            printf("\n| A �rvore n�o foi criada \n");
                        }
                        if(cf == 2){
                        int alt= altura(a);
                        printf("\n| Altura = %i \n", alt);
                        }
                        break;
                case 7: 
                        if(cf != 2){
                            printf("\n| A �rvore n�o foi criada \n");
                        }
                        if(cf == 2){
                            PESSOA *ma=maior(a);
                            PESSOA *me=menor(a);
                            printf("\n| Indiv�duo mais velho: %s \n", ma->nome);
                            printf("\n| Idade: %i \n", ma->idade);
                            printf("\n");
                            printf("\n| Indiv�duo mais novo: %s \n", me->nome);
                            printf("\n| Idade: %i \n", me->idade);
                        }
                        break;
		default:
			printf("\n| Op��o invalida \n");
	}
	}while(op);
return 0;
}

