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
    char *cmds[256];
    //Prompts User for input
    while(1){
        printf("%s", get_path());
        fflush(stdout);

        if(fgets(buffer, 255, stdin) == NULL) {
            break;
        } 
        int n = countcmds(buffer, cmds); // Counts # of commands
        
        for(int i  = 0; i < n; i++) {
        //Running sub processes using fork
            parse_args(cmds[n], args);
            if(args[0] == NULL) {
            continue; // Goes to next while loop iteration
            }
            if(strcmp(args[0], "exit")) {
                break; //Checks if user wants to exit 
            }
            if(strcmp(args[0], "cd")) {
                if(cd(args[1])) {
                    break;
                }
                else {
                    continue;
                }
            }
            pid_t sub = fork();
            if(sub == -1) {
                perror("Fork Failed somehow");
            }
            if(sub == 0) {
                child(args);
            }
            int status;
            wait(&status);
            n++;
        }
    }
    printf("Exiting shell"); //ending program
    return 0;
}