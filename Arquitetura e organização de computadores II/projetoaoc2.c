#include <stdio.h>
#include <stdlib.h>
#include "projetoaoc2.h"

int Log (int N){
   int i, n;
   i = 0;
   n = N;
   while (n > 1) {
      n= n / 2;
      i++;
   }
   return i;    
}

int Pow(int b, int e){
	
	if(e==0){
		return 1;
	}
	else{
		int r = b * Pow(b, e-1);
		return r;
	}
}

void TempoDeAcesso(){
	int tc, tm;
	float tce, ta;
	
	printf("| Informe tempo de acesso à memória cache (em ns):\n| ");
	scanf("%i", &tc);
	printf("\n");
	printf("| Informe taxa de acertos (em porcentagem):\n| ");
	scanf("%f", &ta);
	printf("\n");
	ta = ta/100;
	printf("| Informe tempo de acesso à memória RAM (em ns):\n| ");
	scanf("%i", &tm);
	printf("\n");
	
	//calcula tempo efetivo de acesso à memória
	tce = tc + ((ta - 1) * tm);
	
	printf("| Tempo efetivo de acesso:\n| %2.f ns\n", tce);
	
	return;	
}

// MÓDULO A

void TamanhoCache(){
	int info, lp, tag, off, index, conjuntos;
	float total, overhead;
	
	printf("| Informe capacidade de dados do usuário (em KB):\n| ");
	scanf("%i", &info);
	printf("\n");
	printf("| Informe tamanho da palavra (em bytes):\n| ");
	scanf("%i", &lp);
	printf("\n");
	
	//calcula offset de bytes
	off = Log(lp);
	
	//dados KB para Kb
	info = info * 8;
	
	//palavra em bytes pra bits
	lp = lp * 8;
	
	//número de conjuntos
	conjuntos = (info / lp) * 1024;
	
	//calcula tamanho do índice
	index = Log(conjuntos);
	
	//calcula tamanho da tag
	tag = lp - off - index;
	
	//calcula overhead
	overhead = conjuntos * (1 + tag);
	
	//overhead em bits para bytes
	overhead = overhead / 8;
	
	//overhead em bytes para KB
	overhead = overhead / 1024;
	
	//retorna dados para KB
	info = info / 8;
	
	//retorna palavras para bytes
	lp = lp / 8;
	
	//calcula capacidade total em KB
	total = info + overhead;
	
	
	printf("| Tamanho total da memória: %.2f KB\n", total);
	printf("| Capacidade de dados do usuário: %i KB\n", info);
	printf("| Tamanho das palavras: %i bytes por palavra\n", lp);
	printf("| Offset de bytes: %i bits\n", off);
	printf("| Número de conjuntos da cache: %i conjuntos\n", conjuntos);
	printf("| Tamanho do índice: %i bits\n", index);
	printf("| Tamanho da tag do endereço: %i bits\n", tag);
	printf("\n");
	
	return;
}

// MÓDULO B

void TamanhoCacheBloco(){
	int lp, lb, tag, offbyte, offpal, index, conjuntos, info;
	float overhead, total;
	
	printf("| Informe capacidade de dados do usuário (em KB):\n| ");
	scanf("%i", &info);
	printf("\n");
	printf("| Informe tamanho da palavra (em bytes):\n| ");
	scanf("%i", &lp);
	printf("\n");
	printf("| Informe tamanho do bloco de memória (em palavras):\n| ");
	scanf("%i", &lb);
	printf("\n");
	
	//calcula offset de bytes
	offbyte = Log(lp);
	
	//calcula offset de palavras
	offpal = Log(lb);
	
	//dados KB para B;
	info = info *1024;
	
	//número de conjuntos
	conjuntos = info / (lp * lb);
	
	//dados KB para Kb
	info = info * 8;
	
	//palavra em bytes pra bits
	lp = lp * 8;
	
	//calcula tamanho do índice
	index = Log(conjuntos);
	
	//calcula tamanho da tag
	tag = lp - offbyte - offpal - index;
	
	//calcula overhead
	overhead = conjuntos * (1 + tag);
	
	//overhead em bits para bytes
	overhead = overhead / 8;
	
	//overhead em bytes para KB
	overhead = overhead / 1024;
	
	//retorna dados para bytes
	info = info / 8;
	
	//retorna dados para KB
	info = info / 1024;
	
	//retorna palavras para bytes
	lp = lp / 8;
	
	//calcula capacidade total em KB
	total = info + overhead;
	
	
	printf("| Tamanho total da memória: %.2f KB\n", total);
	printf("| Capacidade de dados do usuário: %i KB\n", info);
	printf("| Tamanho das palavras: %i bytes\n", lp);
	printf("| Offset de bytes: %i bits\n", offbyte);
	printf("| Offset de palavras: %i bits\n", offpal);
	printf("| Número de conjuntos da cache: %i conjuntos\n", conjuntos);
	printf("| Tamanho do índice: %i bits\n", index);
	printf("| Tamanho da tag do endereço: %i bits\n", tag);
	printf("\n");
	
	return;
}

