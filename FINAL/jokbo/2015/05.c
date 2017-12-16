#include <stdio.h>
#include <unistd.h>


int main()
{
    int pip[2];
    FILE* fp0;
    FILE* fp1;
    char buffer[100];
    pipe(pip);

    fp0 = fdopen(3, "r");
    fp1 = fdopen(4, "w");
    fprintf(fp1, "%s", "HI");
    fclose(fp1);
    fscanf(fp0, "%s\n", buffer);
    fprintf(stdout, "%s", buffer);
    printf("\n");
    return 0;
}
