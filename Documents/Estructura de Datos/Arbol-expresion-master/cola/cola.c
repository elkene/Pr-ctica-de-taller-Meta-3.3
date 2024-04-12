#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "cola.h"
#include "../funciones/funciones.h"
#include "../nodo/nodo.h"
#include "lista.h"

void pushcola(Cola *cola, void *dato)
{
    AddTail(cola,dato);
}

void *popcola(Cola *cola) {
    NodoDoble *nodo = cola->head;
    if (nodo == NULL) {
        printf("Error: La cola esta vacia.\n");
        return NULL;
    }
    void *copia = nodo->data;
    cola->head = nodo->next;
    if (cola->head == NULL) {
        cola->tail = NULL;
    } else {
        cola->head->prev = NULL;
    }
    free(nodo);
    cola->size--;
    return copia;
}

int estavaciacola(Cola *cola){
        return cola->head == NULL;
}


void imprimircola(Cola *cola, void (*Print_func)(void *)) {
    Cola aux;
    void *dato = NULL;

    IniciarListaDoble(&aux);

    while (cola->size != 0) {
        dato = popcola(cola);
        Print_func(dato);
        pushcola(&aux, dato);
    }

    LiberarLista(cola); 
    IniciarListaDoble(cola); 

    while (aux.size != 0) {
        dato = popcola(&aux);
        pushcola(cola, dato);
    }

    LiberarLista(&aux); 
}


void *peek(const Cola *const cola)
{
    return cola->head->data;
}
