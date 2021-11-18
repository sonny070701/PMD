//Sonny Ceja

#include <stdio.h>

void printptrarr(char **a,int n) {

	int i;
	for(i=0; i<n; i++) {

    printf("%s\n",*a);
    a++;
	}
}

int main() {

char arr[12][10]={"Uno","Dos","Tres","Cuatro","Cinco","Seis","Siete","Ocho","Nueve","Diez","Once","Doce"}; 

char *ptr[12];
int i;	

for (i = 0; i < 10; i++){
  *(ptr+i) = arr [i];
  }
   printptrarr (ptr,12);
}