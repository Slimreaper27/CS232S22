#include <stdio.h>
#include <string.h>
#define MAX_BUF 1024

int main () {

  /* Zero out the array */
  //int letter_frequency[26] = {0};
  int len;
  int chars = 0;
  int word = 0;
  int lines = 0;
  int whtspc = 0;
  int uucs = 0;
  int llcs = 0;
  int dgts = 0;
  
  //char buf[MAX_BUF];
  char c = getchar();
  if (c == '\n') {
    c = 0;
    
  }
  while (c) {
    
    if (c >= 'A' && c <= 'Z') {
        //letter_frequency[c - 65]++;
        chars++;
        uucs++;
      }
      else if (c >= 'a' && c <= 'z') {
        //letter_frequency[c - 97]++;
        chars++;
        llcs++;
      }
    else if (c == ' ' || c=='\t') {
        whtspc++;
        chars++;
      
      }
      
    else if (c >= '1' && c <= '9'){
      dgts++;
      chars++;
    }
    else if(c >= '!' && c <= '/'){
      chars++;
    }
    
    if (c == '\n') {
      lines++;
      chars++;
      
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
  /*if (lines > 0){
    lines = lines - 1;
    chars = chars - 1;
  }*/
  word = whtspc + lines;

  
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

  //printf("Distribution of letters in corpus:\n");
  /*for (int i = 0; i < 26; i++) {
    // 'A' is ASCII code 65
    printf("%c: %d\n", 65+i, letter_frequency[i]);
    
  }*/
  printf("%d %d %d %d %d %d %d\n", chars, word, lines, whtspc, uucs, llcs, dgts);
  
  
  
}


