#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void cd(char *path) {
    if(chdir(path != 0)) {
        perror("chdir not working");
        return;
    }
    char cwd[256];
    if(getcwd(cwd, sizeof(cwd)) == NULL) {
        perror("CWD does not work");
        return;
    }
    printf("Current directory: %s\n", cwd);
}