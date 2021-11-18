#ifndef STACK_H_
#define STACK_H_

typedef void* TYPE;

struct STRNODE {
	TYPE data;
	struct STRNODE* next;
};

typedef struct STRNODE* NODE;

struct STRQUEUE {
	 NODE* almacen;
	 NODE* invertida;
};

typedef struct STRQUEUE* QUEUE;

void  ESPqueue_offer(NODE*,TYPE);
TYPE ESPqueue_poll(NODE*);
void almacen_a_pilainvertida(QUEUE, TYPE);
TYPE Imprimir_pilainvertida(QUEUE);

#endif /* STACK_H_ */

