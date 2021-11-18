//Sonny Ceja

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool True = 1, False = 0;
typedef float (*Function2D) (float);

bool isLinear(Function2D f) {
  float r1 = f(10000);
  float r2 = f(20000);

  if(r2/r1 >=1.99 && r2/r1 <=2.01)
    return True;
  else return False; 
}

bool isQuadratic(Function2D f) {
  float r1 = f(10000);
  float r2 = f(20000);

  if(r2/r1 >=3.98 && r2/r1 <=4.02)
    return True;
  else return False; 
}

float F1(float x) {
	return 4*x - 2; }

float F2(float x) {
	return 3*x*x - 2*x + 4; }

float F3(float x) {
	return 6*sqrt(x) + 2; }

Function2D arr[3] = {&F1, &F2, &F3};  

int main(int argc, char **argv) {
	
  int i;

	setbuf(stdout, NULL);

	for(i = 0; i<3; i++){

		if(isLinear(*(arr+i)))
			printf("Es lineal. ");
		else
			printf("No es lineal. ");

		if(isQuadratic(*(arr+i)))
			printf("Es cuadrático.");
		else
			printf("No es cuadrático.");
		printf("\n");
	}
	return 0;
}
