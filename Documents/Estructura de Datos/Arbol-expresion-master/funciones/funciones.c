#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../nodo/nodo.h"
#include "funciones.h"
#include "../cola/lista.h"
#include "../cola/cola.h"
#include "../pilas/pilas.h"



void IniciarListaDoble(ListaDoble *lista) {
    lista->head = NULL;
    lista->tail = NULL;
    lista->size = 0;
}

void AddHead(ListaDoble *lista, void *dato) {
    NodoDoble *nuevo = (NodoDoble *)malloc(sizeof(NodoDoble));
    if (nuevo == NULL) {
        printf("Error: No se pudo asignar memoria para el nuevo nodo\n");
        return;
    }
    nuevo->data = dato;
    nuevo->next = lista->head;
    nuevo->prev = NULL;
    if (lista->head != NULL) {
        lista->head->prev = nuevo;
    } else {
        lista->tail = nuevo;
    }
    lista->head = nuevo;
    lista->size++;
}

void AddTail(ListaDoble *lista, void *dato) {
    NodoDoble *nuevo = (NodoDoble *)malloc(sizeof(NodoDoble));
    if (nuevo == NULL) {
        printf("Error: No se pudo asignar memoria para el nuevo nodo\n");
        return;
    }
    nuevo->data = dato;
    nuevo->next = NULL;
    nuevo->prev = lista->tail;
    if (lista->tail != NULL) {
        lista->tail->next = nuevo;
    } else {
        lista->head = nuevo;
    }
    lista->tail = nuevo;
    lista->size++;
}

NodoDoble *GetNodoPos(ListaDoble *lista, int pos) {
    NodoDoble *temp = lista->head;
    while (temp != NULL && pos > 0) {
        temp = temp->next;
        pos--;
    }
    return temp;
}



void ImprimirLista(ListaDoble *lista, void (*func)(void *)) {
    NodoDoble *actual = lista->head;
    while (actual != NULL) {
        func(actual->data);
        actual = actual->next;
    }
}

void LiberarLista(ListaDoble *lista) {
    NodoDoble *temp;
    while (lista->head != NULL) {
        temp = lista->head;
        lista->head = lista->head->next;
        free(temp->data);
        free(temp);
    }
    lista->tail = NULL;
    lista->size = 0;
}

