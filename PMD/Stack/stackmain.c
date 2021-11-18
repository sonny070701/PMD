#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

int main() {

	STACK operadores=stack_create();
	STACK operandos=stack_create();

	int i,  operando1, operando2, resultado;
	char c, operador;
	
	char exprentrada[40];
	
	printf("Dame una expresión aritmética :");
	scanf("%s",exprentrada);
	
	while(exprentrada[i]!='\0'){

		c=exprentrada[i]; //recorrer el arreglo		
		if(esoperador(c)) {

			// Si el stack de operadores no está vacío comprobar si la precedencia del operador que tengo en la variable c es menor a la precedencia del operador que está en el tope del stack
			if(stack_size(operadores)>0 &&
			   precedencia(char_val(stack_top(operadores))) >=
			   precedencia(c))

				op_stack(operadores,operandos); // Hacer el cálculo
			else {

				stack_push(operadores,char_create(c));
				i++;
				//printf("guarda en el stack %c\n",c);
			}
		}
		if(esoperando(c)) {
			stack_push(operandos,int_create(c-'0'));
			i++;
			//printf("\t\t\t\tGuarda en el stack %d\n",c-'0');
		}

	}
	

	while(!stack_isempty(operadores))
		op_stack(operadores,operandos);

	resultado = int_val(stack_pop(operandos));
	//printf("\t\t\t\tSaca del stack: %d\n",resultado);
	
	printf("Resultado %d\n",resultado);
}
