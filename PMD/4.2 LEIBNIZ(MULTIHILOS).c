//Sonny Ceja
//Jessica Donley

#include <stdio.h>
#include <windows.h>
#include <time.h>

#define NTHREADS 10
#define ciclos 1000000000

double Leibniz() {
  double pi = 0, divisor = 1;
  int operador = 1;
  int numerador = 4;
  for (int x=0; x<ciclos; x++){
    pi += operador*(numerador/divisor);
    divisor = divisor+ 2;
    operador = operador* -1;
  }

  return pi;
}

DWORD WINAPI tfunc(LPVOID args) {

	int tnum=*((int *) args);
	int inicio=(ciclos/NTHREADS)*tnum;
	int fin=(ciclos/NTHREADS)*(tnum+1);
	printf("Hilo %d, inicio=%d, fin=%d\n",tnum,inicio,fin);

	return 0;
}

int main() {

	int i;
	HANDLE tid[NTHREADS];
	int args[NTHREADS];
	clock_t inicio,fin;
	float tiempo;
	double pi = Leibniz(ciclos);

	inicio=clock();

	for(i=0;i<NTHREADS;i++)
	{
		args[i]=i;
		tid[i]=CreateThread(NULL,0,tfunc,(LPVOID) &args[i],0,NULL);
		printf("PI = %.10f\n",pi);
	}

	WaitForMultipleObjects(NTHREADS,tid,TRUE,INFINITE);

	fin=clock();

	tiempo = ((float) fin - (float) inicio)/1000;

	printf("Tiempo = %3.2f segundos\n",tiempo);
}