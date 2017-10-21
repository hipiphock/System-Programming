#include <stdio.h>
#include <stdlib.h>

void m1(void){
	printf("1\n");
}

void m2(void){
	printf("2\n");
}

int main(void){
	printf("start\n");
	atexit(m1);
	atexit(m2);
	atexit(m2);
	printf("done\n");
	return 0;
}
