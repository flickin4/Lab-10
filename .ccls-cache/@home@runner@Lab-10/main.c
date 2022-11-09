#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int toArgv(char *source, char *dest[], int size) {
  const char whitespace[7] = " \t\n\v\f\r";
  dest = malloc(size);
  printf("\n7");
  fflush(stdout);
  strtok(source, whitespace);
  printf("\n9");
  fflush(stdout);
  char *token = "HI";
  int currentIndex = 0;
  while (token != NULL && currentIndex < size - 1) {
    printf("12");
    fflush(stdout);
    // int stringLength = strlen(token);
    // dest[currentIndex] = malloc(stringLength);
    // strncpy(dest[currentIndex], token, stringLength);
    dest[currentIndex] = token;
    printf("16");
    fflush(stdout);
    currentIndex++;
    token = strtok(NULL, " ");
    printf("20");
    fflush(stdout);
  }
  printf("22");
  fflush(stdout);
  dest[currentIndex] = NULL;
  return currentIndex;
}

int main(void) {
  char *arr[6];
  int retval = toArgv("my dog has fleas", arr, 6);
  printf("\n%d", retval);
  printf("\n%s", arr[0]);
  printf("\n%s", arr[1]);
  printf("\n%s", arr[2]);
  printf("\n%s", arr[3]);
  printf("\n%s", arr[4]);
  printf("\n%s", arr[5]);

  printf("Hello World\n");
  return 0;
}