void TamanhoBloco(){
	int index, tamend, tambloco, tamblocoKB, conjuntos, tag, overhead;
	
	printf("| Informe número de bits do campo índice:\n| ");
	scanf("%i", &index);
	printf("\n");
	printf("| Informe tamanho do endereço (em bytes):\n| ");
	scanf("%i", &tamend);
	printf("\n");
	printf("| Informe overhead (em bytes):\n| ");
	scanf("%i", &overhead);
	printf("\n");
	
	//calcula número de conjuntos
	conjuntos = Pow (2,index);
	
	//tamanho do endereço para bits
	tamend = tamend * 8;
	
	//overhead para bits 
	overhead = overhead * 8;
	
	//calcula tag
	tag = (overhead - conjuntos)/conjuntos;
	
	//calcula tamanho do bloco
	tambloco = tamend - index - tag;
	tambloco = Pow (2, tambloco);
	
	//tamanho do bloco em KB
	tamblocoKB = tambloco / 1024;
	
	printf("| Tamanho do bloco: %i bytes ou %i KB\n", tambloco, tamblocoKB);	
	
	return;
}

// MÓDULO C

void CPI(){
	//dados de entrada
	float f, latmp, latdados2, latinstrucoes2, falhadados1, falhadados2, falhainstrucoes1, falhainstrucoes2, loadstore, cpi;
	//dados parciais
	float periodo, penalidaderam, penalidadenvlD, penalidadenvlI;
	float esperadados, esperainstrucoes;
	//dados finais
	float cpifinal1, cpifinal2;
	
	printf("| Informe frequência de operação do processador (em GHz):\n| ");
	scanf("%f", &f);
	printf("\n");
	printf("| Informe latência para acesso a bloco na memória principal (em ns):\n| ");
	scanf("%f", &latmp);
	printf("\n");
	printf("| Informe latência para acesso a cache de dados nível 2 (em ns):\n| ");
	scanf("%f", &latdados2);
	printf("\n");
	printf("| Informe latência para acesso a cache de instruções nível 2 (em ns):\n| ");
	scanf("%f", &latinstrucoes2);
	printf("\n");
	printf("| Informe CPI básico do processador (sem falhas):\n| ");
	scanf("%f", &cpi);
	printf("\n");
	printf("| Informe taxa de falhas na cache nível 1 de dados (em porcentagem):\n| ");
	scanf("%f", &falhadados1);
	printf("\n");
	printf("| Informe taxa de falhas na cache nível 1 de instruções (em porcentagem):\n| ");
	scanf("%f", &falhainstrucoes1);
	printf("\n");
	printf("| Informe taxa de falhas na cache nível 2 de dados (em porcentagem):\n| ");
	scanf("%f", &falhadados2);
	printf("\n");
	printf("| Informe taxa de falhas na cache nível 2 de instruções (em porcentagem):\n| ");
	scanf("%f", &falhainstrucoes2);
	printf("\n");
	printf("| Informe porcentagem de instruções do tipo load/store:\n| ");
	scanf("%f", &loadstore);
	printf("\n");
	
	printf("| Frequência de operação do processador: %.0fGHz\n", f);
	printf("| Latência para acesso a bloco na memória principal: %.0fns\n", latmp);
	printf("| Latência para acesso a cache de dados nível 2: %.0fns\n", latdados2);
	printf("| Latência para acesso a cache de instruções nível 2: %.0fns\n", latinstrucoes2);
	printf("| CPI básico do processador (sem falhas): %.0f\n", cpi);
	printf("| Taxa de falhas na cache nível 1 de dados: %.0f\n", falhadados1);
	printf("| Taxa de falhas na cache nível 1 de instruções: %.0f\n", falhainstrucoes1);
	printf("| Taxa de falhas na cache nível 2 de dados: %.0f\n", falhadados2);
	printf("| Taxa de falhas na cache nível 2 de instruções: %.0f\n", falhainstrucoes2);
	printf("| Taxa de instruções do tipo load/store: %.0f\n", loadstore);
	printf("\n");
	
	//calcula período
	periodo = 1 / f;
	
	//penalidade por falha (Nvl 2 de instrições e Nvl 2 de dados)
	penalidaderam = latmp / periodo;
	
	//penalidade por falha em níveis
	penalidadenvlD = latdados2 / periodo;
	penalidadenvlI = latinstrucoes2 / periodo;
	
	//transforma taxas
	falhadados1 = falhadados1 / 100;
	falhainstrucoes1 = falhainstrucoes1 / 100;
	falhadados2 = falhadados2 / 100;
	falhainstrucoes2 = falhainstrucoes2 / 100;
	loadstore = loadstore / 100;
	
	//calcula ciclos de espera de dados
	esperadados = (loadstore * falhadados1 * falhadados2 * penalidaderam) + (loadstore * falhadados1 * penalidadenvlD);
	
	//calcula ciclos de espera de instruções
	esperainstrucoes = (falhainstrucoes1 * falhainstrucoes2 * penalidaderam) + (falhainstrucoes1 * penalidadenvlI);
	
	//calcula CPI final (com falhas) tendo dois níveis de cache
	cpifinal2 = cpi + esperadados + esperainstrucoes;
	
	printf("| CPI final para dois níveis de cache: %.2f \n", cpifinal2);
	
	// PARA UM NIVEL DE CACHE
	
	//calcula ciclos de espera de dados
	esperadados = loadstore * falhadados1 * penalidaderam;
	
	//calcula ciclos de espera de instruções
	esperainstrucoes = falhainstrucoes1 * penalidaderam;
	
	//calcula CPI final (com falhas) tendo um nível de cache
	cpifinal1 = cpi + esperadados + esperainstrucoes;
	
	printf("| CPI final para um nível de cache: %.2f \n", cpifinal1);
	
	return;
}

