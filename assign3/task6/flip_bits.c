#include <stdio.h>
#include <stdlib.h>

// Note, the bits are counted from right to left. 
// Flip the bits of x within range [start, end], in which both are inclusive.
// Assume 0 <= start & end <= 31
void flip_bits(unsigned * x,
              unsigned start,
              unsigned end) {
  unsigned* a = malloc(sizeof(unsigned) * (end +1));
  for (int i = 0; i <= end; i++) {
      if (*x % 2 == 1) {
          a[i] = 1;
        }
      else {
        a[i] = 0;
      }
      *x = *x >> 1;
    }

  for (int i = end; i != start - 1; i--) {
      *x = *x << 1;
      if (a[i] == 0) {
        *x += 1;
        }
    }
  for (int i = start - 1; i >= 0; i--) {
      *x = *x << 1;
      if (a[i] == 1) {
        *x += 1;
      }
    }
  return ;
}
