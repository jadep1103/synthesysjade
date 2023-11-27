#include "constantheader.h"

volatile sig_atomic_t exit_requested = 0;

void handle_signal(int signal) {
    if (signal == SIGINT) {
        write(STDOUT_FILENO, BYE, strlen(BYE));
        exit_requested = 1;
    }
}

int main(void) {
    char command[MAX_SIZE] = {0};
    char display[MAX_SIZE] = {0};
    int command_length;
    int pid;
    int status;
    int test;

    signal(SIGINT, handle_signal);

    write(STDOUT_FILENO, HELLO, strlen(HELLO));
    write(STDOUT_FILENO, REGULAR_PROMPT, strlen(REGULAR_PROMPT));

    while (1) {
        command_length = read(STDIN_FILENO, command, MAX_SIZE);
        command[command_length - 1] = '\0';

        test = strcmp(EXIT, command);
        if (test == 0 || command_length == 0 || exit_requested) {
            write(STDOUT_FILENO, BYE, strlen(BYE));
            break;
        }

        pid = fork();
        if (pid == 0) {
            execlp(command, command, NULL);
            write(STDOUT_FILENO, ERR, strlen(ERR));
            _exit(EXIT_FAILURE);
        } else {
            wait(&status);
            if (WIFSIGNALED(status)) {
                sprintf(display, "%s%d%s", SIGNALED_PROMPT, WTERMSIG(status), END_PROMPT);
                write(STDOUT_FILENO, display, strlen(display));
            } else if (WIFEXITED(status)) {
                sprintf(display, "%s%d%s", EXITED_PROMPT, WEXITSTATUS(status), END_PROMPT);
                write(STDOUT_FILENO, display, strlen(display));
            }
        }
    }

    return 0;
}
