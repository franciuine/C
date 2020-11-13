#include<stdio.h>
#include<stdlib.h>

int main(){
	
int matriz[100][100];
int x=0;
int y=0;
int dp, ds;

for(x=0; x<100; x++){
for(y=0; y<100; y++){
matriz[x][y]= rand() %100;
}
}

printf("%i\n", matriz[x][y]);

for(x=0; x<100; x++){
dp=matriz[x][x];
x++;
}

y=99;
for(y=0; y<100; y++){
ds=matriz[y][y];	
y--;
}

printf("%i\n", dp);
printf("%i\n", ds);

return 0;
}
