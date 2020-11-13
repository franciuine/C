#include <stdio.h>
#include <stdlib.h>

int main(){
  
  int i;
  
  printf("Digite idade:\n");
  scanf("%i", &i);
  
  if(i < 16){
    printf("Não-eleitor \n");
  }
  if(i >= 18 && i < 65){
    printf("Eleitor obrigatório \n");
  }
  if(i >= 16 && i < 18 || i >= 65){
    printf("Eleitor facultativo \n");
  }
  
  return 0;
}