// MÓDULO D

void TamanhoCacheVias(){
	int info, lp, lb, vias;
	int conjuntos, offbyte, offpal, index, tag;
	float total, overhead;
	
	printf("| Informe capacidade de dados do usuário (em KB):\n| ");
	scanf("%i", &info);
	printf("\n");
	printf("| Informe tamanho da palavra (em bytes):\n| ");
	scanf("%i", &lp);
	printf("\n");
	printf("| Informe tamanho do bloco de memória (em palavras):\n| ");
	scanf("%i", &lb);
	printf("\n");
	printf("| Informe número de vias da cache:\n| ");
	scanf("%i", &vias);
	printf("\n");
	
	printf("| Capacidade de dados do usuário (em KB): %i\n", info);
	printf("| Tamanho da palavra (em bytes): %i\n", lp);
	printf("| Tamanho do bloco de memória (em palavras): %i\n", lb);
	printf("| Número de vias da cache: %i\n", vias);
	
	printf("\n");
	
	//calcula offset de bytes
	offbyte = Log(lp);
	
	//calcula offset de palavras
	offpal = Log(lb);
	
	//dados KB para B;
	info = info *1024;
	
	//número de conjuntos
	conjuntos = info / (lp * lb);
	conjuntos = conjuntos / vias;
	
	//dados KB para Kb
	info = info * 8;
	
	//palavra em bytes pra bits
	lp = lp * 8;
	
	//calcula tamanho do índice
	index = Log(conjuntos);
	
	//calcula tamanho da tag
	tag = lp - offbyte - offpal - index;
	
	//calcula overhead
	overhead = conjuntos * (vias * (3 + tag));

	//overhead em bits para bytes
	overhead = overhead / 8;
	
	//overhead em bytes para KB
	overhead = overhead / 1024;
	
	//retorna dados para bytes
	info = info / 8;
	
	//retorna dados para KB
	info = info / 1024;
		
	//calcula capacidade total em KB
	total = info + overhead;
	
	printf("| Tamanho total da memória: %.2f KB\n", total);
	printf("| Offset de bytes: %i bits\n", offbyte);
	printf("| Offset de palavra: %i bits\n", offpal);
	printf("| Índice: %i bits\n", index);
	printf("| Tag: %i bits\n", tag);
	printf("| Número de conjuntos: %i\n", conjuntos);	
	
}

