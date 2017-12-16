#include <stdio.h>
#include <ctype.h>

int main()
{
    char c;
    while(scanf("%c", &c) != EOF)
        printf("%c", toupper(c));
    return 0;
}
