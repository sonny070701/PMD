//Sonny Ceja

#include <stdio.h>

void saludar() {
    printf("Hola\n"); }

void ejecutar (void saludar()) {
    saludar();
}

int main(){
    ejecutar(saludar);
  }