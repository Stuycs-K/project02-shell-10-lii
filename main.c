#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc, int *argv[]) {
    //Variables
    char buffer[256];
    char *args[256];
    //Prompts User for input
    while(1){
        printf("Give input");
        fflush(stdout);

        if(fgets(buffer, 255, stdin) == NULL) {
            break;
        } 
        parse_args(buffer, args); //Parsing
        
        if(args[0] == NULL) {
            continue; // Goes to next while loop iteration
        }

        if(strcmp(args[0], "exit")) {
            break; //Checks if user wants to exit 
        }
        //Running sub processes using fork
        pid_t sub = fork();
        if(sub == -1) {
            perror("Fork Failed somehow");
        }
        if(sub == 0) {
            child(args);
        }
        int status;
        wait(&status);
    }
    printf("Exiting shell"); //ending program
    return 0;
}