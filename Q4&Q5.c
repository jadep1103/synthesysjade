#include "constantheader.h"
 
int main(void) {
    char command[MAX_SIZE] = {0};
    int pid;
    int status;
    int test;
    struct timespec timestart;
    struct timespec timestop;
    char display[MAX_SIZE] = {0};

    write(STDOUT_FILENO, WELCOME_MESSAGE, strlen(WELCOME_MESSAGE));

    while (1) {
        write(STDOUT_FILENO, REGULAR_PROMPT, strlen(REGULAR_PROMPT));

        int command_length = read(STDIN_FILENO, command, MAX_SIZE);

        // Check for EOF
        if (command_length == 0) {
            // User pressed <ctrl>+d (as this is a "end of file" signal) or encountered EOF
            write(STDOUT_FILENO, "Bye bye...\n", strlen("Bye bye...\n"));
            break;
        }

        command[command_length - 1] = '\0';

        test = strcmp(EXIT, command);   
        if (test == 0) {
            // User entered "exit"
            write(STDOUT_FILENO, "Bye bye...\n", strlen("Bye bye...\n"));
            break;   // Exit the loop if the exit condition is met
        }
        pid = fork();  
        clock_gettime(CLOCK_REALTIME, &timestart);

     if (pid == -1) {
        
            perror("Fork failed");
            exit(EXIT_FAILURE);
        }

        if (pid == 0) {
            
            execlp(command, command, NULL);

            perror("Exec failed");
            _exit(EXIT_FAILURE);  }
        else {
            wait(&status);
            clock_gettime(CLOCK_REALTIME, &timestop);
            int time = (timestop.tv_nsec - timestart.tv_nsec) / 1000000;

            if (WIFSIGNALED(status)) {
                sprintf(display, "%s%d%s%d%s%s", SIGNALED_PROMPT, WSTOPSIG(status), "|", time, "ms", END_PROMPT);
                write(STDOUT_FILENO, display, strlen(display));
            } else {
                if (WIFEXITED(status)) {
                    sprintf(display, "%s%d%s%d%s%s", EXITED_PROMPT, WSTOPSIG(status), "|", time, "ms", END_PROMPT);
                    write(STDOUT_FILENO, display, strlen(display));
                }
            }
        }
    }

    return 0;
}
