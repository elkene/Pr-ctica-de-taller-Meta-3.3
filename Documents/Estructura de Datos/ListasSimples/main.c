#include "Estructuras/Listas.H"
#include "Funciones/LLSF.h"
#include <stdio.h>

void ImprimirNumeros(void *dato)
{
    printf("%d\n", *(int *)dato);
}

void ImprimirStrings(void *dato)
{
    printf("%s\n", (char *)dato);
}

int main(void)
{
    int a = 10, b = 20, c = 30, d = 40, e = 50;

    ListaSimple milista;
    IniciarListaSimple(&milista);

    AddHead(&milista, &a);
    AddTail(&milista, &b);
    AddHead(&milista, &c);
    AddTail(&milista, &d);
    AddPos(&milista, &e, 3);
    AddTail(&milista, "HOLA");

    BorrarNodo(&milista, &c);

    ImprimirLista(milista, ImprimirNumeros);
    ImprimirStrings(milista.tail->data);

    LiberarLista(&milista);

    return 0;
}
