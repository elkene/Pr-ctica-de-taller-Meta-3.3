#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones/funciones.h"
int main(void){
/*Porque elegiste la lista enlazada que utilizaste?
R=Utilice listas simples ya que solo iba hacer una tarea muy sencilla de 
buscar palabras y almacenarlas, no iba almacenar una gran cantidad de datos pesados y 
se manejo con mas facilidad.
Cuantas palabras hay sin repetir?
R=148
Cual es la palabra que mas se repitió ?
R=de
Cual es la primera palabra que se repitió 10 veces?
R=Tijuana
Cual es la primera palabra que se repitió 8 veces?
R=ciudad
*/

ListaDoblePalabras listaPalabras;
IniciarListaDoblePalabras(&listaPalabras);
FILE *archivo=fopen("datos/texto.txt","r");
if(archivo==NULL){

fprintf(stderr, "Error\n");
return 1;
}
int palabrasSinRepetir = 0;
ContarPalabras(archivo, &listaPalabras);
ImprimirListaPalabras(listaPalabras, ImprimirPalabra, &palabrasSinRepetir); 
printf("Cantidad de palabras sin repetir: %d\n", palabrasSinRepetir); 
fclose(archivo);
LiberarListaPalabras(&listaPalabras);
return 0;
}