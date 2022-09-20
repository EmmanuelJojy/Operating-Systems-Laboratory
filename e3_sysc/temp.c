#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

void main() {
	char a[30];
	printf("Enter File Name: ");
	scanf("%s", a);
	
	struct stat buf;
	if(stat(a, &buf) == -1) {
		printf("ERROR");
		return;
	}
	int mode = buf.st_mode;
	printf("Mode: %d\n", mode);
	printf("FILE: %d\n\n", S_ISREG(mode));
	printf("USER: %d, %d, %d\n\n", mode & S_IRUSR, mode & S_IWUSR, mode & S_IXUSR);
}
