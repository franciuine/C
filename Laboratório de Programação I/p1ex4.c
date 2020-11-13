#include <stdio.h>
#include <stdlib.h>

int main(){
  
  int a, b, c;
  
  printf("Digite primeiro valor: \n");
  scanf("%i", &a);
  
  printf("Digite segundo valor: \n");
  scanf("%i", &b);
  
  printf("Digite terceiro valor: \n");
  scanf("%i", &c);
  
  if(a < (b+c) && b < (b+c) && c < (a+b)){
    printf("Podem ser lados de um triângulo \n");
  }
  else{
    printf("Não podem ser lados de um triângulo \n");
  }
  
  return 0;
}
  
  