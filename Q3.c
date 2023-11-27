#include "constantheader.h"

int main(void) {
    char command[MAX_SIZE];   
    int pid;                  
    int status;               
    int command_length;       
    int test;                 

    write(STDOUT_FILENO, WELCOME_MESSAGE, strlen(WELCOME_MESSAGE));   

    while (1) {
        write(STDOUT_FILENO, REGULAR_PROMPT, strlen(REGULAR_PROMPT));  

        
        command_length = read(STDIN_FILENO, command, MAX_SIZE);

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
        if (pid == -1) {
        
            perror("Fork failed");
            exit(EXIT_FAILURE);
        }

        if (pid == 0) {
            
            execlp(command, command, NULL);

            perror("Exec failed");
            _exit(EXIT_FAILURE);
        } else {
           

            wait(&status); 
        }
    }

    return 0;
}
