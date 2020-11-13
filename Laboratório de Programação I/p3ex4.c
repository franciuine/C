#include <stdio.h>
#include <stdlib.h>

void media (float n1, float n2){
    float m;
    m=(n1+n2)/2;
    
    printf("Média final: %.2f\n", m);
    
    if(m >=6){
        printf("Parabéns, você foi aprovado!\n");
    }
    else{
        printf("Reprovado!\n");
    }
}

int main(){
    float n1, n2;
    
    printf("Digite nota da primeira prova:\n");
    scanf("%f", &n1);
    
    printf("Digite nota da segunda prova:\n");
    scanf("%f", &n2);
    
    media(n1, n2);
    
    return 0;
}