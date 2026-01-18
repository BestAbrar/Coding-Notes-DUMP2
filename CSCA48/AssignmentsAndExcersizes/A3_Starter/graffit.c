/**
 * CSC A48 - Intro to Computer Science II, Summer 2020
 *
 * Assignment 3 - Graffit
 *
 * Graphs &
 * Recursion
 * Assignment
 * For
 * Freshmen
 * In
 * Toronto
 *
 * (I am so proud of that initialism.)
 *
 * This is the program file where you will implement your solution for
 * assignment 3. Please make sure you read through this file carefully
 * and that you understand what is provided and what you need to complete.
 *
 * You will also need to have read the handout carefully.
 *
 * Parts where you have to implement functionality are clearly labeled TODO
 *
 * Be sure to test your work thoroughly, our testing will be extensive
 * and will check that your solution is *correct*, not only that it
 * provides functionality.
 *
 * (c) 2020 William Song, Mustafa Quraish
 **/

#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_STR_LEN 1024
#ifndef __testing
#define MAT_SIZE 3	// A small graph
#endif

typedef struct user_struct {
    char name[MAX_STR_LEN];
    struct friend_node_struct* friends;
    struct brand_node_struct* brands;
    bool visited;
} User;

typedef struct friend_node_struct {
    User* user;
    struct friend_node_struct* next;
} FriendNode;

typedef struct brand_node_struct {
    char brand_name[MAX_STR_LEN];
    struct brand_node_struct* next;
} BrandNode;

/** Note: We are reusing the FriendNode here as a Linked List for allUsers.
  * This is usually bad coding practice but it will allow us to reuse the
  * helper functions.
  **/
FriendNode* allUsers;

int brand_adjacency_matrix[MAT_SIZE][MAT_SIZE];
char brand_names[MAT_SIZE][MAX_STR_LEN];

/**
 * Checks if a user is inside a FriendNode LL.
 **/
bool in_friend_list(FriendNode *head, User *node) {
  for (FriendNode *cur = head; cur != NULL; cur = cur->next) {
    if (strcmp(cur->user->name, node->name) == 0) {
      return true;
    }
  }
  return false;
}

/**
 * Checks if a brand is inside a BrandNode LL.
 **/
bool in_brand_list(BrandNode *head, char *name) {
  for (BrandNode *cur = head; cur != NULL; cur = cur->next) {
    if (strcmp(cur->brand_name, name) == 0) {
      return true;
    }
  }
  return false;
}

/**
 * Inserts a User into a FriendNode LL in sorted position. If the user
 * already exists, nothing is done. Returns the new head of the LL.
 **/
FriendNode *insert_into_friend_list(FriendNode *head, User *node) {
  if (node == NULL){
    return head;
  }

  if (in_friend_list(head, node)) {
    printf("User already in list\n");
    return head;
  }
  FriendNode *fn = calloc(1, sizeof(FriendNode));
  fn->user = node;
  fn->next = NULL;

  if (head == NULL){
    return fn;
  }
  if (strcmp(head->user->name, node->name) > 0) {
    fn->next = head;
    return fn;
  }

  FriendNode *cur;
  for (cur = head; cur->next != NULL && strcmp(cur->next->user->name, node->name) < 0;
       cur = cur->next)
    ;
  fn->next = cur->next;
  cur->next = fn;
  return head;
}

/**
 * Inserts a brand into a BrandNode LL in sorted position. If the brand
 * already exists, nothing is done. Returns the new head of the LL.
 **/
BrandNode *insert_into_brand_list(BrandNode *head, char *node) {
  if (node == NULL) return head;

  if (in_brand_list(head, node)) {
    printf("Brand already in list\n");
    return head;
  }
  BrandNode *fn = calloc(1, sizeof(BrandNode));
  strcpy(fn->brand_name, node);
  fn->next = NULL;

  if (head == NULL)
    return fn;

  if (strcmp(head->brand_name, node) > 0) {
    fn->next = head;
    return fn;
  }

  BrandNode *cur;
  for (cur = head; cur->next != NULL && strcmp(cur->next->brand_name, node) < 0;
       cur = cur->next)
    ;
  fn->next = cur->next;
  cur->next = fn;
  return head;
}

