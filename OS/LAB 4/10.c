#include <stdio.h>

struct Block {
    int block_no;
    struct Block *next;
};

int main() {
    struct Block b1 = {1, NULL}, b3 = {3, NULL}, b6 = {6, NULL}, b7 = {7, NULL};
    b1.next = &b3; b3.next = &b6; b6.next = &b7;

    printf("Free Blocks (Linked List): ");
    struct Block *current = &b1;
    while (current != NULL) {
        printf("%d ", current->block_no);
        current = current->next;
    }
    return 0;
}
