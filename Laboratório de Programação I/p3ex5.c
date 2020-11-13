#include <stdio.h>
#include <stdlib.h>

float PesoIdeal (int sexo, float h){
    float p;
    
    if(sexo == 1){
        p = (62.1 * h) - 44.7;
        return p;
    }
    if(sexo == 2){
        p = (72.7 * h) - 58;
        return p;
    }
}

int main(){
    float h;
    int sexo;
    
    printf("Gênero: \n1- Feminino\n2- Masculino\n");
    scanf("%i", &sexo);
    
    printf("Altura:\n");
    scanf("%f", &h);
    
    float p = PesoIdeal(sexo, h);
    
    printf("O peso ideal para você é %.2f kg!\n", p);
    
    return 0;
}