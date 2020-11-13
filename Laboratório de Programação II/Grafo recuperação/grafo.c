// Prova 3
// 29/09/2017
// Franciuíne Almeida (franciuine@gmail.com)

#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

int** criaMatriz(grf *g, int v){
  int x,y;
  g->mat = (int**) malloc(v * sizeof(int*));
  for (x=0; x<v; x++){
       g->mat[x] = (int*) malloc(v * sizeof(int));
       for (y=0; y<v; y++){
            g->mat[x][y] = 0;
       }
  }
return g->mat;
}

Fila *CriaFila(){
    Fila* f = (Fila*) malloc (sizeof(Fila));
    f->ini = f->fim = NULL;

    return f;
}

Fila *InsereFila(Fila *f, int x){
    lst *l = (lst*) malloc (sizeof(lst));
    l->info = x;
    l->prox = NULL;

    if(f->fim!=NULL){
        f->fim->prox=l;
    }
    else{
        f->ini=l;
    }
    f->fim=l;
    return f;
}

int *RetiraFila(Fila *f){
    lst* aux = f->ini;
    int atual = aux->info;
    f->ini = f->ini->prox;

    if(f->ini == NULL){
        f->fim = NULL;
    }

    free(aux);
    return atual;
}

grf *CriaGrafo (int v){
    grf *g = (grf*) malloc (sizeof(grf));
    g->ver = v;
    g->mat = (int**) malloc (sizeof(int*) * g->ver);

    int x;
    for(x=0; x<g->ver; x++){
        g->mat[x] = (int*) malloc (sizeof(int) * g->ver);
    }
    int y;
    for(x=0; x<g->ver; x++){
        for(y=0; y<g->ver; y++){
        g->mat[x][y] = 0;
        }
    }
    return g;
}

rtd *CriaResultado (int v){
	
    rtd *r = (rtd*) malloc (sizeof(rtd));
    r->cor = (int*) malloc (sizeof(int) * v);
    r->dist = (int*) malloc (sizeof(int) * v);
    r->pred = (int*) malloc (sizeof(int) * v);

    int x;

    for(x=0; x<v; x++){
        r->cor[x] = 0;
        r->pred[x] = -1;
        r->dist[x] = 0;
    }
    return r;
}

grf *InsereArestaNaoOrientado(grf *g, int va, int vb, int peso){

    g->mat[va][vb]=peso;
    g->mat[vb][va]=peso;
    
    return g;
}

grf *InsereArestaOrientado(grf *g, int va, int vb, int peso){

    g->mat[va][vb]=peso;

    return g;
}

rtd *BFS (grf *g, int origem){
    int adj;
    rtd *r= CriaResultado(g->ver);
    r->cor[origem]=1;
    Fila *f= CriaFila();
    InsereFila(f, origem);
    while(f->ini!=NULL){
        int atual= RetiraFila(f);
        for(adj=0; adj<g->ver; adj++){
            if(g->mat[atual][adj] == 1){
                if(r->cor[adj] == 0){
                    r->cor[adj]=1;
                    InsereFila(f, adj);
                    r->pred[adj]=atual;
                    r->dist[adj]=1+r->dist[atual];
                }
            }
        }
        r->cor[atual]=2;
    }
    return r;
}

dfs *DFS(grf * g){
	dfs *dfsGrafo = (dfs*) malloc (sizeof(dfs));
	int x;
	dfsGrafo->predecessor = (int*) malloc (g->ver * sizeof(int));
	dfsGrafo->descoberta = (int*) malloc (g->ver * sizeof(int));
	dfsGrafo->final = (int*) malloc (g->ver * sizeof(int));
	dfsGrafo->cor = (int*) malloc (g->ver * sizeof(int));

	for (x = 0; x < g->ver; x++){
		dfsGrafo->predecessor[x] = -1;
		dfsGrafo->cor[x] = 0;
	}
	dfsGrafo->tempo = 0;
	for (x = 0; x < g->ver; x++){
		if (dfsGrafo->cor[x] == 0){
			DFSVisit(dfsGrafo, x, g);
		}
	}
	return dfsGrafo;
}

