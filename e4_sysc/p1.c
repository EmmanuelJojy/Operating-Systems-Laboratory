//Q1

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

void main(int argc, char *argv[]){
	if(argc != 2){
		printf("Argument Error.\n");
		return;
	}
	char *name = argv[1];
	int status;
	
	pid_t p = fork();
	if(p < 0)
		printf("Fork Error.\n");
	else if(p == 0)
		wait(&status);
	else
		execlp("/usr/bin/cat", "cat", name, NULL);
}
