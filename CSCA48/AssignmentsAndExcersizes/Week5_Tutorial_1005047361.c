#include <stdio.h>
#include <string.h>

struct Books{
  char title [50];
  char author [50];
  char subject [100];
  int book_id;
};
void printBook(struct Books *book){
  printf("");
}
void printArray(char array[8][10]){
  int i=0,j=0;
  while (i<8){
    while (j<10){
      printf("%c, ",array[i][j]);
      j++;
    }
    printf("\n");
    i++;
    j=0;
  }

}
int []findString(char array[8][10],char str[]){
  int i=0,j=0;
  int found[];
  int counter=0;
  char line[10];
  char line1[10];
  while (i<8){
    while (j<10){
      row[j]=array[i][j];
      j++;
    }
    while(j>=0){
      line1[8-j]=row[j];
      j--;
    }
    i++;
    if (strstr(line,str)!=MULL){
      found[counter]=7;
      counter++;
    }
    if (strstr(line1,str)!=MULL){
      found[counter]=3;
      counter++;
    }
  }
  while (j<10){
    while (i<8){
      line[i]=array[i][j];
      i++;
    }
    while(i>=0){
      line1[10-i]=line[i];
      i--;
    }
    line
    j++;
    if (strstr(line,str)!=MULL){
      found[counter]=5;
      counter
    }
    if (strstr(line1,str)!=MULL){
      found[counter]=1;
      counter
    }
  }
  return found;
}
int main(){
  struct Books Book1;
  struct Books Book2;
  char array[8][10]={{'C','S','C','A','4','8','A','B','C','D'},
                  {'E','C','E','1','1','0','E','F','G','H'},
                  {'S','E','C','I','C','1','2','Z','Y','X'},
                  {'U','C','S','J','Y','S','W','A','L','W'},
                  {'M','E','C','K','E','T','C','E','E','V'},
                  {'M','3','A','L','A','G','O','A',' ','U'},
                  {'E','2','4','M','R','U','N','P','4','T'},
                  {'R','0','8','N','O','P','Q','R','S','8'}};
  printArray(array);
  return 1;
}
