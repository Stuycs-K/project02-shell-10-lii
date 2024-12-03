#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "fork.h"

void child(char ** args) {
  execvp(args[0], args);
  EXIT_SUCCESS;
}

void parent() {

}