/**
 * Deletes a User from FriendNode LL. If the user doesn't exist, nothing is
 * done. Returns the new head of the LL.
 **/
FriendNode *delete_from_friend_list(FriendNode *head, User *node) {
  if (node == NULL) return head;

  if (!in_friend_list(head, node)) {
    printf("User not in list\n");
    return head;
  }

  if (strcmp(head->user->name, node->name) == 0) {
    FriendNode *temp = head->next;
    free(head);
    return temp;
  }

  FriendNode *cur;
  for (cur = head; cur->next->user != node; cur = cur->next)
    ;

  FriendNode *temp = cur->next;
  cur->next = temp->next;
  free(temp);
  return head;
}

/**
 * Deletes a brand from BrandNode LL. If the user doesn't exist, nothing is
 * done. Returns the new head of the LL.
 **/
BrandNode *delete_from_brand_list(BrandNode *head, char *node) {
  if (node == NULL) return head;

  if (!in_brand_list(head, node)) {
    printf("Brand not in list\n");
    return head;
  }

  if (strcmp(head->brand_name, node) == 0) {
    BrandNode *temp = head->next;
    free(head);
    return temp;
  }

  BrandNode *cur;
  for (cur = head; strcmp(cur->next->brand_name, node) != 0; cur = cur->next)
    ;

  BrandNode *temp = cur->next;
  cur->next = temp->next;
  free(temp);
  return head;
}

/**
 * Prints out the user data.
 **/
void print_user_data(User *user) {
  printf("User name: %s\n", user->name);
  printf("Friends:\n");
  for (FriendNode *f = user->friends; f != NULL; f = f->next) {
    printf("   %s\n", f->user->name);
  }
  printf("Brands:\n");
  for (BrandNode *b = user->brands; b != NULL; b = b->next) {
    printf("   %s\n", b->brand_name);
  }
}

/**
 * Get the index into brand_names for the given brand name. If it doesn't
 * exist in the array, return -1
 **/
int get_brand_index(char *name) {
  for (int i = 0; i < MAT_SIZE; i++) {
    if (strcmp(brand_names[i], name) == 0) {
      return i;
    }
  }
  printf("brand '%s' not found\n", name);
  return -1; // Not found
}

/**
 * Print out brand name, index and similar brands.
 **/
void print_brand_data(char *brand_name) {
  int idx = get_brand_index(brand_name);
  if (idx < 0) {
    printf("Brand '%s' not in the list.\n", brand_name);
    return;
  }
  printf("Brand name: %s\n", brand_name);
  printf("Brand idx: %d\n", idx);
  printf("Similar brands:\n");
  for (int i = 0; i < MAT_SIZE; i++) {
    if (brand_adjacency_matrix[idx][i] == 1 && strcmp(brand_names[i], "") != 0) {
      printf("   %s\n", brand_names[i]);
    }
  }
  printf("\n");
}

/**
 * Read from a given file and populate a the brand list and brand matrix.
 **/
void populate_brand_matrix(char* file_name) {
    // Read the file
    char buff[MAX_STR_LEN];
    FILE* f = fopen(file_name, "r");
    fscanf(f, "%s", buff);
    char* line = buff;
    // Load up the brand_names matrix
    for (int i = 0; i < MAT_SIZE; i++) {
        if (i == MAT_SIZE - 1) {
            strcpy(brand_names[i], line);
            break;
        }
        int index = strchr(line, ',') - line;
        strncpy(brand_names[i], line, index);
        line = strchr(line, ',') + sizeof(char);
    }
    // Load up the brand_adjacency_matrix
    for (int x = 0; x < MAT_SIZE; x++) {
        fscanf(f, "%s", buff);
        for (int y = 0; y < MAT_SIZE; y++) {
            int value = (int) buff[y*2];
            if (value == 48) { value = 0; }
            else {value = 1;}
            brand_adjacency_matrix[x][y] = value;
        }
    }
}


