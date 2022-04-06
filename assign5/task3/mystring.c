//* Include the system headers we need */
#include <stdlib.h>
#include <stdio.h>

/* Include our header */
#include "mystring.h"

/* Define what our struct is */
struct mystring_t {
	size_t size;
	char *data;
};

/* Utility function to handle allocation failures. In this case we print a message and exit. */
static void allocation_failed() {
    fprintf(stderr, "Out of memory.\n");
    exit(1);
}

/* Bad example of how to create a new mystring */
mystring_t *bad_string_new() {
	/* Create the string and a pointer to it */
  /*This is a bad constructor as v gets destroyed once contructor returns*/
	mystring_t *retval, v;
	retval = &v;

	/* Initialize attributes */
	retval->size = 1; //why size+1? size is the actual char lenght. 
			  //we must reseve an extra space for null
	retval->data = (char*) malloc((retval->size+1)*sizeof(char));
	if (retval->data == NULL) {
		allocation_failed();
	}

	retval->data[0] = ' ';
	retval->data[retval->size] = '\0';
	return retval;
}

/* Another suboptimal way of creating a string */
mystring_t also_bad_string_new() {
	/* Create the string */
	/*why is this bad? does v get destroyed upon returning? */
	mystring_t s;

	/* Initialize attributes */
	s.size = 1; //why size+1? an extra space for null
	s.data = (char*) malloc((s.size+1)*sizeof(char));
	if (s.data == NULL) {
		allocation_failed();
	}
	s.data[0] = ' ';
	s.data[s.size] = '\0';
	return s;
}

/* Create a new string with a size (length) of 1
   and set its single component to zero... the
   RIGHT WAY */
mystring_t *mystring_new() {
	mystring_t *newval;

  newval = malloc(sizeof(mystring_t));
  
  // check for allocation
  if (newval == NULL){
      allocation_failed(); 
    }

  //create size of 1
  newval->size = 1;
  
  //allocation for string
  newval->data = (char *)malloc((newval->size)*sizeof(char));

  //check allocation
  if(newval->data == NULL){
    allocation_failed();
  }
  
// set single component to zero
  newval->data[0] = 0;
  newval->data[newval->size] = '\0';
  
	return newval;
}

/* Return the value at the specified location/component "loc" of the mystring */
char mystring_get(mystring_t *s, size_t loc) {
	return s->data[loc];
}

/* Free up the memory allocated for the passed mystring.
   Remember, you need to free up ALL the memory that was allocated. */
void mystring_delete(mystring_t *s) {
  // if the string is empty, no need to free
  if (s == NULL)
        return;
  
  free(s->data);
  free(s);
}

int mystring_get_len(mystring_t *s) {
  int string_length = 0;

  // find the end of the string using the terminating character
  while (s->data[string_length] != '\0') {
    string_length++;
  }
  return string_length;
}

char* mystring_get_data(mystring_t *s) {
	return s->data;
}

void mystring_cat(mystring_t *s, char *s2) {
  int x = 0;
  int z = 0;
  // find length of added array
    while (s2[z] != '\0') {
      z++;
    }
  // create a hold for s->data
  if(s->size > 1) {
    char * temp_array;
    temp_array = (char*)malloc((s->size) * sizeof(char));
    
    for (int i = 0; i < s->size; i++) {
      temp_array[i] = s->data[i];
    }
    free(s->data); //freeing s->data to allocate more space
    int hold_size = s->size;
  
    s->size = s->size + z; 
    // adding the length of s2 to the length of the existing array (+1 for null is already within s->size)
  
  //should allocate memory enough for both strings
    s->data = (char*)malloc((s->size) * sizeof(char));

  // restoring from temp_array
    for (int i = 0; i < hold_size; i++){
      s->data[i] = temp_array[i];
    }
    free(temp_array); // free temp_array, done using it
    x = hold_size-1; // starting at the end of the function, at size so it overwrites the null character

  }
  else {
    s->size = z+1; // adding one for null
    
    free(s->data);
    
  //should allocate memory enough for both strings
    s->data = (char*)malloc((s->size) * sizeof(char));
    }

    for(int i = 0;i<z;i++){
        s->data[x] = s2[i];
        x++;
      }
  
  s->data[s->size] = '\0';
}

/* Set a value in the mystring. If the extra memory allocation fails, call
   allocation_failed(). Unset space should be value of space */
void mystring_set(mystring_t *s, size_t loc, char value) {
  if(loc >= s->size){
    // creating a temporary array to hold s->data
    char * temp_array;
    temp_array = (char*)malloc((s->size) * sizeof(char));
    
    for (int i = 0; i < s->size; i++) {
      temp_array[i] = s->data[i];
    }
    
    free(s->data); //freeing s->data to allocate more space
    
    s->size = loc + 1; // setting new size by taking the loc and adding one for null character

    // re allocating s->data with new size
    s->data = (char*) malloc((s->size) * sizeof(char));
    
    if(s->data == NULL){
      allocation_failed();
    }
    // using the temp array to bring back array from previous s->data and saving blanks as spaces
    for (int i = 0; i < s->size; i++){
      if(temp_array[i] == 0){
        s->data[i]= ' ';
      }
      else{
        s->data[i] = temp_array[i];
      }
    }   
    free(temp_array); // free temp_array, done using it
    
    s->data[s->size] = '\0'; // adding new null character
    
    s->data[loc]=value; // setting new value
    // if loc is already within the size
    }
  else {
    s->data[loc]=value; // setting new value
  }
}