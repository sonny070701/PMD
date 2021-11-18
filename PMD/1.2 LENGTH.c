//sonny ceja

#include <stdio.h>

int length (char *texto) 
{
  int i = 0;
  while (*(texto+i)!='\0') {
    i++;
  }
  return i;
}

int main() {

  int size = length ("Hola mundo");
  printf("%d\n", size);

  return 0;
}