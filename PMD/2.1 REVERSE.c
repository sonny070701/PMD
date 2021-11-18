//Sonny Ceja

#include<stdio.h>

void reverse(char *texto){

  int i, size;
  int sw = 0;

  
  for(size = 0; *(texto+size) != 0; size++);
  for(i = 0; i < size/2; i++){

    sw = *(texto+i);
    *(texto+i) = *(texto+size - i - 1);
    *(texto+size - i - 1) = sw;
  }
}

int main() {
    char texto[] = "Guadalajara"; 
    reverse(texto);

    printf("%s\n", texto);
}