#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static void sig_usr1(int signo){
    printf("caught SIGUSR1\n");
}

int main(void)
{
    sigset_t newmask, oldmask, pendmask;

    if(signal(SIGUSR1, sig_usr1) == SIG_ERR){
        perror("can't catch SIGUSR1");
        exit(1);
    }

    sigemptyset(&newmask);
    sigaddset(&newmask, SIGUSR1);
    if(sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0){
        perror("can't catch SIGUSR1");
        exit(1);
    }

    sleep(15);

    /* reset signal mask */
    if(sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0){
        perror("can't catch SIGUSR1");
        exit(1);
    }

    sleep(15);
    printf("done!\n");

    exit(0);
}
