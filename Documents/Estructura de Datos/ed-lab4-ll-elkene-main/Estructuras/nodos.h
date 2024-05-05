#pragma once

typedef struct _Palabra{
char palabra[50];
int contador;
} Palabra;


typedef struct _NodoSimple
{
Palabra datos;
struct _NodoSimple *next;
struct _NodoSimple *prev;
} NodoSimple;