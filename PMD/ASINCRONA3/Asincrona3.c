#include "Asincrona3.h"
#include "Set.h"
#include <stdio.h>
#include <stdlib.h>

void strclean(unsigned char *s) { //funcion para transformar los tokens
		
	while(*s) {

		if(*s=='.' || *s==',' || *s=='!' || *s=='?' || *s==')' || *s==':'|| *s=='"' || *s== '"')
			*s= '\0';

		if(*s>=192 && *s<=197) *s='A';
		if(*s>=224 && *s<=229) *s='a';
		if(*s>=200 && *s<=203) *s='E';
		if(*s>=232 && *s<=235) *s='e';
		if(*s>=204 && *s<=207) *s='I';
		if(*s>=236 && *s<=239) *s='i';
		if(*s>=210 && *s<=214) *s='O';
		if(*s>=242 && *s<=246) *s='o';
		if(*s>=217 && *s<=220) *s='U';
		if(*s>=249 && *s<=252) *s='u';
		
		if(*s>='A' && *s<='Z') //para volver minusculas
			*s+=32;	
		s++; //se recorre s
	}
}	

void repetidas(FILE* f){ //tomamos como argumento un archivo

    SET frases = set_create(string_compare, char_print); //SET

	unsigned char *w; //para pasar los datos al set

    if(f == NULL) {
		  fprintf(stderr,"Error al abrir archivo\n");
		  exit(1); //solo si hay error al abrirlo
	}

    while(!feof(f)) { //si no hay end of file 
        
        w = malloc(sizeof(char)); //malloc para los datos

        fscanf(f, "%s", w); //leemos el archivo y ponemos los datos en w
        strclean(w); //aplicamos la evaluacion de tokens a w
        set_add(&frases, w); //agregamos eso al conjunto 

    }

    printf ("Palabras en total y sin repetir: %d\n", set_size(frases));
    set_print(frases); //imprimit el conjunto como lista
}