// MÓDULO E

int *LeEntrada(FILE *entrada, int tam){
	int vet[tam];
	int x, y;
	char q[100];
	
	entrada = fopen ("entrada.txt", "r");
	if (entrada == NULL){
		printf("| Não foi possível abrir o arquivo!\n");
		exit(1);
	}

	for(x=0; x<tam; x++){
		y=0;
		while((q[y] = getc(entrada))!='\n'){
			y++;
		}
		vet[x] = atoi(q);
	}
	printf("\n");
	
	fclose(entrada);

	return *vet;
}

void Cache16x1(){
	FILE *entrada;
	int x, end, acerto=0, erro=0, achou=0, mod;

	entrada = fopen ("entrada.txt", "w");
	if (entrada == NULL){
		printf("| Não foi possível abrir o arquivo!\n");
		exit(1);
	}
	
	//cria vetor
	int *vet = (int*) malloc (sizeof(int) * 16);
	
	//preenche vetor
	printf("\n");
	for(x=0; x<16; x++){
		printf("| Digite %iº endereço: ", x+1);
		scanf("%i", &end);
		vet[x] = end;
	}
	
	//armazena valores no arquivo de entrada
	for(x=0; x<16; x++){
		fprintf(entrada, "%d\n", vet[x]);
	}
	
	fclose(entrada);
	
	*vet = LeEntrada(entrada, 16);
	
	printf("| Endereços a serem buscados:\n\n| ");
	for(x=0; x<16; x++){
		printf("%i  ", vet[x]);
	}
	printf("\n\n");
	
	int cache[16];
	
	//inicializa cache
	for(x=0; x<16; x++){
		cache[x]=0;
	}

	//busca endereços
	for(x=0; x<16; x++){
		achou=0;
		mod = vet[x] % 16;
		if(cache[mod]==vet[x]){
				acerto++;
				achou=1;
				printf("| [HIT ] Endereço %i encontrado no conjunto %i\n", vet[x], mod);
		}
		if(achou==0){
			erro++;
			cache[mod]=vet[x];
			printf("| [MISS] Endereço %i armazenado na cache\n", vet[x]);
		}
	}
	
	printf("\n");
	printf("| Total de acertos: %i\n", acerto);
	printf("| Total de erros: %i\n", erro);
	printf("\n");
	
	printf("| CACHE\n");
	for(x=0; x<16; x++){
		printf("| [%i]\n", cache[x]);
	}
	printf("\n");
	
	return;
}
	
void Cache4x4(){
	FILE *entrada;
	int x, y, end, acerto=0, erro=0, achou=0, conjunto, mod;

	entrada = fopen ("entrada.txt", "w");
	if (entrada == NULL){
		printf("| Não foi possível abrir o arquivo!\n");
		exit(1);
	}

	//cria vetor
	int *vet = (int*) malloc (sizeof(int) * 16);
	
	//preenche vetor
	printf("\n");
	for(x=0; x<16; x++){
		printf("| Digite %iº endereço: ", x+1);
		scanf("%i", &end);
		vet[x] = end;
	}
	
	//armazena valores no arquivo de entrada
	for(x=0; x<16; x++){
		fprintf(entrada, "%d\n", vet[x]);
	}
	
	fclose(entrada);
	
	*vet = LeEntrada(entrada, 16);
	
	printf("| Endereços a serem buscados:\n\n| ");
	for(x=0; x<16; x++){
		printf("%i  ", vet[x]);
	}
	printf("\n\n");
	
	int cache[16];
	
	//inicializa cache
	for(x=0; x<16; x++){
		cache[x]=0;
	}

	//busca endereços
	conjunto=0;
	for(x=0; x<16; x++){
		achou=0;
		mod = vet[x] % 4;
		if(cache[mod]==vet[x]){
			if(mod>=4 && mod<8){
				conjunto=1;
			}
			if(mod>=8 && mod<12){
				conjunto=2;
			}
			if(mod>=12 && mod<16){
				conjunto=3;
			}
			acerto++;
			achou=1;
			printf("| [HIT ] Endereço %i encontrado no conjunto %i\n", vet[x], conjunto);
		}
		if(achou==0){
			erro++;
			cache[mod]=vet[x];
			printf("| [MISS] Endereço %i armazenado na cache\n", vet[x]);
		}
	}
	
	printf("\n");
	printf("| Total de acertos: %i\n", acerto);
	printf("| Total de erros: %i\n", erro);
	printf("\n");
	
	y=1;
	printf("| CACHE\n| ");
	for(x=0; x<16; x++){
		printf("[%i] ", cache[x]);
		if(y % 4 ==0){
			printf("\n| ");
		}
		y++;
	}
	printf("\n\n");
	
	return;
}

