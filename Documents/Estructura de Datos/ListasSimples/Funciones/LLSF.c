#include "LLSF.h"
#include <stdio.h>  //imprimir
#include <stdlib.h> //malloc etc

void IniciarListaSimple(ListaSimple *lista)
{
    lista->head = NULL;
    lista->tail = NULL;
    lista->current = NULL;
    lista->size = 0;
}

void AddHead(ListaSimple *lista, void *dato)
{
    NodoSimple *nuevo = (NodoSimple *)malloc(sizeof(NodoSimple));
    nuevo->data = dato;
    if (lista->head == NULL)
    {
        lista->tail = nuevo;
        nuevo->next = NULL;
    }
    else
    {
        nuevo->next = lista->head;
    }
    lista->head = nuevo;
    lista->size++;
}

void AddTail(ListaSimple *lista, void *dato)
{
    NodoSimple *nuevo = (NodoSimple *)malloc(sizeof(NodoSimple));
    nuevo->data = dato;
    if (lista->tail == NULL)
    {
        lista->head = nuevo;
        nuevo->next = NULL;
    }
    else
    {
        lista->tail->next = nuevo;
        nuevo->next = NULL;
    }
    lista->tail = nuevo;
    lista->size++;
}

NodoSimple *GetNodoPos(ListaSimple *lista, int pos)
{
    NodoSimple *temp = lista->head;
    while (temp != NULL && pos > 0)
    {
        temp = temp->next;
        pos--;
    }
    return temp;
}

void AddPos(ListaSimple *lista, void *dato, int pos)
{
    if (pos == 0)
        AddHead(lista, dato);
    else if (pos == lista->size)
        AddTail(lista, dato);
    else
    {
        NodoSimple *nuevo = (NodoSimple *)malloc(sizeof(NodoSimple));
        nuevo->data = dato;

        NodoSimple *ant = GetNodoPos(lista, pos - 1);
        nuevo->next = ant->next;
        ant->next = nuevo;
    }
    lista->size++;
}

void ImprimirLista(ListaSimple lista, void (*func)(void *))
{
    lista.current = lista.head;

    while (lista.current != NULL)
    {
        func(lista.current->data);
        lista.current = lista.current->next;
    }
}

void LiberarLista(ListaSimple *lista)
{
    lista->current = lista->head;
    while (lista->current != NULL)
    {
        NodoSimple *temp = lista->current;
        lista->current = lista->current->next;
        free(temp);
    }
}

NodoSimple *GetNodo(ListaSimple *lista, void *dato)
{
    lista->current = lista->head;
    while (lista->current->data != dato && lista->current != NULL)
    {
        lista->current = lista->current->next;
    }
    return lista->current;
}

NodoSimple *GetNodoAnt(ListaSimple *lista, void *dato)
{
    lista->current = lista->head;
    while (lista->current != NULL && lista->current->next != NULL)
    {
        if (lista->current->next->data == dato)
            break;
        lista->current = lista->current->next;
    }
    return lista->current;
}

void BorrarNodo(ListaSimple *lista, void *dato)
{
    NodoSimple *curr = GetNodo(lista, dato);
    NodoSimple *ant = GetNodoAnt(lista, dato);

    if (curr == NULL)
    {
        printf("No se encontro el nodo\n");
        return;
    }
    if (curr == lista->head)
    {
        lista->head = curr->next;
        free(curr);
        lista->size--;
        return;
    }
    else if (curr == lista->tail)
    {
        lista->tail = ant;
    }
    ant->next = curr->next;
    free(curr);
    lista->size--;
}
