#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int toArgv(char *source, char *dest[], int size) {
  const char whitespace[7] = " \t\n\v\f\r";
  char *token;
  token = strtok(source, whitespace);
  int currentIndex = 0;
  while (token != NULL && currentIndex < size - 1) {
    dest[currentIndex] = token;
    printf("\n token: %s", token);
    printf("\n currentIndex: %s", dest[currentIndex]);
    currentIndex++;
    token = strtok(NULL, " ");
  }
  dest[currentIndex] = NULL;
  return currentIndex;
}

int main(int argc, char *argv[]) {
  for (int i = 1; i < argc; i++) {
    char *tempArr[10];
    int retval = toArgv(argv[i], tempArr, 10);
    printf("\n%d", retval);
    printf("\n%s", tempArr[0]);
    printf("\n%s", tempArr[1]);
    printf("\n%s", tempArr[2]);
    printf("\n%s", tempArr[3]);
    printf("\n%s", tempArr[4]);
    printf("\n%s", tempArr[5]);

    // for (int i = 0; i < retval; i++) {
    int id = fork();
    if (id) {
      wait(NULL); //???
    } else {
      execvp("ls", tempArr); //???
    }
    // }
  }
  // for each command line argument in argv
  //   Call toArgv() to break it into an array of tokens named tempArr.
  //   (Assume there will be no more than 10 tokens.)
  //   call fork
  //   if in the parent
  //      call wait
  //   else (in the child)
  //      call execvp with tempArr

  printf("Hello World\n");
  return 0;
}