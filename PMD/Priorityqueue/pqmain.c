#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Priorityqueue.h"

int main(){
	PQ bh = pq_create(TAM,comparechar,printchar);
	int num, i;
	char c1;

	srand(time(NULL));

	for(i=0;i<TAM;i++){
		num=rand()%62;
		if(num<10)
			c1=num+'0';
		else if(num<36)
			c1=num+'A'-10;
		else
			c1=num+'a'-36;
		pq_insert(bh,char_create(c1));
    
	}

    char *m;
	    pq_print(bh);
	        while(bh->current>0){
		    m=(char *)pq_poll(bh);
		    printf("Poll: %c\n",*m);
	}
}
