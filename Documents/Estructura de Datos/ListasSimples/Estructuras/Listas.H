#pragma once
#include "Nodos.h"
typedef struct _ListaSimple
{
    NodoSimple *head;
    NodoSimple *tail;
    NodoSimple *current;
    int size;
} ListaSimple;
