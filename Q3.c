#include "constantheader.h"

int main(void){
    char command[MAX_SIZE];
    int pid;
    int status;
    int command_length;
    int test;
    
    write(STDOUT_FILENO, WELCOME_MESSAGE, strlen(WELCOME_MESSAGE));
    
    while(1){
        write(STDOUT_FILENO, REGULAR_PROMPT, strlen(REGULAR_PROMPT));
        
        command_length = read(STDIN_FILENO, command, MAX_SIZE);
        command[command_length-1] = '\0';
        
        test = strcmp(EXIT, command);
        if(test==0){
            write(STDOUT_FILENO, BYE, strlen(BYE));
            kill(getpid(),SIGINT);
        }
        
        pid = fork();
        if(pid==0){
            execlp(command, command, NULL);
        } else {
            wait(&status);
            if(WIFSIGNALED(status)){
                sprintf(display, "%s%d%s", SIGNALED_PROMPT, WSTOPSIG(status), END_PROMPT);
                write(STDOUT_FILENO, display, strlen(display));
            } else {
                if(WIFEXITED(status)){
                    sprintf(display, "%s%d%s", EXITED_PROMPT, WEXITSTATUS(status), END_PROMPT);
                    write(STDOUT_FILENO, display, strlen(display));
                }
            }
        }
    }   
}
