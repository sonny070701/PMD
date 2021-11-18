//Sonny Ceja

#include <stdio.h>
#include <time.h>
#include <math.h>
#include <windows.h>

#define LEN 5
#define ITER ((int) pow(62,LEN))
#define RESULT 0xBDC96A4

#define NTHREADS 8

int inicio,fin;
int cont=0;
int next_task=0;
CRITICAL_SECTION tcs;

char cod(char c) {
	char ret;
	if(c>=0 && c<=9)
		ret='0'+c;
	else if(c>=10 && c<=35)
		ret='A'+c-10;
	else if(c>=36 && c<=61)
		ret='a'+c-36;
	else
		ret=0;
	return(ret);
}

unsigned long hash(unsigned char *str) {
    unsigned long hash = 5381;
    int c;

     while (c = *str++)
        hash = ((hash << 5) + hash) + c;
     return hash;
}

void strgen(char *s,int n) {
	int i;
        s[LEN]='\0';
	for(i=LEN-1;i>=0;i--) {
		s[i]=cod(n%62);
		n/=62;
	}
}

DWORD WINAPI tfunc (LPVOID args){

	char cad[LEN+1];
	int countcad=0;
	int tnum=*((int *) args); //numero de hilo
	int tam =(ITER/NTHREADS); //Iteraciones

	//HILO 0 = 0, 1, 2, 3, 4
	//HILO 1 = 5 ,6, 7 ,8, 9
	//HILO 2 = 10, 11, 12, 13, 14
	//HILO 3 = 15, 16, 17, 18, 19

	int tinicio = tnum*tam; //Numero de hilo por sus tareas
	int tfin = tinicio+tam; //Rango de inicio a fin (tareas)
	int i;

	for(i=tinicio ;i<tfin; i++) {
			strgen(cad,i);
			if(hash(cad) == RESULT) {
				countcad++;
				printf("La cadena encontrada es %s\n", cad);
				printf("Soluciones encontradas %d\n",countcad);
			}
		}
	return 0;
}

int main(){

	clock_t tinicio,tfin;

	int i;

	int args[NTHREADS];
	HANDLE tid[NTHREADS];

	tinicio=clock();

	InitializeCriticalSection(&tcs);
	for(i=0;i<NTHREADS;i++){

		args[i]=i;

		tid[i]=CreateThread(NULL,0,tfunc,(LPVOID) &args[i],0,NULL);
	}

	WaitForMultipleObjects(NTHREADS,tid,TRUE,INFINITE);
	DeleteCriticalSection(&tcs);

	tfin=clock();
	float tiempo=(tfin - tinicio)/1000.0;
	printf("Tiempo = %2.2f segundos\n", tiempo);
}
