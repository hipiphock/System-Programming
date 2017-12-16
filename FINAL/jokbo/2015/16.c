//header
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int ticks = 0;
void handler(int signum){
    ticks++;
    printf("tick tock: %d\n", ticks);
    if(ticks < 10){
        alarm(1);
    } else {
        raise(SIGQUIT); //MARK 1
    }
}

int main()
{
    signal(SIGALRM, handler);   //<--MARK 2
    alarm(1);
    //MARK 3
    while(1)
        pause();    //<--MARK 3
    return 0;
}
