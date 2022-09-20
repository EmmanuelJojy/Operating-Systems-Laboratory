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
	printf("Listing Files:\n");
	while(de = readdir(d)){
		type = de->d_type;
		if(type == 8)
			printf("%s\n", de->d_name);
	}
}
