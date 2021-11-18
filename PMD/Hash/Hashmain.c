#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Hash.h"

#define M 5

int main() {

	int i, pos;
	LIST hashtable[M];
	KEYVAL kv;
	char key[50];
	char value[50];
	long long hashcode;

	setbuf(stdout,NULL);
	
	for(i=0;i<M;i++)
		hashtable[i] = list_create();

	do {
		printf("Dame una llave ");
		scanf("%s",key);
		fflush(stdin);
		if(strcmp(key,"FIN")!=0) {

			printf("Dame un valor ");
			scanf("%s",value);
			fflush(stdin);

			hashcode=myhash(key);
			
			pos=hashcode % M;
			printf("Posición de la tabla : %d\n",pos);
			list_insert(hashtable[pos],keyval_create(key,value));
		}
	} while(strcmp(key,"FIN")!=0);
	
	for(i=0;i<M;i++) {
		printf("\n%d:",i);
		list_print(hashtable[i]);
	}


	printf("\n\nBúsqueda de claves en la tabla\n");
	do {
		printf("Dame una llave ");
		scanf("%s",key);
		fflush(stdin);
		if(strcmp(key,"FIN")!=0)
		{
			hashcode=myhash(key);
			pos=hashcode % M;
			printf("Posición de la tabla : %d\n",pos);
			kv=keyval_search(hashtable[pos],key);
			if(kv!=NULL)
				printf("<%s,%s>\n",kv->key,kv->value);
      else
        printf("Clave no existente");
		}
	} while(strcmp(key,"FIN")!=0);
}