#include <stdio.h>

int main() {
    int disk[8] = {1, 0, 1, 0, 1, 1, 0, 0}; // 1 = Occupied, 0 = Free
    printf("Free Blocks: ");
    for (int i = 0; i < 8; i++) 
        if (!disk[i]) 
            printf("%d ", i);
    return 0;
}