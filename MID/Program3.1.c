/*
	./a.out < /etc/motd
	seek oK
	cat < /etc/motd | ./a.out
	cannot seek
	./a.out < /var/spool/cron/FIFO
	cannot seek
*/

#include <"apue.h">

int main(void){
	if(lseek(STDIN_FILENO, 0, SEEK_CUR) == -1)
		printf("cannot seek\n");
	else
		printf("seek OK\n");
	exit(0);
}
