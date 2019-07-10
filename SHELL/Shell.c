#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <dirent.h>
extern char **environ;
int funcionShell(char input[200])
{
    int ejecuto = 1;
    //**los comandos que escribe el usuario
    char *comando;
    //**obtenemos el working directory actual
    char *getcwd(char *buf, size_t size);
    //**obtenemos el nombre del directorio actual
    char cwd[FILENAME_MAX];
    //**obtenemos el primero comando
    comando = strtok(input, " ");
    //en caso de que el comando sea quit, terminamos el programa

    //**en caso de que el comando sea cd obtenemos la ruta
    if (strcmp(comando, "cd") == 0)
    {
        int ret;
        comando = strtok(NULL, " ");
        //**si la ruta existe
        if (chdir(comando) == 0)
        {
            ret = chdir(comando);
        }
        //**error
        else
        {
            perror("err");
        }
        ejecuto = 2;
    }
    //**en caso de que el usuario quiera salir
    if (strcmp(comando, "quit") == 0)
    {
        return 1;
    }
    //**en caso de que el comando sea clear, limpiamos la consola
    if (strcmp(comando, "clr") == 0)
    {
        ejecuto=2;
        system("clear");
    }
    //**en caso de que el comando sea dir <directory> obtenemos los archivos del directorio
    if (strcmp(comando, "dir") == 0)
    {
        ejecuto = 2;
        comando = strtok(NULL, " ");
        DIR *d;
        struct dirent *dir;
        //**si la ruta existe
        if(comando==NULL){
            comando="./";
        }
        if (chdir(comando) == 0)
        {
            d = opendir(".");
            while ((dir = readdir(d)) != NULL)
            {

                printf("%s\n", dir->d_name);
            }

            closedir(d);
        }
        //**error
        else
        {
            perror("err");
        }
    }
    //**en caso de que el comando sea dir environ
    if (strcmp(comando, "environ") == 0)
    {
        ejecuto = 2;
        //**mostramos las variables del ambiente
        for (char **env = environ; *env; ++env)
        {
            printf("%s\n", *env);
        }
    }
    if (strcmp(comando, "programname") == 0)
    {
        ejecuto == 2;
        comando = strtok(NULL, "\"");
        if (comando == NULL)
        {
            printf("%s\n", "Ingrese el redireccionamiento");
            char input2[200];
            scanf(" %[^\n]s", input2);
            comando = input2;
            system(comando);
        }
    }
    //**en caso de que el comando sea echo, mostramos en pantalla el comentario
    if (strcmp(comando, "echo") == 0)
    {
        ejecuto = 2;
        comando = strtok(NULL, "\"");
        printf("%s\n", comando);
    }
    //en caso de que el comando sea help
    if (strcmp(comando, "help") == 0)
    {
        ejecuto = 2;
        char *info[] = {
            "1. cd <directory> - Change the current default directory to <directory>. If the ",
            "<directory> argument is not present, report the current directory. If the direc",
            "tory does not exist an appropriate error should be reported. This command should",
            "also change the PWD environment variable. \n",
            "2. clr - Clear the screen.\n",
            "3. dir <directory> - List the contents of directory <directory>.\n",
            "4. environ - List all the environment strings.\n",
            "5. echo <comment> - Display <comment> on the display followed by a new line ",
            "(multiple spaces/tabs may be reduced to a single space).\n",
            "6. help - Display the user manual using the more filter.\n",
            "7. quit - Quit the shell.\n",
            "8. All other command line input is interpreted as program invocation, which should be ",
            "done by the shell forking and execing the programs as its own child processes.",
            "9. myshell <batchfile> the argument is a path from a file that contents a set of commands lines.\n"};
        for (int i = 0; i < 14; i++)
        {
            printf("%s", info[i]);
        }
    }

    //en caso de que el comando no esté en el programa ejecutamos comandos de linux
    else
    {
        if (ejecuto == 1)
        {
            
            char temp[255];
            while (comando != NULL)
            {
                strcat(temp, " ");
                strcat(temp, comando);
                comando = strtok(NULL, "\"");
            }
            system(temp);
            for (int i = 0; i < 255; i++)
            {
                temp[i] = '\0';
            }
        }
    }
    return 2;
}
int main(int argc, char *argv[])
{

    //**EN CASO DE QUE LA PERSONA NO LLAME EL PROGRAMA DE MANERA ADECUADA*
    if (argc > 2)
    {
        fprintf(stderr, "usage: shell <optional file>\n");
        exit(1);
    }
    else
    {
        if (argc == 2)
        {
            FILE *fp;
            if (access(argv[1], F_OK) != -1)
            {
                char linea[1024];
                fp = fopen(argv[1], "r");
                //Lee línea a línea y escribe en pantalla hasta el fin de fichero
                while (fgets(linea, 1024, (FILE *)fp))
                {
                    system(linea);
                }
            }
            else
            {
                // file doesn't exist
                perror("err");
            }
            printf("\n");
            fclose(fp);
        }
        else
        {
            printf("Bienvenido a myshell escriba un comando\n");
            char entrada[200];
            bool seguir = true;
            int result = 0;
            //**obtenemos el working directory actual
            char *getcwd(char *buf, size_t size);
            //**obtenemos el nombre del directorio actual
            char cwd[FILENAME_MAX];
            //**en caso de que el directorio en el que trabajamos sea diferente de null imprimimos el directorio
            if (getcwd(cwd, sizeof(cwd)) != NULL)
            {
                setenv("shell", strcat(cwd, "/myshell"), 1);
                setenv("parent", strcat(cwd, "/myshell"), 1);
            }
            while (seguir)
            {
                //**obtenemos el working directory actual
                char *getcwd(char *buf, size_t size);
                //**obtenemos el nombre del directorio actual
                char cwd[FILENAME_MAX];
                //**en caso de que el directorio en el que trabajamos sea diferente de null imprimimos el directorio
                if (getcwd(cwd, sizeof(cwd)) != NULL)
                {
                    setenv("PWD",cwd, 1);
                    printf("~%s$ ", cwd);
                }
                scanf(" %[^\n]s", entrada);
                if (strcmp(entrada, "quit") == 0)
                {
                    seguir = false;
                }
                else
                {
                    result = funcionShell(entrada);
                    if (result == 1)
                    {
                        seguir = false;
                    }
                }
            }
        }
        return (0);
    }
}
