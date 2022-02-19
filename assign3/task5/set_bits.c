#include <stdio.h>
#include <stdlib.h>

// Set the bits of x within range of [start, end], in which both are inclusive
// Assume 0 <= start & end <= 31
void set_bits(unsigned * x,
             unsigned start,
             unsigned end,
             unsigned *v) {
  unsigned* a = malloc(sizeof(unsigned) * (end +1));
    for (int i = 0; i < start; i++) {
      if (*x % 2 == 1) {
          a[i] = 1;
        }
      else {
        a[i] = 0;
      }
      *x = *x >> 1;
    }
  
      *x = *x >> (end - start + 1);
    
    for (int i = end - start; i >= 0; i--) {
      *x = *x << 1;
      if (v[i] == 1) {
      *x += 1;
        }
    }
    for (int i = start - 1; i >= 0; i--) {
      *x = *x << 1;
      if (a[i] == 1) {
        *x += 1;
      }
}
    
    // v points to an array of at least (end-start+1) unsigned integers.
    // if v[i] == 0, then set (i+start)-th bit of x zero, otherwise, set (i+start)-th bit of x one.
  return ;
}


