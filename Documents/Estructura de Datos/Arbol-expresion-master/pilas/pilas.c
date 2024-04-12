#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "pilas.h"
#include "../funciones/funciones.h"
#include "../cola/lista.h"
#include "../nodo/nodo.h"

void push(Pilas *pila, void *dato) {
    AddTail(pila, dato);
}

void *pop(Pilas *pila) {
    void *copia = pila->tail->data;

    BorrarNodo(pila, pila->tail->data);
    return copia;
}


void ImprimirPila(Pilas *pila) {
    Pilas aux;
    IniciarListaDoble(&aux);

    void *dato = NULL;

    while (!estaVacia(pila)) {
        dato = pop(pila);
        printf("%s ", (char *)dato);
        push(&aux, dato);
    }

    printf("\n");

    while (!estaVacia(&aux)) {
        dato = pop(&aux);
        push(pila, dato);
    }
    LiberarLista(&aux);
}

int estaVacia(Pilas *pila)
{
    return pila->head == NULL;
   
       
}


