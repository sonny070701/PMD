//Sonny ceja

#include <stdio.h>
#include <stdlib.h>

int main(){

    int i;
    int* ptr;

    ptr = malloc(64*sizeof(int));

    for(i=0;i<10;i++) {
		
		*ptr = i; 
        ptr[10] = 5000;	
	}
    printf("%p , %d", &ptr[10], ptr[10]);

    free(ptr);
}
/*¿Cuál es la razón de cambio entre cada dirección impresa?

como se asigno un espacio de almacenamiento al sistema,
la razon de cambio depende de malloc ya que se le asigna 
memoria dinamica y es cambiante.

Si le pido que muestre la dirección de memoria apuntada por ptr ¿Qué imprime el programa?

Muestra la direccion del puntero, lo interesante es que si lo ejecutas muchas veces la direccion cambia por ser dinamica

*/