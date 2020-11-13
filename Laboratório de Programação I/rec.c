#include <stdio.h>
#include <stdlib.h>

int * CriaVetor (int *vet, int *tamanho);

void  ImprimeVetor (int *vet, int tamanho);

int SomaVet (int *vet, int n);

void  ImprimeVetorDec (int *vet, int n, int tamanho, int np);
 
int MenorValor (int *vet, int n);

int Potencia(int b, int e);

int main(){

	int n=0;   //tamanho do vetor
	int *vet;  //vetor
	int m;     //média
	int np;    //índice par
	int s;     //soma
	int e;     //expoente
	int b;     //base
	int p;     //resultado da potenciação
	int menor; //menor valor encontrado no vetor
	int op;    //opção
	int cf;    //controle de fluxo


	do{
		printf("_______MENU_______\n");
        printf("|1- Criar vetor\n");
        printf("|2- Média\n");
        printf("|3- Menor elemento\n");
        printf("|4- Imprimir elementos pares em ordem decrescente\n");
        printf("|5- Somar elementos do vetor\n");
        printf("|6- Calcular potência\n");
        printf("|7- Sair\n");
        printf("\n");
        scanf("%i", &op);

        switch(op){
			case 1:
				vet=CriaVetor(vet, &n);
				printf("\n");
				ImprimeVetor(vet,n);
				printf("\n");
				cf=1;
				break;
			case 2:
				if(cf!=1){
					printf("| Vetor não criado!\n\n");
				}
				else{
					s=SomaVet(vet, (n-1));
					m=s/n;
					printf("| Média = %d\n\n", m);
				}
				break;
			case 3:
				if(cf!=1){
					printf("| Vetor não criado!\n\n");	
				}
				else{
					menor=MenorValor(vet, n-1);
					printf("| Menor valor encontrado no vetor: %d\n\n", menor);
				}
				break;
			case 4:
				if(cf!=1){
					printf("| Vetor não criado!\n\n");	
				}
				else{
					printf("| Defina valor: \n\n");
					scanf("%i", &np);
					
					if(np % 2 == 0){
						ImprimeVetorDec(vet,0, n, np);
					}
					else{
						printf("| Digite um número par!\n");
					}
				}
				break;
			case 5:
				if(cf!=1){
					printf("| Vetor não criado!\n\n");
				}
				else{
					s=SomaVet(vet, (n-1));
					printf("| Resultado final: %d\n\n",s);
				}
				break;
			case 6:
				printf("| Base: ");
				scanf("%i", &b);
				printf("| Expoente: ");
				scanf("%i", &e);
				p=Potencia(b, e);
				printf("\n");
				printf("|Resultado: %i\n\n", p);
				break;
			case 7:
				exit(1);
				break;
            default:
                printf("| Opção inválida!\n");
                break;
		}

	}while(op!=7);

	return 0;
}

int * CriaVetor (int *vet, int *tamanho){
	
	printf("| Defina tamanho do vetor: ");
	scanf("%i", &(*tamanho));
	
	vet = (int *) malloc(sizeof(int)*(*tamanho));
	
	int x;

	for(x=0; x<(*tamanho); x++){
		printf("| Digite valor %i: ", x+1);
		scanf("%i", &vet[x]);
	}

	return vet;
}

int SomaVet (int *vet, int n){	
	
	if(n==0){
		return vet[0];
	}
	else{
		int resultado = SomaVet(vet,n-1);
		return vet[n] +resultado;
	}
}

void  ImprimeVetor (int *vet, int tamanho){
	int x;
	for(x=0; x<tamanho; x++){
		printf("| VET[%d] = %d\n",x+1,vet[x]);
	}
}

void  ImprimeVetorDec (int *vet, int n, int tamanho, int np){
	if(n==np){
		printf("%d\n", vet[n]);
		return;
	}
	else{
		ImprimeVetorDec (vet, n+1,tamanho, np);
		if(vet[n]%2==0){
			printf("%d\n", vet[n]);
		}
		return;
	}
}

int MenorValor (int *vet, int n){
	
	if(n==0){
		return vet[0];
	}
	else{
		int min= MenorValor(vet, (n-1));
		if(min<vet[n-1]){
			return min;
		}
		else{
			return vet[n-1];
		}
	}
}
	
int Potencia(int b, int e){
	
	if(e==0){
		return 1;
	}
	else{
		int r= b*Potencia(b, e-1);
		return r;
	}
}
