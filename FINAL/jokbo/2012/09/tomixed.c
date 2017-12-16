#include <stdio.h>
#include <ctype.h>

int main()
{
    char c;
    while(scanf("%c", &c) != EOF){
        if('a' <= c && c <= 'z')
            printf("%c", toupper(c));
        else if('A' <= c && c <= 'Z')
            printf("%c", tolower(c));
    }
    return 0;
}
