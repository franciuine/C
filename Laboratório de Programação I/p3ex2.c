#include <stdio.h>
#include <stdlib.h>

float area(int r){
    int a;
    
    a= 3.14 * (r*r);
    
    return a;
}

float perimetro(int r){
    int p;
    
    p= 3.14 * 2 * r;
    
    return p;
}
    

int main (){
    float r;
    
    printf("Digite valor do raio:\n");
    scanf("%f", &r);
    
    float a = area(r);
    
    printf("Área: %f\n", a);
    
    float p = perimetro(r);
    
    printf("Perímetro: %f\n", p);
    
    return 0;
}