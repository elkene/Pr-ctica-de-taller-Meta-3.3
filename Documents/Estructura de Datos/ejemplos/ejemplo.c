#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
int n = 5;
int *p_n;

p_n = &n;
printf("Numero: %i", *p_n);
printf("\n");
printf("Direccion: %p", p_n);



char nombre[20], *p_nombre;
int longitud;
printf("\n");

strcpy(nombre,"Alejandro");
longitud = strlen(nombre);
p_nombre = malloc((longitud+1)*sizeof(char));
strcpy(p_nombre,nombre);
printf("\n");

printf("Nombre: %s",p_nombre);



return 0;



}

