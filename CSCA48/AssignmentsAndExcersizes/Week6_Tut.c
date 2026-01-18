#include <stidio.h>
#include <stdlib.h>

struct Node{
  int data;
  struct Node* link;
};
int main(){
  struct Node* head = NULL;
  head = (struct Node*)malloc(sizeof(struct Node));
  head->data = 1;
  head -> link = NULL;

  struct Node* current = (struct Node*)malloc(sizeof(struct Node));
  current -> data = 4;
  current -> link = NULL;
  head-> link = current;

  current = (struct Node*)malloc(sizeof(struct Node));
  current -> data = 7;
  current ->link = current;
 }
//search Node
int searchNode(struct Node** head_ref, int key){//must use double pointer because of using a pointer as a pointer
   while (current != NULL){
     if (current != NULL){
       if (current -> data == key) return 1;
        current = current -> link;
     }
     return 0;
   }
}
void sotrLinkedList(struct Node** head_ref){
  struct Node *current = *head_ref,*index = NULL;
  int temp;
  if (head_ref == NULL){
    return;
  }else{
    while (current != NULL){
      if (curent ->data < index ->data){
        temp = current -> data;
        current->link = current;
      }
    }
  }
}
