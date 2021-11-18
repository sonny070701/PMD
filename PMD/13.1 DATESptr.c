//Sonny ceja

#include <stdio.h>
#include <stdlib.h>

struct strdate{
    int year;
    int month;
    int day;
    struct strdate* next;
};

typedef struct strdate DATE;

void insert(DATE **ptriniciolista, DATE *n) {

	DATE* new = malloc(sizeof(struct strdate));
	DATE* ptr;

	new->year = n->year;
	new->month = n->month;
	new->day = n->day;
	new->next = NULL;

	if(*ptriniciolista == NULL){
		*ptriniciolista = new;
		ptr=*ptriniciolista;
	}
	else{
		ptr = *ptriniciolista;
		while(ptr->next != NULL){
			ptr=ptr->next;
		}
		ptr->next=new;
	}
}

void printdates(DATE *d) {

   DATE *ptr=d;

   while(ptr!=NULL){

       printf("%d,%d,%d\n",ptr->year,ptr->month,ptr->day);
       ptr=ptr->next;
   }
}

int main(){

	DATE d1={1,10,2019,NULL};
	DATE d2={2,02,2020,NULL};
	DATE d3={3,03,2021,NULL};

	DATE* iniciolista = NULL;

	insert(&iniciolista, &d1);
    insert(&iniciolista, &d2);
    insert(&iniciolista, &d3);

    printdates(iniciolista);
}