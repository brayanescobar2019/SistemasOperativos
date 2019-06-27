#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    struct stat sb;
    int miArchivo = open("miArchivo.txt", O_CREAT | O_RDWR, S_IRWXU);
    
    int rc = fork();

    if (rc == 0)
    {
        const char * child_msg = "Hello, I am child process. Writing on you\n";
        printf("proceso hijo escribiendo en el archivo\n");
        write(miArchivo, child_msg , strlen(child_msg));
        exit(0);
    }
    else if (rc > 0)
    {
        wait(NULL);
        const char * parent_msg = "Hello, I am parent process. Writing on you\n";
        printf("proceso padre escribiendo en el archivo\n");
        write(miArchivo, parent_msg, strlen(parent_msg));
    }
    sync();
    fstat(miArchivo, &sb);
    lseek(miArchivo, 0, SEEK_SET);
    char * buffer = malloc(sb.st_size);
    read(miArchivo, buffer, sb.st_size);

    printf("Content of file: \n%s", buffer);
    close(miArchivo);
    return 0;
}
