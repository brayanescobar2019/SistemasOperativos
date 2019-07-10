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
        const char * mensajeDelHijo = "Soy el proceso hijo y estoy escribiendo\n";
        printf("proceso hijo escribiendo en el archivo\n");
        write(miArchivo, mensajeDelHijo , strlen(mensajeDelHijo));
        exit(0);
    }
    else if (rc > 0)
    {
        wait(NULL);
        const char * mensajeDelPadre = "Soy el proceso padre y estoy escribiendo\n";
        printf("proceso padre escribiendo en el archivo\n");
        write(miArchivo, mensajeDelPadre, strlen(mensajeDelPadre));
    }
    sync();
    fstat(miArchivo, &sb);
    lseek(miArchivo, 0, SEEK_SET);
    char * buffer = malloc(sb.st_size);
    read(miArchivo, buffer, sb.st_size);

    printf("contenido del archivo: \n%s", buffer);
    close(miArchivo);
    return 0;
}
