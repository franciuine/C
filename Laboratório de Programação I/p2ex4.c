#include <stdio.h>
#include <stdlib.h>

int main(){
    int mat[5][5], l, c, dp, ds, s, sq;
    
    for(l=0; l<5; l++){
        for(c=0; c<5; c++){
            printf("Digite valor:\n");
            scanf("%i", &mat[l][c]);
            s=s+mat[l][c];
        }
    }
    
    for(l=0; l<5; l++){
        for(c=0; c<5; c++){
            if(l==4){
                sq=sq+mat[l][c];
            }
        }
    }
    printf("Soma de valores da linha 4: %i\n", sq);
    
    for(l=0; l<5; l++){
        for(c=0; c<5; c++){
            if(l==c){
                dp=dp+mat[l][c];
            }
        }
    }
    printf("Soma da diagonal principal: %i\n", dp);
    
     for(l=4; l>=0; l--){
        for(c=4; c>=0; c--){
            if(l==c){
                ds=ds+mat[l][c];
            }
        }
    }
    printf("Soma da diagonal secundária: %i\n", ds);
    
    printf("Soma de todos os elementos: %i\n", s);
    
    return 0;
}
    
    
    
    