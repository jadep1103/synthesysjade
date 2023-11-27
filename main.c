#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "constantheader.h"

int main(){
    write(STDIN_FILENO,WELCOME_MESSAGE,strlen(WELCOME_MESSAGE));
    return 0;
}