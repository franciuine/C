struct descritorPilha {
	int quantmax, quant;
	struct informacoesAluno *topo;
};

struct informacoesAluno {
	int mat;
	char nome[50];
	float nota;
	struct informacoesAluno *prox;
};

struct descritorPilha* inicializaPilha();
struct informacoesAluno* inicializaAluno(void);
int pop(struct descritorPilha *minhaPilha);
int push(struct descritorPilha *minhaPilha, struct informacoesAluno *novoElemento);
struct informacoesAluno search(struct descritorPilha *minhaPilha, int chave);
struct informacoesAluno top(struct descritorPilha *minhaPilha)
int sizep(struct descritorPilha *minhaPilha);
void printp(struct descritorPilha *minhaPilha);
