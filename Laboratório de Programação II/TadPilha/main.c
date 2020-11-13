#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

int main (){
	
	int x, n;
	plh *p;
	
	p = CriaPilha();
	
	printf("Digite número de alunos a serem registrados: \n");
	scanf("%i", &n);
        printf("\n");
    
	for(x=0; x<n; x++){
		p=PushPilha(p);
	}
	
	printf(" ----- IMPRESSÃO -----");
        printf("\n");
	ImprimePilha(p);
	
	return 0;
}


