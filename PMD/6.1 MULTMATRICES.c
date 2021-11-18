//Sonny ceja

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define F_A n
#define C_A n
#define F_B n
#define C_B n

int main(){

    setbuf(stdout, NULL);
    srand(time(NULL));

    int **mA, **mB, **mC;
    int x, y, z, n, R;

    R = rand() % 11;

    printf("De que tamaño? ");
    scanf("%d", &n);

	mA = malloc (n* sizeof(int *));
    mB = malloc (n* sizeof(int *));
    mC = malloc (n* sizeof(int *));

	for (x = 0; x < n; x++) {
		mA[x] = malloc (n* sizeof(int)); 
    }

	for (x = 0; x < n; x++) {
		mB[x] = malloc (n* sizeof(int)); 
    }

	for (x = 0; x < n; x++) {
		mC[x] = malloc (n* sizeof(int)); 
    }

    for (x = 0; x < F_A; x++) {
		for(y = 0; y < C_A; y++){
			mA[x][y] = n*x + n*y+1;
        }
    }

    for (x = F_B-1; x >= 0 ; x--){
	  for(y = C_B-1; y >= 0 ; y--){
		  mB[x][y] = n*-x-y + n*n;
        }
    }

    for (x = 0; x < C_B; x++){
		for(y = 0; y<F_A; y++){
        int suma=0;
        for (z = 0; z < C_A; z++){
        suma += mA[y][z] * mB[z][x];
			mC[y][x] = suma;
            }
        }
    }

	for (x = 0; x < n; x++){
		printf("\n");
		for (y = 0; y < n; y++)
			printf("%d\t",*(*(mA+x)+y));
	}

    printf("\n");
    for (x = 0; x < n; x++){
		printf("\n");
		for (y = 0; y < n; y++)
			printf("%d\t",*(*(mB+x)+y));
	}
  
    printf("\n");
	for (x = 0; x < n; x++){
		printf("\n");
		for (y = 0; y < n; y++)
			printf("%d\t",*(*(mC+x)+y));
	}
}