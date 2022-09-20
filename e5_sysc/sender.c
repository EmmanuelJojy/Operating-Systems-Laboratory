#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>

void main()
{
    char s[7] = "/oslab2";
    printf("Writting to SHM (name = '%s')\n", s);

    int fd = shm_open(s, O_CREAT|O_RDWR, 0666);
    printf("File Descriptor: %d\n", fd);

    ftruncate(fd, 2*sizeof(int));

    int *shmad = mmap(NULL, 2*sizeof(int), PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
    printf("Virtual Address: %p\n", shmad);

    printf("\nA: ");
    scanf("%d", &shmad[0]);
    printf("B: ");
    scanf("%d", &shmad[1]);
    printf("\nValues written to SHM.");

    munmap(shmad, 2*sizeof(int));
    printf("\nMemory Unmapped.\n\n");
    close(fd);
}

