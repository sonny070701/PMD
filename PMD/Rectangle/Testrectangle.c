//Sonny Ceja

#include <stdio.h>
#include "Rectangle.h"

int main() {
    Rectangle r1 = new_rectangle (10.0, 20.0);

    printf("Base del rectángulo %f\n", rectangle_base(r1));          
    printf("Altura del rectángulo %f\n", rectangle_height(r1));       
    printf("Área del rectángulo %f\n", rectangle_area(r1));           
    printf("Perínetro del rectángulo %f\n", rectangle_perimeter(r1)); 

    rectangle_set_base (r1, 12.0);
    rectangle_set_height (r1, 15.0);

    printf("Base del rectángulo %f\n",rectangle_base(r1));           
    printf("Altura del rectángulo %f\n",rectangle_height(r1));   

    rect_destroy(r1);    
}
