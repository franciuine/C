#include <stdio.h>
#include <stdlib.h>

struct tipo_endereco {
    char rua [50];
    int numero;
    char bairro [20];
    char cidade [30];
    char sigla_estado [3];
    long int CEP;
};

struct ficha_pessoal {
    char nome [50];
    long int telefone;
    struct tipo_endereco endereco;
};

int main(){
    
    struct ficha_pessoal p;
    
    printf("Nome:\n");
    scanf("%s", p.nome);
    printf("Telefone:\n");
    scanf("%ld", &p.telefone);
    printf("Rua:\n");
    scanf("%s", p.endereco.rua);
    printf("Número da casa:\n");
    scanf("%d", &p.endereco.numero);
    printf("Bairro:\n");
    scanf("%s", p.endereco.bairro);
    printf("Cidade:\n");
    scanf("%s", p.endereco.cidade);
    printf("UF:\n");
    scanf("%s", p.endereco.sigla_estado);
    printf("CEP:\n");
    scanf("%ld", &p.endereco.CEP);
    
    system("clear");
    
    printf("_____CADASTRO_____\n");
    printf("Nome: %s\n", p.nome);
    printf("Telefone: %ld\n", p.telefone);
    printf("Rua: %s\n", p.endereco.rua);
    printf("Número da casa: %d\n", p.endereco.numero);
    printf("Bairro: %s\n", p.endereco.bairro);
    printf("Cidade: %s\n", p.endereco.cidade);
    printf("UF: %s\n", p.endereco.sigla_estado);
    printf("CEP: %ld\n", p.endereco.CEP);
    
    return 0;
}
