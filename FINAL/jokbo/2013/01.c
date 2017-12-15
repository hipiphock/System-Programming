#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

void err_sys(const char* x){
    perror(x);
    exit(1);
}

char buf[] = "a write to stdout\n";

int main(void)
{
    pid_t pid;
    int glob = 31; /* external variable in initialized data */
    if(write(STDOUT_FILENO, buf, sizeof(buf) - 1) != sizeof(buf) - 1)
        err_sys("write error");
    printf("before fork\n"); /* we don't flush stdout */
    if((pid = fork()) < 0){
        err_sys("fork error");
    } else if(pid == 0){
        glob++; /* modify variables */
        sprintf(buf, "stdout\n");
    } else {
        sleep(2);
    }
    printf("%d %d %d %s\n", pid, getpid(), glob, buf);
    exit(0);
}
