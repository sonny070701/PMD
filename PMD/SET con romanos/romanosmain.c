#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Romanos.h"
#include "Set.h"

#define T 20

int main(){

	int i, n;

	setbuf(stdout,NULL);

	SET intset=set_create(int_compare,int_print);
	SET nrset=set_create(roman_compare,roman_print);

	srand(time(NULL));

	for(i=0; i<T; i++) {
		n=rand()%1000;
		set_add(&intset, int_create(n));
		set_add(&nrset, aratorom(n));
	}

	printf("números arábicos=%d\n",set_size(intset));
	set_print(intset);
	
	printf("números romanos=%d\n",set_size(nrset));
	set_print(nrset);

}
