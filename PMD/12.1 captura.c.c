//Sonny Ceja 

#include <stdio.h>
#include <stdlib.h>

int main(){

	setbuf(stdout, NULL);

	FILE* f;
	
	char i, j, respuesta;
	
	printf("que matriz quieres escribir primero? (a || b)");
	scanf("%c", &respuesta);

	int matA[3][3];
	int matB[3][3];

	f = fopen("entrada.txt", "w");

	if (f == NULL){
		fprintf(stderr,"Error al escribir archivo\n");
		exit(1);
	}

	if (respuesta == 'a'){

		fseek(f, 0, SEEK_SET);
		
		printf("Introduce los numeros de la matriz A:\n");
		for (i = 1; i <= 3; i++){
			for (j = 1; j <= 3; j++) {
				scanf("%d", &matA[i - 1][j - 1]);
        	}
        }
		
		fseek(f, 9, SEEK_SET);
		
		printf("Introduce los numeros de la matriz B:\n");
		for (i = 1; i <= 3; i++){
			for (j = 1; j <= 3; j++) {
				scanf("%d", &matB[i - 1][j - 1]);
			}
		}
	}

	if (respuesta == 'b'){

		fseek(f, 9, SEEK_CUR);
		
		printf("Introduce los numeros de la matriz B:\n");
		for (i = 1; i <= 3; i++){
			for (j = 1; j <= 3; j++) {
				scanf("%d", &matB[i - 1][j - 1]);
			}
		}

		fseek(f, 0, SEEK_SET);
		
		printf("Introduce los numeros de la matriz A:\n");
		for (i = 1; i <= 3; i++){
			for (j = 1; j <= 3; j++) {
				scanf("%d", &matA[i - 1][j - 1]);
			    }
			}
		}

    printf("\nMatriz A.\n");
    
    for (i = 1; i <= 3; i++) {
        for (j = 1; j <= 3; j++){
        	
            printf("%2d, ", matA[i-1][j-1]);
            
            if (matA[i-1][j-1]!=0) {
            	fprintf(f,"%d\n", matA[i-1][j-1]);
            }
        }
        printf("\n");
    }

    printf("\nMatriz B.\n");
    
    for (i = 1; i <= 3; i++) {
        for (j = 1; j <= 3; j++){
        	
            printf("%2d, ", matB[i - 1][j - 1]);
            
        	if (matB[i-1][j-1]!=0) {
        		
        		fprintf(f,"%d\n", matB[i - 1][j - 1]);
        	}
        }
        printf("\n");
    }

    return 0;
}
