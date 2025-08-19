#include <stdio.h>
#include <stdbool.h>

int main() {
    int n = 5; // Number of processes
    int m = 3; // Number of resources

    int alloc[5][3] = {
        {0, 1, 0},
        {2, 0, 0},
        {3, 0, 2},
        {2, 1, 1},
        {0, 0, 2}
    };

    int max[5][3] = {
        {7, 5, 3},
        {3, 2, 2},
        {9, 0, 2},
        {2, 2, 2},
        {4, 3, 3}
    };

    int avail[3] = {3, 3, 2};

    int need[5][3], finish[5] = {0}, safeSeq[5];
    int count = 0;

    // Calculate Need matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    // Safety Algorithm
    while (count < n) {
        bool found = false;

        for (int p = 0; p < n; p++) {
            if (!finish[p]) {
                bool canExecute = true;

                for (int j = 0; j < m; j++) {
                    if (need[p][j] > avail[j]) {
                        canExecute = false;
                        break;
                    }
                }

                if (canExecute) {
                    for (int j = 0; j < m; j++)
                        avail[j] += alloc[p][j];

                    safeSeq[count++] = p;
                    finish[p] = 1;
                    found = true;
                }
            }
        }

        if (!found) break;
    }

    // Print result
    if (count == n) {
        printf("Safe Sequence: ");
        for (int i = 0; i < n; i++)
            printf("P%d ", safeSeq[i]);
        printf("\n");
    } else {
        printf("System is in Deadlock!\n");
    }

    return 0;
}

