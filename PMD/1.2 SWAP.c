//SONNY CEJA

#include <stdio.h>

void swap( int *a, int *b) 
{  
  int SW = *a;
  *a = *b;
  *b = SW;  
  }

int main() 
{
  int a = 35;
  int b = 40;

  swap (&a, &b);

  printf("a=%d\n",a);
  printf("b=%d\n",b);

}