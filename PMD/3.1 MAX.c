//sonny ceja

#define R 3
#define C 3

#include <stdio.h> 

int MAX(int *m) {

  int matriz[R][C] = { { 1, 2, 3}, { -1, -2, 0 }, {2, 4, -3 }};
  int *M = &matriz[0][0];
  
  for (int y = 0; y < R; y++) {
    for (int x = 0; x < C; x++) {
      int l = *(*(matriz+x)+y);
      if (l > *M) *M = l;
      }
  }
   printf("max: %d\n", *M);
  return 0;
}

int main(){
  int m = MAX(&m);
}