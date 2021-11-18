#include <stdio.h>
#include <stdlib.h>

#define N 3

void multiply(int mat_a[N][N], int mat_b[N][N], int mat_c[N][N]);


int main(void) {

  int mat_a[3][3],mat_b[3][3],mat_c[3][3];

  FILE *f;
  f = fopen("entrada.bin", "rb");

  if(f==NULL){
		fprintf(stderr,"Error al crear el archivo");
		exit(1);
	}

  fclose(f);

  multiply(mat_a, mat_b, mat_c);

  f = fopen("salida.bin", "wb+");

  if(f==NULL){
		fprintf(stderr,"Error al crear el archivo");
		exit(1);
	}

  fwrite(mat_c, sizeof(int), 9, f);


  fclose(f);

  return 0;
}

void multiply(int mat_a[][N], int mat_b[][N], int mat_c[][N])
{
    int i, j, k;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            mat_c[i][j] = 0;
            for (k = 0; k < N; k++)
                mat_c[i][j] += mat_a[i][k] * mat_b[k][j];
        }
    }
}