void Cache4x16x1(){
	FILE *entrada;
	int x, z, end, acerto=0, erro=0, achou=0, via;
	int count1=0, count2=0, count3=0, count4=0, v1, v2, v3, v4, menor;

	entrada = fopen ("entrada.txt", "w");
	if (entrada == NULL){
		printf("| Não foi possível abrir o arquivo!\n");
		exit(1);
	}

	//cria vetor
	int *vet = (int*) malloc (sizeof(int) * 16);
	
	//preenche vetor
	printf("\n");
	for(x=0; x<16; x++){
		printf("| Digite %iº endereço: ", x+1);
		scanf("%i", &end);
		vet[x] = end;
	}
	
	//armazena valores no arquivo de entrada
	for(x=0; x<16; x++){
		fprintf(entrada, "%d\n", vet[x]);
	}
	
	fclose(entrada);
	
	*vet = LeEntrada(entrada, 16);
	
	printf("| Endereços a serem buscados:\n\n| ");
	for(x=0; x<16; x++){
		printf("%i  ", vet[x]);
	}
	printf("\n\n");
	
	lru *via1 = malloc(sizeof(lru)*4);
	lru *via2 = malloc(sizeof(lru)*4);
	lru *via3 = malloc(sizeof(lru)*4);
	lru *via4 = malloc(sizeof(lru)*4);
	
	//inicializa cache
	for(x=0; x<4; x++){
		via1[x].endereco=0;
		via1[x].ocupado=0;
	}
	for(x=0; x<4; x++){
		via2[x].endereco=0;
		via2[x].ocupado=0;
	}
	for(x=0; x<4; x++){
		via3[x].endereco=0;
		via3[x].ocupado=0;
	}
	for(x=0; x<4; x++){
		via4[x].endereco=0;
		via4[x].ocupado=0;
	}

	//busca endereços
	v1=0;
	v2=0;
	v3=0;
	v4=0;
	for(z=0; z<16; z++){
		achou=0;
		via = vet[z] % 4;
		via++;
		switch(via){
			case 1:
				for(x=0; x<4; x++){
					if(via1[x].endereco == vet[z]){
						acerto++;
						printf("| [HIT ] Endereço %i encontrado na via 1 - conjunto %i\n", vet[z], x);
						achou=1;
					}
				}
				if(achou==0){
					erro++;
					if(via1[v1].ocupado > 0){
						menor=100;
						for(x=0; x<4; x++){
							if(via1[x].ocupado < menor){
								menor = via1[x].ocupado;
							}
						}
						for(x=0; x<4; x++){
							if(via1[x].ocupado == menor){
								via1[x].endereco=vet[z];
								printf("| [MISS] Endereço %i armazenado na cache\n", vet[z]);
							}
						}
						for(x=0; x<4; x++){
							if(via1[x].ocupado==1){
								via1[x].ocupado=4;
							}
							else{
								via1[x].ocupado--;
							}
						}
					}					
					else{
						count1++;
						if(count1 == 5){
							count1 = 1;
						}
						via1[v1].endereco=vet[z];
						via1[v1].ocupado=count1;
						printf("| [MISS] Endereço %i armazenado na cache\n", vet[z]);
						v1++;
						if(v1 == 4){
							v1=0;
						}
					}					
				}
				break;
			case 2:
				for(x=0; x<4; x++){
					if(via2[x].endereco == vet[z]){
						acerto++;
						printf("| [HIT ] Endereço %i encontrado na via 1 - conjunto %i\n", vet[z], x);
						achou=1;
					}
				}
				if(achou==0){
					erro++;
					if(via2[v2].ocupado > 0){
						menor=100;
						for(x=0; x<4; x++){
							if(via2[x].ocupado < menor){
								menor = via2[x].ocupado;
							}
						}
						for(x=0; x<4; x++){
							if(via2[x].ocupado == menor){
								via2[x].endereco=vet[z];
								printf("| [MISS] Endereço %i armazenado na cache\n", vet[z]);
							}
						}
						for(x=0; x<4; x++){
							if(via2[x].ocupado==1){
								via2[x].ocupado=4;
							}
							else{
								via2[x].ocupado--;
							}
						}
					}					
					else{
						count2++;
						if(count2 == 5){
							count2 = 1;
						}
						via2[v2].endereco=vet[z];
						via2[v2].ocupado=count2;
						printf("| [MISS] Endereço %i armazenado na cache\n", vet[z]);
						v2++;
						if(v2 == 4){
							v2=0;
						}
					}					
				}
				break;
			case 3:
				for(x=0; x<4; x++){
					if(via3[x].endereco == vet[z]){
						acerto++;
						printf("| [HIT ] Endereço %i encontrado na via 1 - conjunto %i\n", vet[z], x);
						achou=1;
					}
				}
				if(achou==0){
					erro++;
					if(via3[v3].ocupado > 0){
						menor=100;
						for(x=0; x<4; x++){
							if(via3[x].ocupado < menor){
								menor = via3[x].ocupado;
							}
						}
						for(x=0; x<4; x++){
							if(via3[x].ocupado == menor){
								via3[x].endereco=vet[z];
								printf("| [MISS] Endereço %i armazenado na cache\n", vet[z]);
							}
						}
						for(x=0; x<4; x++){
							if(via3[x].ocupado==1){
								via3[x].ocupado=4;
							}
							else{
								via3[x].ocupado--;
							}
						}
					}					
					else{
						count3++;
						if(count3 == 5){
							count3 = 1;
						}
						via3[v3].endereco=vet[z];
						via3[v3].ocupado=count3;
						printf("| [MISS] Endereço %i armazenado na cache\n", vet[z]);
						v3++;
						if(v3 == 4){
							v3=0;
						}
					}					
				}
				break;
			case 4:
				for(x=0; x<4; x++){
					if(via4[x].endereco == vet[z]){
						acerto++;
						printf("| [HIT ] Endereço %i encontrado na via 1 - conjunto %i\n", vet[z], x);
						achou=1;
					}
				}
				if(achou==0){
					erro++;
					if(via4[v4].ocupado > 0){
						menor=100;
						for(x=0; x<4; x++){
							if(via4[x].ocupado < menor){
								menor = via4[x].ocupado;
							}
						}
						for(x=0; x<4; x++){
							if(via4[x].ocupado == menor){
								via4[x].endereco=vet[z];
								printf("| [MISS] Endereço %i armazenado na cache\n", vet[z]);
							}
						}
						for(x=0; x<4; x++){
							if(via4[x].ocupado==1){
								via4[x].ocupado=4;
							}
							else{
								via4[x].ocupado--;
							}
						}
					}					
					else{
						count4++;
						if(count4 == 5){
							count4 = 1;
						}
						via4[v4].endereco=vet[z];
						via4[v4].ocupado=count1;
						printf("| [MISS] Endereço %i armazenado na cache\n", vet[z]);
						v4++;
						if(v4 == 4){
							v4=0;
						}
					}					
				}
				break;
		}
	}

	printf("\n");
	printf("| Total de acertos: %i\n", acerto);
	printf("| Total de erros: %i\n", erro);
	printf("\n");
	
	printf("| CACHE ");
	printf("\n| VIA 1 ");
	for(x=0; x<4; x++){
		printf("[%i] ", via1[x].endereco);
	}
	printf("\n| VIA 2 ");
	for(x=0; x<4; x++){
		printf("[%i] ", via2[x].endereco);
	}
	printf("\n| VIA 3 ");
	for(x=0; x<4; x++){
		printf("[%i] ", via3[x].endereco);
	}
	printf("\n| VIA 4 ");
	for(x=0; x<4; x++){
		printf("[%i] ", via4[x].endereco);
	}
	printf("\n\n");
	
	return;
}

