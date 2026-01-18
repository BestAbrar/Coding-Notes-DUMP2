#include <stdio.h>

int excersize1(){
  char a;
  int captial=1;
  for (a='A'; a<91; a=a+2 ){
  //printf ("%c\n",a);
  if (captial){
    printf ("%c\n",a);
    captial = 0;
  }
  else {
    printf ("%c\n",a+32);
    captial = 1;
  }
  }
  return 0;
}
int main (){

  unsigned int var1 = 4294967295;
  unsigned int var2 = 4294967296;
  int var3 = 2147483648;
  unsigned char j = 255;
  j = j +70;
  //range of signed char -128 to 127
  //char are treated like intigers, only need to be concerned about overflow
  char c = 128;
  //overflow of characters
  char chr;// default is always signed
  //for (chr = 'A'; chr < 255; chr++){// results in infinte loop, due to truncation
  //  printf("\n",chr);
  //}
  unsigned ctr1; // note you cant do <= due to truncation which results in intinite loop
  for (ctr1 = 0; ctr1 <255; ctr1++){
    //printf ("%c\n",ctr1);
  }
  excersize1();
  // implicit and explicit casting
  //implicit int ---> float
  int test = 20;
  printf ("%f\n", test);
  //explicit casting
  float test1 = 20.1;
  printf ("%d\n", (int)test1);
  //never rely on implicit casting, note the type casting

  //operators
  //+,-,/,*,%...
  //rational operators --> return true(1) or flase(0)
  //==,!=,<=,>=,<,>
  int a = 5;
  if (a){// if condition != 0 it will evaluate as true
    printf("%d\n", a);
  }
  while(a){// will run loop aslong as condition is true
    printf("%d\n", a);
    break;
  }
  do{
    if (a){
      break;//breaks loop
    }
  }while(a);// will run the program atleast once
  return 0;
}
// excersize
// A
// c
// E
// g
// I
// k
// M
// o
// ...
