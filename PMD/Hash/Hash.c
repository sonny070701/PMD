#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Hash.h"


long long myhash(TYPE data)
{
	int suma=0;
	int factm=1;
	char *cad=data;
	while(*cad) {
		suma=suma+(*cad * factm);
		cad++;
		factm=factm*2;
	}
	return(suma);
}

LIST list_create()
{
	LIST tmp=malloc(sizeof(struct STRLIST));
	tmp->first=NULL;
	tmp->last=NULL;
	tmp->size=0;
	return(tmp);
}

void list_insert(LIST list,TYPE data)
{
	NODE new=malloc(sizeof(struct STRNODE));
	
	keyval_print(data);
	printf("\n");
	
	new->data=data;
	new->next=NULL;
	
	if(list->first==NULL)
		list->first=new;
	else
		list->last->next=new;
	
	list->last=new;
}

KEYVAL keyval_create(char *key,char *value)
{
	KEYVAL tmp=malloc(sizeof(struct KEYVALSTR));
	strcpy(tmp->key,key);
	strcpy(tmp->value,value);
	return(tmp);
}

void list_print(LIST list)
{
	NODE ptr=list->first;
	
	while(ptr!=NULL)
	{
		keyval_print(ptr->data);
		ptr=ptr->next;
	}
}

void keyval_print(KEYVAL kv)
{
	printf("<%s,%s>",kv->key,kv->value);
}

KEYVAL keyval_search(LIST list,char *key)
{
	KEYVAL retval=NULL;
	KEYVAL keyval;
	BOOL found=FALSE;
	
	NODE ptr=list->first;
	
	while(ptr!=NULL && !found)
	{
		keyval=ptr->data;
		if(strcmp(keyval->key,key)==0)
		{
			retval=ptr->data;
			found=TRUE;
		}
    ptr=ptr->next;
	}
	return(retval);
}