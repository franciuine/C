struct LRU {
	int endereco;
	int ocupado;
}; typedef struct LRU lru;

struct entradaesaida{
	int ack;
	int reqleit;
}; typedef struct entradaesaida inout;

struct memoria{
	int ack;
	int dadoprt;
}; typedef struct memoria mem;

int Log (int N);
int Pow(int b, int e);
void TempoDeAcesso ();
void TamanhoCache();
void TamanhoCacheBloco ();
void TamanhoBloco ();
void CPI();
void TamanhoCacheVias();
int *LeEntrada(FILE *entrada, int tam);
void Cache16x1();
void Cache4x4();
void Cache4x16x1();
void MenuCaches();
void RAID3();
void RAID4();
void MenuRAIDs();
int ES(int tam);
int memoria(int end, int tam);
void Handshake();
