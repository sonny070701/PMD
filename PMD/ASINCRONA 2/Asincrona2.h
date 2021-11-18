#ifndef ASINCRONA2_H_
#define ASINCRONA2_H_

int Operador(char op); //Para buscar los operadores

char *infixToPosfix(char *entrada); //Funcion de infix a posfix

void initString(char **c,char *sourse); //Para usar el espacio necesario

int HighPrecedence(char eval, STACK pila); //evalua los operadores

#endif /* ASINCRONA2_H_ */