#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
	pid_t p = fork();
	if(p < 0){
		printf("Error in fork");
	}
	else if(p == 0){
		printf("Child Process  -> PID: %d, PPID: %d", getpid(), getppid());
	}
	else{
		printf("Parent Process -> PID: %d, PPID: %d", getpid(), getppid());
	}
	printf("\n");
	return 0;
}
