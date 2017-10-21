#include <stdio.h>

int main(void){
	char ch[2];
	while(read(0, ch, 1))
		write(1, ch, 1);
	return 0;
}
