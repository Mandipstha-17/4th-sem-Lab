#include <stdio.h>
#include <stdlib.h>

int main() {
    int requests[] = {82, 170, 43, 140, 24, 16, 190};
    int head = 50, n = 7, total = 0, direction = 1; // 1 = Right, -1 = Left
    int max_cylinder = 199;

    // Sort requests (for simplicity, assume sorted as {16, 24, 43, 82, 140, 170, 190})
    // Simulate SCAN movement
    if (direction == 1) {
        for (int i = head; i <= max_cylinder; i++) 
            for (int j = 0; j < n; j++) 
                if (requests[j] == i) 
                    total += abs(i - head), head = i;
        total += max_cylinder - head; // Move to end
        head = max_cylinder;
    } else {
        for (int i = head; i >= 0; i--) 
            for (int j = 0; j < n; j++) 
                if (requests[j] == i) 
                    total += abs(i - head), head = i;
        total += head; // Move to start
        head = 0;
    }
    printf("Total Seek Time (SCAN): %d\n", total);
    return 0;
}