// Prova 3
// 29/09/2017
// Franciuíne Almeida (franciuine@gmail.com)

struct grafo{
    int **mat;
    int ver;
};typedef struct grafo grf;

struct resultado{
    int *cor;
    int *dist;
    int *pred;
};typedef struct resultado rtd;

struct DFS {
	int *predecessor;
	int *descoberta;
	int *final;
	int *cor;
	int tempo;
};typedef struct DFS dfs;

struct lista{
    int info;
    struct lista *prox;
};typedef struct lista lst;

struct fila{
    lst *ini;
    lst *fim;
};typedef struct fila Fila;

struct pontoDFS {
	int valor;
	int inicio;
	int final;
};typedef struct pontoDFS pdfs;

int** criaMatriz(grf *g, int v);

Fila *CriaFila();

Fila *InsereFila(Fila *f, int x);

int *RetiraFila(Fila *f);

grf *CriaGrafo (int v);

rtd *CriaResultado (int v);

grf *InsereArestaNaoOrientado(grf *g, int va, int vb, int peso);

grf *InsereArestaOrientado(grf *g, int va, int vb, int peso);

rtd *BFS (grf *g, int origem);

dfs *DFS(grf * g);

void DFSVisit(dfs *dfsGrafo, int x, grf *g);

pdfs *OrdenacaoTopologica(grf *g);

void Prim (grf *g);

void ImprimeDFS(dfs *dfsR, grf *g);

void ImprimeBFS(rtd *r, grf *g);

void ImprimeMatriz(grf *g);

void ImprimeTopologica(pdfs *p, grf *g);

