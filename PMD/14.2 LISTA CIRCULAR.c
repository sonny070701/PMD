//Sonny Ceja Celis

#include <stdio.h>
#include <stdlib.h>

struct strprim{
    int TOTAL;
    struct strprim* next;
};

typedef struct strprim* PRIMOS;

typedef struct {
	PRIMOS head;
	PRIMOS tail;
    int tamano;
} LIST;

void list_display(LIST l, int tam);
void list_insert(LIST *l, PRIMOS new);
PRIMOS list_create(int total);
void primos_print(PRIMOS d);

int main() {
	LIST list = {NULL, NULL};
	PRIMOS new;

	int ni, nf, tot = 0, t, tam;

	setbuf(stdout,NULL);

	printf("Cuantos  numeros imprimiras? :");
	scanf("%d", &tam);

	printf("NUM INCIAL :");
	scanf("%d", &ni);
	printf("NUM FINAL :");
	scanf("%d", &nf);

    
    int i, div, primo;
    i = ni;
    for (i = ni+1; i <= nf; i++){
		primo = 0;
		for (div = 2; div < i-1 && primo == 0; div++){
			if (i % div == 0)
            primo = 1;
		}
        if(primo == 0){
		    tot++;
            t = i;

		    new = list_create(t);

		    list_insert(&list,new);

		    fflush(stdin);
		    }
	    }
        list_display(list, tam);
}

PRIMOS list_create(int total){

	PRIMOS tmp = malloc(sizeof(struct strprim));
    LIST t;

	tmp->TOTAL = total ;
	tmp->next = NULL;

	return(tmp);
}

void primos_print(PRIMOS d) { 
	printf("\nPRIMOS: %d ",d->TOTAL);
}

void list_display(LIST l, int tam){

	PRIMOS d = l.head;

	for(int i=0; i<tam; i++){
	  primos_print(d);
	  d=d->next;
	}
}

void list_insert(LIST *l, PRIMOS new){

    if(l->head==NULL) {
	    l->head=new;
        l->tail=new;
    }
	else {
	    l->tail->next=new;
	    l->tail=new;
        new->next = l->head;
	}
}