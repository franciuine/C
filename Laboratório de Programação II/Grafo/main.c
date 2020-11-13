// Prova 3
// 29/09/2017
// Franciuíne Almeida (franciuine@gmail.com)

#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

int main(){
	int va, vb;
	int origem;
	int cf=0;
	int op;
	int opp;
	grf *g;
	rtd *r;
	dfs *resultadoDFS;
	pdfs *p;
	int x;
	int v;
	int orientado;
	
	do{
		printf("\n");
		printf("_____________MENU_____________\n\n");
		printf("|1 Criar grafo\n");
		printf("|2 Inserir arestas no grafo\n");
		printf("|3 Imprimir grafo (matriz)\n");
		printf("|4 Executar Busca em largura\n");
		printf("|5 Executar Busca em profundidade\n");
		printf("|6 Ordenação topológica\n");
		printf("|7 Árvore de amplitude mínima\n");    
		printf("|8 Liberar grafo\n");
		printf("|9 Sair do programa\n");
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
					printf("| 1 Orientado\n");
					printf("| 2 Não Orientado\n");
					printf("\n");
					scanf("%i", &opp);
					
					switch(opp){
						case 1:
							printf ("\n| Defina entre quais vértices deseja inserir aresta: \n| ");
							scanf("%i %i", &va, &vb);
							orientado=1;
							g = InsereArestaOrientado(g, va, vb);
							cf=2;
							break;
						case 2:
							printf ("\n| Defina entre quais vértices deseja inserir aresta: \n| ");
							scanf("%i %i", &va, &vb);
							g = InsereArestaNaoOrientado(g, va, vb);
							orientado=0;
							cf=2;
							break;
						default:
							printf("\n| Opção inválida!\n");
							break;
					}
				}
				else{
					printf("\n| Grafo inda não foi criado!\n");
				}
			case 3:
				if(cf>=1){
					ImprimeMatriz(g);
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
					ImprimeBFS(r, g);
					cf=3;
				}
				else{
					printf("\n| Grafo ou matriz ainda não foi criado(a)!\n");
				}
				break;
			case 5:
				if(cf>=2){
					resultadoDFS = DFS(g);
					ImprimeDFS(resultadoDFS, g);
				}
				else{
					printf("\n| Grafo ou matriz ainda não foi criado(a)!\n");
				}
				break;
			case 6:
				if(cf>=2){
					if(orientado==1){
						p = OrdenacaoTopologica(g);
						ImprimeTopologica(p,g);
					}
					else{
						printf("\n| O grafo criado não é orientado!\n");
					}
				}
				else{
					printf("\n| Grafo ou matriz ainda não foi criado(a)!\n");
				}
				break;
			case 7:
				if(cf>=2){
					if(orientado==0){
						Prim(g);
					}
					else{
						printf("\n| O grafo criado é orientado!\n");
					}
				}
				else{
					printf("\n| Grafo ou matriz ainda não foi criado(a)!\n");
				}
				break;
			case 8:
				for(x=0;x<g->ver;x++){
					free(g->mat[x]);
				}
				free(g->mat);
				free(g);
				printf("\n| Grafo liberado!\n");
				cf=0;
				break;
			case 9:
				exit(1);
				break;
			default:
				printf("\n| Opção inválida!\n");
				break;
		}
	}while(op!=9);

	return 0;
}



