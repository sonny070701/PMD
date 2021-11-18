#include "Heap.h"
#include <stdlib.h>
#include <stdio.h>

void insert(TYPE *arr, int pos, TYPE data, COMPAREFUNC cf) {

	int par = parent(pos);
	arr[pos] = data;

	while (par >= 0 && cf(arr[pos], arr[par]) > 0){

		swap (&arr[pos], &arr[par]);
		pos = par;
		par = parent(par);
	}
}

void swap(TYPE *i1, TYPE *i2){

	TYPE tmp = *i1;
	*i1 = *i2;
	*i2 = tmp;
}

void binheap_insert(BINHEAP binheap,TYPE data) {

	insert (binheap->arr, binheap->root, data, binheap->cf);
	binheap->root++;
}

int comparefunc (TYPE d1, TYPE d2) {
	int *n1 = d1;
	int *n2 = d2;
	return(*n1 - *n2);
}

void printfunc(TYPE data) {

	int *n = data;
	printf("%d\n",*n);
}

BINHEAP binheap_create (int size, COMPAREFUNC cf, PRINTFUNC pf) {

	BINHEAP bh = malloc(sizeof(struct BINHEAPSTR));
	int i;
	
	bh->arr = malloc(size * sizeof(TYPE));

	for(i=0;i<size;i++)
		bh->arr[i] = NULL;
	bh->root=0;
	bh->cf = cf;
	bh->pf = pf;
	
	return(bh);
}

void binheap_print(BINHEAP binheap) {
	recorre(binheap->arr, 0, 0, binheap->pf);
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
	for(i = 0; i < t; i++)
		printf("\t");
}

int *int_create(int n) {
	int *tmp = malloc(sizeof(int));	
	*tmp = n;	
	return(tmp);
}