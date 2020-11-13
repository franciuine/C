int *LeEntrada(FILE *entrada, int tam){

	int vet[tam], x, y;
	char q[100];

	entrada = fopen ("entrada.txt", "r");
	if (entrada == NULL){
		printf("| Não foi possível abrir o arquivo!\n");
		exit(1);
	}

	for(x=0; x<tam; x++){
		y=0;
		while((q[y] = getc(entrada))!='\t'){
			y++;
		}
		vet[x] = atoi(q);
	}
	printf("\n");
	
	fclose(entrada);

	return *vet;
}

void BubbleSort (int *vet, int tam){
	time_t tIni, tFim;
	int x, y, aux, op;
	FILE *bubble;

	bubble = fopen ("bubblesort.txt", "w");
	if (bubble == NULL){
		printf("| Não foi possível abrir o arquivo!\n");
		exit(1);
	}

	tIni = time(NULL);
	for(x=0; x<tam-1; x++){
		for(y=x+1; y<tam; y++){
			if(vet[x] > vet[y]){
			aux = vet[x];
			vet[x] = vet[y];
			vet[y] = aux;
			}
		}
	}
	tFim = time(NULL);
	printf("| Tempo de Ordenação: %ld segundos\n\n", tFim - tIni);

	for (x=0; x<tam; x++){
		fprintf(bubble, "%d\t", vet[x]);
	}

	fclose(bubble);

	printf("| Imprimir valores na tela?\n");
	printf("| 1- Sim\n");
	printf("| 2- Não\n| ");
	scanf("%i", &op);

	if(op==1){
		printf("\n");
		for (x=0; x<tam; x++){
			printf("%d\t", vet[x]);
		}
	}
	printf("\n");
	if((op!=1) && (op!=2)){
		printf("| OPÇÃO INVÁLIDA!\n");
	}
}

void InsertionSort(int *vet, int tam){
	time_t tIni, tFim;
	int x, y, aux, op;
	FILE *insertion;

	insertion = fopen ("insertionsort.txt", "w");
	if (insertion == NULL){
		printf("| Não foi possível abrir o arquivo!\n");
		exit(1);
	}
	
	tIni = time(NULL);
	for(x=1; x<tam; x++) {
		y = x;
        while(y>0 && vet[y-1] > vet[y]){
			aux = vet[y];
			vet[y] = vet[y-1];
            vet[y-1] = aux;
            y--;
		}
	}
	tFim = time(NULL);
	printf("| Tempo de Ordenação: %ld segundos\n\n", tFim - tIni);
	
	for (x=0; x<tam; x++){
		fprintf(insertion, "%d\t", vet[x]);
	}

	fclose(insertion);
	
	printf("| Imprimir valores na tela?\n");
	printf("| 1- Sim\n");
	printf("| 2- Não\n| ");
	scanf("%i", &op);

	if(op==1){
		printf("\n");
		for (x=0; x<tam; x++){
			printf("%d\t", vet[x]);
		}
	}
	printf("\n");
	if((op!=1) && (op!=2)){
		printf("| OPÇÃO INVÁLIDA!\n");
	}
}

void SelectionSort(int *vet, int tam){
	time_t tIni, tFim;
	int x, y, aux, op, min;
	FILE *selection;

	selection = fopen ("selectionsort.txt", "w");
	if (selection == NULL){
		printf("| Não foi possível abrir o arquivo!\n");
		exit(1);
	}
	
	tIni = time(NULL);
	for(x=0; x<(tam-1); x++){
		min = x;
		for(y=x+1; y<tam; y++){
			if(vet[y]<vet[min]){
			min = y;
			}
		}
		if(x!=min){
			aux = vet[x];
			vet[x] = vet[min];
			vet[min] = aux;
		}
	}
	tFim = time(NULL);
	printf("| Tempo de Ordenação: %ld segundos\n\n", tFim - tIni);
	
	for (x=0; x<tam; x++){
		fprintf(selection, "%d\t", vet[x]);
	}

	fclose(selection);
	
	printf("| Imprimir valores na tela?\n");
	printf("| 1- Sim\n");
	printf("| 2- Não\n| ");
	scanf("%i", &op);

	if(op==1){
		printf("\n");
		for (x=0; x<tam; x++){
			printf("%d\t", vet[x]);
		}
	}
	printf("\n");
	if((op!=1) && (op!=2)){
		printf("| OPÇÃO INVÁLIDA!\n");
	}
}
