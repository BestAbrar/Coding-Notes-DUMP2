#include <stdio.h>
/*
Tail recursion- is only considered when the return statment is ONLY a call to itself, no operators, and no
other return statments are present
base case\Recursion case-> method calls itself
break the problem into smaller cases and solve each case individually
*/
int largest (int arr[], int n){
  if(arr[n-1]>arr[n-2]&&n!=1)
    largest(arr,n-1);
  return arr[n-1];
}
int factorial_recursion(int n){
  if (n==1||n==0){
    return 1;
  }
  return n * factorial_recursion(n-1);
}
int main(){
  int test = factorial_recursion(5);
  printf("%d",test);
}
