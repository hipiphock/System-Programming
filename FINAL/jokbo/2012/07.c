// should add mutex
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

pthread_t ntid[8];

typedef struct SharedData{
    int count;
    pthread_mutex_t lock;
}SharedData;

void* thr_fn(void* arg){
    SharedData *pd = (SharedData*)arg;
    int i;
    pthread_mutex_lock(&pd->lock);
    for (i = 0; i < 10000; i++) {
        pd->count=pd->count + 1;
    }
    pthread_mutex_unlock(&pd->lock);
    return((void*)0);
}

int main()
{
    SharedData d;
    SharedData* pd = &d;
    int i;
    d.count = 0;

    pthread_mutex_init(&pd->lock, NULL);

    for (i = 0; i < 8; i++) {
        pthread_create(&ntid[i], NULL, thr_fn, (void*)pd);
    }

    for (i = 0; i < 8; i++) {
        pthread_join(ntid[i], NULL);
    }
    printf("count=%d\n", d.count);
    exit(0);
}
