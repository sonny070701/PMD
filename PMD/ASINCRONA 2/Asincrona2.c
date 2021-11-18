#include "Queue.h"
#include "Stack.h"
#include "Types.h"
#include "Asincrona2.h"
#include <stdio.h> //cabecera inicial
#include <stdlib.h> // para malloc
#include <ctype.h> // Para la funcion alpha y digit
#include <string.h> //para la entrada

void initString(char **c,char *sourse) {
    
	int sizeString = strlen(sourse);
	*c = (char*)malloc(sizeString*sizeof(char)+1);
	strcpy(*c,sourse);
} // usa el espacio necesario en la expresion del usuario

int Operador(char op) {

  return (op == '*' || op == '/'|| op == '+' || op == '-');
} //evalua si hay operadores

int HighPrecedence(char eval, STACK pila){

  char top = (*(char *)stack_top(pila));

  if((eval == '*' || eval == '/') && (top == '*' || top == '/')){
    return 1;} //evalua si encuentra eso en el top

  if((eval == '+' || eval == '-') && (top == '*' || top == '/')){
    return 2;} //evalua si encuentra eso en el top

  if((eval == '+' || eval == '-') && (top == '+' || top == '-')){
    return 3;} //evalua si encuentra eso en el top
    
    return 0;
}

char *infixToPosfix(char *entrada) { 
    
  STACK Pila = stack_create(); // ordena digitos
  QUEUE Cola = queue_create(); // contenedor final
  QUEUE Almacen = queue_create(); // operandos, o productos

  char *result = malloc(15 * sizeof(char)); //para resultado
  char *ptrresult = result; 
  
  while(*entrada != '\0') { //recorriendo cada char 
    queue_offer(Almacen, entrada);//poner toda la entrada en una fila 
    entrada++;
  }

  while(!queue_isempty(Almacen)) { //
    char* digit = (char *)queue_poll(Almacen); //tomamos lo que hay adelante
    if(isdigit(*digit) || isalpha(*digit)) { //evalua si es numero o letra
      queue_offer(Cola, digit); //lo guardamos en la cola final
    }
    //si es parentesis que abre 
    if(*digit == '(') { 
      stack_push(Pila, digit); 
    }
    // si es operadores 
    if(Operador(* digit)){ 
      while(stack_isempty(Pila) == FALSE && *((char*)stack_top(Pila)) != '(' ) {
        if(HighPrecedence( *digit, Pila)){
          queue_offer(Cola, stack_pop(Pila)); //si cumple se mete en la cola final
        }else{
          break; 
        } 
      }
      stack_push(Pila, digit);
    }

    if(*digit == ')') {  //si encuentra )
      while(stack_isempty(Pila) == FALSE && *((char*)stack_top(Pila)) != '(' ){
        queue_offer(Cola, (char*)stack_pop(Pila));  //lo mete a la cola final
      }
      if(stack_isempty(Pila) == FALSE) {
        stack_pop(Pila);
      } 
    }
  }

  while(stack_isempty(Pila) == FALSE){ 
    queue_offer(Cola, (char*)stack_pop(Pila)); 
  }

  while(queue_isempty(Cola) == FALSE){ //para imprimir bonito 
    *ptrresult = *((char*)queue_poll(Cola)); 
    ptrresult ++; 
    *ptrresult = ' ';
    ptrresult ++;
  }

  *ptrresult = '\0';//SI ENCUENTRA FIN DE CADENA:
  stack_destroy(Pila);
  queue_destroy(Cola); //LIBERAMOS MEMORIA 
  queue_destroy(Almacen);

  return (result); //DEVOLVEMOS EL RESULTADO
}
