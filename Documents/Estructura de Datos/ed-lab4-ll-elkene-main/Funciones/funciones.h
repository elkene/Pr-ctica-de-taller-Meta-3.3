#include <stdio.h>
#include "../Estructuras/listas.H"
#include "../Estructuras/nodos.h"

void IniciarListaDoblePalabras(ListaDoblePalabras *lista);
void AddTail(ListaDoblePalabras *lista, Palabra *dato);

void ImprimirListaPalabras(ListaDoblePalabras lista, void (*func)(Palabra *), int *palabrasSinRepetir);

void LiberarListaPalabras(ListaDoblePalabras *lista);

void ImprimirPalabra(Palabra *palabra);
void ContarPalabras(FILE *archivo, ListaDoblePalabras *lista);