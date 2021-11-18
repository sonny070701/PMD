#ifndef DATATYPES_H_
#define DATATYPES_H_

#define string_val(d) 		((char *) d)
#define int_val(d)			(*((int *) d))
#define char_val(d)			(*((char *) d))
#define double_val(d)		(*((double *) d))
#define float_val(d)		(*((float *) d))
#define date_year_val(d) 	(((DATE) d)->year)
#define date_month_val(d) 	(((DATE) d)->month)
#define date_day_val(d) 	(((DATE) d)->day)

struct STRDATE {
	int year,month,day;
};

typedef char * STRING;
typedef int * INT;
typedef char * CHAR;
typedef double * DOUBLE;
typedef float * FLOAT;
typedef struct STRDATE * DATE;

STRING string_create(STRING str);
INT int_create(int num);
CHAR char_create(char chr);
DOUBLE double_create(double dbl);
FLOAT float_create(float flt);
DATE date_create(int year,int month,int day);

#endif /* DATATYPES_H_ */