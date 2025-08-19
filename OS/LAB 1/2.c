#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_PHILOSOPHERS 5
#define THINKING 0
#define HUNGRY 1
#define EATING 2

sem_t mutex;
sem_t S[NUM_PHILOSOPHERS];  
int state[NUM_PHILOSOPHERS];

void *philosopher(void *num);
void take_chopsticks(int);
void put_chopsticks(int);
void test(int);

int main() {
    pthread_t philosophers[NUM_PHILOSOPHERS];
    int philosopher_numbers[NUM_PHILOSOPHERS];

    // Initialize semaphores
    sem_init(&mutex, 0, 1);
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        sem_init(&S[i], 0, 0);
        philosopher_numbers[i] = i;
        state[i] = THINKING;
    }

    // Create philosopher threads
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_create(&philosophers[i], NULL, philosopher, &philosopher_numbers[i]);
    }

    // Wait for threads (runs indefinitely)
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_join(philosophers[i], NULL);
    }

    // Clean up
    sem_destroy(&mutex);
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        sem_destroy(&S[i]);
    }

    return 0;
}

void *philosopher(void *num) {
    int i = *(int *)num;
    while (1) {
        printf("Philosopher %d is thinking\n", i);
        sleep(1);
        take_chopsticks(i);
        printf("Philosopher %d is eating\n", i);
        sleep(1);
        put_chopsticks(i);
    }
}

void take_chopsticks(int i) {
    sem_wait(&mutex);
    state[i] = HUNGRY;
    printf("Philosopher %d is hungry\n", i);
    test(i);
    sem_post(&mutex);
    sem_wait(&S[i]); // Wait until allowed to eat
}

void put_chopsticks(int i) {
    sem_wait(&mutex);
    state[i] = THINKING;
    printf("Philosopher %d has finished eating\n", i);
    // Check if neighbors can now eat
    test((i + NUM_PHILOSOPHERS - 1) % NUM_PHILOSOPHERS);
    test((i + 1) % NUM_PHILOSOPHERS);
    sem_post(&mutex);
}

void test(int i) {
    if (state[i] == HUNGRY &&
        state[(i + NUM_PHILOSOPHERS - 1) % NUM_PHILOSOPHERS] != EATING &&
        state[(i + 1) % NUM_PHILOSOPHERS] != EATING) {
        state[i] = EATING;
        sem_post(&S[i]);  // Signal the philosopher to start eating
    }
}