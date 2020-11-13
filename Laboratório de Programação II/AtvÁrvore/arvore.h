struct arvore{
	int info;
	struct arvore *pai;
	struct arvore *esq;
	struct arvore *dir;
}; typedef struct arvore arv;

arv *InsereArvore(arv *a, int x);

void ImprimePreOrdem(arv *a);

void ImprimeSimetrica(arv *a);

void ImprimePosOrdem(arv *a);

void BuscaArvore(arv *a, int x);

int Menor(arv *a);

int Maior(arv *a);

arv *RemocaoArvore(arv *a, int x);

