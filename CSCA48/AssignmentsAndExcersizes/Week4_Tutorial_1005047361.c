//Array basics
//note that first element of array has index 0
//note for strings you must give an extra space for the null character /o
// this is the only difference between array and strings

//2d arrays are defined by two square bracket pairs "[][]"
//can be described as rows and columns, it can also be interperated var
//linear indexing

int Array1D(){
  int nums[5];
  printf("\n Run-time Initialization Example:\n");
  printf("\n Enter array elements: ");
  for (int i = 0; i<5; i++){
    scanf("%d",&nums[i]);
  }
  pirntf("Accessing array elemnts after dynamic Initilzation: ");
  for (int i = 0; i<5;i++){
    printf("%d",nums[i]);
  }
  return 0;
}
int Array2D(){
  float a[2][2],b[2][2],result[2][2];
  printf("Enter elements of 1st matrix\n");
  for(int i = 0;i<2;i++){
    for (int j = 0;i<2;j++){
      printf("Enter a%d%d%:",a,i+1,j+1);
    }
  }
}
//Matrix Multiplication
//for (int i = 0; i<r1;++i){
// for (int j=0; j<c2,++j){
//   for (int k = 0; k<c1; ++k){
//     result[i][j]+=first[i][k]*second[k][j];
//   }
// }
// }
