//Sonny Ceja

#include <stdio.h>

void imprimirdoble(int n){
  printf("función doble: %d\n", n*2);}

void imprimirtriple(int n){
  printf("función triple: %d\n", n*3);}

int sumar (int a, int b, int c){
  return a + b + c;}

int multiplicar (int a, int b, int c){
  return a * b * c;}

int main(){

  void (*func_a)(int) = 0;

  func_a = imprimirdoble;
  func_a(2);

  func_a = imprimirtriple;
  func_a(2);
  
  int(*func_b)(int, int, int) = 0;

  func_b = sumar;
  printf("función suma: %d\n", func_b (10, 15, 20));

  func_b = multiplicar;
  printf("función multiplicar: %d\n", func_b (10, 15, 20));

}
