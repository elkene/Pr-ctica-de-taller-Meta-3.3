#pragma once
#include "../Estructuras/Listas.H"
#include "../Estructuras/Nodos.h"

void IniciarListaSimple(ListaSimple *lista);
void AddHead(ListaSimple *lista, void *dato);
void AddTail(ListaSimple *lista, void *dato);
void AddPos(ListaSimple *lista, void *dato, int pos);

void BorrarNodo(ListaSimple *lista, void *dato);

void LiberarLista(ListaSimple *lista);

NodoSimple *GetNodo(ListaSimple *lista, void *dato);
NodoSimple *GetNodoAnt(ListaSimple *lista, void *dato);
NodoSimple *GetNodoPos(ListaSimple *lista, int pos);

void ImprimirLista(ListaSimple lista, void (*func)(void *));
