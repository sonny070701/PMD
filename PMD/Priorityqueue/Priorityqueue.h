

#define left(n) (n*2+1)
#define right(n) (n*2+2)
#define parent(n) (n==0?-1:(n-1)/2)

#define TAM 15

typedef void * TYPE;

typedef int (*COMPAREFUNC)(TYPE,TYPE);
typedef void (*PRINTFUNC)(TYPE);

struct PQSTR {
	TYPE *arr;
	int current;
    int size;
	PRINTFUNC pf;
	COMPAREFUNC cf;
};

typedef struct PQSTR * PQ;


int *int_create(int n);
float *float_create(float n);
unsigned char *char_create(unsigned char c);

void insert(TYPE *arr,int pos,TYPE data,COMPAREFUNC cf);
void recorre(TYPE *arr,int pos,int level,PRINTFUNC pf);
void printtabs(int t);
void swap(TYPE *i1,TYPE *i2);

PQ pq_create(int size,COMPAREFUNC cf,PRINTFUNC pf);
void pq_insert(PQ pq,TYPE data);
void pq_print(PQ pq);
TYPE pq_poll(PQ pq);

int comparefloat(TYPE d1,TYPE d2);
int compareint(TYPE d1,TYPE d2);
int comparechar(TYPE d1,TYPE d2);
void printfloat(TYPE data);
void printint(TYPE data);
void printchar(TYPE data);