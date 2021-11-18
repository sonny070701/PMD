#include <stdio.h>
#include <stdlib.h>

#define F_B 3
#define C_B 3
#define F_A 3
#define C_A 3

#define LEN 10


int main() {

	FILE *fa, *fb, *fc;

    int matrizA[F_A][C_A] = {
            {1, 2, 3}, {4, 5, 6}, {7, 8, 9},
    };

    int matrizB[F_B][C_B] = {
            {9, 8, 7}, {6, 5, 4}, {3, 2, 1},
    };

    int matrizC[F_B][C_B];

    fa = fopen("a.txt","w");
    if(fa == NULL) {
    fprintf(stderr,"Error al abrir archivo de texto\n");
    	exit(1);
    }

    fb = fopen("b.txt","w");
    if(fb == NULL) {
    	fprintf(stderr,"Error al abrir archivo de texto\n");
    	exit(2);
    }

    fc = fopen("c.txt","w");
    if(fc == NULL) {
        fprintf(stderr,"Error al abrir archivo de texto\n");
        exit(3);
    }

    for (int i = 0; i < F_A; ++i) {
    		for( int j = 0; j < C_A; ++j ) {

            if (matrizA[i][j]!=0) {
            fprintf(fa,"%d\n",matrizA[i][j]);
            }
    	}
    }

    for (int i = 0; i < F_B; ++i) {
    	for( int j = 0; j < C_B; ++j ) {

    	if (matrizB[i][j]!=0) {
    	fprintf(fb,"%d\n", matrizB[i][j]);
    	    }
    	}
    }

    for (int x = 0; x < C_B; x++) {
        for (int i = 0; i < F_A; i++) {
        int suma = 0;
        for (int j = 0; j < C_A; j++) {
        	suma += matrizA[i][j] * matrizB[j][x];
        	}
            matrizC[i][x] = suma;
        }
    }

    for (int i = 0; i < F_B; ++i) {
        for( int j = 0; j < C_B; ++j ) {

        if (matrizC[i][j]!=0) {
        	fprintf(fc,"%d\n", matrizC[i][j]);
            }
       	}
   }

    fclose(fa);
    fclose(fb);
    fclose(fc);

    return 0;
}
