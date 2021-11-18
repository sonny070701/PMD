//Sonny Ceja 

#include <stdio.h>
#include <arpa/inet.h>  //bibliotecas para big endian

void printchar (void *a, int n) {
	int i;
	char *ptr;
  for(i=0;i < n; i++) { 
    ptr = a;
		printf ("%c\n", *ptr);
    printf ("%d\n", *ptr);
		a++; }}

void printshort (void *a, short n){

  uint16_t i; //16 bits para 4 digitos (short)
	uint16_t *ptr;
  for(i=0;i < n; i++) { 
    ptr = a;
    printf ("%X\n", *ptr);
    a++; }}

void printint (void *a, short n){

  uint32_t i; // 32 bits para 6 digitos (int)
	uint32_t *ptr;
  for(i=0;i < n; i++) { 
    ptr = a;
    printf ("%X\n", *ptr);
    a++; }}


int main() {
  char arr[]={'A','B',100 ,20 ,0x4E ,50 ,60 ,'M' ,'D' ,0x25 ,040};

  printchar(arr, 1);
  printshort(arr, 1);
  printint(arr, 1);
}