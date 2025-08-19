#include <stdio.h>

struct Block {
    int data;
    struct Block *next;
};

int main() {
    struct Block b1 = {100, NULL}, b2 = {200, NULL}, b3 = {300, NULL};
    b1.next = &b2; b2.next = &b3;
    printf("File Blocks: %d -> %d -> %d\n", b1.data, b1.next->data, b1.next->next->data);
    return 0;
}