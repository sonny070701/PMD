#ifndef STACK_H_
#define STACK_H_

#include <string.h>

typedef void* TYPE;
typedef enum{FALSE,TRUE} BOOL;
typedef char * STRING;
typedef int * INT;
typedef char * CHAR;
typedef double * DOUBLE;
typedef float * FLOAT;
typedef struct STRDATE * DATE;

#define string_val(d) 		((char *) d)
#define int_val(d)			(*((int *) d))
#define char_val(d)			(*((char *) d))
#define double_val(d)		(*((double *) d))
#define float_val(d)		(*((float *) d))
#define date_year_val(d) 	(((DATE) d)->year)
#define date_month_val(d) 	(((DATE) d)->month)
#define date_day_val(d) 	(((DATE) d)->day)

struct STRNODE {
	TYPE data;
	struct STRNODE *prior;
};

typedef struct STRNODE* NODE;

struct STRSTACK {
	NODE top;
	int size;
};

typedef struct STRSTACK* STACK;

STACK stack_create();
void stack_push(STACK s,TYPE e);
TYPE stack_pop(STACK s);
TYPE stack_top(STACK stack);
void stack_destroy(STACK stack);
BOOL stack_isempty(STACK stack);
int stack_size(STACK stack);
BOOL esoperador(char c);
BOOL esoperando(char c);
int precedencia(char c);
void op_stack(STACK operadores,STACK operandos);
int operacion(int op1,int op2,char operador);

struct STRDATE {
	int year,month,day;
};

STRING string_create(STRING str);
INT int_create(int num);
CHAR char_create(char chr);
DOUBLE double_create(double dbl);
FLOAT float_create(float flt);
DATE date_create(int year,int month,int day);


#endif /* STACK_H_ */