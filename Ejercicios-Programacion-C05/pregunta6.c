#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    int rc = fork();
    
    if (rc == 0) // proceso hijo
    {
        printf("soy el proceso hijo y me identificador es: %d\n", getpid());
        exit(0);
    }
    else if (rc > 0) // proceso padre
    {
        int status;
        waitpid(rc, &status, 0);
        printf("soy el proceso padre y mi identificador es: %d\n", getpid());        
    }
}
