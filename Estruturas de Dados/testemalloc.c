#include <stdio.h>
#include <stdlib.h>

int main (){

int *v, n, x, s=0, m;

printf("Número de elementos: \n");
scanf("%i", &n);

v= (int*) malloc (n* sizeof(int));

for(x=0; x<n; x++){
    printf("Digite valor: \n");
    scanf("%i", &v[x]);
    s=s+v[x];
}

printf("\n");

for(x=0; x<n; x++){
    printf("%i \n", v[x]);
}

m=s/n;

printf("A média dos valores armazenados no vetor é %i. \n", m);

void free (void*v);

return 0;
}
