#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#define BUFFER_SIZE 5
int buffer[BUFFER_SIZE];
int in = 0, out = 0;
sem_t mutex, empty, full;
void *producer(void *arg) {
 int item;
 for (int i = 0; i < 10; i++) {
 item = rand() % 100; // Produce random item

 sem_wait(&empty); // Wait if buffer is full
 sem_wait(&mutex); // Enter critical section

 buffer[in] = item;
 printf("Producer produced %d\n", item);
 in = (in + 1) % BUFFER_SIZE;

 sem_post(&mutex); // Leave critical section
 sem_post(&full); // Signal that buffer has one more item

 sleep(rand() % 2); // Simulate random production time
 }
 return NULL;
}
void *consumer(void *arg) {
 int item;
 for (int i = 0; i < 10; i++) {
 sem_wait(&full); // Wait if buffer is empty
 sem_wait(&mutex); // Enter critical section

 item = buffer[out];
 printf("Consumer consumed %d\n", item);
 out = (out + 1) % BUFFER_SIZE;

 sem_post(&mutex); // Leave critical section
 sem_post(&empty); // Signal that buffer has one more empty slot

 sleep(rand() % 2); // Simulate random consumption time
 }
 return NULL;
}
int main() {
 pthread_t prod_thread, cons_thread;

 // Initialize semaphores
 sem_init(&mutex, 0, 1);
 sem_init(&empty, 0, BUFFER_SIZE);
 sem_init(&full, 0, 0);

 // Create producer and consumer threads
 pthread_create(&prod_thread, NULL, producer, NULL);
 pthread_create(&cons_thread, NULL, consumer, NULL);

 // Wait for threads to finish
 pthread_join(prod_thread, NULL);
 pthread_join(cons_thread, NULL);

 // Destroy semaphores
 sem_destroy(&mutex);
 sem_destroy(&empty);
 sem_destroy(&full);

 return 0;
}

