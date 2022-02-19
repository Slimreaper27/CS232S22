#include<stdio.h>
#include<stdlib.h>
//Program to convert a 32-bit Decimal numbers to Binary
//1) Do not change the signature of convert_2, or your task receives zero
//2) No globals allowed.
char* convert_2(int dec)
{
  char* s = malloc(sizeof(char)*42);
  if (dec < 0) {
    dec = 2147483648 + dec;
    for (int i = 2; i < 41; i++) {
    if (dec % 2 == 1) {
      s[42 - i] = '1';
    }
    else {
      s[42 - i] = '0';
    }
    dec /= 2;
    if (i % 5 == 0) {
      s[41 - i] = ' ';
      i++;
    }
  }
    s[2] = '1';
  }
  else {
    for (int i = 2; i < 41; i++) {
    if (dec % 2 == 1) {
      s[42 - i] = '1';
    }
    else {
      s[42 - i] = '0';
    }
    dec /= 2;
    if (i % 5 == 0) {
      s[41 - i] = ' ';
      i++;
    }
  }
  }
  
  
  s[0] = '0';
  s[1] = 'b';
  s[41] = '\0';
  
	return s;
}

int main() {
	int n;
	char * bin;
	printf("Enter the Decimal Number\n");
	scanf("%d",&n);
	bin = convert_2(n);
	printf("The Binary Notation of %d is\t %s \n", n, bin);
	free(bin);
}
