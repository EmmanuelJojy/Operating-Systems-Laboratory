#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>

void main()
{
    char s[7] = "/oslab2";
    printf("Reading from SHM (name = '%s')\n", s);

    int fd = shm_open(s, O_RDONLY, 0666);
    printf("File Descriptor: %d\n", fd);

    if (fd == -1)
	{
		printf("Error accessing shared memory. Failure.\n");
		return;
	}

    int *shmad = mmap(NULL, 2*sizeof(int), PROT_READ, MAP_SHARED, fd, 0);
    printf("Virtual Address: %p\n", shmad);

    printf("\n'%d' and '%d' read from SHM.\n", shmad[0], shmad[1]);

    munmap(shmad, 2*sizeof(int));
    printf("\nMemory Unmapped.\n");
    shm_unlink(s);
    printf("Memory Unlinked.\n\n");
    close(fd);
}

