// Lista 7
// 17/02/2017
// Andrew Pacheco Silveira (andrew-pacheco@hotmail.com) / Franciuíne Barbosa da Silva de Almeida (franciuine@gmail.com)

#include <stdio.h>
#include <stdlib.h>

struct grafo{
    int **mat;
    int ver;
};typedef struct grafo grf;

struct resultado{
    int *cor;
    int *dist;
    int *pred;
};typedef struct resultado rtd;

struct lista{
    int info;
    struct lista *prox;
};typedef struct lista lst;

struct fila{
    lst *ini;
    lst *fim;
};typedef struct fila Fila;

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
    g->mat = (int**) malloc (sizeof(int*) * v);

    int x;
    for(x=0; x<v; x++){
        g->mat[x] = (int*) malloc (sizeof(int) * v);
    }
    int y;
    for(x=0; x<v; x++){
        for(y=0; y<v; y++){
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

grf *InsereAresta(grf *g, int va, int vb){

    g->mat[va][vb]=1;
    g->mat[vb][va]=1;

    return g;
}

void ImprimeResultado(rtd *r, int v){
    int x;
    printf("Vertice\t\tPredecessor\t\tCor\t\tDistancia\t\t");
    for(x=0; x<v; x++){
        printf("\n%i\t\t%i\t\t\t%i\t\t\t%i\n", x, r->pred[x], r->cor[x], r->dist[x]);
    }
    printf("\n");
}

void ImprimeMatriz(grf *g, int v){
int x, y;
printf("\n");
for(x=0; x<v; x++){
    for(y=0; y<v; y++){
        printf(" %i", g->mat[x][y]);
    }
    printf("\n");
}
}

int main(void){
int v;
int va, vb;
int origem;
int cf=0;
int op;
grf *g;
rtd *r;

do{
    printf("_____________MENU_____________\n\n");
    printf("|1 Criar grafo\n");
    printf("|2 Inserir arestas no grafo\n");
    printf("|3 Imprimir grafo (matriz)\n");
    printf("|4 Largura do grafo\n");
    printf("|5 Imprimir resultado\n");
    printf("|6 Sair do programa\n");
    scanf("%i", &op);

    switch(op){
        case 1:
            if(cf==0){
                printf ("\n| Defina número de vértices: \n| ");
                scanf("%i", &v);
                g = CriaGrafo(v);
                cf=1;
            }
            else{
                printf("\n| Grafo já criado!\n");
            }
            break;
        case 2:
            if(cf>=1){
                printf ("\n| Defina entre quais vértices deseja inserir aresta: \n| ");
                scanf("%i %i", &va, &vb);
                g = InsereAresta(g, va, vb);
                cf=2;
            }
            else{
                printf("\n| Grafo inda não foi criado!\n");
            }
        case 3:
            if(cf>=1){
                ImprimeMatriz(g, v);
            }
            else{
                printf("\n| Grafo ou matriz ainda não foi criado(a)!\n");
            }
            break;
        case 4:
            if(cf>=2){
                printf ("\n| Defina origem: \n| ");
                scanf("%i", &origem);
                r = BFS(g, origem);
                cf=3;
            }
            else{
                printf("\n| Grafo ou matriz ainda não foi criado(a)!\n");
            }
            break;
        case 5:
            if(cf>=3){
                ImprimeResultado(r, v);
            }
            else{
                printf("\n| Resultado ainda não definido!\n");
            }
            break;
        case 6:
            exit(1);
            break;
        default:
            printf("\n| Opção inválida!\n");
            break;
    }
}while(op!=6);

return 0;
}



