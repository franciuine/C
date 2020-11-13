// Pesquisa e Classificação de Dados - Atividade Semi-Presencial 04
// 24/05/2018
// Franciuíne Almeida (francuine@gmail.com)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct hash{
	int cod;
	char descricao[40];
	float valor;
	struct hash *prox;
	int colisao;
}; typedef struct hash hash;

int Ocupacao (int n);

int main (){
	int op, tam, n, x, c, k, end, count, y=0, existe=0;
	hash *aux = NULL;
	hash *novo = NULL;
	
	printf("| Defina o número de registros: ");
	scanf("%i", &n);
	
	tam = Ocupacao(n);
	printf("| Tamanho total da tabela: %i\n", tam);
	
	hash *tabela[tam];
	int keys[n];
	
	for(x=0; x<tam; x++){
		tabela[x] = NULL;
	}
	
	do{
		printf("\n========================\n");
		printf("| 1- Inserir registro  |\n");
		printf("| 2- Consultar tabela  |\n");
		printf("| 3- Exibir registros  |\n");
		printf("| 0- Sair              |\n");
		printf("========================\n| ");
		scanf("%i", &op);
		
		switch(op){
			case 0:
				exit(1);
				break;
			case 1:
				if(c==n){
					printf("| NÚMERO MÁXIMO DE REGISTROS ALCANÇADO! |\n");
				}
				else{
					existe = 0;
					printf("\n");
					novo = malloc (sizeof(hash));
	
					printf("| Código:\n| ");
					scanf("%i", &k);
					
					for(x=0; x<tam; x++){
						if(k==keys[x]){
							printf("| ESTE CÓDIGO JÁ EXISTE NA TABELA! |\n");
							existe = 1;
						}
					}
					
					if(existe == 1){
						break;
					}
					
					keys[y]=k;
					y++;

					//preenche novo nodo
					novo->cod = k;
					printf("| Descrição:\n| ");
					scanf("%s", novo->descricao);
					printf("| Valor:\n| ");
					scanf("%f", &novo->valor);
					novo->prox = NULL;
	
					//calcula hash
					end = novo->cod % tam;
	
					//insere novo nodo na tabela
					novo->prox = tabela[end];
					tabela[end] = novo;
					c++;
				}
				
				printf("\n");
				for (x=0; x<tam; x++){
					count = 0;
					aux = tabela[x];
					printf("| %i	", x);
					while (aux != NULL) {
						printf("| %d | %s | %.2f |-> ", aux->cod, aux->descricao, aux->valor); 
						aux = aux->prox;
						count++;
					}
					printf("(%i)\n", count);
					if(count > 1){
						tabela[x]->colisao = 1;
					}
				} 
				break;
			case 2:
				if(c==0){
					printf("| TABELA VAZIA! |\n");
				}
				else{
					printf("\n| Digite código para busca:\n| ");
					scanf("%i", &k);
	
					end = k % tam;
					
					if(tabela[end] == NULL){
						printf("\n| REGISTRO NÃO ENCONTRADO! |\n");
						break;
					}
					
					if(tabela[end]->colisao == 1){
						for(aux = tabela[end]; aux!=NULL; aux = aux ->prox){
							if(aux->cod == k){
								printf("\n");
								printf("| Endereço: %i | Código: %i | Descrição: %s | Valor: %.2f |\n", end, aux->cod, aux->descricao, aux->valor);
							}
						}
					}
					else{
						printf("\n");
						printf("| Endereço: %i | Código: %i | Descrição: %s | Valor: %.2f |\n", end, tabela[end]->cod, tabela[end]->descricao, tabela[end]->valor);
					}
				}
				break;
			case 3:
				printf("\n");
				for (x=0; x<tam; x++){
					count = 0;
					aux = tabela[x];
					printf("| %i	", x);
					while (aux != NULL) {
						printf("| %d | %s | %.2f |-> ", aux->cod, aux->descricao, aux->valor); 
						aux = aux->prox;
						count++;
					}
					printf("(%i)\n", count);
					if(count > 1){
						tabela[x]->colisao = 1;
					}
				} 
				break;
			default:
				printf("| OPÇÃO INVÁLIDA! |\n");
				break;
		}
	} while(op!=0);
	
	return 0;
}

int Ocupacao (int n){
	int tam;
	float oc;
	
	printf("| Defina porcentagem de ocupação da tabela: ");
	scanf("%f", &oc);
	
	oc = oc/100;
	tam = n/oc;
	tam = tam + 1;
	
	return tam;
}
