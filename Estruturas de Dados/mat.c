#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){

int **mat1, **mat2, **matr, l, c, x, y;

printf("Digite o número de linhas e colunas, respectivamente: \n");
scanf("%i %i", &l, &c);

printf ("\n");

mat1= (int**) malloc (l*sizeof(int*));

for(x=0; x<l; x++){
    mat1[x]=(int*) malloc (c*sizeof(int));
}

for(x=0; x<l; x++){
    for(y=0; y<c; y++){
    printf("Digite valor: \n");
    scanf("%i", &mat1[x][y]);
    }
}

printf ("\n");

mat2= (int**) malloc (l*sizeof(int*));

for(x=0; x<l; x++){
    mat2[x]=(int*) malloc (c*sizeof(int));
}

for(x=0; x<l; x++){
    for(y=0; y<c; y++){
    printf("Digite valor: \n");
    scanf("%i", &mat2[x][y]);
    }
}

printf ("\n");

matr= (int**) malloc (l*sizeof(int*));

for(x=0; x<l; x++){
    matr[x]=(int*) malloc (c*sizeof(int));
}

for(x=0; x<l; x++){
    for(y=0; y<c; y++){
        matr[x][y]=mat1[x][y]+mat2[x][y];
    }
}

for(x=0; x<l; x++){
    for(y=0; y<c; y++){
            printf("%i ", matr[x][y]);
    }
    printf("\n");
}

printf ("\n");

free (mat1);
free (mat2);

return 0;
}
