#include <stdio.h>

int main() {
    int n = 5; // Processes
    int m = 3; // Resources
    int alloc[5][3] = { {0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2} };
    int request[5][3] = { {0, 0, 0}, {2, 0, 2}, {0, 0, 0}, {1, 0, 0}, {0, 0, 2} };
    int avail[3] = {0, 0, 0};
    int work[3], finish[5] = {0}, deadlock = 0;

    // Initialize Work = Available
    for (int i = 0; i < m; i++) 
        work[i] = avail[i];

    // Deadlock Detection
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            if (alloc[i][j] != 0) 
                finish[i] = 0;
            else 
                finish[i] = 1;

    while (1) {
        int found = 0;
        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                int canExecute = 1;
                for (int j = 0; j < m; j++) 
                    if (request[i][j] > work[j]) 
                        canExecute = 0;
                if (canExecute) {
                    for (int j = 0; j < m; j++) 
                        work[j] += alloc[i][j];
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if (!found) break;
    }

    for (int i = 0; i < n; i++) 
        if (!finish[i]) {
            deadlock = 1;
            printf("Deadlock detected at Process P%d\n", i);
        }
    
    if (!deadlock) 
        printf("No deadlock detected.\n");
    
    return 0;
}