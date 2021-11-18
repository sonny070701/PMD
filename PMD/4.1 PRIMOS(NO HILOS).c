//Sonny Ceja 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void numPrimos(int *  NI, int *NF) {
  int i, div, primo, total = 0;
  i = *NI;
  for (i = *NI; i <= *NF; i++){ 
    primo = 0;
    for (div = 2; div < i-1 && primo == 0; div++){
      if (i % div == 0) 
      primo = 1;
    }
    if(primo == 0){
      printf("%d ,", i);
      total++;
    }
  }
  printf("primos: %d ,", total);
}

int main(){
  setbuf(stdout, NULL);
	
	clock_t inicio, fin;
  inicio = clock();

	double time;

	int NFinal, NInit;
	printf("escriba el numero inical: ");
  scanf("%d", &NInit);
  printf("escriba el numero final: ");
  scanf("%d", &NFinal);

  numPrimos(&NInit, &NFinal);

  fin = clock();
  time = (double)(fin - inicio) / CLOCKS_PER_SEC;
  printf("Tiempo: %fs", time);
  
  return 0;

}