#include <stdlib.h>
#include <string.h>

//selection sort
/*
find the minimum and swap with the nth index where n stqrts from
the first index and continues down the array
you may skip the last step because last index will always be maximum
*/
void main(){
  int i,j,n,temp=0,index=0;
  scanf("%d",&n);

  int a[n];
  for (i=0;i<n;i++){

  }
}
//insertion sort
/*
start at the second index and find the smallest between the first
2 indexes, then you increase the range and find the smallest value
and insert it in the beginning of the index or where ever it fits
*/
/*
note the complexity of a function O(log(n)) is the lowest and most\
desirable complexity avoid exponential or O*n! complexity

time complexity O(1)
constant, will always have same time regardless of array size

O(n)
linear number of steps/loops is depenent on size of array where
number of loops is equal to nubmer of values in array
  -> O(2n) is still considered as O(n)
  -> when n is large all coeffecients are neglagable

O(n^a)
Squared, this is typical of nested loop algorithms
  -> where a represents the level of nested loops
  -> when there is more than 2ns with diffrent power a is
     the one with the highest power

o(2^n)
Exponential, typically avoid these types of algorithms, would
be considered a poor algorithm

O(loga(n))
logarithmic algorithm, typically a while loop with a division
where n/a is part of the loop
  Ex.
  while(n<0){
  n=n/2;
  }

Assignment:
prove time complexity of:
  *Merge sort
  *Quick sort
  *Bucket sort
*/
void printArray(int array[]){
  do{
    printf("%d",array[i]);
  }while (array[i]!=NULL);
}
void BucketSort(int array[]){

  return;
}
void partition(int list[],int low,int high){
    int i = low;
    int pivot = list[high];

    for (int j=low;j<high;j++){
        if (list[j] <= pivot){
            list[i], list[j] =  list[j], list[i];
            i++;
        }
    }
    list[i], list[high] = list[high] ,list[i]

    return i;

}
void QuickSort(int list[],int low, int high){
  if (low < high){
        partition_index = partition(list, low, high);
        quick_sort(list, low, partition_index - 1);
        quick_sort(list, partition_index + 1, high);
  }
  return;
}
void MergeSort(int array[]){
  return;
}

int main(){
  int array[]={5,4,3,9,16,20,11,15};
  BucketSort(array,3,20);
  printArray(array);
  return 1;
}
