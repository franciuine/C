struct arvore{
	struct arvore *dir;
	struct arvore *esq;
	void *info;
	int altura;
};typedef struct arvore avl;

avl *RotacaoDireita (avl *a);

avl *RotacaoEsquerda (avl *a);

avl *RotacaoDireitaEsquerda (avl *a);

avl *RotacaoEsquerdaDireita (avl *a);

int Max (int a, int b);

int RetornaAltura (avl *a);

int Compara (void* info, void* dado);

avl *InsereGen (avl *a, int(*cb)(void*,void*), void *dado);

avl *Insere (avl *a);

void Menor (avl *a, void (*cb)(void*));

void Maior (avl *a, void (*cb)(void*));

void ImprimeTela (void *dado);

void ImprimePreOrdemTela (avl *a, void (*cb)(void*));

void ImprimeSimetricaTela (avl *a, void (*cb)(void*));

void ImprimePosOrdemTela (avl *a, void (*cb)(void*));

void ImprimePreOrdemArquivo (avl *a, FILE *impressao);

void ImprimeSimetricaArquivo (avl *a, FILE *impressao);

void ImprimePosOrdemArquivo (avl *a, FILE *impressao);

void ImprimeArquivo (avl *a);

avl *Remove(avl *a, int(*cb)(void*,void*), int *v);
