#include "Set.h"
#include <stdio.h>

SET set_create(COMPAREFUNC cf,PRINTFUNC pf){

	SET tmp=malloc(sizeof(struct STRSET));
	tmp->root=NULL;
	tmp->size=0;
	tmp->cf=cf;
	tmp->pf=pf; 

	return(tmp);
}

void set_add(SET *set,TYPE data){
	if(tree_insert(&(*set)->root,data,(*set)->cf))
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

void set_print(SET set) {
	tree_print(set->root,set->pf,0);
}

void tree_print(NODE node,PRINTFUNC pf,int level) {

	if(node->left!=NULL)
		tree_print(node->left,pf,level+1);

	printtabs(level);
	pf(node->data);

	if(node->right!=NULL)
		tree_print(node->right,pf,level+1);
}

int set_size(SET set){
	return(set->size);
}

BOOL set_contains(SET set,TYPE data){
	BOOL result=tree_contains(set->root,data,set->cf);

	return(result);
}

BOOL tree_contains(NODE root,TYPE data,COMPAREFUNC cf){
	BOOL result=FALSE;
	if(root!=NULL){
		if(cf(root->data,data)==0)	// Son iguales
			result=TRUE;
		else if(cf(root->data,data)>0) // data es menor
			result=tree_contains(root->left,data,cf);
		else if(cf(root->data,data)<0) // data es mayor
			result=tree_contains(root->right,data,cf);
	}
	return(result);
}

NODE tree_min(NODE node){
	NODE current=node;
	while(current->left!=NULL)
		current=current->left;
	return(current);
}

void set_remove(SET set,TYPE data){
	set->root = tree_remove(set->root,data,set->cf);
}

NODE tree_remove(NODE node,TYPE data,COMPAREFUNC cf){
	NODE temp=NULL;
	NODE retval=node;

	if(node!=NULL){
		if(cf(data,node->data)<0)	// Si es menor
			node->left=tree_remove(node->left,data,cf);

		else if(cf(data,node->data)>0) // Si es mayor
			node->right=tree_remove(node->right,data,cf);

		else {
			if(node->left==NULL){
				retval=node->right;
				free(node);
			}
			else if(node->right==NULL) {
				retval=node->left;
				free(node);
			}
			else{
				temp=tree_min(node->right);
				node->data = temp->data;
				node->right = tree_remove(node->right,temp->data,cf);
			}
		}
	}
	return(retval);
}

void printtabs(int level) {
	int i;
    for(i=0;i<level;i++)
		printf("\t");
}

INT int_create(int num)
{
	INT n=malloc(sizeof(int));
	*n=num;
	return n;
}
