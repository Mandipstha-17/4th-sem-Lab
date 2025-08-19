#include <stdio.h>
#include <stdlib.h>

int main() {
    int requests[] = {82, 170, 43, 140, 24, 16, 190};
    int head = 50, n = 7, total = 0, max_cylinder = 199;

    // Simulate C-SCAN (right only, wrap around)
    for (int i = head; i <= max_cylinder; i++) 
        for (int j = 0; j < n; j++) 
            if (requests[j] == i) 
                total += abs(i - head), head = i;
    total += max_cylinder - head; // Move to end
    head = max_cylinder;
    total += max_cylinder; // Jump to 0
    head = 0;
    for (int i = 0; i <= head; i++) 
        for (int j = 0; j < n; j++) 
            if (requests[j] == i) 
                total += abs(i - head), head = i;
    printf("Total Seek Time (C-SCAN): %d\n", total);
    return 0;
}