void MenuCaches(){
	int op;
	
	do{
		printf("|===============================================================================================|\n");
		printf("| 1- Diretamente mapeada, com 16 blocos de uma palavra cada                                     |\n");
		printf("| 2- Diretamente mapeada, com 4 blocos de 4 palavras cada                                       |\n");
		printf("| 3- Associativa por conjunto de 4 vias, com 16 blocos ao todo, sendo cada bloco de uma palavra |\n");
		printf("| 0- Retornar para o menu principal                                                             |\n");
		printf("|===============================================================================================|\n| ");
		scanf("%i", &op);
				
		switch(op){
			case 0:
				return;
				break;
			case 1:
				Cache16x1();
				break;
			case 2:
				Cache4x4();
				break;
			case 3:
				Cache4x16x1();
				break;
			default:
				printf("\n| OPÇÃO INVÁLIDA!\n\n");
				break;
		}
	} while (op!=0);
}

// MÓDULO F

void RAID3(){
	int d0=0, d1=0, d2=0, d3=0, p=0;
	int op1, op2, dado;
	
	do{
		printf("\n");
		printf("|======================================|\n");
		printf("| 1- Armazenar dado de 4 bytes         |\n");
		printf("| 2- Armazenar dado de 16 bytes        |\n");
		printf("| 3- Emular falha no disco             |\n");
		printf("| 0- Retornar para seleção de RAID's   |\n");
		printf("|======================================|\n| ");
		scanf("%i", &op1);
		
		switch(op1){
			case 0:
				printf("\n");
				return;
				break;
			case 1:
				printf("\n| Digite dado a ser armazenado:\n| ");
				scanf("%i", &dado);
				
				if (d0!=0){
					if(d1!=0){
						if(d2!=0){
							if(d3!=0){
								d0 = dado;
								p = dado ^ d1 ^ d2 ^ d3;
							}
							else{
								d3 = dado;
								p = dado ^ d1 ^ d2 ^ d3;
							}								
						}
						else{
							d2 = dado;
							p = dado ^ d1 ^ d2 ^ d3;
						}
					}
					else{
						d1 = dado;
						p = dado ^ d1 ^ d2 ^ d3;
					}				
				}
				else {
					d0 = dado;
					p = dado ^ d1 ^ d2 ^ d3;
				}
				
				printf("\n");
				printf("| Disco 0 [%i]\n", d0);
				printf("| Disco 1 [%i]\n", d1);
				printf("| Disco 2 [%i]\n", d2);
				printf("| Disco 3 [%i]\n", d3);
				printf("| Backup  [%i]\n", p);
				
				break;
			case 2:
				printf("\n| Digite dado a ser armazenado:\n| ");
				scanf("%i", &dado);
				p = dado;
				dado = dado/4;
				
				d0 = dado;
				d1 = dado;
				d2 = dado;
				d3 = dado;
				
				printf("\n");
				printf("| Disco 0 [%i]\n", d0);
				printf("| Disco 1 [%i]\n", d1);
				printf("| Disco 2 [%i]\n", d2);
				printf("| Disco 3 [%i]\n", d3);
				printf("| Backup  [%i]\n", p);
				break;
			case 3:
				printf("| Digite disco:\n| ");
				scanf("%i", &op2);
				switch(op2){
					case 0:
						d0 = p ^ (d1 ^ d2 ^ d3);
						printf("| Disco 0 [%i]\n", d0);
						break;
					case 1:
						d1 = p ^ (d0 ^ d2 ^ d3);
						printf("| Disco 1 [%i]\n", d1);
						break;
					case 2:
						d2 = p ^ (d1 ^ d0 ^ d3);
						printf("| Disco 2 [%i]\n", d2);
						break;
					case 3:
						d3 = p ^ (d1 ^ d2 ^ d0);
						printf("| Disco 3 [%i]\n", d3);
						break;
				}
			default:
				printf("\n| OPÇÃO INVÁLIDA!\n\n");
				break;
		}
	} while (op1!=0);

}

