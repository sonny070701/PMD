#include <stdio.h>

int main () {

char matrix[2][3] = {};
char*ptr = &matrix[2][3];
char **ptr2 = &ptr; 
ptr = "a";
ptr2++;
*ptr2 = "b";
ptr2++;

}