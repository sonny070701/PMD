//Sonny Ceja

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define NTHREADS 1

DWORD WINAPI tfunc(LPVOID *args)
{
	int i;
	while(i != 0) {
		Sleep(1000);
	}
	return(0);
}


void numPrimos(int *  NI, int *NF) {
	int i, div, primo, total = 0;
	i = *NI;
	for (i = *NI; i <= *NF; i++){
		primo = 0;
		for (div = 2; div < i-1 && primo == 0; div++){
			if (i % div == 0)
				primo = 1;
		}
		if(primo == 0){
			printf("%d ,", i);
			total++;
		}
	}
	printf("primos: %d ,", total);
}

int main(){

	setbuf(stdout,NULL);

	double time;

	HANDLE tid[NTHREADS];

	int i;

	int NFinal, NInit;
	printf("escriba el numero inical: ");
	scanf("%d", &NInit);

	printf("escriba el numero final: ");
	scanf("%d", &NFinal);

	clock_t inicio, fin;

	inicio = clock();

	for(i = 0; i<NTHREADS; i++){
		tid[i] = CreateThread(NULL, 0, tfunc, NULL, 0, NULL);

		numPrimos(&NInit, &NFinal);

		WaitForSingleObject(tid[i],INFINITE);

		fin = clock();
		time = (double)(fin - inicio) / CLOCKS_PER_SEC;

		printf("Tiempo: %fs", time);
	}
	return 0;

}