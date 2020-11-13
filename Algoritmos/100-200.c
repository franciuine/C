#include <stdio.h>

int main(void){
	
int x=0;
int cont=0;

for (x=100; x<200; x++){
	printf("%i \n", x);
	cont++;	
}

printf("Foram escritos %i números", cont);

return 0;
}
