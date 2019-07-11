#### El Shell se compila y se ejecuta:

            gcc Shell.c -o Shell
            ./Shell

#### y los comandos que se ejecutan son:


1. cd <directory> - Change the current default directory to <directory>. If the,<directory> argument is not present, report the current directory. If the directory does not exist an appropriate error should be reported. This command should also change the PWD environment variable.
2. clr - Clear the screen.               
3. dir <directory> - List the contents of directory <directory>.
4. environ - List all the environment strings.
5. echo <comment> - Display <comment> on the display followed by a new line(multiple spaces/tabs may be reduced to a single space).
6. help - Display the user manual using the more filter.
7. quit - Quit the shell.
8. All other command line input is interpreted as program invocation, which should be done by the shell forking and execing the programs as its own child processes.
9. myshell <batchfile> the argument is a path from a file that contents a set of commands lines.
