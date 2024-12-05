#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int err(){
    printf("errno %d\n",errno);
    printf("%s\n",strerror(errno));
    exit(1);
}

void cd(char *path) {
    if(chdir(path != 0)) {
        err();
        return;
    }
}

char * get_path() {
    char cwd[256];
    if(getcwd(cwd, sizeof(cwd)) == NULL) {
        perror("CWD does not work");
        return NULL;
    }
    return cwd;
}