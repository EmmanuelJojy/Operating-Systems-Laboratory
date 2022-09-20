#include <stdio.h>
#include <string.h>

#include <unistd.h>
#include<fcntl.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

void main(int argc, char *argv[]){
	if(argc != 3){
		printf("Argument Error.\n");
		return;
	}
	
	char *a = argv[1], *b = argv[2];
	char buf[128] = "";
	int rfd, wfd, stat;
	
	// only read
	rfd = open(a, O_RDONLY);
	
	// only write
	wfd = open(b, O_WRONLY);
	if(wfd == -1)
		wfd = open(b, O_WRONLY | O_CREAT);
	write(wfd, "START\n", 6);
	while(read(rfd, buf, 1) > 0){
		write(wfd, buf, strlen(buf));
	}
	write(wfd, "\nSTOP\n", 6);
	
	close(rfd);
	close(wfd);
	
	printf("Copied Contents from %s -> %s\n", a, b);
	return;
}