void DFSVisit(dfs *dfsGrafo, int x, grf *g){
	int y;
	dfsGrafo->cor[x] = 1;
	dfsGrafo->tempo = dfsGrafo->tempo + 1;
	dfsGrafo->descoberta[x] = dfsGrafo->tempo;
	for (y=0; y < g->ver; y++) {
		if (dfsGrafo->cor[y] == 0 && g->mat[x][y]%2==0) {
			dfsGrafo->predecessor[y] = x;
			DFSVisit(dfsGrafo, x, g);
		}
	}
	dfsGrafo->cor[x] = 2;
	dfsGrafo->tempo = dfsGrafo->tempo + 1;
	dfsGrafo->final[x] = dfsGrafo->tempo;
}

pdfs *OrdenacaoTopologica(grf *g){
	dfs *dfsg = DFS(g);
	pdfs *lista;
	lista = (pdfs*) malloc (g->ver * sizeof(pdfs));
	int x;
	int y;
	for(x=0; x < g->ver; x++){
		lista[x].valor = x;
		lista[x].inicio = dfsg->descoberta[x];
		lista[x].final = dfsg->final[x];
	}

	for(x=0; x < g->ver; x++){
		int maior = lista[x].final;
		for (y=0; y < g->ver; y++){
			if(maior < lista[y].final){
				pdfs aux = lista[y];
				lista[y] = lista[x];
				lista[x] = aux;
			}
		}
	}
	return lista;
}

void Prim (grf *g){
	int *key = (int*) malloc (g->ver * sizeof(int));
	int *pi = (int*) malloc (g->ver * sizeof(int));
	int *q = (int*) malloc(g->ver * sizeof(int));
	int x;
	
	for(x=0; x < g->ver; x++){
		key[x] = 99;
		pi[x] = -1; //sem pai
		q[x] = x;
	}
	key[0]=0;
	
	int y=0;

	q[y]=-1;
	
	while(y >= 0){
		for(x=0; x < g->ver; x++){
			if (g->mat[y][x] > 0 && q[x] > 0 && key[x] > g->mat[y][x]){
				pi[x] = y;
				key[x] = g->mat[y][x];
			}
		}
		q[y] = -1;
		y = -1;
		for (x=0; x < g->ver; x++){
			if ((q[x] >= 0 && y < 0) || (q[x] >= 0 && key[x] < key[y])) {
				y = q[x];
			}
		}
	}

	printf("KEY\t\tPI\t\tQ\t\t");
    for(x=0; x<g->ver; x++){
        printf("\n%i\t\t%i\t\t%i\n", key[x], pi[x], q[x]);
    }
    printf("\n");
	
	free(key);
	free(pi);
	free(q);
}

void ImprimeDFS(dfs *dfsR, grf *g){
	int x;
    printf("Vertice\t\tPredecessor\t\tTempo Inicial\t\tTempo Final\t\t");
    for(x=0; x<g->ver; x++){
        printf("\n%i\t\t%i\t\t\t%i\t\t\t%i\n", x, dfsR->predecessor[x], dfsR->descoberta[x], dfsR->final[x]);
    }
    printf("\n");
}

void ImprimeBFS(rtd *r, grf *g){
    int x;
    printf("Vertice\t\tPredecessor\t\tCor\t\tDistancia\t\t");
    for(x=0; x<g->ver; x++){
        printf("\n%i\t\t%i\t\t\t%i\t\t\t%i\n", x, r->pred[x], r->cor[x], r->dist[x]);
    }
    printf("\n");
}

void ImprimeMatriz(grf *g){
	int x, y;
	printf("\n");
	for(x=0; x<g->ver; x++){
		for(y=0; y<g->ver; y++){
			printf(" %i", g->mat[x][y]);
		}
		printf("\n");
	}
}

void ImprimeTopologica(pdfs *p, grf *g){
	int x;
    printf("Vertice\t\tValor\t\tTempo Inicial\t\tTempo Final\t\t");
    for(x=0; x<g->ver; x++){
        printf("\n%i\t\t%i\t\t\t%i\t\t\t%i\n", x, p[x].valor, p[x].inicio, p[x].final);
    }
    printf("\n");
    
    free(p);
}
