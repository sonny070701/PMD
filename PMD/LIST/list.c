#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

LIST list_create()
{
	LIST ptr=malloc(sizeof(struct STRLIST));
	ptr->first=NULL;
	ptr->last=NULL;
	ptr->size=0;
	ptr->prefirst=malloc(sizeof(struct STRNODE));
	ptr->postlast=malloc(sizeof(struct STRNODE));
	ptr->prefirst->prior=NULL;
	ptr->prefirst->data=NULL;
	ptr->postlast->next=NULL;
	ptr->postlast->data=NULL;
	return(ptr);
}

void list_add(LIST list,TYPE data)
{
	NODE new=malloc(sizeof(struct STRNODE));
	new->data = data;
	new->next = NULL;
	new->prior = NULL;

	// ¿está la lista vacía?
	if(list->first==NULL)
	{
		list->first=new;
		list->prefirst->next=list->first;
		new->position=0;
	}
	else
	{
							  //   last           new
		list->last->next=new; // +--------+     +-------+
							  // | | |next| --> |       |
							  // +--------+     +-------+

		new->prior=list->last;//   last           new
							  // +--------+     +-------+
							  // |        | <---|prior| |
							  // +--------+     +-------+
		new->position=new->prior->position + 1;
	}
	list->size++;
	list->last=new;
	list->postlast->prior=list->last;
}

int list_size(LIST list)
{
	return(list->size);
}

/*
 * Obtener un valor de la lista
 * 	Regresa el apuntador
 */
TYPE list_get(LIST list,int p)
{
	NODE ptr=list->prefirst;
	TYPE retval=NULL;
	BOOL found=FALSE;
	while(has_next(ptr) && !found)
	{
		ptr=ptr->next;
		if(ptr->position==p) // Si ya lo encontré
		{
			found=TRUE;
			retval=ptr->data;
		}
	}
	return(retval);
}

TYPE list_remove(LIST list, int p)
{
	NODE ptr=list->prefirst;
	NODE toremove=NULL;
	TYPE retval=NULL;
	BOOL found=FALSE;
	while(has_next(ptr) && !found)
	{
		ptr=ptr->next;
		if(ptr->position==p) // Si ya lo encontré
		{
			found=TRUE;
			retval=ptr->data;
			toremove=ptr;
		}
	}

	if(found)
	{
		// Desconectar el nodo toremove
		// 1er caso, es el único
		if(list->first==toremove && list->last==toremove)
		{
			list->prefirst->next=NULL;
			list->postlast->prior=NULL;
			list->first=NULL;
			list->last=NULL;
		}

		// 2do caso, es el primero
		else if(list->first == toremove)
		{
			list->prefirst->next = toremove->next;
			// No hay prior
			toremove->next->prior=NULL;
			list->first = toremove->next;
		}

		// 3er caso, es el último
		else if(list->last == toremove)
		{
			list->postlast->prior = toremove->prior;
			// No hay next
			toremove->prior->next=NULL;
			list->last=toremove->prior;
		}

		// 4to caso, es un nodo que está enmedio
		else
		{
			toremove->prior->next = toremove->next;
			toremove->next->prior = toremove->prior;
		}

		list->size--;
		free(toremove);
	}

	return(retval);
}

void list_set(LIST list, TYPE elem, int p)
{
	NODE ptr=list->prefirst;
	BOOL found=FALSE;
	while(has_next(ptr) && !found)
	{
		ptr=ptr->next;
		if(ptr->position==p) // Si ya lo encontré
		{
			found=TRUE;
			ptr->data=elem;
		}
	}
}


// Manejo de los tipos de datos
STRING string_create(STRING str)
{
	STRING s=malloc(strlen(str));
	strcpy(s,str);
	return s;
}

INT int_create(int num)
{
	INT n=malloc(sizeof(int));
	*n=num;
	return n;
}

CHAR char_create(char chr)
{
	CHAR c=malloc(sizeof(char));
	*c=chr;
	return c;
}

DOUBLE double_create(double dbl)
{
	DOUBLE d=malloc(sizeof(double));
	*d=dbl;
	return d;
}

FLOAT float_create(float flt)
{
	FLOAT f=malloc(sizeof(float));
	*f=flt;
	return f;
}

DATE date_create(int year,int month,int day)
{
	DATE d=malloc(sizeof(struct STRDATE));
	d->year=year;
	d->month=month;
	d->day=day;
	return(d);
}
