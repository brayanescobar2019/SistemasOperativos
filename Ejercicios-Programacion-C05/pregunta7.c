#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int rc = fork();

    if (rc == 0) // proceso hijo
    {
        close(STDOUT_FILENO);
        printf("Esto no debería verse\n");
    }
    else if (rc > 0) // proceso padre
    {
        wait(NULL);
        printf("Soy el proceso padre\n");
    }
}
