#include <stdio.h>
#include <stdlib.h>

float celsius(float f){
    float c;
    
    c=((f-32)/9) * 5;
    
    return c;
}

int main(){
    
    float f;
    
    printf("Temperatura: \n");
    scanf("%f", &f);
    
    float c = celsius (f);
    
    printf("%.2f°C\n",c);
    
    return 0;
}