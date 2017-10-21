#include<stdio.h>
#include<setjmp.h>

jmp_buf jmpbuffer;
void cmd();

int main(int argc, char *argv[]){
	printf("1\n");
	if(setjmp(jmpbuffer)!=0){
		printf("2\n");
		return 0;
	}

	printf("3\n");
	while(1)
		cmd();
	printf("4\n");
	return 0;
}

void cmd(){
	static int i = 0;
	printf("5\n");
	i++;
	if(i==2)
		longjmp(jmpbuffer, 1);
	printf("6\n");
}
