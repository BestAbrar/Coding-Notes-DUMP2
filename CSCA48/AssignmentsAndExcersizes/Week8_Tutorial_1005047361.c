#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//selection sort
/*
find the minimum and swap with the nth index where n stqrts from
the first index and continues down the array
you may skip the last step because last index will always be maximum
*/

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
  *Merge sort -> complexity O(nlog(n)) for loop (merge) inside recursive while loop (MergeSort)
  *Quick sort -> complexity O(n^2) for loop (partition) inside recursive for loop (QuickSort)
  *Bucket sort-> complexity at least O(n^2) depending on the sorting algorithm used in each bucket * for loop in BucketSort
*/
#define ARRAY_LEN 8

void printArray(int array[]){
  for (int i=0;i<ARRAY_LEN;i++){
    printf("%d,",array[i]);
  }
  printf("\n");
  return;
}
void BucketSort(int array[]){
  int temp1[ARRAY_LEN],temp2[ARRAY_LEN],temp3[ARRAY_LEN],temp4[ARRAY_LEN];//buckets
  int *p1,*p2,*p3,*p4;
  p1=temp1;p2=temp2;p3=temp3;p4=temp4;
  for(int i=0;i<ARRAY_LEN;i++){
    temp1[i]=-1;
    temp2[i]=-1;
    temp3[i]=-1;
    temp4[i]=-1;
    if(array[i]<10 && array[i]>=0){
      *p1=array[i];
      p1=p1+1;
    }
    if(array[i]<20 && array[i]>=10){
      *p2=array[i];
      p2=p2+1;
    }
    if(array[i]<30 && array[i]>=20){
      *p3=array[i];
      p3=p3+1;
    }
    if(array[i]<40 && array[i]>=30){
      *p4=array[i];
      p4=p4+1;
    }
  }
  int i=0,a=0;
  while(temp1[a]!=-1){
    array[i]=temp1[a];
    i++;
    a++;
  }
  a=0;
  while(temp2[a]!=-1){
    array[i]=temp2[a];
    i++;
    a++;
  }
  a=0;
  while(temp3[a]!=-1){
    array[i]=temp3[a];
    i++;
    a++;
  }
  a=0;
  while(temp4[a]!=-1){
    array[i]=temp4[a];
    i++;
    a++;
  }
  return;
}

int partition(int array[], int low, int high) {
  int pivot = array[high], i = (low - 1),temp;
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      i++;
      temp=array[i];array[i]=array[j];array[j]=temp;
    }
  }
  temp=array[i + 1];array[i + 1]=array[high];array[high]=temp;
  return (i + 1);
}
void QuickSort(int array[], int low, int high){
  if (low < high) {
    int pi = partition(array, low, high);
    QuickSort(array, low, pi - 1);
    QuickSort(array, pi + 1, high);
    }
  return;
}
void merge(int arr[], int p, int q, int r) {
  int n1 = q - p + 1;
  int n2 = r - q;
  int L[n1], M[n2];
  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];
  int i=0, j=0, k=p;
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }
  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}
void MergeSort(int array[], int l, int r){
  if (l < r) {
    int m = l + (r - l) / 2;
    MergeSort(array, l, m);
    MergeSort(array, m + 1, r);
    merge(array, l, m, r);
  }
  return;
}

int main(){
  int array[ARRAY_LEN]={5,3,9,16,20,11,4,15};
  printArray(array);
  BucketSort(array);
  printArray(array);
  int array2[ARRAY_LEN]={5,3,9,16,20,11,4,15};
  int n = sizeof(array2) / sizeof(array2[0]);
  QuickSort(array2,0,n-1);
  printArray(array2);
  int array3[ARRAY_LEN]={5,3,9,16,20,11,4,15};
  n = sizeof(array3) / sizeof(array3[0]);
  MergeSort(array3, 0, n - 1);
  printArray(array2);
  return 1;
}
