#include "Set.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

SET set_create(COMPAREFUNC cf,PRINTFUNC pf) {

	SET tmp=malloc(sizeof(struct STRSET));
	tmp->root=NULL;
	tmp->size=0;
	tmp->cf=cf;
	tmp->pf=pf;
	return(tmp);
}

void set_add(SET *set,TYPE data) {

	if(tree_insert(&(*set)->root, data, (*set)->cf))
		(*set)->size++;
}


int tree_insert(NODE *node,TYPE data,COMPAREFUNC cf) {

	int success=0;

	if(*node==NULL){

		*node = malloc(sizeof(struct STRNODE));
		(*node)->data=data;
		(*node)->left=NULL;
		(*node)->right=NULL;
		success=1;
	}
	else if(cf(data,(*node)->data)<0)
		success=tree_insert(&(*node)->left,data,cf);
	else if(cf(data,(*node)->data)>0)
		success=tree_insert(&(*node)->right,data,cf);

	return(success);
}

void recorre(NODE node,int level) {

	if(node->left!=NULL)
		recorre(node->left,level+1);

	printtabs(level);
	date_print(node->data);

	if(node->right!=NULL)
		recorre(node->right,level+1);
}

int set_size(SET set) {

	return(set->size);
}

int date_compare(TYPE data1,TYPE data2) {
	int d1, d2;

	d1 = (((DATE) data1)->year << 16) + (((DATE) data1)->month << 8) + (((DATE) data1)->day);
	d2 = (((DATE) data2)->year << 16) + (((DATE) data2)->month << 8) + (((DATE) data2)->day);
	return(d1-d2);
}

void date_print(TYPE data) {

	printf("{%d; %d; %d}\n",((DATE) data)->year,
			((DATE) data)->month,((DATE) data)->day);
}

void printtabs(int level) {
    
	int i;
    for(i=0;i<level;i++)
		printf("\t"); 
}