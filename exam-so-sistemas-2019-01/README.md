Nota: los archivos del primer punto están en la carpeta del parcial, el punto 2 tiene su propia carpeta. 

Pregunta 1:

    otroThreads: se va a encargar de medir el tiempo para el escenario donde se cierra la puerta antes del ciclo for donde se incrementa la variable compartida y abrir la puerta una vez finalizado este ciclo for.

Para medir el tiempo de ejecución me basé en el siguiente link: https://foro.elhacker.net/programacion_cc/medir_el_tiempo_de_ejecucion_en_c-t462042.0.html

    threads.c: se va a encargar de medir el tiempo para el escenario donde se encuentra ubicado dentro del ciclo for, cerrar la puerta justo antes de incrementar la variable compartida y abrir la puerta justo después de haberla incrementado.


El dato de entrada para cada uno será 200, los tiempos de cada uno son:

(1)
otroThreads: Initial value : 0
Final value   : 400
0.000173 segundos

threads: Initial value : 0
Final value   : 400
0.000161 segundos

(2)
otroThreads: Initial value : 0
Final value   : 400
0.000178 segundos

threads: Initial value : 0
Final value   : 400
0.000169 segundos

(3)
otroThreads: Initial value : 0
Final value   : 400
0.000186 segundos

threads: Initial value : 0
Final value   : 400
0.000170 segundos

(4)
otroThreads: Initial value : 0
Final value   : 400
0.000191 segundos

threads: Initial value : 0
Final value   : 400
0.000176 segundos

(5)
otroThreads: Initial value : 0
Final value   : 400
0.000199 segundos

threads: Initial value : 0
Final value   : 400
0.000182 segundos

El primer hilo fue más rapido que el segundo debido a que se cierra antes del for, el segundo se toma un poco más de tiempo ya que ese es el tiempo que se toma en abrir y cerrar la puerta 


Pregunta 2: 

    El primer hilo realiza la operación z/y y el segundo hilo ejecuta sleep(2), después multiplica el resultado en el primer hilo por x.

