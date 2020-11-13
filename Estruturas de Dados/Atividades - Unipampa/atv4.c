#include <stdio.h>
#include <stdlib.h>

struct hm{
    int horas;
    int minutos;
};

struct hm Converte (int x, struct hm r){
    
    r.horas = x/60;
    r.minutos = x%60;
    
    return r;
}
    
int main(){
    int x;
    
    printf("Digite valor: \n");
    scanf("%d", &x);
    
    struct hm r = Converte(x, r);
    
    printf("%d Horas e %d minutos\n", r.horas, r.minutos);
    
    return 0;
}
    
    
    