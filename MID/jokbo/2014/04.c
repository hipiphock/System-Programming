#include <stdio.h>
#include <stdlib.h>

int a = 3;
int F();

int main(){
	int k = 0;
	int *l = malloc(10);
	F();
	printf("B:%p\n", &k);
	printf("C:%p\n", &a);
	printf("D:%p\n", &F);
	printf("E:%p\n", l);
}

int F(){
	int l;
	printf("A:%p\n", &l);
	return 0;
}
