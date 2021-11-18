#include "Priorityqueue.h"
#include <stdio.h>
#include <stdlib.h>

void insert(TYPE *arr,int pos,TYPE data,COMPAREFUNC cf) {

	int par=parent(pos);
	
	arr[pos]=data;
	while(par>=0 && cf(arr[pos],arr[par]) < 0) {

		swap(&arr[pos],&arr[par]);
		pos=par;
		par=parent(par);
	}
}

void swap(TYPE *i1,TYPE *i2) {

	TYPE tmp=*i1;
	*i1=*i2;
	*i2=tmp;
}

void pq_insert(PQ pq,TYPE data) {

	insert(pq->arr,pq->current,data,pq->cf);
	pq->current++;
}

int comparefloat(TYPE d1,TYPE d2) {

	float *n1=d1;
	float *n2=d2;
	int i1=*n1 * 100;
	int i2=*n2 * 100;
	
	return (i1 - i2);
}

int compareint(TYPE d1,TYPE d2) {
	int *n1=d1;
	int *n2=d2;
	return (*n1 - *n2);
}


int comparechar(TYPE d1,TYPE d2) {
	unsigned char *c1=d1;
	unsigned char *c2=d2;
	return (*c1 - *c2);
}


void printfloat(TYPE data) {
	float *n=data;
	printf("%2.2f\n",*n);
}

void printint(TYPE data) {
	int *n=data;
	printf("%d\n",*n);
}

void printchar(TYPE data) {
	unsigned char *c=data;
	printf("%c\n",*c);
}


PQ pq_create(int size,COMPAREFUNC cf,PRINTFUNC pf) {
	PQ tmp = malloc(sizeof(struct PQSTR));
	int i;

	tmp->arr = malloc(size * sizeof(TYPE));

	for(i=0;i<size;i++)
		tmp->arr[i] = NULL;
	tmp->current=0;
    tmp->size = 0;
	tmp->cf = cf;
	tmp->pf = pf;

	return(tmp);
}

void pq_print(PQ pq) {
	recorre(pq->arr,0,0,pq->pf);
}

void recorre(TYPE *arr,int pos,int level,PRINTFUNC pf) {
	int left=left(pos);
	int right=right(pos);

	if(pos<TAM) {
		if(left>0 && arr[left]>0)
			recorre(arr,left,level+1,pf);

		printtabs(level);
		pf(arr[pos]);

		if(right>0 && arr[right]>0)
			recorre(arr,right,level+1,pf);
	}
}

void printtabs(int t) {
	int i;
	for(i=0;i<t;i++)
		printf("\t");
}

int *int_create(int n) {
	int *tmp = malloc(sizeof(int));	
	*tmp = n;	
	return(tmp);	
}

float *float_create(float n){
	float *tmp = malloc(sizeof(float));	
	*tmp = n;	
	return(tmp);
}

unsigned char *char_create(unsigned char c){
	unsigned char *tmp = malloc(sizeof(char));	
	*tmp = c;	
	return(tmp);	
}

TYPE pq_poll(PQ pq){
    
    if(pq->current == 0) return NULL;
    TYPE poll = pq->arr[0];
    pq->current--;
    
    if(pq->current == 0) return poll;
    
    pq->arr[0] = pq->arr[pq->current];
    int Viejopadre = 0;
    int Tope = 0;
    
    while (!Tope){
    int nuevoPadre = Viejopadre;
    int left = left(Viejopadre);
    int right = right(Viejopadre);

    if(left < pq->current && pq->cf (pq->arr[left], pq->arr[Viejopadre]) < 0)
      nuevoPadre = left;

    if(right < pq->current && pq->cf(pq->arr[right], pq->arr[nuevoPadre]) < 0)
      nuevoPadre = right;

    if(nuevoPadre != Viejopadre) {
      swap(&pq->arr[nuevoPadre], &pq->arr[Viejopadre]);
      Tope = nuevoPadre;
    } else {
        Tope = 1;
        }
    }
     return poll;
}
