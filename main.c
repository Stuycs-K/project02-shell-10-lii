#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc, int *argv[]) {
    if(argc == 1) {
        printf("0");
        exit;
    }
    printf("give input");
    char buffer[256];
    fgets(buffer, 255, stdin);
    char *args[256];
    parse_args(buffer, args);
    execvp(args[0], args);

    pid_t sub, parent;
    sub = fork();
    if(sub == 0) {
        child(args);
    }
    int status;
    wait(&status);
}