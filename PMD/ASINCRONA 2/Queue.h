#include <stdlib.h>
#include "Types.h"

#ifndef QUEUE_H_
#define QUEUE_H_

struct STRNODE { //Para apuntar a los Nodos
	TYPE data;
	struct STRNODE *next;
};

typedef struct STRNODE * NODE;

struct STRQUEUE { //Para almacenar la cola
	NODE first,last;
	int size;
};

typedef struct STRQUEUE * QUEUE;

QUEUE queue_create(); //Crear la cola

void queue_offer(QUEUE queue,TYPE data); //Almacenar datos dentro de la cola

TYPE queue_poll(QUEUE queue); //Quitar datos de adelante

int queue_size(QUEUE queue); // Devuelve el tamaño

BOOL queue_isempty(QUEUE queue); //R/F si esta vacia 

TYPE queue_peek(QUEUE queue); //Devuelve sin quitar el dato de adelante

void queue_destroy(QUEUE queue); //Destruye la cola

#endif /* QUEUE_H_ */