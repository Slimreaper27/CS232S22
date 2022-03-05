#include <stdio.h>
#define LEN 1000
int main(int argc, char *argv[]) {
  int n = 0, ch;
  char str[LEN];

  while ((ch = getchar()) != '\n' && n < LEN) {
    if (ch >= 'a' && ch <= 'z' ) {
      str[n] = ch - 32; 
    }
    else {
      str[n] = ch;
    }
    n++;
    }
  
  for (int i = 0; i < n; ++i) {
      putchar(str[i]);
    }
  printf("\n");

  
  
  
/* example: 
   char str[12];
   int ch, n = 0;

   while ((ch = getchar()) != EOF && n < 10) {
      str[n] = ch;
      ++n;
   }

   for (int i = 0; i < n; ++i)
      putchar(str[i]);*/


   return 0;


}

