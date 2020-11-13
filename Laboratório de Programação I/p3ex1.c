#include <stdio.h>
#include <stdlib.h>

int ParOuImpar (int x){
    if(x % 2 == 0){
        return 1;
    }
    else{
        return 0;
    }
}

int main (){
    int x;
    
    printf("Digite valor:\n");
    scanf("%i", &x);
    
    int p= ParOuImpar (x);
    
    if(p==1){
        printf("Par!\n");
    }
    else{
        printf("Ímpar!\n");
    }    
        
    return 0;
}