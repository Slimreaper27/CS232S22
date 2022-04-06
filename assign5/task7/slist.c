#include "snode.h"
#include "slist.h"

/*struct slist {
  struct snode *front; // front node
  struct snode *back;  // back node
};
struct snode {
  char* str;
  struct snode *next;
}; 
struct snode *snode_create(char *s) ; 
void snode_destroy(struct snode * s) ;
*/

/**
 * Allocates new slist dynamically.
 * 
 * @return pointer to the list
 */
struct slist *slist_create() {
  struct slist* list = malloc (sizeof(struct slist));
  list->front = NULL;
  list->back = NULL;
  return list;
}

/** 
 * Inserts new node in slist after the last node.
 *
 * @param l pointer to the list (non-NULL)
 * @param str pointer to a C string to store in new list node
 * returns a pointer to the newly added node
 */
struct snode* slist_add_back(struct slist *l, char *str) {
  struct snode* newNode = snode_create(str);
  if (l->front == NULL) {
    l->front = newNode;
    l->back = newNode;
    return newNode;
  }
  l->back->next = newNode;
  l->back = newNode;
  return newNode;
}

/** 
 * Inserts new node in slist before the first node.
 *
 * @param l pointer to the list (non-NULL)
 * @param str pointer to a C string to store in new list node
 * returns a pointer to the newly added node
 */
struct snode* slist_add_front(struct slist *l, char *str) {
  struct snode* newNode = snode_create(str);
  if (l->front == NULL) {
    l->front = newNode;
    l->back = newNode;
    return newNode;
  }
  newNode->next = l->front;
  l->front = newNode;
  return newNode;
}

/**
 * Returns the first snode with the given string.
 *  
 * @param l pointer to the list (non-NULL)
 * @parap str pointer to a string
 * @return struct snode* or NULL if no match
 */
struct snode* slist_find(struct slist *l, char *str) {
  struct snode* p = l->front;
  while (p != NULL) {
    if (strcmp(p->str, str) == 0) {
      return p;
    }
    p = p->next;
  }
  return NULL;
}

/**
 * Deallocate a list and all snodes
 *
 * @param l pointer tot he list
 */
void slist_destroy(struct slist *l) {
  struct snode* p = l->front;
  while (p != NULL) {
    struct snode* temp = p;
    p = p->next;
    snode_destroy(temp);
  }
  free(l);
}

/**
 * Traverse the list and print the content of each node.
 *
 * @param l pointer to the list (non-NULL)
 */
void slist_traverse(struct slist *l) {
  struct snode* p = l->front;
  while (p != NULL) {
    printf("%s\n", p->str);
    p = p->next;
  }
}

/**
 * Returns the number of elements in the list (nodes).
 *
 * @param l pointer to the list (non-NULL)
 */
uint32_t slist_length(struct slist *l) {
  struct snode* p = l->front;
  uint32_t count = 0;
  while (p != NULL) {
    count++;
    p = p->next;
  }
  return count;
}
/**
 * Deletes the first snode with the given string.
 *  
 * @param l pointer to the list (non-NULL)
 * @parap str pointer to a string
 */
void slist_delete(struct slist *l, char *str) {
  struct snode* p = l->front;
  int stop = 0;
  if (strcmp(p->str, str) == 0) {
    l->front = l->front->next;
    snode_destroy(p);
    stop = 1;
  }
  while (p != NULL && stop == 0) {
    if (strcmp(p->next->str, str) == 0) {
      struct snode* temp = p->next;
      if (temp == l->back) {
        l->back = p;
        }
      p->next = temp->next;
      snode_destroy(temp);
      break;
    }
    p = p->next;
  }
  
}