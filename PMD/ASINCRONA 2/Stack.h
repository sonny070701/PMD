#ifndef STACK_H_
#define STACK_H_

#include "Types.h"

struct STRNODES { //Para apuntar cada nodo
	TYPE data;
	struct STRNODES *prior;
};

typedef struct STRNODES* NODES; 

struct STRSTACK { //Para almacenar la pila
	NODES top;
	int size;
};

typedef struct STRSTACK* STACK;

STACK stack_create(); //Crear pila

void stack_push(STACK s,TYPE e); //meter datos a la pila

TYPE stack_pop(STACK s); //Sacar de la pila

TYPE stack_top(STACK stack); //Ver el tope sin quitarlo

void stack_destroy(STACK stack); //Destruir la pila

BOOL stack_isempty(STACK stack); //T/F si tiene datos

int stack_size(STACK stack); //Devuelve el tamaño

#endif /* STACK_H_ */