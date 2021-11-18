#include <stdlib.h> // Por las llamadas a malloc
#include <stdio.h>
#include "stack.h"

STACK stack_create() {

	STACK tmp=malloc(sizeof(struct STRSTACK));
	tmp->top = NULL;
	tmp->size = 0;
	return tmp;
}

void stack_push(STACK s,TYPE e) {

	NODE new = malloc(sizeof(struct STRNODE));
	new->data = e;
	new->prior = s->top;
	s->top = new;
	s->size++;
}

TYPE stack_pop(STACK s) {

	NODE node=s->top;
	TYPE retval=NULL;;

	if(node!=NULL){ // Si el stack no está vacio

		retval=node->data;
		s->top=node->prior;	// Ahora el tope del stack se mueve
						// al elemento previo
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

STRING string_create(STRING str) {

	STRING s=malloc(strlen(str));
	strcpy(s,str);
	return s;
}

INT int_create(int num) {

	INT n=malloc(sizeof(int));
	*n=num;
	return n;
}

CHAR char_create(char chr) {

	CHAR c=malloc(sizeof(char));
	*c=chr;
	return c;
}

DOUBLE double_create(double dbl)
{
	DOUBLE d=malloc(sizeof(double));
	*d=dbl;
	return d;
}

FLOAT float_create(float flt){

	FLOAT f=malloc(sizeof(float));
	*f=flt;
	return f;
}

DATE date_create(int year,int month,int day) {

	DATE d=malloc(sizeof(struct STRDATE));
	d->year=year;
	d->month=month;
	d->day=day;
	return(d);
}

BOOL esoperador(char c) {

	BOOL res=FALSE;
	if(c=='+' || c=='-' || c=='*' || c=='/' || c=='(' || c==')')
		res=TRUE;
	return(res);
}

BOOL esoperando(char c) {

	BOOL res=FALSE;
	if(c>='0' && c<='9')
		res=TRUE;
	return(res);
}

int precedencia(char c) {
    
	int ret=0;
	if(c=='(' || c==')')
		ret=1;
	if(c=='+' || c=='-')
		ret=2;
	if(c=='*' || c=='/')
		ret=3;
		
	return(ret);
}

void op_stack(STACK operadores,STACK operandos) {

	int operando1,operando2, resultado;
	char operador;

	operando2=int_val(stack_pop(operandos));
	//printf("\t\t\t\tSaca del stack: %d\n",operando2);
	operando1=int_val(stack_pop(operandos));
	//printf("\t\t\t\tSaca del stack: %d\n",operando1);
	
	// Sacar el operador del stack
	operador=char_val(stack_pop(operadores));
	//printf("Saca del stack: %c\n",operador);

	resultado=operacion(operando1,operando2,operador);
				
	stack_push(operandos,int_create(resultado));
	//printf("\t\t\t\tGuarda en el stack %d\n",resultado);
	
}


int operacion(int op1,int op2,char operador) {

	int resultado;
	switch(operador) {

		case '+':
			resultado=op1+op2;
			break;

		case '-':
			resultado=op1-op2;
			break;
            
		case '*':
			resultado=op1*op2;
			break;

		case '/':
			resultado=op1/op2;
			break;										
	}
	printf("Realiza operación %d %c %d\n",op1,operador,op2);
	return(resultado);
}

