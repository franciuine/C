#include <stdio.h>

int main(void){
	int v=0;
	int x=0;
	
	printf("Digite um valor maior que 10 \n");
	scanf("%i", &v);
	
	for(x=x; x<v; x++){
		if(x % 2 == 0){
			
			printf("%i \n",x);
		}
	}
return 0;
}

