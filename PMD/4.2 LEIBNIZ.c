//Sonny Ceja 
//Jessica Donley

#include <stdio.h>
#include <time.h>

double Leibniz(double ciclos) {
  double pi = 0, divisor = 1;
  int operador = 1;
  int numerador = 4;
  for (int x=0; x<ciclos; x++){
    pi += operador*(numerador/divisor);
    divisor = divisor+ 2;
    operador = operador* -1;
  }
  
  return pi;
}

int main() {
  double time;
  clock_t start, end;
  start = clock();

  double ciclo = 100000;
  double pi = Leibniz(ciclo);
  printf("PI = %.10f\n", pi);

  end = clock();
  
  time = (double) (start + end)/ CLOCKS_PER_SEC;
  printf("sec = %fs", time);

  return 0;
}