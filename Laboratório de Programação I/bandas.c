#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum gen {
    rock=1, samba, reggae, folk, classica, gospel, pop, eletronica, rap, jazz, funk
}; typedef enum gen gen;

struct bandas{
    char nome[50];
    int nint;
    int ranking; 
    gen genero;
}; typedef struct bandas bnd;

void apresentaGenero(bnd banda);

bnd Preencher(bnd banda[4], int x);

void Mostrar(bnd banda[4], int x);

void Ranking(bnd banda[4], int x, int pos);

void BuscaGenero(bnd banda[4], int x, int g);

void Verificar(bnd banda[4], int x);

int main(){
    
    bnd banda[4];
    int x;
    int op;
    int cf;
    int pos;
    int g;
    
    do{
        printf("_______MENU_______\n");
        printf("1- Preencher dados\n");
        printf("2- Mostrar dados\n");
        printf("3- Buscar por posição no ranking\n");
        printf("4- Buscar por gênero musical\n");
        printf("5- Verificar se banda está no ranking\n");
        printf("6- Sair\n");
        printf("\n");
        scanf("%i", &op);
        
        switch(op){
            case 1: 
                banda[4]=Preencher(banda, x);
                cf=1;
                break;
            case 2:
                if(cf==1){
                    Mostrar(banda, x);
                }
                else{
                    printf("Estruturas ainda não preenchidas!\n");
                }
                break;
            case 3:
                if(cf==1){
                    printf("Posição no ranking:\n");
                    scanf("%i", &pos);
                    Ranking(banda, x, pos);
                }
                else{
                    printf("Estruturas ainda não preenchidas!\n");
                }
                break;
            case 4:
                if(cf==1){
                    printf("|Gênero:\n");
                    printf("|1- Rock\n");
                    printf("|2- Samba\n");
                    printf("|3- Reggae\n");
                    printf("|4- Folk\n");
                    printf("|5- Clássica\n");
                    printf("|6- Gospel\n");
                    printf("|7- Pop\n");
                    printf("|8- Eletrônica\n");
                    printf("|9- Rap\n");
                    printf("|10- Jazz\n");
                    printf("|11- Funk\n");
                    scanf("%i", &g);
                    BuscaGenero(banda, x, g);
                }
                else{
                    printf("Estruturas ainda não preenchidas!\n");
                }
                break;
            case 5:
                if(cf==1){
                    Verificar(banda, x);
                }
                else{
                    printf("Estruturas ainda não preenchidas!\n");
                }
                break;
            case 6:
                exit(1);
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    }while(op!=6);
    
    return 0;
}

void apresentaGenero( bnd banda){
	switch(banda.genero){
            case 1:
                printf("| Gênero: Rock\n");
                break;
            case 2:
                printf("| Gênero: Samba\n");
                break;
            case 3:
                printf("| Gênero: Reggae\n");
                break;
            case 4:
                printf("| Gênero: Folk\n");
                break;
            case 5:
                printf("| Gênero: Clássica\n");
                break;
            case 6:
                printf("| Gênero: Gospel\n");
                break;
            case 7:
                printf("| Gênero: Pop\n");
                break;
            case 8:
                printf("| Gênero: Elêtronica\n");
                break;
            case 9:
                printf("| Gênero: Rap\n");
                break;
            case 10:
                printf("| Gênero: Jazz\n");
                break;
            case 11:
                printf("| Gênero: Funk\n");
                break;
            default:
	        printf("| Gênero: Sem gênero\n");		
	        break;
	}
	return ;
}

bnd Preencher(bnd banda[4], int x){
    
    for(x=0; x<5; x++){
        printf("_____BANDA %d_____\n", x+1);
        printf("| Nome: ");
        scanf("%s", banda[x].nome);
        printf("| Número de integrantes: ");
        scanf("%i", &banda[x].nint);
        printf("| Gênero:\n");
        printf("| 1- Rock\n");
        printf("| 2- Samba\n");
        printf("| 3- Reggae\n");
        printf("| 4- Folk\n");
        printf("| 5- Clássica\n");
        printf("| 6- Gospel\n");
        printf("| 7- Pop\n");
        printf("| 8- Eletrônica\n");
        printf("| 9- Rap\n");
        printf("| 10- Jazz\n");
        printf("| 11- Funk\n");
        printf("| ");
        scanf("%i", &banda[x].genero);
        printf("| Posição no ranking: ");
        scanf("%i", &banda[x].ranking);
        printf("\n");
        system("clear");
    }
    
    return banda[4];
}

void Mostrar(bnd banda[4], int x){
    
    for(x=0; x<5; x++){
        printf("_____BANDA %d_____\n", x+1);
        printf("| Banda: %s\n", banda[x].nome);
        printf("| Número de integrantes: %i\n", banda[x].nint);
        apresentaGenero(banda[x]);
        printf("| Posição no ranking: %i\n", banda[x].ranking);
        printf("\n\n");
    }
    return;
}

void Ranking(bnd banda[4], int x, int pos){
    
    for(x=0; x<5; x++){
        if(pos==banda[x].ranking){
            printf("_____BANDA %d_____\n", x+1);
            printf("| Banda: %s\n", banda[x].nome);
            printf("| Número de integrantes: %i\n", banda[x].nint);
            apresentaGenero(banda[x]);
            printf("| Posição no ranking: %i\n", banda[x].ranking);
            printf("\n\n");
        }
    }
    if(pos>5){
        printf("Ranking apenas para 5 bandas!\n\n");
    }
    
    return;
}

void BuscaGenero(bnd banda[4], int x, int g){
    
    for(x=0; x<5; x++){
        if(g==banda[x].genero){
            printf("_____BANDA %d_____\n", x+1);
            printf("| Banda: %s\n", banda[x].nome);
            printf("| Número de integrantes: %i\n", banda[x].nint);
            apresentaGenero(banda[x]);
            printf("| Posição no ranking: %i\n", banda[x].ranking);
            printf("\n\n");
        }
    }
    
    if(g>11){
        printf("Gênero inválido!\n\n");
    }
    
    return;
}  

void Verificar(bnd banda[4], int x){
    
    int n;
    char b[20];
    
    printf("Nome da banda:\n");
    scanf("%s", b);

    for(x=0; x<5; x++){
        n=strcasecmp(b,banda[x].nome);
        if(n==0){
            printf("Está na posição %i do ranking.\n\n", x+1);
        }
    }
    
    if(n!=0){
        printf("Não está no ranking!\n\n");
    }
    
    return;
}  