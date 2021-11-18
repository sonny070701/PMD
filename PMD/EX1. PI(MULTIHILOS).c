//Sonny Ceja Celis

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <windows.h>

/* Este programa calcula PI utilizando integraciÃ³n numÃ©rica con
 * la regla del trapecio la es un mÃ©todo de integraciÃ³n, es decir,
 * un mÃ©todo para calcular aproximadamente el valor de una integral
 * definida. La regla se basa en aproximar el valor de la integral
 * de la funciÃ³n, que pasa a travÃ©s de los puntos desde 0 hasta 1
 */

#define ITER 1000000000
#define NTHREADS 8 //los hilos se dividen tareas, si coloca con un solo hilo vera

double f(long double x) {
	return(sqrt(1.0-x*x));
}

DWORD WINAPI tfunc (LPVOID args){

	double base=1.0/ITER; //formula 
	double height,x,sum=0.0; //formula
	int tnum=*((int *) args); //numero de hilo
	int tam =(ITER/NTHREADS); //Iteraciones

	int tinicio = tnum*tam; //Numero de hilo por sus tareas
	int tfin = tinicio+tam; //Rango de inicio a fin (tareas)
	int i;

	for(i=tinicio ;i<tfin; i++) { //se dividio el rango por hilos, para que cada hilo sea 
		x=(i+0.5)/ITER;  //responsable de una seccion 
		height=f(x);
		sum=sum+base*height;
		}
	printf("Hilo = %1.16f\n",4*sum); //se imprimira el valor de pi fragmentado por el numero
	return 0; //de hilos, si gusta probarlo con 1 hilo se notara, igual con 1 solo es mas rapido ya, al sumarlo notara que da 3.1415....
}

int main() {

	int i;
	clock_t inicio,fin;
	float tiempo;
	int args[NTHREADS];
	HANDLE tid[NTHREADS];

	inicio=clock();
	for(i=0;i<NTHREADS;i++){
		args[i]=i;
		tid[i]=CreateThread(NULL,0,tfunc,(LPVOID) &args[i],0,NULL);
	}
	WaitForMultipleObjects(NTHREADS,tid,TRUE,INFINITE);
	fin=clock();
	tiempo=(fin-inicio)/1000.0;
	printf("Tiempo %.2f segundos\n",tiempo);

}