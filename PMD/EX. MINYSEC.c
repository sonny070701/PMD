

#include <stdio.h>

void addSecond (short *minutes, short *seconds){
  if (*seconds>=59){
    minutes++;
    *seconds=0;
  }
  else{
    seconds++;
  }
}

int main(){

short min = 15, sec = 59;
addSecond(&min , &sec); 
}