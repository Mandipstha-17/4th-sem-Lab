#include <stdio.h>
#include <stdlib.h>

int main() {
    int requests[] = {82, 170, 43, 140, 24, 16, 190};
    int head = 50, n = 7, total = 0;

    for (int i = 0; i < n; i++) {
        total += abs(requests[i] - head);
        head = requests[i];
    }
    printf("Total Seek Time (FCFS): %d\n", total);
    return 0;
}