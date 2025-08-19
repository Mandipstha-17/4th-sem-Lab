#include <stdio.h>

int main() {
    int frames = 3, pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int n = sizeof(pages)/sizeof(pages[0]);
    int frame[frames], page_faults = 0;

    for (int i = 0; i < frames; i++) 
        frame[i] = -1;

    for (int i = 0; i < n; i++) {
        int page = pages[i], found = 0;
        for (int j = 0; j < frames; j++) 
            if (frame[j] == page) 
                found = 1;
        
        if (!found) {
            int farthest = -1, replace = 0;
            for (int j = 0; j < frames; j++) {
                int k;
                for (k = i + 1; k < n; k++) 
                    if (frame[j] == pages[k]) 
                        break;
                if (k == n) {
                    replace = j;
                    break;
                }
                if (k > farthest) {
                    farthest = k;
                    replace = j;
                }
            }
            frame[replace] = page;
            page_faults++;
        }
    }
    printf("Total Page Faults (Optimal): %d\n", page_faults);
    return 0;
}