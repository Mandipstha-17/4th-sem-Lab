#include <stdio.h>      // For printf()
#include <pthread.h>    // For POSIX threads (pthreads)
#include <unistd.h>     // For sleep()

#define NUM_THREADS 3   // Define how many threads we want to create

// Thread function that will be executed by each thread
void *print_message(void *thread_id) {
    // Convert the passed thread ID to a long integer
    long tid = (long)thread_id;

    // Print message indicating the thread has started
    printf("Thread %ld started (TID: %lu)\n", 
           tid, (unsigned long)pthread_self());

    // Simulate work by sleeping for (1 + tid) seconds
    sleep(1 + tid);

    // Print message indicating the thread is about to complete
    printf("Thread %ld completing\n", tid);

    // Exit the thread and return a value (tid * 100)
    pthread_exit((void *)(tid * 100));
}

int main() {
    pthread_t threads[NUM_THREADS];  // Array to hold thread IDs
    int rc;                          // Variable to store return code of pthread_create

    // Loop to create threads
    for (long t = 0; t < NUM_THREADS; t++) {
        // Print a message before creating each thread
        printf("Creating thread %ld\n", t);

        // Create a thread, passing:
        // - Address of the pthread_t variable to store thread ID
        // - NULL for default thread attributes
        // - Function to run in the thread
        // - Thread ID (t) cast as void* to pass to the function
        rc = pthread_create(&threads[t], NULL, print_message, (void *)t);

        // Check if thread creation was successful
        if (rc) {
            printf("Error creating thread %ld\n", t);
            return -1;  // Exit with error
        }
    }

    // Wait for all threads to finish and collect their return values
    void *status;  // To store the exit value returned by each thread
    for (long t = 0; t < NUM_THREADS; t++) {
        // Wait (join) for each thread to complete
        pthread_join(threads[t], &status);

        // Print the return value of each thread
        printf("Thread %ld returned %ld\n", t, (long)status);
    }

    // Indicate that all threads have completed
    printf("All threads completed\n");

    // Optional: Call pthread_exit to allow any remaining threads to finish cleanly
    pthread_exit(NULL);
}
