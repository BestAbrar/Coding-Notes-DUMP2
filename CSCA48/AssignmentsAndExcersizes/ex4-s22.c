/**
 * Exercise 4 - Fun with Pointers
 *
 * Please read the comments below carefully, they describe your task in detail.
 * Any clarifications and corrections will be posted to Piazza so please keep
 * an eye on the forum!
 *
 * NOTE: You should NOT use array notation inside your functions. Use only
 *       pointer notation for any code that you write. Any array notation
 *       used outside of the main function will result in a 0. This includes
 *       making a new array of characters.
 * EG:   char x[1024]; <--- [] used to create a new array is prohibited
 * EG:   char y = x[0]; <--- [] used to access an array is prohibited
 *
 * Starter code:  Mustafa Quraish, Charles Xu, 2022
 */

#include <stdio.h>
#include <stdlib.h>
// NO additional imports allowed. You *can* make helper functions if you wish.

#define MAX_STRING_LEN 1024
int strlen(char str[]){
  char *p = NULL;
  p = str;
  int i=0;
  do{
    i++;
  }while(*(p+i)!=0);
  return i;
}
int indexOf(char str[], char a[]){
  int alen= strlen(a);
  int slen = strlen(str);
  int i,j;
  char *p1=NULL;
  char *p2=NULL;
  p1 = str;
  p2 = a;
  for (i =0; i<slen; i++){
    if (*(p1+i)==*(p2)){
      for (j = 0; j<alen; j++){
        if (*(p1+i+j)!=*(p2+j)){
          break;
        }
      }
      if (i+j==i+alen){
        return i;
      }
    }
  }
  return -1;
}
void copystr(char str[], char copy[]){
  int slen = strlen(str);
  char *p1=NULL;
  char *p2=NULL;
  p1 = str;
  p2 = copy;
  for (int j = 0; j <= slen-1; j++){
    *(p2+j) = *(p1+j);
  }
}
void indexDel(char str[], int i){
  int j = 0;
  char *p=NULL;
  p = str;
  do {
    *(p+i+j)=*(p+(i+j)+1);
    j++;
  } while(*(p+(i+j)+1)!=0);
  *(p+(i+j))=0;
}
char *find_last_substring(char *str, char *a){
  /**
   * Given a string `str` and another string `a`, return a pointer to the start
   * of the *LAST* occurrence of `a` in `str`. (Unlike ex3, where you had to
   * find the FIRST occurrence).
   *
   * For instance, if we had:                       (here)
   *                                                  V
   *      char str[MAX_STRING_LEN] = "Hello everyone, Hello world!"
   *      char *res = find_last_substring(str, "Hello");
   *
   * then, we would except `res` to be a pointer to the character marked above.
   * In particular, since the second "Hello" is at index 16, we should get
   * the following:
   *
   *      res - str == 16;      (This is pointer arithmetic)
   *
   * If `a` is not a valid substring of `str`. return NULL.
   */
  int i,temp;
  char tempstr[MAX_STRING_LEN];
  char *p1 = NULL;
  char *p2 = NULL;
  p1 = str;
  p2 = tempstr;
  copystr(str,tempstr);
  temp=-1;
  do{
  i = indexOf(tempstr,a);
    //printf("%s\n", tempstr);
    if (i != -1){
      temp = i;
      *(p2+i)=255;
    }
  }while (i != -1);
  if (temp!=-1){return (p1+temp);}
  return NULL;// Replace with correct return
}

void split_vowels(char *str, char *vowels)
{
  /**
   * Move all of the vowels from `str` (in the order of appearance) to the
   * string `vowels`. (ie, after the function call `str` should not have any
   * vowels in it). You may assume there is enough space allocated in `vowels`.
   *
   * Look at the test case below for an example.
   */
  int slen,vlen,i,j,k,f;
  char v[MAX_STRING_LEN]="aeiouAEIOU";
  char *p1=NULL;
  char *p2=NULL;
  char *p3=NULL;
  p1 = str;
  p2 = v;
  p3 = vowels;
  slen = strlen(str);
  vlen = strlen(v);
  k=0;
  f=0;
  for (i = 0; i<slen; i++){
    for ( j= 0; j<vlen; j++){
      if (*(p1+i)==*(p2+j)){
        f=1;
        break;
      }
    }
    if (f){
      *(p3+k)=*(p1+i);
      indexDel(str,i);
      f=0;
      k++;
      i--;
    }
  }
  *(p3+k)=0;
  return; // Not returning anything. `str` and `vowels` modified directly.
}

// ----------------------------------------------------------------------------

// Do not change the lines above and below the main function. These
// are here to ensure that the main() function defined here does not
// Conflict with the automarker when testing your code. Changing them
// will result in a 0 for this exercise. You are free to change anything
// inside the main() function itself.
#ifndef __testing__
int main()
{
  char my_str[MAX_STRING_LEN] = "many  any people have  any  any hobbies";
  char *res = find_last_substring(my_str, " any");
  if (res - my_str == 27)
  {
    printf("- find_last_substring() returned the correct result!\n");
  }
  else
  {
    printf("! find_last_substring() did not work properly.\n");
  }

  printf("----------------------------------------------------------------\n");

  char str[MAX_STRING_LEN] = "This sentence has many vowels! AEIOU";
  char vowels[MAX_STRING_LEN];
  split_vowels(str, vowels);

  printf("(Expected Result) str: \"Ths sntnc hs mny vwls! \", "
         "vowels: \"ieeeaaoeAEIOU\"\n");
  printf("(Your Solution) str: \"%s\", vowels: \"%s\"\n", str, vowels);
}
#endif
