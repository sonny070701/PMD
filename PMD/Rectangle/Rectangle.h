//Sonny Ceja

#ifndef Rectangle_H_
#define Rectangle_H_

struct StructRec {
	double x, y;
};

typedef struct StructRec* Rectangle;

Rectangle new_rectangle(double x, double y);

void rect_destroy (Rectangle r1);

void rectangle_set_base (Rectangle r1, double x);
void rectangle_set_height (Rectangle r1, double y);

double rectangle_base (Rectangle r1);
double rectangle_height (Rectangle r1);

double rectangle_area (Rectangle r1);
double rectangle_perimeter (Rectangle r1);

void rect_print(Rectangle r1);

#endif /* Rectangle_H_ */
