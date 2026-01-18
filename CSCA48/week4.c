#include <stdio.h>
#define MAX_LENGTH 100 //macros, determine the max length of a array
//macros can be used as small functions\
//can't change the value of macros
//can be used multiple times in the same code

int main(){
  int arr[MAX_LENGTH];
  // * = value of, detefence operator
  // & = address of operator
  int x = 5, int *px = x;
  // above line is equivlent to
  // int x;
  // int *px;
  // x=5;
  // px = &x;
  // we use %p to print the pointer, cant do %d would output a un-
  // specified intiger value
  *px = 10; // changes the value of px from 5 to 10
  int px1;
  //px1=6;// gives a segmentation fault because the pointer hasn't been assigned
        // to an address
  float y = 5
  float *py = &y;
  *py = y *5;// changes the value of the variable the pointer is assigned to
  printf("Value of Y is: %f\n", y);
  return 0;

  y = 10;
  float *pz, *qz;
  pz = &y;
  qz = pz; // assigns the pointer qz to the address variable assigned to pz
  printf("%f,%f",pz,qz);
}
