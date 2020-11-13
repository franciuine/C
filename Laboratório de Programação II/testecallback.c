// CALLBACK E PARÂMETROS GENÉRICOS

void callback (void* info); //DECLARAÇÃO DE CALLBACK
void (cb) (void); //DECLARAÇÃO DA VARIÁVEL CB DO CALLBACK

void percorre(ListaGen l, void (*cb)(void)){ //FUNÇÃO DE PERCORRER SEM PAUSA
	ListaGen *p;
	for (p=l; p!=NULL; p=p->prox){
		cb(p->info);
	}
}

int cond_percorre(ListaGen* l, int (cb)(void, void*), void* dado){ //FUNÇÃO DE PERCORRER COM PAUSA
	ListaGen *p;
	for(p=l;p!=NULL;p=p->prox){
		int r = cb(p->info, dado);
		if (r!=0){
			return r;
		}
	}
return 0;
}

ListaGen *insere(ListaGen *l, void *dado) { //INSERE UM DADO GENÉRICO NA LISTA
	ListaGen t = (ListaGen)malloc(sizeof(ListaGen));
	t->info = dado;
	t->prox = l;
	return t;
}

void imprime(void *info) { //IMPRIME INDIVIDUAL (USADA COM PERCORRE: percorre(l,imprime);
	Aluno al = (Aluno)info;
	printf("MATRICULA: %i\n", al->matricula);
	printf("NOME: %s\n", al->nome);
	printf("==========================================\n");
}

ListaGen *exclui(ListaGen *l, void *dado) { //EXCLUI UM ELEMENTO DA LISTA (Por matrícula)
	ListaGen *a = NULL; // Ponteiro para o elemento anterior
	ListaGen *p = l; // Ponteiro para percorrer a lista
	Aluno temp = (Aluno)dado; 
	int matric = temp->matricula;
	Aluno al = (Aluno)p->info;
	while(p!=NULL && al->matricula!=matric) { //Procura o elemento na lista...
		a = p;
		p = p->prox;
		al = (Aluno*)p->info;
	}
	if (p==NULL) { //VERIFICA SE ACHOU O ELEMENTO... (Caso não, retorna a lista original)
		return l;
	}
	if (a==NULL) {
		l = p->prox; //Retira o elemento do início
	} else {
		a->prox = p->prox; //Retira o elemento do meio
	}
	free(p); // Libera o espaço do usuário removido da memória
	return l;
}

void *busca(ListaGen *l, void*dado) { // BUSCA UM ELEMENTO NA LISTA
	Aluno temp = (Aluno)dado;
	int matric = temp->matricula;
	ListaGen *p;
	Aluno *al;
	for (p=l;p!=NULL;p=p->prox) {
		al = (Aluno*)p->info;
		if (al->matricula==matric) {
			printf("==========================================\n");
			printf("Aluno encontrado!\n");
			printf("MATRÍCULA: %i\n", al->matricula);
			printf("NOME: %s\n", al->nome);
			printf("==========================================\n");
			return;
		}
	}
	printf("Aluno nao encontrado!\n");
}
