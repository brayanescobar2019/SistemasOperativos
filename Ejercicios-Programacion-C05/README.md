En este espacio se responden las preguntas correspondientes al capítulo 5 (de la 1 a la 7) del libro Operating systems Three Easy Pieces. Además, por cada pregunta se tiene un enlace donde se lleva a un archivo de este repositorio con el código correspondiente.
 
 
 # Pregunta 1
 * [pregunta1.c](pregunta1.c)
 
Write a program that calls fork(). Before calling fork(), have the
main process access a variable (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
What happens to the variable when both the child and parent change
the value of x?

Respuesta:

 # Pregunta 2
 * [pregunta2.c](pregunta2.c)

Write a program that opens a file (with the open() system call)
and then calls fork() to create a new process. Can both the child
and parent access the file descriptor returned by open()? What
happens when they are writing to the file concurrently, i.e., at the
same time?

Respuesta:


 # Pregunta 3
 * [pregunta3.c](pregunta3.c)
 
 Write another program using fork(). The child process should
print “hello”; the parent process should print “goodbye”. You should
try to ensure that the child process always prints first; can you do
this without calling wait() in the parent?

Respuesta:


 # Pregunta 4
 * [pregunta4.c](pregunta4.c)
 
  Write a program that calls fork() and then calls some form of
exec() to run the program /bin/ls. See if you can try all of the
variants of exec(), including (on Linux) execl(), execle(),
execlp(), execv(), execvp(), and execvpe(). Why do
you think there are so many variants of the same basic call?

Respuesta:


# Pregunta 5
* [pregunta5.c](pregunta5.c)

 Now write a program that uses wait() to wait for the child process
to finish in the parent. What does wait() return? What happens if
you use wait() in the child?

Respuesta:


# Pregunta 6
* [pregunta6.c](pregunta6.c)

 Write a slight modification of the previous program, this time using waitpid() instead of wait(). When would waitpid() be
useful?

Respuesta:


# Pregunta 7
* [pregunta7.c](pregunta7.c)

Write a program that creates a child process, and then in the child
closes standard output (STDOUT FILENO). What happens if the child
calls printf() to print some output after closing the descriptor?

Respuesta:
 
 
