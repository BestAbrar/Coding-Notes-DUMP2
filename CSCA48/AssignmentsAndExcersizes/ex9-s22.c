/**
 * Exercise 9 - Morse Code
 *
 * Please read the comments below carefully, they describe your task in detail.
 * Any clarifications and corrections will be posted to Piazza so please keep
 * an eye on the forum!
 *
 * Starter code:  Angela Zavaleta, 2020
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1024

/**
 * Let's define a Morse Node which will contain a letter
 * and a right and a left pointer to another Node
 */
typedef struct morse_node_struct
{
  char letter;
  struct morse_node_struct *left;
  struct morse_node_struct *right;
} MorseNode;

/**
 * This function will initialize a Morse Node given a letter.
 *
 * ----------------------------------------------------------------------------
 * --- This function is already implemented for you. Nothing to change here ---
 * ----------------------------------------------------------------------------
 */

MorseNode *new_morse_node(char letter)
{

  // Create the pointer to a new node and allocate memory
  MorseNode *new_node = NULL;
  new_node = (MorseNode *)calloc(1, sizeof(MorseNode));

  // Initialize the node
  new_node->letter = letter;
  new_node->left = NULL;
  new_node->right = NULL;

  return new_node;
}

/**
 * This function will take the root of the Morse tree, a letter
 * and the morse code related to that letter.
 *
 * Insert the letter on the Morse tree based on its morse code.
 * Remember that the root node is empty (doesn't have any letter),
 * and that a dot indicates left and a dash indicates right.
 *
 * Note: All nodes may not have an associated character (for eg: the root).
 *       for these, set the associated character to '\0'.
 *
 * Note: Inserting a node for a letter may require you to create multiple
 *       other nodes or not create any and just update an existing one. Make
 *       sure you don't break any existing nodes for other letters!
 */
void insert_node(MorseNode *root, char *morse, char letter)
{
  if (*(morse)!='-'&&*(morse)!='.'){
    root->letter=letter;
    return;
  }
  if(*morse=='.'){
    if (root->left==NULL)
      root->left=new_morse_node('\0');
    insert_node(root->left,morse+1,letter);
  }
  if(*morse=='-'){
    if (root->right==NULL)
      root->right=new_morse_node('\0');
    insert_node(root->right,morse+1,letter);
  }
}

/**
 * This function will create a tree given an array of an alphabet and the
 * morse code relative to the alphabet.
 *
 * Use the insertNode function to create the Morse Tree and return the root.
 *
 * ----------------------------------------------------------------------------
 * --- This function is already implemented for you. Nothing to change here ---
 * ----------------------------------------------------------------------------
 */
MorseNode *make_tree(char **morse_code, char *abc)
{

  // Create a node that stores the char 0, which is an empty char
  MorseNode *root = new_morse_node(0);

  // The alphabet has 26 letters so we need to loop this many times
  // and insert each letter in the Morse Tree
  for (int i = 0; i < 26; i++)
  {
    insert_node(root, morse_code[i], abc[i]);
  }
  return root;
}

char getLetter(MorseNode *root, char *morse)
{
  if (*(morse)!='-'&&*(morse)!='.'){
    //printf("%c,%c\n",*morse,root->letter);
    if(*morse==' '){
      return root->letter;
    }
    if(*morse=='/'){
      return ' ';
    }
  }
    if(*morse=='.'){
      return getLetter(root->left,morse+1);
    }
    if(*morse=='-'){
      return getLetter(root->right,morse+1);
    }
  return root->letter;
}
/**
 * This function will decode the morse code and store it in the text variable.
 *
 * Remember than the morse code can only include dots, dashes, spaces (' ') and
 * slashes ('/'). Spaces indicate the separation of letters and the slashes
 * indicate the separation of words.
 */
 void decode(MorseNode *root, char *morse, char *text)
 {
   while(*morse!='\0'){
     *text=getLetter(root,morse);
     text++;
     while(*morse=='.'||*morse=='-'||*morse=='/'){
      morse++;
     }
     if(*morse!='\0')
     morse++;
   }
   *text='\0';
   return;
 }

 /**
  * This function will encode the text and store it in the morse variable.
  * This function also takes the morse_code array where you can get the morse
  * code related to each alphabet letter.
  *
  * Remember than the morse code can only include dots, dashes, spaces (' ')
  * and slashes ('/'). Spaces indicate the separation of letters and the
  * slashes indicate the separation of words.
  *
  * Note that it is easier here to just use the array containing the morse
  * code values, since we can get the correct code for every letter very fast
  * (figure out how!). The binary tree that was constructed is useful in
  * decoding the text!
  */
 void encode(char **morse_code, char *text, char *morse)
 {
   int index,i;
   while(*text!='\0'){
     if(*text==' '){
       *morse='/';
       morse=morse+1;
       *morse=' ';
       morse=morse+1;
     }else{
     index = *text-65;
     for(i = 0;i<strlen(*(morse_code+index));i++){
       *(morse+i)=*(*(morse_code+index)+i);
     }
     morse=morse+i;
     *morse=' ';
     morse=morse+1;
     }
     text++;
   }
   *(morse-1)='\0';
   return; // TODO: update `morse` to have the encoded string.
 }

 /*****************************************************************************/

 #ifndef __testing__ // You know the drill, don't remove this

 int main()
 {
   // Create some space to store the morse and text
   char morse[MAX_STRING_LENGTH];
   char text[MAX_STRING_LENGTH];

   // Set up the alphabet, char array with null terminator at the end
   char abc[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

   // Set up the morse code relative to the alphabet
   char *morse_code[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
                           "....", "..", ".---", "-.-", ".-..", "--", "-.",
                           "---", ".--.", "--.-", ".-.", "...", "-", "..-",
                           "...-", ".--", "-..-", "-.--", "--.."};

   // Create the Morse Tree
   MorseNode *tree = make_tree(morse_code, abc);

   // Encode "HELLO WORLD"
   encode(morse_code, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", morse);
   printf("yours: \"%s\"\n", morse);
   decode(tree, morse, text);
   printf("yours: \"%s\"\n", text);
   /*if (strcmp(morse, ".... . .-.. .-.. --- / .-- --- .-. .-.. -..") != 0)
   {
     printf("- encode() function result not correct:\n");
     printf("  expected: \".... . .-.. .-.. --- / .-- --- .-. .-.. -..\"\n");
     printf("     yours: \"%s\"\n", morse);
   }
   else
   {
     printf("- encode() passed the test.\n");
   }

   // Decode ".... . .-.. .-.. --- / .-- --- .-. .-.. -.."
   decode(tree, ".... . .-.. .-.. --- / .-- --- .-. .-.. -..", text);
   if (strcmp(text, "HELLO WORLD") != 0)
   {
     printf("- decode() function result not correct:\n");
     printf("  expected: \"HELLO WORLD\"\n");
     printf("     yours: \"%s\"\n", text);
   }
   else
   {
     printf("- decode() passed the test.\n");
   }
   */
   // TODO: Add tests to make sure your tree has the correct structure, we will
   //       test this when automarking, not just your encode() and decode().

   return 0;
 }

 #endif
