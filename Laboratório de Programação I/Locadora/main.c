#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "locadora.h"

int main (){

	FILE *filmes;
	int op;
	char q[256];
	int x=0;
	int y=0;
	char linha[256];
	int num;
	char c;

	filmes = fopen ("acervo.txt", "r");       //lista de filmes no acervo (arquivo de entrada)

	if (filmes == NULL){
		printf("Não foi possível abrir o arquivo!\n");
		exit(1);
	}

	while((q[x] = fgetc(filmes))!='\n'){
		x++;
	}

	num = atoi(q); //número de structs

	flm *filme = (flm*) malloc (num * sizeof(flm)); //aloca número de estruturas lido no arquivo
        x=0;
        while((c = fgetc(filmes))!= EOF){
            if((c =='\n')&&(c != ' ')&&(y>1)){
                linha[y] = '\0';
                MontaStructs(linha,filme, x);
                x++;
                y=0;
                linha[y]='\0';
            }
            else{
            linha[y] = c;
            y++;
            }
        }

	fclose(filmes);
        
	do{
		printf("\n");
        printf("######### MENU #########\n");
		printf("|1- Locação            |\n");
		printf("|2- Entrega            |\n");
		printf("|3- Busca              |\n");
		printf("|4- Relatórios         |\n");
		printf("|5- Sair               |\n");
		printf("########################\n");
		scanf("%d", &op);

		switch(op){
			case 1:
				Locacao(filme,num);
				break;
			case 2:
				Entrega(filme,num);
				break;
			case 3:
				Busca(filme,num);
				break;
			case 4:
				Relatorios(filme,num);
				break;
			case 5:
				exit(1);
				break;
			default:
				printf("xxx Opção inválida! xxx\n\n");
				break;
		}
	}while (op!=5);
	
	return 0;
}


