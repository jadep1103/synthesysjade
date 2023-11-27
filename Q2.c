#include "constantheader.h"

int main(void) {
    char command[MAX_SIZE];   // Buffer to store user-entered command
    int pid;                  // Process ID for forking
    int status;               // Status of child process
    int command_length;       
    int test;                 // Result of comparing command with exit condition

    write(STDOUT_FILENO, WELCOME_MESSAGE, strlen(WELCOME_MESSAGE));   

    while (1) {
        write(STDOUT_FILENO, REGULAR_PROMPT, strlen(REGULAR_PROMPT));  

        // Read user-entered command from standard input
        command_length = read(STDIN_FILENO, command, MAX_SIZE);
        command[command_length - 1] = '\0'; 

        test = strcmp(EXIT, command);   
        if (test == 0) {
            break;   // Exit the loop if the exit condition is met
        }

        pid = fork();   // Create a new process to execute the entered command without blocking interactive command loop

        if (pid == -1) {
        
            perror("Fork failed");
            exit(EXIT_FAILURE);
        }

        if (pid == 0) {
            // In the child process

            // Execute the entered command
            execlp(command, command, NULL);

          
            perror("Exec failed");
            _exit(EXIT_FAILURE);
        } else {
            // In the parent process

            wait(&status);  // Wait for the child process to complete
            
        }
    }

return 0;
}
   
