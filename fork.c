#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void child(char ** args) {
  execvp(args[0], args);
  EXIT_SUCCESS;
}
