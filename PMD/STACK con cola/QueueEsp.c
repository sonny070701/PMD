#include <stdlib.h> // Por las llamadas a malloc
#include <stdio.h>
#include <string.h>
#include "QueueEsp.h"

void almacen_a_pilainvertida(QUEUE cola, TYPE d){
	ESPqueue_offer(&cola->almacen, d);
}

TYPE Imprimir_pilainvertida(QUEUE cola){
	TYPE result;
	if (cola->invertida == NULL){
		while(cola->almacen != NULL){
			result = ESPqueue_poll(&cola->almacen);
			ESPqueue_offer(&cola->invertida, (int *)result);
		}
	}
	result = ESPqueue_poll(&cola->invertida);
	return result;
}

void  ESPqueue_offer(NODE *n,TYPE d){
	NODE node = malloc(sizeof(struct STRNODE));
	node->data = d;
	node->next=(*n);
	(*n)=node;
}

TYPE ESPqueue_poll(NODE * n){
	NODE top = malloc(sizeof(struct STRNODE));
	TYPE result;
		top = *n;
		result = top->data;
		*n = top->next;
		free(top);
		return result;
}
