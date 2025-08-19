#include <stdio.h>

int main() {
    int frames = 3;
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int n = sizeof(pages) / sizeof(pages[0]);
    int frame[frames], page_faults = 0, ptr = 0;

    // Initialize all frames as empty (-1 means empty slot)
    for (int i = 0; i < frames; i++)
        frame[i] = -1;

    // Process each page request
    for (int i = 0; i < n; i++) {
        int page = pages[i];
        int found = 0;

        // Check if page is already in frame
        for (int j = 0; j < frames; j++) {
            if (frame[j] == page) {
                found = 1;
                break;
            }
        }

        // If not found, replace using FIFO
        if (!found) {
            frame[ptr] = page;
            ptr = (ptr + 1) % frames;
            page_faults++;
        }
    }

    printf("Total Page Faults (FIFO): %d\n", page_faults);
    return 0;
}
