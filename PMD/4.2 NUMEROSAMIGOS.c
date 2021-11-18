//Sonny Ceja 
//Jessica Donley

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int numAmigos (int* x) {
  int sum = 1;
  for (int i = 2;  i < (*x/2)+1;  i++) {
    if (*x % i == 0) {
      sum += i;
    }
  }
  return sum;
}

int main() {
  setbuf(stdout, NULL);

  double time;
  clock_t start, end;

  int max, min, n2, n1;
  printf("inicio del rango: ");
  scanf("%d",&min);
  printf("final deñ rango: ");
  scanf("%d",&max);

  start = clock();

  for (n1 = min;  n1 <= max;  n1++) {
    n2 = numAmigos(&n1);
    if (n2 > n1 && n1 == numAmigos(&n2)) {

    printf("%d  es amigo de %d \n", n1, n2);
    printf("%d  es amigo de %d \n", n2, n1);

    end = clock();
  
    }
  }
  time = (double) (start - end)/ CLOCKS_PER_SEC;
  printf("sec = %fs", time);

  return 0;
}





