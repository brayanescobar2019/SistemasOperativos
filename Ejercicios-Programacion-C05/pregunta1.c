#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int x;
    x = 100;
    int rc = fork();

    if (rc == 0) // proceso hijo
    {
        printf("Proceso hijo\n");
        printf("valor de x: %d\n", x);
        x = 200;
        printf("nuevo de valor de x: %d\n", x);
        
    }
    else if (rc > 0) // proceso padre
    {
        wait(NULL);
        printf("proceso padre\n");
        printf("valor de x: %d\n", x);
        x = 300;
        printf("nuevo valor de x: %d\n", x);
    }
}
