//	Sonny Ceja Celis

#include <stdio.h>
#include <stdlib.h>

struct strprim{
    int TOTAL;
    struct strprim* prev;
    struct strprim* next;
};

typedef struct strprim* PRIMOS;

typedef struct {
	PRIMOS head;
	PRIMOS tail;
} LIST;

PRIMOS list_create(int total);
void primos_print(PRIMOS d);
void list_displayNormal(LIST l);
void list_displayReverse(LIST l);
void list_insert(LIST *l, PRIMOS new);

int main() {
	LIST list = {NULL, NULL};
	PRIMOS new;

	int respuesta, ni, nf, tot = 0, t;

	setbuf(stdout,NULL);

    printf("En que orden quieres imprimir? (ascendente = 0, descendente = 1)");
    scanf("%d", &respuesta);

    if(respuesta == 0){
	
	printf("NUM INCIAL :");
	scanf("%d", &ni);
	printf("NUM FINAL :");
	scanf("%d", &nf);

    
    int i, div, primo;
    i = ni;
    for (i = ni; i <= nf; i++){
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
        list_displayNormal(list);
    }
    if(respuesta == 1){
	
	printf("NUM INCIAL :");
	scanf("%d", &ni);
	printf("NUM FINAL :");
	scanf("%d", &nf);

    
    int i, div, primo;
    i = ni;
    for (i = ni; i <= nf; i++){
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
        list_displayReverse(list);
    }

}

PRIMOS list_create(int total){

	PRIMOS tmp = malloc(sizeof(struct strprim));

	tmp->TOTAL = total ;
	tmp->next = NULL;
    tmp->prev=NULL;

	return(tmp);
}

void primos_print(PRIMOS d) {  

	printf("\nPRIMOS: %d ",d->TOTAL);
}

void list_displayNormal(LIST l) {
	PRIMOS d = l.head;
	while(d!=NULL) {
		primos_print(d);
		d=d->next;
	}
}

void list_displayReverse(LIST l) {
    
	PRIMOS d = l.tail;
	while(d!=NULL){
		primos_print(d);
		d=d->prev;
	}
}

void list_insert(LIST *l, PRIMOS new){

	if(l->head==NULL) {
		l->head=new;
		l->tail=new;
	}

	else {
    new->prev = l->tail;
		l->tail->next=new;
		l->tail=new;
    new->next=NULL;
	}
}