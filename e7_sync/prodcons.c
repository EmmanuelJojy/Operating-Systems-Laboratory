#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>

sem_t mutex, empty, full;
int buffer[5], in = 0, out = 0, item = 0;

void *producer(int *arg)
{
    do
    {
        sem_wait(&empty);
        sem_wait(&mutex);

        buffer[in] = item;
        printf("\n[PRODUCER %d]: buffer[%d] <- %d", *arg, in, item);
        in = (in + 1) % 5;
        item++;

        sem_post(&mutex);
        sem_post(&full);

        sleep(1);
    } while (1);
}

void *consumer(int *arg)
{
    do
    {
        sem_wait(&full);
        sem_wait(&mutex);

        printf("\n[CONSUMER %d]: buffer[%d] -> %d", *arg, out, buffer[out]);
        out = (out + 1) % 5;
        
        sem_post(&mutex);
        sem_post(&empty);

        sleep(1);
    } while (1);
}

void main()
{
    int p, c;
    printf("\nBUFFER SIZE = 5\n");

    printf("Number of Producers: ");
    scanf("%d", &p);
    pthread_t prod[p];
    int np[p];

    printf("Number of Consumers: ");
    scanf("%d", &c);
    pthread_t cons[c];
    int nc[c];

    sem_init(&mutex, 0, 1);
    sem_init(&empty, 0, 5);
    sem_init(&full, 0, 0);

    int i;
    for (i = 0; i < p; i++)
    {
        np[i] = i;
        pthread_create(&prod[i], NULL, (void *)producer, &np[i]);
    }
    for (i = 0; i < c; i++)
    {
        nc[i] = i;
        pthread_create(&cons[i], NULL, (void *)consumer, &nc[i]);
    }
    for (i = 0; i < p; i++)
        pthread_join(prod[i], NULL);
    for (i = 0; i < c; i++)
        pthread_join(cons[i], NULL);

    printf("\n\n");
    sem_destroy(&mutex);
    sem_destroy(&full);
    sem_destroy(&empty);
}
