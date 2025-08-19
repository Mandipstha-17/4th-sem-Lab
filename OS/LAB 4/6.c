#include <stdio.h>

int main() {
    int blocks[] = {1, 1, 0, 0, 1, 0, 1, 1}; // 1 = Occupied, 0 = Free
    int start = 2, length = 3;
    int allocated = 1;

    for (int i = start; i < start + length; i++) 
        if (blocks[i] != 0) {
            allocated = 0;
            break;
        }
    
    if (allocated) {
        printf("File allocated contiguously from block %d to %d\n", start, start + length - 1);
        for (int i = start; i < start + length; i++) 
            blocks[i] = 1;
    } else {
        printf("Not enough contiguous space available.\n");
    }
    return 0;
}