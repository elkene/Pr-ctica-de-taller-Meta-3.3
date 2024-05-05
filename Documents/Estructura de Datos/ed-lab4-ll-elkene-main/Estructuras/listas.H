#pragma once
#include "nodos.h"


typedef struct _ListaDoblePalabras
{
NodoSimple *head;
NodoSimple *tail;
NodoSimple *current;
int size;
} ListaDoblePalabras;