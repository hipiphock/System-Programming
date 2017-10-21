#include <stdio.h>
int main(void){
		char ch;
		char buf[18];
		setvbuf(stdout, buf, _IONBF, 18);

		while((ch = getchar()) != '#')
			putchar(ch);

		return 0;
}
