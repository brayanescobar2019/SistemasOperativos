#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "common.h"
#include "common_threads.h"
#include "mycommon.h"


volatile int counter = 0; 
puerta miPuerta;
int loops;


void *worker(void *arg) {
    int i;
    cerrar_puerta(miPuerta);
    for (i = 0; i < loops; i++) {
	counter++;
    }
    abrir_puerta(m);
    return NULL;
}

int main(int argc, char *argv[]) {
    clock_t tiempo_inicio, tiempo_final;
    double segundos;

    tiempo_inicio = clock();
    if (argc != 2) { 
	fprintf(stderr, "usage: threads <loops>\n"); 
	exit(1); 
    } 
    crear_puerta(miPuerta);
    loops = atoi(argv[1]);
    pthread_t p1, p2;
    printf("Initial value : %d\n", counter);
    pthread_create(&p1, NULL, worker, NULL); 
    pthread_create(&p2, NULL, worker, NULL);
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    printf("Final value   : %d\n", counter);
    destruir_puerta(miPuerta);
    tiempo_final = clock();
    segundos = (double) (tiempo_final - tiempo_inicio) / CLOCKS_PER_SEC;
    printf("%f segundos \n", segundos);
    return 0;
}
