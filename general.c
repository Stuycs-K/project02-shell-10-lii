#include <stdio.h>
#include <unistd.h>
#include <string.h>

void parse_args( char * line, char ** arg_ary ) {
  char *curr = line;
  char *token;
  int n = 0;
  while(token = strsep(&curr, " ")) {
    arg_ary[n++] = token;
  }
  arg_ary[n] = NULL;
}