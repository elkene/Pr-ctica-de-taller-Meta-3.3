#include "../estructuras/lista.h"
#include "../estructuras/nodo.h"


void IniciarListaDoble(ListaDoble *lista);
void AddHead(ListaDoble *lista, void *dato);
void AddTail(ListaDoble *lista, void *dato);

void BorrarNodo(ListaDoble *lista, void *dato);

void LiberarLista(ListaDoble *lista);

NodoDoble *GetNodo(ListaDoble *lista, void *dato);
NodoDoble *GetNodoAnt(ListaDoble *lista, void *dato);
NodoDoble *GetNodoPos(ListaDoble *lista, int pos);

void ImprimirLista(ListaDoble *lista, void (*func)(void *));

