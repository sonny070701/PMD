#include <stdio.h>

int main(){

int arr[3] = {};
int *p1 = arr;
for (int i=1; i<4; i++){
  *p1=i;
  p1++;
}
printf("lugar 1: %d, lugar 2: %d y lugar 3: %d\n ", *p1, *p1+1, *p1+2);
}