#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t chop[5];

void *phil(int *arg) {
	//printf("\nPHILOSOPHER %d: START THINKING", *arg);	
	
	sem_wait(&chop[*arg]);
	sem_wait(&chop[(*arg + 1) % 5]);
	
	printf("\nPHILOSOPHER %d: EAT\tCHOP = %d, %d", *arg, *arg, (*arg + 1) % 5);
	sleep(1);
	
	sem_post(&chop[*arg]);
	sem_post(&chop[(*arg + 1) % 5]);
	
	//printf("\nPHILOSOPHER %d: STOPS THINKING", *arg);
}

void main() {
	pthread_t p[5];
	int np[5] = {0, 1, 2, 3, 4};
	int i;
	for(i = 0; i < 5; i++)
		sem_init(&chop[i], 0, 1);
	for(i = 0; i < 5; i++)
		pthread_create(&p[i], NULL, (void *)phil, &np[i]);
	for(i = 0; i < 5; i++)
		pthread_join(p[i], NULL);
	for(i = 0; i < 5; i++)
		sem_destroy(&chop[i]);
	printf("\n");
}
