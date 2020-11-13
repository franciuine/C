struct Lista{
	char nome[50];
	float nota;
	struct Lista *prox;
}; typedef struct Lista lst;

struct Pilha{
	lst *topo;
}; typedef struct Pilha plh;

plh *CriaPilha ();

plh *PushPilha (plh *p);

void ImprimePilha (plh *p);