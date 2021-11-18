//LAURA PATRICIA GARCIA REYES
//SONNY DOMINIQUE CEJA CELIS 

#include <stdio.h>
#include <stdlib.h>
#include "Set.h"
#include "Asincrona3.h"

int main()  {

	system("chcp 1252");
	system("cls");

	FILE *archivo = fopen("texto.txt","r"); //abrir archivo
	
	if(archivo == NULL) {
		fprintf(stderr, "Error al abrir archivo\n");
		exit(1); //en caso de no poder abrirse
	}
	
	while (!feof(archivo)) {
        	repetidas(archivo); //llamado a la funcion repetidas
	}
	fclose(archivo);

    system("pause");
}
