#include<stdio.h>

int num, num1;

int fat (num,num1){
num=num1;
do{
num1--;
fat=(num*num1);
} while (num>1 && num1>1);

return(fat);
}

int main(){

printf("Digite um numero natural\n");
scanf("%d", &num);

fat=fat(num,num1);

printf("Fatorial: %d", fat);

return 0;
}
