struct Registro{
	long int matricula;
	char nome[40];
	int faltas;
	float nota;
}; typedef struct Registro rgst;

long int Insere (rgst *tabela, long int n);
void Remove (rgst *tabela);
void Imprime (rgst *tabela, long int n);
int PesquisaSequencial (rgst *tabela, long int n, int q);
int PesquisaBinaria (rgst *tabela, long int n, int q);
rgst *Random (long int tam);