void RAID4(){
	int d0=0, d1=0, d2=0, d3=0, p=0;
	int op1, op2, dado, dadoparcial;
	
	do{
		printf("\n");
		printf("|======================================|\n");
		printf("| 1- Armazenar dado de 4 bytes         |\n");		
		printf("| 2- Emular falha no disco             |\n");
		printf("| 0- Retornar para seleção de RAID's   |\n");
		printf("|======================================|\n| ");
		scanf("%i", &op1);
		
		switch(op1){
			case 0:
				printf("\n");
				return;
				break;
			case 1:
				printf("\n| Digite dado a ser armazenado:\n| ");
				scanf("%i", &dado);
				
				d0 = dado;
				dadoparcial = dado ^ d0;
				p = p ^ dadoparcial;
				
				if (d0!=0){
					if(d1!=0){
						if(d2!=0){
							if(d3!=0){
								dadoparcial = dado ^ d0;
								p = p ^ dadoparcial;
								d0 = dado;
							}
							else{
								dadoparcial = dado ^ d3;
								p = p ^ dadoparcial;
								d3 = dado;
							}								
						}
						else{
							dadoparcial = dado ^ d2;
							p = p ^ dadoparcial;
							d2 = dado;
						}
					}
					else{
						dadoparcial = dado ^ d1;
						p = p ^ dadoparcial;
						d1 = dado;
					}				
				}
				else {
					dadoparcial = dado ^ d0;
					p = p ^ dadoparcial;
					d0 = dado;
				}
				
				printf("\n");
				printf("| Disco 0 [%i]\n", d0);
				printf("| Disco 1 [%i]\n", d1);
				printf("| Disco 2 [%i]\n", d2);
				printf("| Disco 3 [%i]\n", d3);
				printf("| Backup  [%i]\n", p);			
				break;
			case 2:
				printf("| Digite disco:\n| ");
				scanf("%i", &op2);
				switch(op2){
					case 0:
						d0 = p ^ (d1 ^ d2 ^ d3);
						printf("| Disco 0 [%i]\n", d0);
						break;
					case 1:
						d1 = p ^ (d0 ^ d2 ^ d3);
						printf("| Disco 1 [%i]\n", d1);
						break;
					case 2:
						d2 = p ^ (d1 ^ d0 ^ d3);
						printf("| Disco 2 [%i]\n", d2);
						break;
					case 3:
						d3 = p ^ (d1 ^ d2 ^ d0);
						printf("| Disco 3 [%i]\n", d3);
						break;
				}
			default:
				printf("\n| OPÇÃO INVÁLIDA!\n\n");
				break;
			}
		} while (op1!=0);
}

