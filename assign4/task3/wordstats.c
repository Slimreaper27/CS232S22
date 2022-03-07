#include <stdio.h>
#include <string.h>
#define MAX_BUF 1024

int main () {

  /* Zero out the array */
  int letter_frequency[26] = {0};
  int len;
  //char buf[MAX_BUF];
  char c = getchar();
  if (c == '\n') {
    c = 0;
  }
  while (c) {
    if (c >= 'A' && c <= 'Z') {
        letter_frequency[c - 65]++;
      }
      else if (c >= 'a' && c <= 'z') {
        letter_frequency[c - 97]++;
      }
    if (c == '\n') {
      if (len == 1) {
        break;
      }
      len = 1;
      }
    else {
      len = 0;
      }
    c = getchar();
    if (c == EOF) {
      break;
    }
  }
   //do {
    //fgets(buf, MAX_BUF, stdin);
    /*len = strlen(buf);
    for (int i = 0; i < len - 1; i++) {
      if (buf[i] >= 'A' && buf[i] <= 'Z') {
        letter_frequency[buf[i] - 65]++;
      }
      else if (buf[i] >= 'a' && buf[i] <= 'z') {
        letter_frequency[buf[i] - 97]++;
      }
    } */
  //} while (len > 1);

  printf("Distribution of letters in corpus:\n");
  for (int i = 0; i < 26; i++) {
    // 'A' is ASCII code 65
    printf("%c: %d\n", 65+i, letter_frequency[i]);
  }
}


