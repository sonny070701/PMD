#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Set.h"
#include "datatypes.h"

#define ELEMS 30

int main() {
	
	int i;
	int y, m, d;
	
	SET set=set_create(date_compare, date_print);

	srand(time(NULL));

	for(i=0;i<ELEMS;i++) {

		y = rand()% 2 +  2020;
        m = rand()% 2 + 12;
        d = rand()% 31;

        if (m > 12){
            m = 01;
        }
        if (m == 12 && y == 2021){
            y =2020;
        }
        if (m == 01 && y == 2020){
            y = 2021;
        }

		set_add(&set, date_create(y, m, d));
	}

	printf("Elementos insertados=%d\n",set_size(set));
	recorre(set->root,0);
}