// Users
/**TODO: Complete this function
 * Creates and returns a user. Returns NULL on failure.
 **/
User* create_user(char* name){
  User *new_user = (User*)calloc(1,sizeof(User));
  strcpy(new_user->name,name);
  new_user->friends=NULL;
  new_user->brands=NULL;
  if(in_friend_list(allUsers,new_user))
    return NULL;
  allUsers=insert_into_friend_list(allUsers,new_user);
  return new_user;

}

/**TODO: Complete this function
 * Deletes a given user.
 * Returns 0 on success, -1 on failure.
 **/
int delete_user(User* user){
  if(!in_friend_list(allUsers,user))
    return -1;
  FriendNode *p= user->friends,*q=p;
  while(p!=NULL){
    q = p->next;
    p->user->friends=delete_from_friend_list(p->user->friends,user);
    user->friends=delete_from_friend_list(user->friends,p->user);
    p=NULL;
    p=q;
  }
  allUsers=delete_from_friend_list(allUsers,user);
  return 0;
}

/**TODO: Complete this function
 * Create a friendship between user and friend.
 * Returns 0 on success, -1 on failure.
 **/
int add_friend(User* user, User* friend){
  if(!in_friend_list(allUsers,user)){
    return -1;
  }
  if (!in_friend_list(user->friends,friend)){
    friend->friends=insert_into_friend_list(friend->friends,user);
    user->friends=insert_into_friend_list(user->friends,friend);
    return 0;
  }
  return -1;
}
/**TODO: Complete this function
 * Removes a friendship between user and friend.
 * Returns 0 on success, -1 on faliure.
 **/
int remove_friend(User* user, User* friend){
  if(!in_friend_list(user->friends,friend))
    return -1;
  user->friends=delete_from_friend_list(user->friends,friend);
  friend->friends=delete_from_friend_list(friend->friends,user);
  return 0;
}
/**TODO: Complete this function
 * Creates a follow relationship, the user follows the brand.
 * Returns 0 on success, -1 on faliure.
 **/
int follow_brand(User* user, char* brand_name){
  if (get_brand_index(brand_name)==-1)
    return -1;
  if(in_brand_list(user->brands,brand_name))
    return -1;
  user->brands=insert_into_brand_list(user->brands,brand_name);
  return 0;
}

/**TODO: Complete this function
 * Removes a follow relationship, the user unfollows the brand.
 * Returns 0 on success, -1 on faliure.
 **/
int unfollow_brand(User* user, char* brand_name){
  if (get_brand_index(brand_name)==-1)
    return -1;
  if(!in_brand_list(user->brands,brand_name))
    return -1;
  user->brands=delete_from_brand_list(user->brands,brand_name);
  return 0;
}

/**TODO: Complete this function
 * Return the number of mutual friends between two users.
 **/
int get_mutual_friends(User* a, User* b){
  int counter=0;
  for (FriendNode *cur = a->friends; cur != NULL; cur = cur->next) {
    if (in_friend_list(b->friends,cur->user))
      counter++;
  }
  return counter;
}

/**TODO: Complete this function
 * A degree of connection is the number of steps it takes to get from
 * one user to another.
 *
 * For example, if X & Y are friends, then we expect to recieve 1 when calling
 * this on (X,Y). Continuing on, if Y & Z are friends, then we expect to
 * recieve 2 when calling this on (X,Z).
 *
 * Returns a non-negative integer representing the degrees of connection
 * between two users, -1 on failure.
 **/
