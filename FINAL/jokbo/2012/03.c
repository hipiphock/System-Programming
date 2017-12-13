#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

//typedef sigset_t int;

void err_sys(const char* x){
    perror(x);
    exit(1);
}

static void sig_usr1(int signo){
    printf("caught SIGUSR1\n");
}

int main(void)
{
    sigset_t newmask, oldmask, pendmask;

    if(signal(SIGUSR1, sig_usr1) == SIG_ERR)
        err_sys("can't catch SIGUSR1");

    sigemptyset(&newmask);
    sigaddset(&newmask, SIGUSR1);
    if(sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
        err_sys("SIG_BLOCK error");

    sleep(15);

    /* Reset signal mask */
    if(sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
        err_sys("SIG_SETMASK error");

    sleep(15);
    printf("done!\n");
    exit(0);
}
