#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

void main(){
	DIR *d;
	int type;
	struct dirent *de;
	d = opendir(".");
	printf("Listing Directories:\n");
	while(de = readdir(d)){
		type = de->d_type;
		if(type == 4)
			printf("%s\n", de->d_name);
	}
}
