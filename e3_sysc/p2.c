//2

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
	printf("P = Parent Process, C = Child Process\n");
	pid_t p = fork();
	if(p < 0){
		printf("Error in fork");
	}
	else if(p == 0){
		for(int i=1;i<=10;i++){
			printf("C%d ", i);
			fflush(stdout);
		}
	}
	else{
		for(int i=1;i<=10;i++){
			printf("P%d ", i);
			fflush(stdout);
		}
		wait(NULL);
		printf("\n");
	}
	return 0;
}
