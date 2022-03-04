/* Example: bubble sort strings in array */

#include <stdio.h>  /* Need for standard I/O functions */
#include <string.h> /* Need for strlen() */
#include <stdlib.h>


#define NUM 30   /* number of strings */
#define LEN 1200  /* max length of each string */



int main()
{
  char * Strings[NUM];
  
  printf("\nPlease enter %d strings, one per line:\n", NUM);
  
  for (int i = 0; i < NUM; i++) {
    Strings[i] = malloc(sizeof(char)*LEN);
    fgets(Strings[i], LEN, stdin);
  }
  /* Write a for loop here to read NUM strings.

     Use fgets(), with LEN as an argument to ensure that an input line that is too
     long does not exceed the bounds imposed by the string's length. However, each 
	 string stored in array Strings must not waste space. That is, only the buffer
	 used by fgets() to temporary store the string read from input stream needs to 
	 be LEN bytes long.  
	 Note that the newline and NULL characters will be included in LEN.
  */

  puts("\nHere are the strings in the order you entered:");

  for (int i = 0; i < NUM; i++) {
    printf("%s", Strings[i]);
  }
  /* Write a for loop here to print all the strings. */

  for (int i = 0; i < NUM - 1; i++) {
    
    for (int j = 0; j < NUM - (i + 1); j++) {

      for (int c = 0; c < strlen(Strings[j]) - 1 && c < strlen(Strings[j+1]) - 1; c++) {
        if (Strings[j][c] > Strings[j+1][c]) {
          char* temp = Strings[j];
          Strings[j] = Strings[j+1];
          Strings[j+1] = temp;
          break;
        }
        else if (Strings[j][c] < Strings[j+1][c]) {
          break;
        }
      }
    }
  }
  /* Bubble sort ABCDEFGHIJKLMNOPQRSTUVWXYZ*/
  /* Write code here to bubble sort the strings in ascending alphabetical order

     Your code must meet the following requirements:
        (i) The comparison of two strings must be done by checking them one
            character at a time, without using any C string library functions.
            That is, write your own while/for loop to do this.
       (ii) Implement a swap function to swap two strings by swapping pointers
	    without copying any chars.You are not allowed to use any C library 
	    functions in swap.
      (iii) You are allowed to use strlen() to calculate string lengths.
  */
  /* Output sorted list */
  
  puts("\nIn alphabetical order, the strings are:"); 

  for (int i = 0; i < NUM; i++) {
    fputs(Strings[i], stdin);
    free(Strings[i]);
  }
  /* Write a for loop here to print all the strings. Feel free to use puts/printf
     etc. for printing each string.
  */

}
