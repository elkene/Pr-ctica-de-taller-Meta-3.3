#include <stdio.h>
#include <stdlib.h>
#include "nodo/nodo.h"
#include "funciones/funciones.h"
#include "cola/cola.h"


int main() {
    // Ingresa la expresión
    char expresion[] = "(1-t)^2*p+2*(1-t)*t*a+t^2*b";

    // Convierte la expresión a notación posfija
    char *posfija = InfixToPostfix(expresion);

    // Crea un árbol de expresión a partir de la expresión posfija
    NodoBinario *arbolExpresion = NULL;
    AgregarNodoExpr(&arbolExpresion, posfija);

    // Calcula e imprime la altura del árbol de expresión
    printf("La altura del árbol de expresión es: %d\n", alturaArbol(arbolExpresion));

    // Libera la memoria utilizada
    free(posfija);
    liberarArbol(arbolExpresion);

    return 0;
}