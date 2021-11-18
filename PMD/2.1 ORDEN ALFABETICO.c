//Sonny Ceja

#include <stdio.h>
#include <string.h> 

void sortnames (char names[][10], int l) {
  
  char temp[10];
  int i, First;

  for (i = 0; i < l; i++) {
    for (First = 0; First < l - 1; First++) {
      int Next = First + 1;

      if (strcmp(*(names+First), *(names+Next)) > 0) {
        memcpy(temp, *(names+First), 10);
        memcpy(*(names+First), *(names+Next), 10);
        memcpy(*(names+Next), temp, 10);}}}}

int main() {
  char Nombre[][10] =  { "Juán","zoe","José","Gaby","María","Karla","Luis","Antonio","Cecilia","Roberto","Francisdo" };
    
  int longitud = sizeof(Nombre) / sizeof( Nombre[0]);

  int i;
  sortnames(Nombre, longitud);
  
  for (i = 0; i < longitud; i++) {
    printf("%s\n", *(Nombre+i));
  }
}

//este problema resulto un poco dificil, tuve que hacer uso de internet 
//utilizando el algoritmo de ordenamiento burbuja y apoyandome con un video de youtube