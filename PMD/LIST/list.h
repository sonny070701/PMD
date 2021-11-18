#ifndef list_H_
#define list_H_

#define string_val(d) 		((char *) d)
#define int_val(d)			(*((int *) d))
#define char_val(d)			(*((char *) d))
#define double_val(d)		(*((double *) d))
#define float_val(d)		(*((float *) d))
#define date_year_val(d) 	(((DATE) d)->year)
#define date_month_val(d) 	(((DATE) d)->month)
#define date_day_val(d) 	(((DATE) d)->day)

#define list_begin(l)	(l->prefirst)
#define list_end(l)		(l->postlast)
#define has_next(i)		(i->next!=NULL)
#define has_prior(i)	(i->prior!=NULL)
#define next(i)			(i->next)
#define prior(i)		(i->prior)

typedef char * STRING;
typedef int * INT;
typedef char * CHAR;
typedef double * DOUBLE;
typedef float * FLOAT;
typedef struct STRDATE * DATE;
typedef enum {FALSE,TRUE} BOOL;
typedef void * TYPE;

STRING string_create(STRING str);
INT int_create(int num);
CHAR char_create(char chr);
DOUBLE double_create(double dbl);
FLOAT float_create(float flt);
DATE date_create(int year,int month,int day);

struct STRDATE {
	int year,month,day;
};

struct STRNODE {
	int position;
	TYPE data;
	struct STRNODE *prior,*next;
};

typedef struct STRNODE * NODE;
typedef NODE ITERATOR;

struct STRLIST {
	NODE prefirst,first,last,postlast;
	int size;
};

typedef struct STRLIST * LIST;

LIST list_create();
void list_add(LIST list,TYPE data);		// Insertar en la lista
int list_size(LIST list);				// Obtener el tamaño
TYPE list_remove(LIST list, int p);		// Eliminar de la lista
TYPE list_get(LIST list,int p);			// Obtener un elemento de la lista
void list_set(LIST list, TYPE elem, int p);

#endif /* list_H_ */