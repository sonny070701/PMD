///Sonny Ceja Celis

#include <stdio.h>

#define ROWS 4
#define COLS 4
#define SIZE 4

void multmat(void *m1,void *m2,void *m3,int size);
void printmat(void *m,int rows,int cols);

int main()
{
	int mat1[ROWS][COLS] = {{0,1,2,4},
							{5,6,7,8},
							{9,10,11,12},
							{13,14,15,16}};
					
	int mat2[ROWS][COLS] = {{17,18,19,20},
							{21,22,23,24},
							{25,26,27,28},
							{29,30,31,32}};
					
	int mat3[ROWS][COLS] = {{0,0,0,0},
							{0,0,0,0},
							{0,0,0,0},
							{0,0,0,0}};;
	
	multmat(mat1,mat2,mat3,SIZE);
	
	printmat(mat3,ROWS,COLS);
}

void multmat(void *m1,void *m2,void *m3,int size) {
    
    int* a = (int *)m1;// aplicamos cast en todos los void
    int* b = (int *)m2;
    int* c = (int*)m3;
    for(int i = 0; i<16; i++) { //en lugar de hacer por ROW Y COLS lo hacemos para su tamaño total 4*4

        (*(c+i)) = (*(a+i)) * (*(b+i)); //usamos apuntadores para no usar [][]

    }
}

void printmat(void *m,int rows,int cols) {

    int i;
    int* mat = (int *)m;
    for(i = 0;  i<16; i++) {
        printf("%d\n ", (*((mat)+i)));
    }
}