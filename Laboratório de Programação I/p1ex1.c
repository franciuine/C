#include <stdio.h>
#include <stdlib.h>

int main (){

  float b, h;
  float a;

  printf("Altura: \n");
  scanf("%f", &h);

  printf("Base: \n");
  scanf("%f", &b);

  a=(b*h)/2;

  printf("Área do triângulo = %.2f\n", a);

  return 0;
}