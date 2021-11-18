#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Heap.h"
#include <string.h>

int main() {

	BINHEAP bh = binheap_create(TAM,comparefunc,printfunc);
	int num, i;

	setbuf(stdout,NULL);
    srand(time(NULL));

	for(i=0; i<255; i++) {

		num = rand()%1000;
		binheap_insert(bh,int_create(num));
	}

	binheap_print(bh);
}
