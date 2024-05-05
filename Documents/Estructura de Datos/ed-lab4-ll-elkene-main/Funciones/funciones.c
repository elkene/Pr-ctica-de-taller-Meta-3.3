#include "../Estructuras/listas.H"
#include "../Estructuras/nodos.h"
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

void IniciarListaDoblePalabras(ListaDoblePalabras *lista)
{
    lista->head = NULL;
    lista->tail = NULL;
    lista->current = NULL;
    lista->size = 0;
}
void AddTail(ListaDoblePalabras *lista, Palabra *dato)
{
    NodoSimple *nuevo = (NodoSimple *)malloc(sizeof(NodoSimple));
        nuevo->datos= *dato;
        nuevo->next=NULL;
        nuevo->prev=lista->tail;

    if (lista->tail == NULL)
    {
        lista->head = nuevo;
    }
    else
    {
        lista->tail->next = nuevo;
    }
    lista->tail = nuevo;
    lista->size++;
}
void ImprimirListaPalabras(ListaDoblePalabras lista, void (*func)(Palabra *), int *palabrasSinRepetir)
{
    lista.current = lista.head;
    *palabrasSinRepetir = 0; 
    while (lista.current != NULL)
    {
        func(&(lista.current->datos));
        if (lista.current->datos.contador == 1) {
            (*palabrasSinRepetir)++;
        }
        lista.current = lista.current->next;
    }
}
void LiberarListaPalabras(ListaDoblePalabras *lista)
{
lista->current = lista->head;
while (lista->current != NULL)
{
NodoSimple *temp = lista->current;
lista->current = lista->current->next;
free(temp);
}
}

void ContarPalabras(FILE *archivo, ListaDoblePalabras *lista){
char palabra[50];
while(fscanf(archivo, "%s", palabra)==1){
    NodoSimple *current=lista->head;
        while(current!=NULL){
            if(strcmp(current->datos.palabra, palabra)==0){
                current->datos.contador++;
                break;
}
    current=current->next;
                            }

if(current==NULL){
    Palabra nuevaPalabra={0};
    strcpy(nuevaPalabra.palabra, palabra);
    nuevaPalabra.contador=1;
    AddTail(lista, &nuevaPalabra);
        }
    }
}

void ImprimirPalabra(Palabra *palabra){
printf("%s: %d\n",palabra->palabra, palabra->contador);
}