#include <stdlib.h>

#define left(n) (n*2+1)
#define right(n) (n*2+2)
#define parent(n) (n==0?-1:(n-1)/2)

#define TAM 255

typedef void * TYPE;
typedef int (*COMPAREFUNC)(TYPE,TYPE);
typedef void (*PRINTFUNC)(TYPE);

struct BINHEAPSTR {
	TYPE *arr;
	int root;
	PRINTFUNC pf;
	COMPAREFUNC cf;
};

typedef struct BINHEAPSTR * BINHEAP;

int *int_create(int n);

void insert (TYPE *arr, int pos, TYPE data, COMPAREFUNC cf);
void recorre (TYPE *arr, int pos, int level, PRINTFUNC pf);
void printtabs( int t);
void swap (TYPE *i1, TYPE *i2);
BINHEAP binheap_create (int size, COMPAREFUNC cf, PRINTFUNC pf);
void binheap_insert (BINHEAP binheap,TYPE data);
void binheap_print (BINHEAP binheap);

int comparefunc (TYPE d1,TYPE d2);
void printfunc (TYPE data);