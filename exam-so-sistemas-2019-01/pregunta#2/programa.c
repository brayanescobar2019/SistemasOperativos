#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "common_threads.h"
#include "mycommon.h"
#include <unistd.h>


float v = 0.0; 
puerta miPuerta;

void *worker1(void *arg){
    float y = 350;
    float z = 25;
    v = (z/y) * v;
    return NULL;
}

void *worker2(void *arg) {
    sleep(2);
    float x = 1250;
    v= x * v;
    return NULL;
}

int main(int argc, char *argv[]) {
    int x, y, z;
    pthread_t p1, p2;
    pthread_create(&p1, NULL, worker1, NULL); 
    pthread_create(&p2, NULL, worker2, NULL);
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    printf("valor de v: %f\n", v);

    return 0;
}
