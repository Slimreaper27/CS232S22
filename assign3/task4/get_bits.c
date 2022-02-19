#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
// Note, the bits are counted from right to left. 
// Return the bit states of x within range of [start, end], in which both are inclusive.
// Assume 0 <= start & end <= 31
unsigned * get_bits(unsigned x,
                 unsigned start,
                 unsigned end) {
    unsigned * a = malloc(sizeof(unsigned) * (end-start+1));
  for (int i = 0; i < start; i++) {
    printf("Ran ");
    x = x >> 1;
  }
  
  
  int i = end;
  int arr = 0;
  while (i != start - 1) {
    if (x % 2 == 1) {
      printf("Odd");
      a[arr] = 1;
      }
    else {
      printf("Even");
      a[arr] = 0;
    }
    
    x = x >> 1;
    i--;
    arr++;
  }

  return a;
}



