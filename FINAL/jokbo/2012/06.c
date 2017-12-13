#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

pthread_t ntid[8];

typedef struct SharedData{
    int count;
    pthread_mutex_t lock;
}SharedData;

void* thr_fn(void* arg){
    SharedData d;
    SharedData *pd = &d;
    int i;
    d.count = 0;

    for (i = 0; i < 8; i++) {
        pthread_create(&ntid[i], NULL, thr_fn, (void*)pd);
    }

    for (i = 0; i < 8; i++) {
        pthread_join(ntid[i], NULL);
    }
    printf("count=%d\n", d.count);
    exit(0);
}
