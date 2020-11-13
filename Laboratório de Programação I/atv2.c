#include <stdio.h>
#include <stdlib.h>

struct cadastro {
    char nome[20];
    char end[50];
    char telefone[11];
};

int main(){
    
    struct cadastro p[5];
    int x;
    
    for(x=0; x<5; x++){
        printf("Nome %d: \n", x);
        scanf("%s", p[x].nome);
        printf("Endereço %d: \n", x);
        scanf("%s", p[x].end);
        printf("telefone %d: \n", x);
        scanf("%s", p[x].telefone);
        system("clear");
    }
    
    system("clear"); 
    
    for(x=0; x<5; x++){
        printf("_____Pessoa %d_____\n", x);
        printf("Nome: %s\n", p[x].nome);
        printf("Endereço: %s\n", p[x].end);
        printf("telefone: %s\n", p[x].telefone);
        printf("\n");
    }
    
    return 0;
}
    
    