#include <stdio.h>

int main() {
    int frames = 3, pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int n = sizeof(pages)/sizeof(pages[0]);
    int frame[frames], time[frames], page_faults = 0;

    for (int i = 0; i < frames; i++) 
        frame[i] = -1;

    for (int i = 0; i < n; i++) {
        int page = pages[i], found = 0;
        for (int j = 0; j < frames; j++) {
            if (frame[j] == page) {
                found = 1;
                time[j] = i;
                break;
            }
        }
        if (!found) {
            int lru = 0;
            for (int j = 1; j < frames; j++) 
                if (time[j] < time[lru]) 
                    lru = j;
            frame[lru] = page;
            time[lru] = i;
            page_faults++;
        }
    }
    printf("Total Page Faults (LRU): %d\n", page_faults);
    return 0;
}