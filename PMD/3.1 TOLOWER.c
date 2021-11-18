//Sonny Ceja 

#include <stdio.h>
#include <ctype.h>
 
void arrtolower (char *a){

  int l = sizeof(a)/sizeof(a+0);

  int i;
  for (i = 0; i < l; i++){
    while (*a != l){
      *(a+i) = tolower (*a+i);
      a++; }}
}

int main() {  

  char words[][10] = {"HOLA", "MUNDO", "Cruel5", "ADIÓS"};
  
  int i;	
  for (i = 0; i < 4; i++){
  arrtolower (*words);
  printf("%s\t", *(words+i));
  }
}