#include <stdio.h>
#include <stdlib.h>

// Note, the bits are counted from right to left. 
// Flip the bits of x within range [start, end], in which both are inclusive.
// Assume 0 <= start & end <= 31
void flip_bits(unsigned * x,
              unsigned start,
              unsigned end) {
  unsigned tempS = 1, tempE = 1;
  for (int i = 0; i <= end; i++) {
    if (i < start) {
      tempS *= 2;
      tempE *= 2;
    }
    else {
      tempE *= 2;
    }
  }
  *x = *x ^ (tempE - tempS);
  return ;
}
