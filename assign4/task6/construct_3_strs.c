#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    char * value; //must use dynamic allocation 
    struct node* next;
} node_t;

node_t * construct_3_strs() {
  node_t* x = (node_t*) malloc(sizeof(node_t));
  node_t* y = (node_t*) malloc(sizeof(node_t));
  node_t* z = (node_t*) malloc(sizeof(node_t));
  x->value = (char*) malloc(sizeof(char)*6);
  y->value = (char*) malloc(sizeof(char)*3);
  z->value = (char*) malloc(sizeof(char)*8);
  x->value[0] = 'C';
  x->value[1] = 'S';
  x->value[2] = '2';
  x->value[3] = '3';
  x->value[4] = '2';
  x->value[5] = '\0';
  y->value[0] = 'i';
  y->value[1] = 's';
  y->value[2] = '\0';
  z->value[0] = 'a';
  z->value[1] = 'w';
  z->value[2] = 'e';
  z->value[3] = 's';
  z->value[4] = 'o';
  z->value[5] = 'm';
  z->value[6] = 'e';
  z->value[7] = '\0';
  x->next = y;
  y->next = z;
  z->next = x;
  return x;
}

//You can ignore the following code for testing
int dump_all(node_t*);
int main (int argc, char ** argv) {
    node_t * x = construct_3_strs();
    return dump_all(x);

}

int dump_all(node_t * x) {
    printf("x -> %s", x->value);
    node_t * y = x->next;
    printf(" %s", y->value);
    node_t * z = y->next;
    printf(" %s\n", z->value);
    if(z->next != x) {
    	printf("failed");
      free(x->value);
      free(y->value);
      free(z->value);
      free(x);
      free(y);
      free(z);
	    return -1;
    } 
    else {
      free(x->value);
      free(y->value);
      free(z->value);
      free(x);
      free(y);
      free(z);
      return 0;
    }
}
