#include "pilha.h"

int main (vod) {
	FILE *arquivo = fopen("entrada.txt", "r+");
	if (arquivo == NULL) {
		printf("Falha ao abrir arquivo, o programa nao pode ser inicializado!");
		return 0;
	}
	
	int ma;
	fscanf(arquivo, "%i", &ma);
	struct descritorPilha *pilha = inicializaPilha(ma);
	
	char acao, name[50];
	float n;
	int i, m, verif, k;
	do {
		if (fgetc(arquivo) != EOF) {
			acao = fgetc(arquivo);
			switch (acao) {
				case 'c':
					fscanf(arquivo, "%i", &m);
					i=0;
					while (fgetc(arquivo) != '\n') {
						name[i] = fgetc(arquivo);
						i++;
					}
					fscanf(arquivo, "%f", &n);
					struct informacoesAluno *novo = (struct informacoesAluno *)malloc(sizeof(struct informacoesAluno));
					if (novo == NULL) {
						printf("Acabou a memória!");
						return 0;
					} else {
						novo->mat = m;
						novo->nome = name;
						novo->nota = n;
						novo->prox = NULL;
						verif = push(pilha, novo);
						if (verif == 0)
							printf("Falha na insercao!");
						else
							printf("Inserido com sucesso");
					}
					break;
				case 'd':
					verif = pop(pilha);
					if (verif == 0)
						printf("Falha na remocao!");
					else
						printf("Removido com sucesso!");
					break;
				case 'p':
					fscanf(arquivo, "%i", &k);
					struct informacoesAluno *seek = search(pilha, k);
					printf("Matricula: %i\nNome: %s\nNota: %2.f\n\n", seek->mat, seek->nome, seek->nota);
					break;
				case 't':
					struct informacoesAluno *t = top(pilha);
					printf("Matricula: %i\nNome: %s\nNota: %2.f\n\n", t->mat, t->nome, t->nota);
					break;
				case 's':
					printf("O tamanho da pilha e: %i", sizep(pilha);
					break;
				case 'v':
					printp(pilha);
					default;
				default:
					printf("Erro no arquivo de entrada! O programa sera encerrado!");
					return 0;
			}
		}
	} while (fgetc(arquivo) == EOF);
	
	printf("Fim do programa!");
	return 0;
}
