int main (){
  int i,j;
  float f, k;
  char m,n;

  printf("%d,\n",i);
  printf("%d,\n",j);
  printf("%f,\n",f);
  printf("%f,\n",k);
  printf("%c,\n",m);
  printf("%c,\n",n);
  //cant rely on undeclared values

  int x = 3;
  int y = x;
  char z;
  y = (x==3) * (y == 3) * 3;
  z = y + 34.1232;
  printf("%d",x);
  printf("%d",y);
  printf("%c",z);// can't make specifier anything beyond %d or %c, ie, cant make %f

  int var;
  var = 4/9;
  printf("%d",var);// prints 0
  int var1;
  var1 = 4/9;
  printf("%.2f",var1);// prints 0.0, type cast first then print format
  int var2;
  var2 = 4.0/9.0;
  printf("%.2f",var2);// prints 0.44

  {
    int var = 12;// this is exicutable this variable is outside of the scope of the
                //rest of them function
                //scope: the lifetime of a variable, where it is defined
  }
  //arrays
  //cannot extend
  //same data type
  //no warning if you access anything that is not in the arrays
  int arr[5] = {1,2,3,4,5};
  int arr1[] = {1,2,3,4,5};
  int arr2[2];
  arr2[1] = 2;
  for (int i = 0; i<5; i++){
    arr2[i] = i+1;
  }
  int arr3 [10] = {0};
  // write a program to find out if a digit has been repeated more than once

}
