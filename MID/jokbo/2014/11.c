#include <stdio.h>
#include <setjmp.h>

void cmd();
jmp_buf jmpbuffer;

int main(int argc, char * argv[]){
		register int i = 0;
		static int j = 0;

		printf("A\n");
		if(setjmp(jmpbuffer)!=0){
				printf("B\n");
				printf("%d %d\n", i, j);	//출력물이 정해지지 않는 경우 ?로 적으세요.
				return 0;
		}

		i++;
		j++;
		printf("C\n");
		cmd();
		printf("D\n");
		return 0;
}

void cmd(){
		int i = 0;
		printf("E\n");
		while(1){
				i++;
				if(i == 2)
						longjmp(jmpbuffer, 1);
		}
		printf("F\n");
}
