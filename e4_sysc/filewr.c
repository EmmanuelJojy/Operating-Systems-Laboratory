#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void main(){
	int fd;
	char wbuf[128] = "hello, World\n\0";
	fd = open("newfile.txt", O_RDWR | O_CREAT);
	write(fd, wbuf, strlen(wbuf));
	close(fd);
}
