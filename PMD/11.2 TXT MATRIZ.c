#include <stdio.h>
#include<stdlib.h>
#include <string.h>

#define SIZE 3
int main()
{
    int matC[SIZE][SIZE];

    FILE* fc = fopen("c.txt","r");

    int num;

   if (fc==NULL){
        fprintf(stderr,"Error al abrir el archivo\n");
        exit(1);
    }
     for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            fscanf(fc,"%d",&num);
            if(j == SIZE-1)
                printf("%d",num);
            else
                printf("%d,",num);
        }
        printf("\n");
    }

    fclose(fc);

}
