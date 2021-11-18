//Sonny ceja

#include <stdio.h>	
#include <stdlib.h>
#include "Rectangle.h"	

Rectangle  new_rectangle(double x, double y){

	Rectangle new = malloc(sizeof(struct StructRec));
	new->x=x;
	new->y=y;
	return(new);
}

void rect_destroy (Rectangle r1){
    
	free(r1);
}

void rectangle_set_base (Rectangle r1, double x){

    r1->x=x;
}

void rectangle_set_height (Rectangle r1, double y){

    r1->y=y;
}

double rectangle_base (Rectangle r1){

	return(r1->x);
}

double rectangle_height (Rectangle r1){

    return (r1->y);
}

double rectangle_area (Rectangle r1){

    	return((r1->x)*(r1->y));
}

double rectangle_perimeter (Rectangle r1){

    return((r1->x*2)+(r1->y*2));
}

void rect_print(Rectangle r1){

	printf("{x=%.2f; y=%.2f}",r1->x,r1->y);

}