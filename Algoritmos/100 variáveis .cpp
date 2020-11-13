#include <stdio.h>
int main(void){
	
	float media=0;
	int par=0;
	int impar=0;
	int qtdimpar=0;
	int qtdpar=0;
	int val=0;
	int somaimpar=0;
	
	int x=0;
	
	for(x=0; x<100; x++){
	
	printf("Digite um valor \n");
	scanf("%i", &val);
	
	if(val % 2 == 0){
	qtdpar++;
	}
	
	if(val % 2 != 0){
	qtdimpar++;
	somaimpar=somaimpar+val;
	}
}   
	media=somaimpar/qtdimpar;
	
	printf("A média de números ímpares é %f \n", media);
	printf("Foram digitados %i números pares \n", qtdpar);
	
	return 0; 
	
}