void MenuRAIDs(){
	int op;
	
	do{
		printf("|===================================|\n");
		printf("| 1- Emular RAID 3                  |\n");
		printf("| 2- Emular RAID 4                  |\n");
		printf("| 0- Retornar para o menu principal |\n");
		printf("|===================================|\n| ");
		scanf("%i", &op);
				
		switch(op){
			case 0:
				return;
				break;
			case 1:
				RAID3();
				break;
			case 2:
				RAID4();
				break;
			default:
				printf("\n| OPÇÃO INVÁLIDA!\n\n");
				break;
		}
	} while (op!=0);
}

// MÓDULO G
int ES(int tam){
	int end;
	
	printf("\n");
	printf("| Digite endereço entre 0 e %i:\n| ", tam);
	scanf("%i", &end);
	
	if(end < tam){
		return end;
	}
	else{
		printf("\n");
		printf("| Por favor, digite um endereço válido!\n\n");
		return -1;
	}
}

int memoria(int end, int tam){
	int dado, x;
	
	int *mem = (int*) malloc (sizeof(int) * tam);
	
	printf("\n");
	printf("| Endereço\t| Dado  |\n");
	for(x=0; x<tam; x++){
		mem[x] = rand() % tam;
		printf("| %i\t\t| %i\n", x, mem[x]);
	}
	dado = mem[end];
	return dado;
}

void Handshake(){
	int tam, end, dado;
	int tempototal, tempotransmissao, tempomemoria;
	inout device;
	mem memory;
	float banda, segundo;
	
	printf("| Digite tamanho da memória:\n| ");
	scanf("%i", &tam);
	printf("\n");
	printf("| Informe latências (em ns) para:\n");
	printf("| Barramento: ");
	scanf("%i", &tempotransmissao);
	printf("| Leitura da memória: ");
	scanf("%i", &tempomemoria);
	
	if((3*tempotransmissao) > tempomemoria){
		tempototal = (7*tempotransmissao);
	}
	else{
		tempototal = tempomemoria + (4*tempotransmissao);
	}		

	// Envia endereço a ser lido
	end = ES(tam);
	if(end == -1){
		return;
	}
	// Ativa requisição de leitura
	device.reqleit=1;
	// Memória ativa Ack
	memory.ack=1;
	device.reqleit=0;
	// Memória lê dado no endereço
	memory.ack=0;
	dado = memoria(end, tam);
	memory.dadoprt=1;
	// E/S ativa Ack
	device.ack=1;
	// E/S lê dado
	memory.dadoprt=0;
	device.ack=0;
	
	segundo = tempototal * 0.001;
	banda = 4 / segundo;
	
	printf("\n");
	printf("| Dado [%i] encontrado no endereço [%i]\n", dado, end);
	printf("| Tempo total: %ins\n", tempototal);
	printf("| Banda passante máxima: %.2fMB/s\n", banda);
}
