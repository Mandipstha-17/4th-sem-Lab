#include <stdio.h>        // For printf(), perror()
#include <unistd.h>       // For fork(), execlp(), getpid(), getppid(), _exit()
#include <sys/wait.h>     // For waitpid(), WIFEXITED(), WEXITSTATUS()

int main() {
    // Print the starting message and the current (parent) process ID
    printf("Parent starting (PID: %d)\n", getpid());

    // Create a new process using fork()
    pid_t pid = fork();

    // Check the result of fork()
    if (pid == 0) {
        // -------------------
        // Child process block
        // -------------------

        // Print child process ID and parent process ID
        printf("Child running (PID: %d, Parent PID: %d)\n", 
               getpid(), getppid());

        // Replace the current child process image with the `ls -l` command
        // This replaces the current process with the `/bin/ls` program
        execlp("/bin/ls", "ls", "-l", NULL);

        // If execlp() fails, this code is executed
        perror("execlp failed");

        // Exit the child process with error status 1 (use _exit, not exit)
        _exit(1);  
    } 
    else if (pid > 0) {
        // --------------------
        // Parent process block
        // --------------------

        // Print the child's PID
        printf("Parent waiting for child (PID: %d)\n", pid);

        int status;

        // Wait for the child process to finish
        waitpid(pid, &status, 0);

        // Check if child exited normally
        if (WIFEXITED(status)) {
            // Print the child’s exit status code
            printf("Child exited with status %d\n", WEXITSTATUS(status));
        }
    } 
    else {
        // -----------------
        // Forking failed
        // -----------------

        perror("fork failed");  // Print error message
        return 1;               // Return error code
    }

    // Final message from parent process
    printf("Parent process ending\n");
    return 0;
}

