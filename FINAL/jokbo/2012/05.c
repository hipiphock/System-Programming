// make count global var.
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdint.h>

pthread_t ntid[8];
int count = 0;

void* thr_fn(void* arg){
    int i;
    for(i = 0; i < 10000; i++)
        count++;
    return((void*)(intptr_t)count);
}

int main(){
    int i;
    void* res;
    for(i = 0; i < 2; i++){
        pthread_create(&ntid[i], NULL, thr_fn, NULL);
    }

    for(i = 0; i < 2; i++){
        pthread_join(ntid[i], &res);
        printf("count = %d\n", (int)(intptr_t)res);
    }
    exit(0);
}
