// Prova 5
// 30/10/2017
// Franciuíne Almeida (franciune@gmail.com)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cripto.h"

char CHAVE[] = "CrIp";
int tamC = strlen(CHAVE);

char TEXTO[100000];
int tamT = 100000;

char TEXTO_CRIPT[100000];

bool ConverteC(){
    int chave;
    int x;
    
    for(x=0; x< strlen(TEXTO) ; x++){
        TEXTO_CRIPT[x]=TEXTO[x];
    }

	int aux;
	
    for(aux=0; aux < strlen(TEXTO);){
        for(x=0;x<tamC; x++){
			//TEXTO_CRIPT[aux] = TEXTO_CRIPT[aux] * CHAVE[x];
            chave = CHAVE[x];
            TEXTO_CRIPT[aux] *= chave;
            aux++;
        }
    }
    return true;
}

bool ConverteD(){
	FILE *c;
	int valor;
    int pos_chave;
    int pos_texto;
	
	c = fopen ("criptografado.txt", "r");
	if (c == NULL) {
		printf ("| Ocorreu um erro ao abrir o arquivo 'criptografado.txt'!\n");
		return false;
	}
	
	pos_chave=0;
    pos_texto=0;
    
	while(!feof(c)){
        fscanf(c,"%d", &valor);

        valor /= CHAVE[pos_chave];
        //valor = valor / CHAVE[pos_chave];

        TEXTO[pos_texto] = (char)valor;

        pos_texto++;

        if(pos_chave==tamC-1){
            pos_chave=0;
        }else{
            pos_chave++;
        }
    }
    fclose(c);
    return true;
}

void Criptografa(){
	char txt[tamT];
	char palavra[100];
	bool ok;
	int x;
	FILE *c;  //arquivo com texto criptografado
	FILE *d;  //arquivo com texto descriptografado
 
    c = fopen ("criptografado.txt", "w");
	if (c == NULL) {
		printf ("| Ocorreu um erro ao abrir o arquivo 'criptografado.txt'!\n");
	}
	
	d = fopen ("descriptografado.txt", "r");
	if (d == NULL) {
		printf ("| Ocorreu um erro ao abrir o arquivo 'descriptografado.txt'!\n");
	}
		 
	while(!feof(d)){
		fscanf(d,"%s",palavra);
        strcat(txt," ");
        strcat(txt,palavra);
    }
    fclose(d);
    
    if(strlen(txt)<=tamT){
		strcpy(TEXTO,txt);
		ok=true;
    }else{
        printf("| Tamanho do texto excede o limite de caracteres!\n");
        ok=false;
        system("pause");
    }
    
    if(ok){
		if(ConverteC()){
			printf("| Texto criptografado!\n| Verifique o arquivo de saída.\n");
			for(x=0; x < strlen(TEXTO); x++){
                    fprintf(c,"%d ",TEXTO_CRIPT[x]);
            }
		}
		fclose(c);
		fclose(d);
	}
	else{
		printf("| Não foi possível criptografar o texto!\n");
	}
}

void Descriptografa(){
	FILE *d;
	
	d = fopen ("descriptografado.txt", "r");
	if (d == NULL) {
		printf ("| Ocorreu um erro ao abrir o arquivo 'descriptografado.txt'!\n");
	}
	
	if(ConverteD()){
        printf("| Texto descriptografado!\n| Verifique o arquivo de saída.\n");
        fprintf(d,"\n%s\n\n",TEXTO);
        fclose(d);
    }
    else{
        printf("| Não foi possível descriptografar o texto!\n");
    }
}
