#include <stdio.h>
#include <stdlib.h>

int main(){
  
  float s, p;
  
  printf("Digite salário: \n");
  scanf("%f", &s);
  
  printf("Digite valor da prestação: \n");
  scanf("%f", &p);
  
  if(p > (s*0.2)){
    printf("Empréstimo não pode ser concedido!\n");
  }
  else{
    printf("Empréstimo pode ser concedido!\n");
  }
  
  return 0;
}