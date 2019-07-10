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
    if (rc == 0) // proceso hijo
    {
        printf("hello\n");
        kill(pid_padre, SIGCONT);
        exit(0);
    }
    else if (rc > 0) // proceso padre
    {        
        signal(SIGCONT, sig_handler); 
        pause();
    }
  
}
