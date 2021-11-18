#include <stdlib.h>
#include <string.h>
#include "datatypes.h"

STRING string_create(STRING str) {

	STRING s=malloc(strlen(str));
	strcpy(s,str);
	return s;
}

INT int_create(int num) {

	INT n=malloc(sizeof(int));
	*n=num;
	return n;
}

CHAR char_create(char chr) {

	CHAR c=malloc(sizeof(char));
	*c=chr;
	return c;
}

DOUBLE double_create(double dbl) {

	DOUBLE d=malloc(sizeof(double));
	*d=dbl;
	return d;
}

FLOAT float_create(float flt) {

	FLOAT f=malloc(sizeof(float));
	*f=flt;
	return f;
}

DATE date_create(int year,int month,int day) {
    
	DATE d=malloc(sizeof(struct STRDATE));
	d->year=year;
	d->month=month;
	d->day=day;
	return(d);
}