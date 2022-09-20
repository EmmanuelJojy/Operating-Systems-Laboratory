#include <stdio.h>
#include <unistd.h>
#include <sys/shm.h>

void main()
{
	key_t key = 12345;
	printf("Writing to Shared Memory (Key = %d)\n", key);

	int shmid = shmget(key, sizeof(int), 0666 | IPC_CREAT);
	printf("shmid:\t%d\n", shmid);

	void *shmad = shmat(shmid, NULL, 0);
	printf("shmad:\t%p\n", shmad);

	int n;
	printf("\nFactorial:\n");
	printf("N = ");
	scanf("%d", &n);
	sprintf(shmad, "%d", n);
	printf("\nWrite '%d' to SHM complete.\n\n", n);
}
