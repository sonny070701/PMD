//Sonny Ceja
//Jessica Donley

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define NTHREADS 2
#define TASKSIZE 1000
int inicio,fin;
int cont=0;
int next_task=0;

CRITICAL_SECTION cs,tcs;

int numAmigos (int* x) {
  int sum = 1;
  for (int i = 2;  i < (*x/2)+1;  i++) {
    if (*x % i == 0) {
      sum += i;
    }
  }
  return sum;
}

DWORD WINAPI tfunc(LPVOID args) {

	int tam =(NTHREADS-1)+fin-inicio;
	int tottasks =1+(tam/TASKSIZE);

	int tinicio;
	int tfin;
	int lcont=0;

	int i,t;

	while(next_task < tottasks) {

		EnterCriticalSection(&tcs);
		t=next_task;
		next_task++;
		LeaveCriticalSection(&tcs);

		tinicio=t*TASKSIZE+inicio;
		tfin=(t+1)*TASKSIZE+inicio;
		if(tfin > fin)
			tfin = fin;
		for(i=tinicio;i<tfin;i++)
			if(numAmigos(&i))
				lcont++;
	}
	return 0;
}

int Result (int *min, int *max){

	int n1, n2;
	for (n1 = *min;  n1 <= *max;  n1++) {
	n2 = numAmigos(&n1);
	if (n2 > n1 && n1 == numAmigos(&n2)) {

	printf("%d  es amigo de %d \n", n1, n2);
		}
	}
	return 0;
}


int main() {
  setbuf(stdout, NULL);

  float tiempo;
  clock_t tinicio,tfin;

  int i;
  int args[NTHREADS];
  HANDLE tid[NTHREADS];

  int max, min;
  printf("inicio del rango: ");
  scanf("%d",&min);
  printf("final del rango: ");
  scanf("%d",&max);

  tinicio=clock();
  InitializeCriticalSection(&tcs);

  	for(i=0;i<NTHREADS;i++) {
  		args[i]=i;

  		tid[i]=CreateThread(NULL,0,tfunc,(LPVOID) &args[i],0,NULL);
  		Result(&min, &max);
  	}

  	WaitForMultipleObjects(NTHREADS,tid,TRUE,INFINITE);
  	DeleteCriticalSection(&tcs);

  	tfin=clock();
  	tiempo = (tfin - tinicio)/1000.0;

  	printf("Tiempo = %2.2f",tiempo);

}








