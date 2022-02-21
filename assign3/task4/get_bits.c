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
  unsigned temp = 1;
  for (unsigned i = 0; i <= end; i++) {
    if (i >= start) {
      if (x < (x ^ temp)) {
        a[i - start] = 0;
      }
      else {
        a[i-start] = 1;
      }
    }
    temp *= 2;
  }
  return a;
}