/**
 * Exercise 3 - Fun with Strings
 *
 * Please read the comments below carefully, they describe your task in detail.
 * Any clarifications and corrections will be posted to Piazza so please keep
 * an eye on the forum!
 *
 * Starter code: Mustafa Quraish & Charles Xu, 2022
 */

#include <stdio.h>
// NO additional imports allowed. You *can* make helper functions, and in fact I strongly
// encourage doing so to make your life easier.

// Maximum length of a string
#define MAX_STRING_LEN 1024

//-----------------------------------------------------------------------------
int strlen(char str[]){
  int i=0;
  do{
    i++;
  }while(str[i]!=0);
  return i;
}
int indexOf(char str[], char a[]){
  int alen= strlen(a);
  int slen = strlen(str);
  int i,j;
  for (i =0; i<slen; i++){
    if (str[i]==a[0]){
      for (j = 0; j<alen; j++){
        if (str[i+j]!=a[j]){
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
void replaceSubstring(char str[], char a[], char b[])
{
  /**
   * If `a` is a substring of `str`, then the first occurence of `a` in `str`
   * is replaced with `b`.
   *
   * For example:
   *
   *    char str[50] = "Hello World!";
   *    replaceSubstring(str, "llo W", "---");
   *    printf("%s\n", str);
   *
   * should print out "He---orld!"
   *
   * You may assume that `str[]`` has enough space to store the modified string.
   * Remember that all the strings here all null-terminated, and you must
   * also null-terminate the modified string.
   */
  int alen = strlen(a);
  int blen = strlen(b);
  int slen = strlen(str);
  int i = indexOf(str,a);
  char temp[1024]="temp";
  for (int j = 0; j <= slen-1; j++){
    temp[j] = str[j];
  }
  if (i!=-1){
    for (int k= 0; k<blen; k++){
      str [i+k]=b[k];
    }
    //printf("%s, %d\n",temp,blen+1);
    for (int l=i;l<slen-i;l++){
      str[l+blen]=temp[l+alen];
    }
    //printf("%s\n",str);
  }
  return; // Not returning anything. `str` is modified directly.
}

void changeSubstringCase(char str[], char a[])
{
  /**
   * If `a` is a substring of `str`, then change the case (capitalization) of
   * the first occurence of the corresponding substring in `str`. Special
   * characters (' ', '.', ...) do not need to be handled. You should only
   * change the letters.
   *
   * For example:
   *
   *    char str[100] = "This IS a SENTence WITH BAd CAPITalizaTION";
   *    changeSubstringCase(str, "IS a SENTence WI");
   *    printf("%s\n", str);
   *
   * should print out "This is A sentENCE wiTH BAd CAPITalizaTION".
   */
  int alen = strlen(a);
  int b = indexOf(str,a);
  if (b != -1){
  for (int i = b; i<alen+b; i++){
    if (str[i]>64 && str[i]<123 && !(str[i]>91 && str[i]<96)){
    if (str[i]>'Z'){
      str[i]=str[i]-32;
    }
    else{
      str[i]=str[i]+32;
    }
  }
  }
}
  return; // Not returning anything. `str` is modified directly.
}

//-----------------------------------------------------------------------------

// Do not change the lines above and below the main function. These
// are here to ensure that the main() function defined here does not
// Conflict with the automarker when testing your code. Changing them
// will result in a 0 for this exercise. You are free to change anything
// inside the main() function itself.
#ifndef __testing__
int main()
{
  char str[MAX_STRING_LEN] = "CSCA48 Exercise 3";
  // This should replace the substring:
  replaceSubstring(str, "A48 Ex", "A48 sUMMER Ex");

  // This should NOT replace anything, since some of the letters
  // in `a` have a different capitalization than in the string, so it is
  // NOT a valid substring.
  replaceSubstring(str, "summer", "Winter");

  // This should change the capitalization of the substring:
  changeSubstringCase(str, "sUMMER");

  // This should NOT change the capitalization, since the corresponding letters
  // in `a` are lowercase, and it is not a valid substring.
  changeSubstringCase(str, "csca48");

  printf("Expected result: \"CSCA48 Summer Exercise 3\"\n");
  printf("Your solution: \"%s\"\n", str);

  return 0;
}
#endif
