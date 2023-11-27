#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>

#define WELCOME_MESSAGE "Welcome to ENSEA Shell \n Pour quitter tapez exit \n"
#define ERR "This command doesn't exist. Are you sure ? \n"

#define REGULAR_PROMPT "enseash %  "
#define EXITED_PROMPT "enseash [exit : "
#define SIGNALED_PROMPT "enseash [sign : "
#define END_PROMPT "] % "

#define MAX_SIZE 128
#define MAX_ARG 10
#define EXIT "exit"
