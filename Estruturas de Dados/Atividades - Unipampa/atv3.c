#include <stdio.h>
#include <stdlib.h>

struct chamada{
    int num;
    int media;
};

int main(){
    struct chamada DadosAluno[4];
    int x, s, m;
    float mg;
    
    for(x=0; x<4; x++){
        printf("Número:\n");
        scanf("%d", &DadosAluno[x].num);
        printf("Média:\n");
        scanf("%d", &DadosAluno[x].media);
        m=DadosAluno[x].media;
        s=s+m;
    }
    
    mg=s/4;
    
    system("clear");
    
    for(x=0; x<4; x++){
        printf("_____Aluno %d_____\n", x);
        printf("Número: %d\n", DadosAluno[x].num);
        printf("Média: %d\n", DadosAluno[x].media);
        printf("\n");
    }
    
    printf("Média do grupo: %.2f\n", mg);
    
    return 0;
}
        
    