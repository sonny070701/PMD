//Sonny Ceja

#include <stdio.h>
#include <stdlib.h>
 
int main(){

    setbuf(stdout, NULL);

    int N;
    printf("numero:");
    scanf("%d", &N);

    int* arr = malloc(N* sizeof(int));
    double suma = 0;
    float prom;



    for (int x = 1; x < N+1; x++){
        suma = suma + (*arr+x);
        prom = suma / N;
    }

    printf("El promedio es: %.2f\n", prom);
    printf("cantidad de memoria usada: %d\n", N*4);
    printf("direccion de memoria: %p\n", arr);

    free(arr);
}
}