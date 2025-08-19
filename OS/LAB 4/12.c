#include <stdio.h>
#include <stdlib.h>

int main() {
    int requests[] = {82, 170, 43, 140, 24, 16, 190};
    int head = 50, n = 7, total = 0;
    int visited[7] = {0};

    for (int i = 0; i < n; i++) {
        int min_dist = 9999, index = -1;
        for (int j = 0; j < n; j++) {
            if (!visited[j]) {
                int dist = abs(requests[j] - head);
                if (dist < min_dist) {
                    min_dist = dist;
                    index = j;
                }
            }
        }
        visited[index] = 1;
        total += min_dist;
        head = requests[index];
    }
    printf("Total Seek Time (SSTF): %d\n", total);
    return 0;
}