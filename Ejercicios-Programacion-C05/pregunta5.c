#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int rc = fork();

    if (rc == 0) // proceso hijo
    {
        int miEspera = wait(NULL);
        printf("proceso hijo\n");
        printf("el codigo de retorno de wait() es %d\n", miEspera);
    }
    else if (rc > 0) // proceso padre
    {
        printf("proceso padre\n");
    }
}
