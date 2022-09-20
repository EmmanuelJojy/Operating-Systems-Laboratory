#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

long int tobin(int);
void analyse(long int);

void main(){
	char name[25], loc[50];
	struct stat buf;
	int mode;
	
	printf("Enter file name (in current directory): ");
	scanf("%s", name);

	int status = stat(name, &buf);
	if(status == -1){
		printf("File not found.\n");
		return;
	}
	mode = buf.st_mode;
	printf("MODE = %d\n", mode);
	printf("TYPE = ");
	if(S_ISDIR(mode))
		printf("DIRECTORY\n");
	if(S_ISREG(mode))
		printf("REGULAR FILE\n");
	analyse(tobin(buf.st_mode));
	printf("\n");
}

long int tobin(int n){
	long int temp = 0, b = 0;
	while(n != 0){
		temp = (temp * 10) + (n % 2);
		n /= 2;
	}
	while(temp != 0){
		b = (b * 10) + (temp % 10);
		temp /= 10;
	}
	return b;
}

void analyse(long int n){
	char s[4] = {'X', 'W', 'R'};
	int i, j, p;
	printf("\nPermission\n");
	printf("\tWORLD  GROUP  ROOT\n\t");
	if(n == 1){
		printf("- - -  - - -  - - -\n");
		return;
	}
	for(i = 0; i < 3; i++){
		p = n % 1000;
		n = n / 1000;
		for(j = 0; j < 3; j++, p /= 10){
			if(p%10 == 1)
				printf("%c ", s[j]);
			else
				printf("- ");
		}
		printf(" ");
	}
}
