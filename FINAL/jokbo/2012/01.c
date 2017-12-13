#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

void err_sys(const char* x){
    perror(x);
    exit(1);
}

int glob = 31; /* external variable in initialized data */
char buf[] = "a write to stdout\n";

int main(void)
{
    int var; /* automatic variable on the stack */
    pid_t pid;
    var = 88;
    if(write(STDOUT_FILENO, buf, sizeof(buf) - 1) != sizeof(buf) - 1)
        err_sys("write error");
    printf("before fork\n"); /* we don't flush stdout */
    if((pid = fork()) < 0){
        err_sys("fork error");
    } else if(pid == 0){
        glob++; /* modify variables */
        var++;
    } else {
        sleep(2);
    }
    printf("cpid = %d, pid = %d, glob = %d, var = %d\n", pid, getpid(), glob, var);
    exit(0);
}
