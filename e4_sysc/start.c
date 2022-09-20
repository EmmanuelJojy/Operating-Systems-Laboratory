#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void main(){
	open("newfile.txt", O_RDWR | O_CREAT);
}
