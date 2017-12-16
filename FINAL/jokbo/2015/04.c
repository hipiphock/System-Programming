#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int var = 1;
pthread_mutex_t lock;

void* myThread(void* arg){
//    printf("\t%d\n", *(int*)arg);
    sleep(*(int*)arg);
    static int glob = 31;
    int nvar = 30;
    pthread_mutex_lock(&lock);
    glob++;
    pthread_mutex_unlock(&lock);
    var++;
    nvar++;
    printf("%d %d %d\n", glob, var, nvar);
    return NULL;
}

int main()
{
    void* res;
    pthread_t thread[2];
    int a = 1;
    int b = 2;
    int* one = &a;
    int* two = &b;

    pthread_create(&thread[0], NULL, myThread, one);
    pthread_create(&thread[1], NULL, myThread, two);

    pthread_join(thread[0], &res);
    pthread_join(thread[1], &res);

    return 0;
}
