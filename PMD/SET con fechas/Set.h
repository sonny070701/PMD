#ifndef SET_H_
#define SET_H_

#include "datatypes.h"

typedef void * TYPE;

typedef int (*COMPAREFUNC)(TYPE,TYPE);
typedef void (*PRINTFUNC)(TYPE);

struct STRNODE {
	TYPE data;
	struct STRNODE *left,*right;
};

typedef struct STRNODE * NODE;

struct STRSET {
	NODE root;
	int size;
	COMPAREFUNC cf;
	PRINTFUNC pf;
};

typedef struct STRSET * SET;

void set_add(SET *set,TYPE data);
int set_size(SET set);
int tree_insert(NODE *node,TYPE data,COMPAREFUNC cf);
void recorre(NODE node,int level);
void printtabs(int level);
int date_compare(TYPE data1,TYPE data2);
void date_print(TYPE data);
SET set_create(COMPAREFUNC cf,PRINTFUNC pf);
DATE date_create(int year,int month,int day);

#endif /* SET_H_ */