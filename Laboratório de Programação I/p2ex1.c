#include <stdio.h>
#include <stdlib.h>
 
int main(){
    
    int vet[1000], x=0, s, m, n, cont=0;
    
    do{
        printf("Digite número: \n");
        scanf("%i", &n);
        vet[x]=n;
        if(vet[x] % 3 == 0 && vet[x]!=0){
            cont++;
            s=s+vet[x];
        }
        x++;
    }while(n!=0);
    
    if(s==0){
        printf("Nenhum múltiplo de 3 foi digitado!\n");
    }
    else{
    
    printf("Soma = %i\n\n", s);
    
    m = s / cont;
    
    printf("A média dos múltilplos de 3 digitados é = %i\n\n", m);
    } 
    
    return 0;
}
    
        
    