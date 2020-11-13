typedef struct lista ListaGen;

ListaGen *cria_lista();

void vazia(ListaGen *l);

ListaGen *lista_insere(ListaGen *l, void* p);

void percorre(ListaGen *l, void(*cb)(void*));

void lgen_busca(ListaGen *l,int(*cb)(void*,void*),void* dado);

ListaGen *lgen_exclui(ListaGen *l,int(*cb)(void*,void*),void* dado);

ListaGen *libera (ListaGen* l);

