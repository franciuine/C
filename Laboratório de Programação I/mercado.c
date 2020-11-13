#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct produto {
	char nome[15];
	char setor[3];
	int qtd;
	float preco;
	float pt;       //preço total
}; typedef struct produto pdt;

pdt *Insere (pdt *estoque, int p);

void MostraUm (pdt *estoque, int *p, int n);

void MostraTodos(pdt *estoque, int p, int n);

float Soma(pdt *estoque, int p);

void BuscaNome(pdt *vetor, int p);

void BuscaSetor(pdt *vetor, int p);

pdt *Venda(pdt *estoque, int p);

int main (){
	int n;          //número de espaços alocados
	int op;         //switch
	int cf;         //conrole de fluxo
	int pos;        //posição a escolher
	int p=0;        //total de produtos cadastrados
	float s;        //resultado da soma
	
	printf("| Informe quantidade de produtos a ser cadastrada: \n| ");
	scanf("%i", &n);
	printf("\n");
	
	pdt *estoque= (pdt*) malloc (n * sizeof(pdt));
	
	do{
        printf("______________________MENU______________________\n");
        printf("\n");
        printf("| 1- Inserir produto                           |\n");
        printf("| 2- Mostrar produto                           |\n");
        printf("| 3- Mostrar todos os produtos registrados     |\n");
        printf("| 4- Balanço                                   |\n");
        printf("| 5- Busca por nome                            |\n");
        printf("| 6- Busca por setor                           |\n");
        printf("| 7- Venda                                     |\n");
		printf("| 8- Sair                                      |\n");
        printf("________________________________________________\n");
        printf("\n| ");
        scanf("%i", &op);
        
        switch(op){
            case 1:
				estoque = Insere (estoque, p);
				p++;
				printf("| Produto inserido!\n\n");
				cf=1;
                break;
            case 2:
				if(cf==1){
					printf("| Posição de armazenamento do produto: \n| ");
					scanf("%i", &pos);
					printf("\n");
					MostraUm(estoque, &pos, n);
					printf("\n");
				}
				else{
					printf("| Nenhum produto registrado!\n\n");
				}
                break;
            case 3:
				if(cf==1){
					MostraTodos(estoque, p, n);
					printf("\n");
				}
				else{
					printf("| Nenhum produto registrado!\n\n");
				}
                break;
            case 4:
				if(cf==1){
					s=Soma(estoque,p+1);
					printf("\n");
					printf("| Balanço: R$%.2f\n", s);
					printf("\n");
				}
				else{
					printf("| Nenhum produto registrado!\n\n");
				}
                break;
            case 5:
				if(cf==1){
					BuscaNome(estoque, p);
					printf("\n");
				}
				else{
					printf("| Nenhum produto registrado!\n\n");
				}
                break;
            case 6:
				if(cf==1){
					BuscaSetor(estoque, p);
					printf("\n");
				}
				else{
					printf("| Nenhum produto registrado!\n\n");
				}
                break;
            case 7:
				if(cf==1){
					estoque = Venda(estoque, p);
					printf("\n");
				}
				else{
					printf("| Nenhum produto registrado!\n\n");
				}
				break;
            case 8:
				exit(1);
				break;
            default:
                printf("| Opção inválida!\n");
                break;
        }
    }while(op!=8);
	
	return 0;
}

pdt *Insere (pdt *estoque, int p){
	
	printf("\n");	
	printf("| Nome: \n| ");
	scanf("%s", estoque[p].nome);
	printf("| Setor: \n| ");
	scanf("%s", estoque[p].setor);
	printf("| Quantidade: \n| ");
	scanf("%i", &estoque[p].qtd);
	printf("| Preço: \n| ");
	scanf("%f", &estoque[p].preco);
	estoque[p].pt = estoque[p].qtd * estoque[p].preco;

	return estoque;
}

void MostraUm (pdt *estoque, int *y, int n){
		
	int x;
	
	for(x=0; x<n; x++){
		if(*y==x){
			printf("| Nome: %s\n", estoque[x].nome);
			printf("| Setor: %s\n", estoque[x].setor);
			printf("| Quantidade em estoque: %i itens\n", estoque[x].qtd);
			printf("| Preço: R$%.2f\n", estoque[x].preco);
			printf("\n");
		}
	}
	y++;
}

void MostraTodos(pdt *estoque, int p, int n){
	
	printf("\n");
	
	int x=0;
	
	while(x<=p){
		MostraUm(estoque, &x, n);
		x++;
	}
}

float Soma(pdt *estoque, int p){
	
	if(p==0){
		return estoque[0].pt;
	}
	else{
		float resultado = Soma(estoque, p-1);
		return estoque[p].pt + resultado;
	}
}

void BuscaNome(pdt *vetor, int p){
	
	char nome[15];
	
	printf("| Produto a ser buscado: ");
	scanf("%s", nome);
	printf("\n");
	
	int x;
	int n;
	
	for(x=0; x<=p; x++){
		n=strcasecmp(nome, vetor[x].nome);
		if(n==0){
			printf("| Nome: %s\n", vetor[x].nome);
			printf("| Setor: %s\n", vetor[x].setor);
			printf("| Quantidade em estoque: %i itens\n", vetor[x].qtd);
			printf("| Preço: R$%.2f\n", vetor[x].preco);
		}
	}
}

void BuscaSetor(pdt *vetor, int p){
	
	char setor[3];
	
	printf("| Setor a ser buscado: ");
	scanf("%s", setor);
	printf("\n");
	
	int x;
	int n;
	
	for(x=0; x<=p; x++){
		n=strcasecmp(setor, vetor[x].setor);
		if(n==0){
			printf("| Nome: %s\n", vetor[x].nome);
			printf("| Setor: %s\n", vetor[x].setor);
			printf("| Quantidade em estoque: %i itens\n", vetor[x].qtd);
			printf("| Preço: R$%.2f\n", vetor[x].preco);
		}
	}
}

pdt *Venda(pdt *estoque, int p){
	
	char v[15];
	int q;
	
	printf("| Produto vendido: ");
	scanf("%s", v);
	printf("| Quantidade vendida: ");
	scanf("%i", &q);
	
	int x;
	int n;
	 
	for(x=0; x<=p; x++){
		n=strcasecmp(v, estoque[x].nome);
		if(n==0){
			estoque[x].qtd = estoque[x].qtd - q;
		}
	}
	
	printf("| Produto removido do estoque!\n");
	
	return estoque;	
}
