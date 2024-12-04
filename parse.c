#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "parse.h"

//Used to seperate a string and splitting by spaces using strsep() before storing it in a char **
void parse_args( char * line, char ** arg_ary ) {
  char *curr = line;
  char *token;
  int n = 0;
  while(token = strsep(&curr, " ")) {
    arg_ary[n++] = token;
  }
  arg_ary[n] = NULL;
}

//Used to count how many commands are in the stdin
int count_cmds(char * line, char ** cmds) {
  char *curr = line;
  char *token;
  int i = 0;
  while(token = strsep(&curr, " ")) {
    cmds[i++] = token;
  }
  cmds[i] = NULL;
  return i;
}