#include <stdio.h>

#define SIZE 10

int suma(int a,int b) {
  return (a+b); }

int resta(int a,int b) {
  return(a-b); }

int mult(int a,int b) {
  return(a*b); }

void printvec(int *v,int n) {
  int i;
  for(i=0; i<n; i++){
    printf("%d\t",*v);
    v++;
  }
  printf("\n");
}

char opvec(int* vectores[], int size, int (*func)(int,int)){

  for (int i = 0; i < size; i++){
     *(*(vectores+2)+i) = func(*(*(vectores)+i), (**(vectores+1)+i));
  }
  return 0;
}

int main() {
  int i;
  int v1[SIZE]={9,8,7,6,5,4,3,2,1,0};
  int v2[SIZE]={0,1,2,3,4,5,6,7,8,9};
  int v3[SIZE];

  int *vectores[3]={v1,v2,v3};

  opvec(vectores,SIZE,suma);
  printf("La suma de los vectores a y b =");
  printvec(v3,SIZE);

  opvec(vectores,SIZE,resta);
  printf("La resta de los vectores a y b =");
  printvec(v3,SIZE);

    opvec(vectores,SIZE,mult);
    printf("La multiplicación de los vectores a y b =");
    printvec(v3,SIZE);
}