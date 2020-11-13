#include <stdio.h>
#include <stdlib.h>

int main (){
  
  int n;
  
  printf("Digite valor: \n");
  scanf("%i", &n);
  
  if(n >= 20 && n <= 80){
    printf("Parabéns!\n");
  }
  else{
    printf("Erro!\n");
  }
  
  return 0;
}