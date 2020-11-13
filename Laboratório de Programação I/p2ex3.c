#include <stdio.h>
#include <stdlib.h>

int main(){
    int a[10], p, x;
    
    for(x=0; x<10; x++){
        printf("Digite valor:\n");
        scanf("%i", &a[x]);
        
        if(a[x] == 10){
            printf("\nPosição: %i\n\n", x);
        }
    }
    
    return 0;
}