Aquí va la descripción
 
 
 # Pregunta 1
 * [pregunta1.c] (pregunta1.c)
 
Write a program that calls fork(). Before calling fork(), have the
main process access a variable (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
What happens to the variable when both the child and parent change
the value of x?

Respuesta:

 # Pregunta 2
 aquí va el enlace

Write a program that opens a file (with the open() system call)
and then calls fork() to create a new process. Can both the child
and parent access the file descriptor returned by open()? What
happens when they are writing to the file concurrently, i.e., at the
same time?

Respuesta:


 # Pregunta 3
 aquí va el enlace
 
 Write another program using fork(). The child process should
print “hello”; the parent process should print “goodbye”. You should
try to ensure that the child process always prints first; can you do
this without calling wait() in the parent?

Respuesta:


 # Pregunta 4
 aquí va el enlace
 
  Write a program that calls fork() and then calls some form of
exec() to run the program /bin/ls. See if you can try all of the
variants of exec(), including (on Linux) execl(), execle(),
execlp(), execv(), execvp(), and execvpe(). Why do
you think there are so many variants of the same basic call?

Respuesta:


# Pregunta 5
aquí va el enlace

 Now write a program that uses wait() to wait for the child process
to finish in the parent. What does wait() return? What happens if
you use wait() in the child?

Respuesta:


# Pregunta 6
aquí va el enlace

 Write a slight modification of the previous program, this time using waitpid() instead of wait(). When would waitpid() be
useful?

Respuesta:


# Pregunta 7
aquí va el enlace

Write a program that creates a child process, and then in the child
closes standard output (STDOUT FILENO). What happens if the child
calls printf() to print some output after closing the descriptor?

Respuesta:
 
 
