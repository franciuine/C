typedef struct lista lst;

lst *Cria();

void Percorre(lst *l, void (*cb)(void*));

lst *InsereGen(lst *l, void *novo);

void Busca(lst *l, int(*cb)(void*,void*), void* m);

lst *Remove(lst *l, int(*cb)(void*,void*), void *m);

void Vazia (lst *l);
