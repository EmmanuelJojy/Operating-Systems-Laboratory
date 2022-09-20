#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(){
	printf("hello, World!");
	for(int i = 0; i < 1000; i++);
	sleep(2);
	pid_t p = fork();
	printf("\nExpect 2\n");
	if(p < 0){
		printf("Fork Unsuccessful");
	}
	else if(p == 0){
		printf("Child Process");
	}
	else{
		printf("Parent Process");
		sleep(10);
	}
	printf("\n");
	return 0;
}
