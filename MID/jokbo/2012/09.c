#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

	char* path = argv[1];
	struct stat  statbuf;
	struct dirent *dirp;
	DIR *dp;
	if((dp = opendir(path))==NULL)
		exit(1);

	while((dirp = readdir(dp)) != NULL){
		printf("%s\n", dirp->d_name);
	}

	return 0;
}
