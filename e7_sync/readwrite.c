#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

// #define RW_LIMIT = 10;

sem_t mutex, rwmutex;
int read_count = 0;

void *reader(int *arg) {
	do {
		sem_wait(&mutex);
		read_count++;
		if(read_count == 1) {
			sem_wait(&rwmutex);
			//printf("\n");
		}
		sem_post(&mutex);
		
		printf("\n[READER %d]: READING...", *arg);
		
		sem_wait(&mutex);
		read_count--;
		if(read_count == 0) {
			sem_post(&rwmutex);
			//printf("\n");
		}
		sem_post(&mutex);
		sleep(1);
	}while(1);
}

void *writer(int *arg) {
	do{
		sem_wait(&rwmutex);
		
		printf("\n[WRITER %d]: WRITING...", *arg);
		
		sem_post(&rwmutex);
		sleep(1);
	}while(1);
}

void main() {
	int r, w;
	int i, j;
	printf("--- READER / WRITERS PROBLEM ---\n");
	// printf("(All readers and writer write ONLY %d block of data)\n\n", RW_LIMIT); 
	printf("Number of Readers: ");
	scanf("%d", &r);
	pthread_t rp[r];
	int nr[r];
	
	printf("Number of Writers: ");
	scanf("%d", &w);
	pthread_t wp[w];
	int nw[w];
	
	sem_init(&mutex, 0, 1);
	sem_init(&rwmutex, 0, 1);
	
	for(i = 0; i < w; i++) {
		nw[i] = i;
		pthread_create(&wp[i], NULL, (void *)writer, &nw[i]);
	}
	
	for(i = 0; i < r; i++) {
		nr[i] = i;
		pthread_create(&rp[i], NULL, (void *)reader, &nr[i]);
	}
	
	for(i = 0; i < r; i++)
		pthread_join(rp[i], NULL);
	for(i = 0; i < w; i++)
		pthread_join(wp[i], NULL);
	
	sem_destroy(&mutex);
	sem_destroy(&rwmutex);
	printf("\n");
}
	
