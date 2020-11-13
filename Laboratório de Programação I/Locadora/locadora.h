struct Filme{
	int codigo;
	char nome[100];
	int ano;
	int quantidade;
	char genero[10];
}; typedef struct Filme flm;

void MontaStructs(char *linha, flm *filme, int x);

void Locacao(flm *filme, int num);

void Entrega(flm *filme, int num);

void Busca(flm *filme, int num);

void Relatorios(flm *filme, int num);