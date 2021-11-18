#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "QueueEsp.h"

int main() {

    setbuf(stdout, NULL); 
    int c, n;

    QUEUE cola = malloc(sizeof(struct STRQUEUE));

    cola->almacen = NULL;
    cola->invertida = NULL;

    almacen_a_pilainvertida(cola, (int *)1);
    almacen_a_pilainvertida(cola, (int *)2);
    almacen_a_pilainvertida(cola, (int *)3);

    printf("%d\n", (int )Imprimir_pilainvertida(cola));
    printf("%d\n", (int )Imprimir_pilainvertida(cola));
    printf("%d\n", (int) Imprimir_pilainvertida(cola));
    
}