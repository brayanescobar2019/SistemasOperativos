Pregunta 1:

    otroThreads: Cerrar la puerta antes del ciclo for donde se incrementa la variable compartida y abrir la puerta una vez finalizado este ciclo for.

Para medir el tiempo de ejecución me basé en el siguiente link: https://foro.elhacker.net/programacion_cc/medir_el_tiempo_de_ejecucion_en_c-t462042.0.html

    Threads.c: Ubicado dentro del ciclo for, cerrar la puerta justo antes de incrementar la variable compartida y abrir la puerta justo después de haberla incrementado.


El dato de entrada para cada uno será 200, los tiempos de cada uno son:

threads:
otroThreads:

Pregunta 2: 
el primer hilo realiza la operación z/y y el segundo hilo ejecuta sleep(2), después multiplica el resultado en el primer hilo por x.

