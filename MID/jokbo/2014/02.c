//#include "apue.h"
#include <fcntl.h>

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ\n";

int main(void){
	int fd;
	fd = creat("out", FILE_MODE);
	write(fd, buf1, 10);
	lseek(fd, -1, SEEK_END);
	write(fd, &buf2[5], 5);
	close(fd);
	return 0;
}
