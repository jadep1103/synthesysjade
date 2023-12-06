#include "constantheader.h"

int main(void) {
    char command[MAX_SIZE] = {0};
    char display[MAX_SIZE] = {0};
    int command_length;
    int pid;
    int status;
    
    write(STDOUT_FILENO, WELCOME_MESSAGE, strlen(WELCOME_MESSAGE));
    write(STDOUT_FILENO, REGULAR_PROMPT, strlen(REGULAR_PROMPT));
    
    while (1) {
        command_length = read(STDOUT_FILENO, command, MAX_SIZE);
        
        command[command_length - 1] = '\0';
        
        int test = strcmp(EXIT, command);
        if (test == 0 || command_length == 0) {
            write(STDOUT_FILENO, BYE, strlen(BYE));
            break;
        }
        
        pid = fork();
        if (pid == 0) {
            char *argv[MAX_ARG] = {NULL};
            int i = 0;
            
            argv[0] = strtok(command, " ");
            while (argv[i] != NULL) {
                i++;
                argv[i] = strtok(NULL, " ");
            }
            
            execvp(argv[0], argv);
            
            write(STDOUT_FILENO, ERR, strlen(ERR));
            _exit(EXIT_FAILURE);  // Ensure the child process exits even if execvp fails
        } else {
            wait(&status);
            
            if (WIFSIGNALED(status)) {
                sprintf(display, "%s%d%s%s", SIGNALED_PROMPT, WSTOPSIG(status), END_PROMPT);
                write(STDOUT_FILENO, display, strlen(display));
            } else if (WIFEXITED(status)) {
                sprintf(display, "%s%d%s%s", EXITED_PROMPT, WEXITSTATUS(status), END_PROMPT);
                write(STDOUT_FILENO, display, strlen(display));
            }
        }
    }

    return 0;
}
