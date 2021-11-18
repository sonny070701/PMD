//Sonny Ceja Celis

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  int **matriz;

  setbuf(stdout, NULL);
  srand(time(NULL));
  
  int R = rand () % 21;
  printf("numero: %d\n", R);

  matriz = malloc(R * sizeof(int *));

  for(int x = 0; x < R; x++){
		matriz[x] = malloc( R* sizeof(int *));
	}

  for(int x = 0 ; x < R; x++) {
    printf("\n[");
    for (int y = 0; y <= x; y++){
      *matriz[x] = x+1;
      printf("%d,", *matriz[x]);
    }
    printf("]");
  }
}