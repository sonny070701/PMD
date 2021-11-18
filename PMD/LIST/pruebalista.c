#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

int main()
{
	LIST list=list_create();
	ITERATOR ite;
	int i,p,n;
	TYPE res;

	setbuf(stdout,NULL);

	for(i=0;i<10;i++)
		list_add(list,int_create(i*10));


	printf("La lista tiene %d elementos\n",list_size(list));

	printf("Dame una posición a modificar ");
	scanf("%d",&p);
	printf("Dame el nuevo valor de la posición ");
	scanf("%d",&n);

	list_set(list,int_create(n),p);


	printf("Dame una posición a borrar ");
	scanf("%d",&p);

	res=list_remove(list,p);
	if(res!=NULL)
		printf("Elemento eliminado contenía %d\n",*((int *) res));
	else
		printf("Posición no encontrada\n");


	printf("De inicio a fin \n");
	ite=list_begin(list);
	while(has_next(ite))
	{
		ite=next(ite);
		printf("position=%d, dato contenido=%d\n",ite->position,int_val(ite->data));
	}

	printf("De fin a inicio \n");
	ite=list_end(list);
	while(has_prior(ite))
	{
		ite=prior(ite);
		printf("position=%d, dato contenido=%d\n",ite->position,int_val(ite->data));
	}

}