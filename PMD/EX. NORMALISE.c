
#include <stdio.h>
#include <math.h>

struct vec3d {
  float x, y, z;
};

void normalize (struct vec3d *v) {
  
  float magnitud = sqrt(pow(v-> x,2) + pow(v->y,2) + pow(v->z,2));
  v->x = v->x /magnitud;
  v->y = v->y /magnitud;
  v->z = v->z /magnitud;

}

int main(){
struct vec3d prueba = {1.5, 3.0, 4.5};
normalize(&prueba);

printf("magnitud = %f\n", prueba.x + prueba.y + prueba.z);
}