#include <stdio.h>
#include <stdlib.h>

int main (){
  
  int car;
  int p, c;
  
  printf("Informe tipo de carro:\n Digite 1 para tipo A \n Digite 2 para tipo B \n Digite 3 para tipo C \n");
  scanf("%i", &car);
  
  printf("Informe percurso em km: \n");
  scanf("%i", &p);
  
  switch(car){
    case 1:
      c = p * 8;
      printf("Consumo: %i litros \n", c);
      break;
    case 2:
      c = p * 9;
      printf("Consumo: %i litros \n", c);
      break;
    case 3:
      c = p * 12;
      printf("Consumo: %i litros \n", c);
      break;
    default:
      printf("Carro não encontrado!\n");
      break;
  }
  
  return 0;
}
      