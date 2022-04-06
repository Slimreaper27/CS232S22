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
  

void teardown(node_t* head) {
    //TODO: free all dynamic memory you requested.
    //Please complete the prototype of teardown.
    //You are not allowed to use globals

  node_t* node1 = head->next;
  node_t* node2 = node1->next;
  node_t* node3 = node2->next;
  free(node3);
  free(node2);    
  free(node1);
  free(head);
  
}

void add(node_t ** head, char * newString, int strLength){
    //TODO: implement add to add a new node to front, pointed by head
  ////////////////////////////////////////////////
  node_t* newNode = malloc(sizeof(node_t));
  strcpy(newNode -> str, newString);
  newNode -> length = strLength;
  newNode -> next = *head;
  *head = newNode;
  
  ////////////////////////////////////////////////
}

void dump_all(node_t*);
int main (int argc, char ** argv) {
    node_t * head = setup();
    add(&head, "hi", 2);
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
