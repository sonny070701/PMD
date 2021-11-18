#include <stdio.h>

#ifndef SET_H_
#define SET_H_

#define string_val(d) ((char *) d) //PARA EL STRING

typedef void * TYPE;

typedef int (*COMPAREFUNC)(TYPE,TYPE);
typedef void (*PRINTFUNC)(TYPE);
typedef char * STRING;

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
void tree_print(NODE node,PRINTFUNC pf,int level);
void recorre(NODE node,int level);
void printtabs(int level);
SET set_create(COMPAREFUNC cf,PRINTFUNC pf);
void set_print(SET set) ;
void char_print(TYPE data);
int string_compare(TYPE s1, TYPE s2);

#endif /* SET_H_ */