#include "Set.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

SET set_create(COMPAREFUNC cf,PRINTFUNC pf) { //PARA CREAR SET

	SET tmp=malloc(sizeof(struct STRSET));
	tmp->root=NULL;
	tmp->size=0;
	tmp->cf=cf;
	tmp->pf=pf;
	return(tmp);
}

void set_add(SET *set,TYPE data) { //AGREGAR DATOS

	if(tree_insert(&(*set)->root, data, (*set)->cf))
		(*set)->size++;
}

int tree_insert(NODE *node,TYPE data,COMPAREFUNC cf) { //INSERTAR EN EL ARBOL

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

void recorre(NODE node,int level) { //RECORRER NODOS

	if(node->left!=NULL)
		recorre(node->left,level+1);

	printtabs(level);
	char_print(node->data);

	if(node->right!=NULL)
		recorre(node->right,level+1);
}

int set_size(SET set) { //REGRESA EL TAMAÑO

	return(set->size);
}

void printtabs(int level) { //IMPRIME COMO LISTA
    
	int i;
    for(i=0;i<level;i++)
		printf(""); 
}

void set_print(SET set) { //FUNCION DE IMPRIMIR EL SET
	tree_print(set->root,set->pf,0);
}

void tree_print(NODE node,PRINTFUNC pf,int level) { //IMPRIMIR EL ARBOL

	if(node->left!=NULL)
		tree_print(node->left,pf,level+1);

	printtabs(level);
	pf(node->data);

	if(node->right!=NULL)
		tree_print(node->right,pf,level+1);
}

void char_print(TYPE data) { // USADA PARA EL SET CREATE
	printf("%s\n",(char *)data);
}

int string_compare(TYPE s1, TYPE s2){ //USADA PARA EL SET CREATE

    int ret; //ENTERO DE RETURN 
    ret = strcmp(s1, s2); //STRCMP PARA COMPARAR
    return ret; //REGRESA EL VALOR MAS GRANDE
}

