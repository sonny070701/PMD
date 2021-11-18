//LAURA PATRICIA GARCIA REYES.
//SONNY DOMINIQUE CEJA CELIS.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Stack.h"
#include "Asincrona2.h"
#include "Queue.h"
#include "Types.h"

int main(){

  setbuf(stdout, NULL); 

  char arraexp[20]; //para la entrada del usuario
  char *exp;

  printf("\nexpresion con formato infix: ");
  scanf("%s", arraexp);

  initString(&exp,arraexp); //para no gastar memoria 

  char *arr=infixToPosfix(exp); //usamos la funcion
  printf("expresion con formato posfix: %s\n", arr);

  free(arr); //liberamos memoria
  free(exp);
}