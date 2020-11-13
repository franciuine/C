// Lista 3
// 09/02/2017
// Andrew Pacheco Silveira (andrew-pacheco@hotmail.com) / Franciuíne Barbosa da Silva de Almeida (franciuine@gmail.com)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct lista{
	float info;	
	struct lista *prox;
}LISTA;

typedef struct pilha{
	LISTA *prim;
}PILHA;

int cf1 = 1;

PILHA *pilha_cria(void){
	PILHA *p = (PILHA*) malloc(sizeof(PILHA));
	p->prim = NULL;
	return p;
}

void pilha_libera(PILHA *p){
	LISTA *q = p->prim;
	while(q != NULL){
		LISTA *t = q->prox;
		free(q);
		q = t;
	}
	free(p);
}

PILHA *pilha_push (PILHA *p, float operando){
	LISTA *n = (LISTA*) malloc(sizeof(LISTA));
	n->info = operando;
	n->prox = p->prim;
	p->prim = n;
	return p;
}

float pilha_pop(PILHA *p){
	LISTA *t;
	float operando;
	if(pilha_vazia(p)){
		printf("\n| [ERRO!] Pilha vazia \n");
		return ;
	}
	t = p->prim;
	operando = t->info;
	p->prim = t->prox;
	free(t);
	cf1--;
	return operando;
}

void pilha_imprime(PILHA *p){
	LISTA *q;
	for(q = p->prim; q!=NULL; q=q->prox){
		printf("	%.2f\n", q->info);
	}
}

int pilha_vazia(PILHA *p){
	if(p->prim == NULL)
		return 1;
	else
		return 0;
}

void calcular(PILHA *p, char *operador){
	float op1 = 0;
	float op2 = 0;
	float r = 0;
	op1 = pilha_pop(p);
	op2 = pilha_pop(p);
	if(operador[0] == '+'){
		r = op1 + op2;
	}
	if(operador[0] == '-'){
		r = op1 - op2;
	}
	if(operador[0] == '*'){
		r = op1 * op2;
	}
	if(operador[0] == '/'){
		r = op1 / op2;
	}
	printf("\n %.2f %s %.2f = %.2f\n", op1, operador, op2, r);
}

int main(void){
	setlocale(LC_ALL, "Portuguese");
	PILHA *p;
	int op = 1;
	int cf = 1;
	float operando = 0;
	char operador[0];
	do{
	printf("\n| -- Menu --	\n");
	printf("| 0 - Sair \n");
	printf("| 1 - Criar pilha \n");
	printf("| 2 - Empilhar novo operando na pilha \n");
	printf("| 3 - Imprimir pilha \n");
	printf("| 4 - Calcular \n");
	printf("Op.: "); 
	scanf("%i", &op);
	system("@cls||clear");
	switch(op){
		case 0:	//encerra programa
				if(cf != 2){
					printf("\n| Programa encerrado. \n");
				}else{
					pilha_libera(p);
					printf("\n| Pilha liberada e programa encerrado. \n");
				}
			break;
		case 1: // criar pilha
				if(cf != 1){
					printf("\n| [ERRO!] A pilha já foi criada. \n");
				}
				if(cf == 1){
					printf("\n| Pilha criada. \n");
					cf = 2;
					p = pilha_cria();
				}
			break;
		case 2:	// inserir operando na pilha
				if(cf != 2){
					printf("\n| [ERRO!] A pilha não foi criada. \n");
				}
				if(cf == 2){
					printf("\n| Entre com os dados do novo operando: \n");
					printf("\nOperando: ");
					scanf("%f", &operando);
					cf1++;
					p = pilha_push(p, operando);
				}
			break;
		case 3: // imprimir pilha
				if(cf != 2){
					printf("\n| [ERRO!] A pilha não foi criada. \n");
				}
				if(cf == 2){
					if(pilha_vazia(p)){
						printf("\n| [ERRO!] Pilha vazia. \n");
					}
					if(pilha_vazia(p) != 1){
						printf("\n| Imprimindo pilha: \n\n");
						pilha_imprime(p);
					}
				}
			break;	
		case 4: // calcular
				if(cf != 2){
					printf("\n| [ERRO!] A pilha não foi criada. \n");
				}
				if(cf == 2){
					if(pilha_vazia(p)){
						printf("\n| [ERRO!] Pilha vazia. \n");
					}
					if(pilha_vazia(p) != 1){
						if(cf1 < 3){
							printf("\n| [ERRO!] A pilha não tem 2 ou mais operandos. \n");
						}
						if(cf1 >= 3){
							operador[0] = 'a';
							while(operador[0] != '+' && operador[0] != '-' && operador[0] != '*' && operador[0] != '/'){
							printf("\n| Entre com o operador  (+) (-) (*) (/): \n");
							printf("| Adição (+), Subtração (-), Multiplicação (*), Divisão (/): \n");
								printf("\nOperador: ");
								scanf("%s", operador);
								if(operador[0] != '+' && operador[0] != '-' && operador[0] != '*' && operador[0] != '/'){
									system("@cls||clear");
									printf("\n| [ERRO!] Operador invalido. \n");
								}else{
									calcular(p, operador);
								}
							}
						}
					}
				}
			break;	
		default:
			printf("\n| [ERRO!] Opção invalida. \n");
	}
	}while(op);
return 0;
}
