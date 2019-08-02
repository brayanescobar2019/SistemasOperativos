Nota: los archivos del primer punto están en la carpeta, el punto 2 tiene su propia carpeta. 

Pregunta 1:

    otroThreads: se va a encargar de medir el tiempo para el escenario donde se cierra la puerta antes del ciclo for donde se incrementa la variable compartida y abrir la puerta una vez finalizado este ciclo for.

Para medir el tiempo de ejecución me basé en el siguiente link: https://foro.elhacker.net/programacion_cc/medir_el_tiempo_de_ejecucion_en_c-t462042.0.html

    threads.c: se va a encargar de medir el tiempo para el escenario donde se encuentra ubicado dentro del ciclo for, cerrar la puerta justo antes de incrementar la variable compartida y abrir la puerta justo después de haberla incrementado.


El dato de entrada para cada uno será 200, los tiempos de cada uno son:


threads: Initial value : 0
Final value   : 400
0.000161 segundos

otroThreads:

Pregunta 2: 
el primer hilo realiza la operación z/y y el segundo hilo ejecuta sleep(2), después multiplica el resultado en el primer hilo por x.

