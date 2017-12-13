#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

void *thread(void *vargp){
    printf("Hello, world!\n");
    return NULL;
}

int main(){
    pthread_t tid;
    pthread_create(&tid, NULL, thread, NULL);
    sleep(2);
    pthread_join(tid, NULL);
    exit(0);
}