NodoDoble *GetNodo(ListaDoble *lista, void *dato) {
    NodoDoble *temp = lista->head;
    while (temp != NULL) {
        if (temp->data == dato) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void BorrarNodo(ListaDoble *lista, void *dato) {
    NodoDoble *curr = GetNodo(lista, dato);
    if (curr == NULL) {
        printf("No se encontro el nodo\n");
        return;
    }

    if (curr->prev == NULL) {
        lista->head = curr->next;
    } else {
        curr->prev->next = curr->next;
    }

    if (curr->next == NULL) {
        lista->tail = curr->prev;
    } else {
        curr->next->prev = curr->prev;
    }

    free(curr);
    lista->size--;
}

int comparar(void *a, void *b) {
    int *int_a = (int *)a;
    int *int_b = (int *)b;
    return (*int_a - *int_b);
}

void imprimir_entero(void *dato) {
    int *valor = (int *)dato;
    printf("%d ", *valor);
}

void imprimir_char(void *dato) {
    char *valor = (char *)dato;
    printf("%c ", *valor);
}


void ingresarNodo(NodoBinario **raiz, NodoBinario *nuevo, int (*comparar)(void *, void *)) {
    if (*raiz == NULL) {
        *raiz = nuevo;
    } else {
        if (comparar(nuevo->dato, (*raiz)->dato) < 0) {
            ingresarNodo(&((*raiz)->izq), nuevo, comparar);
        } else {
            ingresarNodo(&((*raiz)->der), nuevo, comparar);
        }
    }
}


void ingresarElementoArbol(NodoBinario **raiz, void *dato, int (*comparar)(void *, void *)) {
    NodoBinario *nuevo = (NodoBinario *)malloc(sizeof(NodoBinario));
    if (nuevo == NULL) {
        fprintf(stderr, "Error: memoria insuficiente para crear un nuevo nodo.\n");
        exit(EXIT_FAILURE);
    }
    nuevo->dato = dato;
    nuevo->izq = NULL;
    nuevo->der = NULL;

    ingresarNodo(raiz, nuevo, comparar);
}

void imprimirPreOrden(NodoBinario *const raiz, void (*printf)(void*))
{
    if (raiz==NULL)
    return;

    printf(raiz->dato);
    imprimirPreOrden(raiz->izq,printf);
    imprimirPreOrden(raiz->der,printf);
}
void imprimirInOrden(NodoBinario *const raiz, void (*printf)(void*))
{
    if (raiz==NULL)
    return;

    imprimirInOrden(raiz->izq,printf);
    printf(raiz->dato);
    imprimirInOrden(raiz->der,printf);

}
void imprimirPostOrden(NodoBinario *const raiz, void (*printf)(void*))
{
    if (raiz==NULL)
    return;

    imprimirPostOrden(raiz->izq,printf);
    imprimirPostOrden(raiz->der,printf);
    printf(raiz->dato);

}

void liberarArbol(NodoBinario *raiz) {
    if (raiz == NULL)
        return;

    liberarArbol(raiz->izq);
    liberarArbol(raiz->der);
    free(raiz);
}
void imprimirNivelOrden(NodoBinario *const arbol, void (*print)(void *)) {
    if (arbol == NULL)
        return;

    Cola colaAuxiliar;
    IniciarListaDoble(&colaAuxiliar);
    pushcola(&colaAuxiliar, arbol);

    while (!estavaciacola(&colaAuxiliar)) {
        NodoBinario *nodo = (NodoBinario *)popcola(&colaAuxiliar);
        print(nodo->dato);

        if (nodo->izq != NULL)
            pushcola(&colaAuxiliar, nodo->izq);
        if (nodo->der != NULL)
            pushcola(&colaAuxiliar, nodo->der);
    }
}

NodoBinario **buscarNodo(NodoBinario **raiz, void *data, int (*comparar)(void *, void *)) {
    if (*raiz == NULL || comparar((*raiz)->dato, data) == 0) {
        return raiz;
    }

    if (comparar((*raiz)->dato, data) > 0) {
        return buscarNodo(&((*raiz)->izq), data, comparar);
    } else {
        return buscarNodo(&((*raiz)->der), data, comparar);
    }
}

NodoBinario **buscarMinimo(NodoBinario **raiz) {
    NodoBinario **actual = raiz;

    while ((*actual)->izq != NULL) {
        actual = &((*actual)->izq);
    }

    return actual;
}


int eliminarNodo(NodoBinario **raiz, void *data, int (*comparar)(void *, void *)) {
    NodoBinario **nborrar = buscarNodo(raiz, data, comparar);

    if (*nborrar == NULL) {
        return 0;
    }

    if ((*nborrar)->izq == NULL && (*nborrar)->der == NULL) {
        free(*nborrar);
        *nborrar = NULL;
        return 1;
    } else if ((*nborrar)->der == NULL) {
        NodoBinario *temporal = *nborrar;
        *nborrar = (*nborrar)->izq;
        free(temporal);
        temporal = NULL;
        return 1;
    } else if ((*nborrar)->izq == NULL) {
        NodoBinario *temporal = *nborrar;
        *nborrar = (*nborrar)->der;
        free(temporal);
        temporal = NULL;
        return 1;
    } else {
        NodoBinario **minimo = buscarMinimo(&((*nborrar)->der));
        (*nborrar)->dato = (*minimo)->dato;
        return eliminarNodo(&((*nborrar)->der), (*minimo)->dato, comparar);
    }
}
int Jerarquia(char op) {
    switch(op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}
char* InfixToPostfix(char* expression) {
    int length = strlen(expression);
    char* posfija = (char*)malloc(sizeof(char) * (length + 1)); // +1 para el carácter nulo
    char* pila = (char*)malloc(sizeof(char) * (length + 1)); // +1 para el carácter nulo
    int c = 0;
    int top = 0; // Variable para el tope de la pila

    for (int i = 0; i < length; i++) {
        char token = expression[i];
        if (token >= 'a' && token <= 'z') {
            posfija[c++] = token;
        } else if (token == '(') {
            pila[top++] = token;
        } else if (token == ')') {
            while (top > 0 && pila[top - 1] != '(') {
                posfija[c++] = pila[--top];
            }
            if (top > 0 && pila[top - 1] == '(') {
                top--; // Descarta el paréntesis izquierdo de la pila
            }
        } else { // Si es un operador
            while (top > 0 && Jerarquia(token) <= Jerarquia(pila[top - 1])) {
                posfija[c++] = pila[--top];
            }
            pila[top++] = token;
        }
    }

    while (top > 0) {
        posfija[c++] = pila[--top];
    }

    posfija[c] = '\0'; // Agrega el carácter nulo al final de la cadena
    free(pila); // Libera la memoria de la pila
    return posfija;
}
int EsOperando(char token) {
    return (token >= 'a' && token <= 'z');
}

// Definición de la función AgregarNodoExpr
void AgregarNodoExpr(NodoBinario** Arbol, char* postfix) {
    NodoBinario** pila = (NodoBinario**)malloc(sizeof(NodoBinario*) * strlen(postfix));
    int top = -1;

    for (int i = 0; i < strlen(postfix); i++) {
        char token = postfix[i];
        if (EsOperando(token)) {
            NodoBinario* nodo = (NodoBinario*)malloc(sizeof(NodoBinario));
            nodo->dato = (char*)malloc(sizeof(char)); // Reserva memoria para el operando
            *((char*)nodo->dato) = token; // Almacena el operando en el nodo
            nodo->izq = NULL;
            nodo->der = NULL;
            pila[++top] = nodo;
        } else {
            NodoBinario* nodo = (NodoBinario*)malloc(sizeof(NodoBinario));
            nodo->dato = (char*)malloc(sizeof(char)); // Reserva memoria para el operador
            *((char*)nodo->dato) = token; // Almacena el operador en el nodo
            nodo->der = pila[top--];
            nodo->izq = pila[top--];
            pila[++top] = nodo;
        }
    }

    *Arbol = pila[top]; // El árbol será la raíz de la expresión
}
int max(int a, int b) {
    return (a > b) ? a : b;
}

int alturaArbol(NodoBinario* raiz) {
    if (raiz == NULL) {
        return -1; // Por convención, un árbol vacío tiene altura -1
    } else {
        int alturaIzquierda = alturaArbol(raiz->izq);
        int alturaDerecha = alturaArbol(raiz->der);
        return 1 + max(alturaIzquierda, alturaDerecha);
    }
}

