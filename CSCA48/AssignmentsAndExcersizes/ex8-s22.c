/**
 * CSCA48 Summer 2020
 * Exercise 8 - More Linked List Fun
 *
 * Please read the comments below carefully, they describe your task in detail.
 * Any clarifications and corrections will be posted to Piazza so please keep
 * an eye on the forum!
 *
 * Starter code: Charles Xu, 2022
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// You may NOT modify this struct in any way.
// This includes adding new variables.
typedef struct NumNode
{
    int val;
    struct NumNode *next;
} NumNode;

/**
 * Populates a NumNode linked list based on a given array of integer values.
 * Maintains the same order as the array.
 *
 * Returns the head of a new linked list.
 * If the array of values is negative or empty (count <= 0), return an empty list.
 */
void printArray(int array[],int len){
  int j =0;
  while(j<len){
    printf("%d,",array[j]);
    j++;
  }
  printf("\n");
}
void printLinkedList(NumNode *head){
NumNode *p;
p=head;
  while(p!=NULL){
    printf("%d,",p->val);
    p=p->next;
  }
  printf("\n");
}
NumNode *create_num_node(int val){
  NumNode *NewNumNode =(NumNode *)calloc(1, sizeof(NumNode));
  NewNumNode->val = val;
  NewNumNode->next = NULL;
  return NewNumNode;
}
NumNode *create_num_list(int *vals, int count)
{
    NumNode *head=NULL,*p=NULL;
    if (count<=0){
      return head;
    }
    head = create_num_node(*vals);
    p=head;
    for (int i = 1; i<count;i++){
      p->next=create_num_node(*(vals+i));
      p = p->next;
    }
    printf("\n");

    return head;
}

/**
 * Sorts a NumNode linked list in increasing order.
 *
 * NOTE:
 *      [-10] -> [3] -> [5] -> [5] -> [30]
 *
 * NOTE:
 *      To sort, you can use any algorithm you wish as
 *      long as it runs in O(N^2) or faster.
 *
 * Returns the head of the new linked list.
 * Similaritily, if the given list is empty, return NULL.
 */
NumNode *sort_num_list(NumNode *list)
{
    NumNode *p=NULL;
    if (list==NULL){
      return p;
    }
    p=list;
    int temp;
    while (p->next!=NULL){//bubble sort
    if (p->val>p->next->val){
      temp=p->val;p->val=p->next->val;p->next->val=temp;
      sort_num_list(list);
    }
    p=p->next;
  }
    return list;
}

void delete_num_list(NumNode *head)
{
    if (head == NULL)
    {
        return;
    }

    if (head->next != NULL)
    {
        delete_num_list(head->next);
    }

    free(head);
}

bool check_num_list_order(NumNode *list, int *vals, int count)
{
    int idx = 0;

    while (count > 0)
    {
        if (list == NULL) // reached end of list, but not end of array
        {
            return false;
        }

        if (list->val != vals[idx++]) // list and array vals do not match
        {
            return false;
        }

        list = list->next;
        count--;
    }

    if (list != NULL) // reached end of array, but not end of list
    {
        return false;
    }

    return true;
}

// Don't touch the line below or the automarker will fail to compile your program.
#ifndef __testing__

// Feel free to modify any part of the main function!
int main()
{
    int nums[10] = {-7, 9, -1, 10, -5, 3, 3, 10, 5, -30};
    NumNode *list = create_num_list(nums, 10);
    if (!check_num_list_order(list, nums, 10))
    {
        printf("The list returned by create_num_list() is not correct\n");
        return 1;
    }
    printArray(nums,10);
    NumNode *sorted_list = sort_num_list(list);
    printLinkedList(sorted_list);
    int expected_nums[10] = {-30, -7, -5, -1, 3, 3, 5, 9, 10, 10};
    if (!check_num_list_order(sorted_list, expected_nums, 10))
    {
        printf("The list returned by sort_num_list() is not correct\n");
        return 1;
    }

    delete_num_list(sorted_list);
    printf("End reached :)\n");
    return 0;
}

// You know the drill, don't remove this
#endif