int get_degrees_of_connection_recursion(User* a, User* b, int depth){
  if (!strcmp(a->name,b->name))
    return depth;
  else{
  a->visited = true;
  if(in_friend_list(a->friends,b))
    depth = get_degrees_of_connection_recursion(b,b,depth+1);
  else{
  FriendNode *tmp = a->friends;
  while (tmp!=NULL&&tmp->user->visited){
    tmp = tmp->next;
  }
  if(tmp!=NULL)
    depth = get_degrees_of_connection_recursion(tmp->user,b,depth+1);
  else{
    return -1;
  }
  }
}
return depth;
}

int get_degrees_of_connection(User* a, User* b){
  for (FriendNode *f = allUsers; f != NULL; f = f->next) {
      f->user->visited=false;
    }
  if (a==NULL||b==NULL||!in_friend_list(allUsers,a)||!in_friend_list(allUsers,b))
    return -1;
  if (!strcmp(a->name,b->name))
    return 0;
  return get_degrees_of_connection_recursion(a,b,0);
}

// Brands
/**TODO: Complete this function
 * Marks two brands as similar.
 **/
void connect_similar_brands(char* brandNameA, char* brandNameB){
  if(get_brand_index(brandNameA)!=-1&&get_brand_index(brandNameB)!=-1){
    brand_adjacency_matrix[get_brand_index(brandNameA)][get_brand_index(brandNameB)]=1;
    brand_adjacency_matrix[get_brand_index(brandNameB)][get_brand_index(brandNameA)]=1;
  }
  return;
}

void remove_similar_brands(char* brandNameA, char* brandNameB){
  if(get_brand_index(brandNameA)!=-1&&get_brand_index(brandNameB)!=-1){
    brand_adjacency_matrix[get_brand_index(brandNameA)][get_brand_index(brandNameB)]=0;
    brand_adjacency_matrix[get_brand_index(brandNameB)][get_brand_index(brandNameA)]=0;
  }
  return;
}


// Harder ones
/**TODO: Complete this function
 * Returns a suggested friend for the given user, returns NULL on failure.
 * See the handout for how we define a suggested friend.
 **/
User* get_suggested_friend(User* user){
  User* friend = NULL;
  int like_brands=-1;
  for (FriendNode *f = allUsers; f != NULL; f = f->next) {
    int i=0;
    for (BrandNode *b = f->user->brands; b != NULL; b = b->next) {
      if (in_brand_list(user->brands,b->brand_name))
        i++;
    }
    if(i>like_brands&&get_degrees_of_connection(f->user,user)>1){
      friend=f->user;
    }
  }
  return friend;
}

/**TODO: Complete this function
 * Friends n suggested friends for the given user.
 * See the handout for how we define a suggested friend.
 * Returns how many friends were successfully followed.
 **/
int add_suggested_friends(User* user, int n){
  int i = 0;
  while (i<n&&get_suggested_friend(user)!=NULL){
    add_friend(user,get_suggested_friend(user));
    i++;
  }
  return i;
}

/**TODO: Complete this function
 * Follows n suggested brands for the given user.
 * See the handout for how we define a suggested brand.
 * Returns how many brands were successfully followed.
 **/
void get_suggested_brands(User* user, int n, int like_brands[]){
  int *p=NULL,counter=0;
  BrandNode *b=NULL;
  p = like_brands;
  for (int name = 0; name < MAT_SIZE; name++) {
    for (b = user->brands; b != NULL; b = b->next) {
      if (brand_adjacency_matrix[name][get_brand_index(b->brand_name)])
        break;
    }
    if(b!=NULL){
      *(p+counter) = name;
      if(counter<=n-2)
        counter++;
    }
  }
  return;
}

int follow_suggested_brands(User* user, int n){
  int i = 0;
  int like_brands [n];
  for(int a = 0; a<n; a++){
    like_brands[a]=-1;
  }
  get_suggested_brands(user,n,like_brands);
  while (i<n&&like_brands[i]!=-1){
    follow_brand(user,brand_names[like_brands[i]]);
    i++;
  }
  return i;
}
