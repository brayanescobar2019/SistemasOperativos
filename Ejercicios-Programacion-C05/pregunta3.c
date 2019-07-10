#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void sig_handler(int signum) {
    printf("goodbye\n");
    exit(0);
}

int main (int argc, char const *argv[]) {
    int pid_padre = getpid();
    int rc = fork();
    if (rc == 0) //child
    {
        printf("hello\n");
        kill(pid_padre, SIGCONT);
        exit(0);
    }
    else if (rc > 0) // parent
    {
        //  https://www.unix.com/302582537-post2.html?s=c29ed69cf8a6adc4c14984b71e3aa176
        
        signal(SIGCONT, sig_handler); 
        pause();
    }
  
}
