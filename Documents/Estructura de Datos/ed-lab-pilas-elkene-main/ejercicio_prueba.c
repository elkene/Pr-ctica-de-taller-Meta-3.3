#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "funciones/funciones.h"
#include "estructuras/nodo.h"
#include "estructuras/lista.h"
#include "pilas/pilas.h"

int main() {
    Pilas pila;
    IniciarListaDoble(&pila);
    LeerArchivo(&pila);
    ImprimirPila(&pila);
    LiberarLista(&pila);
    return 0;
}
