//Sonny Ceja

#include <stdio.h>
#include <math.h>

struct v2d {
  float x, y;
};

void toUnit (struct v2d *p) {

  float formula = sqrt(pow( p -> x, 2) + pow(p -> y, 2));

  p -> x = (p -> x/formula);
  p -> y = (p -> y/formula);
}

int main () {

  struct v2d v = {3.0, 4.0};

  toUnit(&v);

  printf("%f, %f\n", v.x, v.y);

  return 0;
}

//Los ejercicios como tal no fueron tan complicados, 
//a mi parecer el mas complicado fue el del vector ya que tuve 
//que investigar mas acerca de los apuntadores y encontre su forma en -> y ., 
//al final resulto exitoso y espero aprender mas sobre la materia 
//y reforzar lo visto en programacion estructurada.