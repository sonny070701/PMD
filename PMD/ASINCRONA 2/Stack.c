#include <stdlib.h> 
#include "Stack.h"

STACK stack_create() {

	STACK tmp=malloc(sizeof(struct STRSTACK));
	tmp->top = NULL;
	tmp->size = 0;
	return tmp;
}

void stack_push(STACK s,TYPE e) {

	NODES new = malloc(sizeof(struct STRNODES));
	new->data = e;
	new->prior = s->top;
	s->top = new;
	s->size++;
}

TYPE stack_pop(STACK s) {

	NODES node=s->top;
	TYPE retval=NULL;;

	if(node!=NULL) {
		retval=node->data;
		s->top=node->prior;
		free(node);
		s->size--;
	}
	return retval;
}

TYPE stack_top(STACK stack) {

	return(stack->top->data);
}

void stack_destroy(STACK stack) {

	while(!stack_isempty(stack)) {

		stack_pop(stack);
	}
	free(stack);
}

BOOL stack_isempty(STACK stack) {

	return(stack->top==NULL);
}

int stack_size(STACK stack) {

	return(stack->size);
}