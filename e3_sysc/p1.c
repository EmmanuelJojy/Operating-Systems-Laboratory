//1

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
	pid_t p = fork();
	if(p < 0){
		printf("Error in fork");
	}
	else if(p == 0){
		printf("I'm Child.");
	}
	else{
		printf("I'm Parent.");
	}
	printf("\n");
	return 0;
}
