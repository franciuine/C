#include <stdio.h>
#include <stdlib.h>

int main (){
    int n[80], m=100, x, p;
    
    for(x=0; x<80; x++){
        printf("Digite valor:\n");
        scanf("%i", &n[x]);
        
        if(n[x]< m){
            m=n[x];
            p=x;
        }
    }
    
    printf("Vetor:\n");
    for(x=0; x<80; x++){
        printf("%i ", n[x]);
    }
    printf("\n");
    
    printf("O menor elemento de N é %i e sua posição é %i\n", m, p);
    
    return 0;
}