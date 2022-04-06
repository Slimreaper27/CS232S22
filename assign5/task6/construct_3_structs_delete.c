#include<stdio.h>
#include<stdlib.h>
#include "snode.h"
typedef struct snode node_t;

node_t * setup() {
    //TODO:copy setup func from previous task

  node_t * head ;
    //TODO:head declared for you
    //Allocate three more pointers
    //head for the first Node, and temporary pointers node1, node2 and node3

  node_t *node1, *node2, *node3;

    //Allocate three node pointees and store references to them in the three pointers

  node1 = malloc(sizeof(struct snode));
  node2 = malloc(sizeof(struct snode));
  node3 = malloc(sizeof(struct snode));
    //Dereference each pointer to store the appropriate number and string into the length and str fields in its pointee.
  strcpy(node1->str, "hello");
  node1->length = 5;
  
  strcpy(node2->str, "there");
  node2->length = 5;
  
  strcpy(node3->str, "prof");
  node3->length = 4;

    //Dereference each pointer to access the .next field in its pointee, 
    //and use pointer assignment to set the .next field to point to the appropriate Node. 
  node1->next = node2;
  node2->next = node3;
  node3->next = NULL;
  head = node1;
    
   return head;
}

void teardown(node_t * head) {
    //TODO: free all dynamic memory you requested.
    //Please complete the prototype of teardown.
    //You are not allowed to use globals
    node_t *temp = head;
    while (temp != NULL) {
      node_t *prev = temp;
      temp = temp->next;
      free(prev);
    }

}

void add(node_t ** head, char * str, int length){
    //TODO: copy add func from task2
  node_t * temp = *head;
  node_t* newNode = malloc(sizeof(node_t));
  strcpy(newNode -> str, str);
  newNode -> length = length;
  newNode -> next = temp;
  *head = newNode;
}
void delete_node_at(node_t ** head, int idx) {
    //TODO: implement delete a node based on index
	//deletes a node at index idx, which ranges from zero to the length of the list - 1.
  node_t * prev = NULL;
  node_t * ndelete = *head;
  node_t * temp = *head;
  for (int i = 0; i < idx; i++) {
    prev = ndelete;
    ndelete = (ndelete -> next);
  }
  if (prev == NULL) {
   *head = temp->next;
    free(ndelete);
  } else {
    (prev -> next) = (ndelete -> next);
    free(ndelete);
  }
} 
void delete_node_key(node_t ** head, char * key) {
    //TODO: implement delete a node based on key
	//given a certain key, find and delete.
  node_t * prev = NULL;
  node_t * sdelete = *head;
  while (sdelete != NULL) {
    if(strcmp(key, sdelete->str) == 0) {
      if (*head == sdelete) {
        *head = sdelete->next;
      }
      else {
        prev->next = sdelete->next;
      }
      free(sdelete);
      return ;
    } 
    prev = sdelete;
    sdelete = (sdelete -> next);
  }

}
void dump_all(node_t*);
int main (int argc, char ** argv) {
    node_t * head = setup();
    add(&head, "hi", 2);
    delete_node_key(&head, "prof");
    delete_node_at(&head, 0);
    dump_all(head);
    teardown(head);
    return 0;
}

void dump_all(node_t * head) {
    printf("head -> ");
    node_t * cur = head;
    while(cur != NULL) {
        printf("%s ", cur->str);
	cur = cur->next;
    }
    printf("\ndone\n ");
}
