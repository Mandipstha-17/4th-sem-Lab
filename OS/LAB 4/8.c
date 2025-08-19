#include <stdio.h>

int main() {
    int index_block[] = {5, 9, 12};
    int data_blocks[12] = {0};
    data_blocks[5] = 100;
    data_blocks[9] = 200;
    data_blocks[12] = 300;

    printf("File Blocks via Index: %d, %d, %d\n", 
           data_blocks[index_block[0]], 
           data_blocks[index_block[1]], 
           data_blocks[index_block[2]]);
    return 0;
}