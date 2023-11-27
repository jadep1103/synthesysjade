#include "constantheader.h"
#include <signal.h>

volatile sig_atomic_t exit_requested = 0;

void handle_signal(int signal) {
    if (signal == SIGINT) {
        write(STDOUT_FILENO, BYE, strlen(BYE));
        exit_requested = 1;
    }
}

int main(void) {
    char command[MAX_SIZE];
    int pid;
    int status;
    int command_length;
    int test;

    signal(SIGINT, handle_signal);

    write(STDOUT_FILENO, WELCOME_MESSAGE, strlen(WELCOME_MESSAGE));

    while (1) {
        write(STDOUT_FILENO, REGULAR_PROMPT, strlen(REGULAR_PROMPT));

        command_length = read(STDIN_FILENO, command, MAX_SIZE);
        command[command_length - 1] = '\0';

        test = strcmp(EXIT, command);
        if (test == 0 || exit_requested) {
            write(STDOUT_FILENO, BYE, strlen(BYE));
            break;
        }

        pid = fork();
        if (pid == 0) {
            execlp(command, command, NULL);
            _exit(EXIT_FAILURE);
        } else {
            wait(&status);
        }
    }

    return 0;
}
