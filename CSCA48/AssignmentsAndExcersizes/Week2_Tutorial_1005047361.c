#include <stdio.h>
#include <math.h>

int factorial (int x){
  int i,fac =1;
  for (i=1; i<=x;i++){
    fac=fac*i;
  }
  return fac;
}

int example1(){
  float x,deg,sum = 0;
  int i, limit, sign =1;

  printf("Enter the value of x of sinx series: ");
  scanf("%f",&x);
  printf("enter the limit upto which you want to expand the series: ");
  scanf("%d",&limit);
  deg = x;
  x = x*(3.1415/180);
  for (int i =0; i<=limit; i++){
    sum = sum + pow(-1,i)*pow(x,(2*i+1))/factorial(2*i+1);
  }
  printf("sin(%f) to %.1d intervals is %f" ,deg, limit, sum);
  return 0;
}
// #define f(x)=1/(1+pow(x,2))
int example2(){
  float lower, upper, integration = 0.0;
  float stepSize, k;
  int i, subinterval;
  printf("Enter lower limit and upper limit of integration: ");
  scanf("%f%f", &lower, &upper);
  printf("Enter number of sub intervals: ");
  scanf("%d",&subinterval);
  float domain = upper-lower;
  stepSize = domain/subinterval;
  for(int i =0; i<= subinterval; i++){
  }
  return -1;
}
int main(){
  example1();
  return 0;
}
