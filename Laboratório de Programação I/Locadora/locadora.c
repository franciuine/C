#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "locadora.h"

void MontaStructs(char *linha, flm *filme, int x){

	filme[x].codigo= x+1;
	strcpy(filme[x].nome, strtok(linha,";"));

	char *ano;
	ano = strtok(NULL,";");
	filme[x].ano= atoi(ano);

	char *quantidade;
	quantidade = strtok(NULL,";");

	filme[x].quantidade= atoi(quantidade);
	
	char *genero = strtok(NULL,"");
	strcpy(filme[x].genero,genero);
	
	}

void Locacao(flm *filme, int num){
	int c;
	int x;

	printf("|Digite código: \n|");
	scanf("%i", &c);

	for(x=0; x<num; x++){
		if(c==filme[x].codigo){
			if(filme[x].quantidade >= 1){
				filme[x].quantidade = filme[x].quantidade-1;
				printf("\nxxx Registrado! xxx\n\n");
			}
			else{
				printf("\nxxx Filme não disponível! xxx\n\n");
			}
		}
	}
}


void Entrega(flm *filme, int num){
	int c;
	int x;

	printf("|Digite código: \n|");
	scanf("%i", &c);

	for(x=0; x<num; x++){
		if(c==filme[x].codigo){
			filme[x].quantidade = filme[x].quantidade+1;
		}
	}
	printf("\nxxx Registrado! xxx\n\n");
}

void Busca(flm *filme, int num){
	int op;
	int x;
	int c;
	char n[100];
	int cmp;
	
	printf("\n");
	printf("#######################\n");
	printf("|1- Busca por código  |\n");
	printf("|2- Busca por nome    |\n");
	printf("|3- Busca por ano     |\n");
	printf("|4- Busca por gênero  |\n");
	printf("#######################\n");
	scanf("%d", &op);

	switch(op){
	case 1:
		printf("|Digite código:\n|");
		scanf("%i", &c);
		for(x=0; x<num; x++){
			if(c==filme[x].codigo){
				printf("\n");
				printf("Código: %i\n", filme[x].codigo);
				printf("Nome: %s\n", filme[x].nome);
				printf("Ano: %i\n", filme[x].ano);
				printf("Quantidade: %i\n", filme[x].quantidade);
				printf("Gênero: %s\n", filme[x].genero);
			}
		}
	break;
	case 2:
		printf("|Digite nome:\n|");
                setbuf(stdin,NULL);
                scanf("%[^\n]s", n);
                n[strlen(n)]='\0';
		for(x=0; x<num; x++){
			cmp = strcasecmp(n, filme[x].nome);
			if(cmp==0){
				printf("\n");
				printf("Código: %i\n", filme[x].codigo);
				printf("Nome: %s\n", filme[x].nome);
				printf("Ano: %i\n", filme[x].ano);
				printf("Quantidade: %i\n", filme[x].quantidade);
				printf("Gênero: %s\n", filme[x].genero);
			}
		}
	break;
	case 3:
		printf("|Digite ano: \n|");
		scanf("%i", &c);
		for(x=0; x<num; x++){
			if(c==filme[x].ano){
				printf("\n");
				printf("Código: %i\n", filme[x].codigo);
				printf("Nome: %s\n", filme[x].nome);
				printf("Ano: %i\n", filme[x].ano);
				printf("Quantidade: %i\n", filme[x].quantidade);
				printf("Gênero: %s\n", filme[x].genero);
			}
		}
	break;
	case 4:
		printf("|Digite gênero:\n|");
                setbuf(stdin,NULL);
                scanf("%[^\n]s", n);
                n[strlen(n)]='\0';
		for(x=0; x<num; x++){
			cmp = strcasecmp(n, filme[x].genero);
			if(cmp==0){
				printf("\n");
				printf("Código: %i\n", filme[x].codigo);
				printf("Nome: %s\n", filme[x].nome);
				printf("Ano: %i\n", filme[x].ano);
				printf("Quantidade: %i\n", filme[x].quantidade);
				printf("Gênero: %s\n", filme[x].genero);
			}
		}
	break;
	default:
		printf("\n");
		printf("xxx Opção inválida! xxx\n\n");
		break;
	}

}

void Relatorios(flm *filme, int num){

	FILE *relatorio;
	FILE *relatoriog;
	relatorio = fopen ("relatorioacervo.txt", "w");  //relatório de saída para acervo completo
	relatoriog = fopen ("relatoriogenero.txt", "w"); //relatório de saída para gênero escolhido

	int x;
	int op;
	int cmp;
	char g[100];
	printf("\n");
	printf("############################\n");
	printf("|1- Relatório completo     |\n");
	printf("|2- Relatório ṕor gênero   |\n");
	printf("############################\n");
	printf("\n");
	scanf("%d", &op);

	switch(op){
		case 1:
			for(x=0; x<num; x++){
				printf("\n");
				fprintf(relatorio, "\n");
				printf("Código: %i\n", filme[x].codigo);
				fprintf(relatorio, "Código: %i\n", filme[x].codigo);
				printf("Nome: %s\n", filme[x].nome);
				fprintf(relatorio, "Nome: %s\n", filme[x].nome);
				printf("Ano: %i\n", filme[x].ano);
				fprintf(relatorio, "Ano: %i\n", filme[x].ano);
				printf("Quantidade: %i\n", filme[x].quantidade);
				fprintf(relatorio, "Quantidade: %i\n", filme[x].quantidade);
				printf("Gênero: %s\n", filme[x].genero);
				fprintf(relatorio, "Gênero: %s\n", filme[x].genero);
			}
			break;
		case 2:
			printf("Digite gênero:\n");
			setbuf(stdin,NULL);
			scanf("%[^\n]s", g);
			for(x=0; x<num; x++){
				cmp = strcasecmp(filme[x].genero,g);
				if(cmp==0){
					printf("\n");
					fprintf(relatoriog, "\n");
					printf("Código: %i\n", filme[x].codigo);
					fprintf(relatoriog, "Código: %i\n", filme[x].codigo);
					printf("Nome: %s\n", filme[x].nome);
					fprintf(relatoriog, "Nome: %s\n", filme[x].nome);
					printf("Ano: %i\n", filme[x].ano);
					fprintf(relatoriog, "Ano: %i\n", filme[x].ano);
					printf("Quantidade: %i\n", filme[x].quantidade);
					fprintf(relatoriog, "Quantidade: %i\n", filme[x].quantidade);
					printf("Gênero: %s\n", filme[x].genero);
					fprintf(relatoriog, "Gênero: %s\n", filme[x].genero);
                                }
                        }
			break;
		default:
			printf("xxx Opção inválida! xxx\n\n");
			break;
	}
    fclose(relatorio);
    fclose(relatoriog);
}
