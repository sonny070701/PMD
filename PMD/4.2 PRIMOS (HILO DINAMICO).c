//Sonny Ceja
//Jessica Donley

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <windows.h>

#define NTHREADS 4
#define TASKSIZE 1000

int inicio,fin;
int cont=0;
int next_task=0;

CRITICAL_SECTION cs,tcs;

int esprimo(int n){
	int primo;
	int factor=3;
	int limite=sqrt(n)+1;

	if(n<2)
		primo=0;
	else if(n==2)
		primo=1;
	else if(n%2==0)	
		primo=0;
	else{
		while(n%factor && factor<limite)
			factor+=2;

		primo=factor>=limite;
	}
	return(primo);
}

DWORD WINAPI tfunc(LPVOID args) {
	int tnum=*((int *) args);	
	int tam=(NTHREADS-1)+fin-inicio;
	int tottasks=1+(tam/TASKSIZE);

	int tinicio;
	int tfin;
	int lcont=0;

	int i,t;
	
	while(next_task<tottasks) {

		EnterCriticalSection(&tcs);
		t=next_task;	
		next_task++;	
		LeaveCriticalSection(&tcs);

		tinicio=t*TASKSIZE+inicio;
		tfin=(t+1)*TASKSIZE+inicio;
		if(tfin>fin)
			tfin=fin;
		for(i=tinicio;i<tfin;i++)
			if(esprimo(i))
				lcont++;
	}

	EnterCriticalSection(&cs);
	cont=cont+lcont;
	LeaveCriticalSection(&cs);

	return 0;
}

int main(int argc,char *argv[]) {

	int i;
	int args[NTHREADS];
	HANDLE tid[NTHREADS];
	clock_t tinicio,tfin;
	float tiempo;

	if(argc!=3) {
		fprintf(stderr,"Error en los argumentos");
		exit(1);
	}
	inicio=atoi(argv[1]);
	fin=atoi(argv[2]);
	printf("Rango de %d a %d\n",inicio,fin);

	tinicio=clock();

	InitializeCriticalSection(&cs);
	InitializeCriticalSection(&tcs);
	
	for(i=0;i<NTHREADS;i++) {
		args[i]=i;	
					
		tid[i]=CreateThread(NULL,0,tfunc,(LPVOID) &args[i],0,NULL);
	}

	WaitForMultipleObjects(NTHREADS,tid,TRUE,INFINITE);
	DeleteCriticalSection(&cs);
	DeleteCriticalSection(&tcs);
	tfin=clock();
	tiempo=(tfin - tinicio)/1000.0;

	printf("Se encontraron %d números primos\n",cont);
	printf("Tiempo = %2.2f",tiempo);
}
