#include <stdio.h>
#include <string.h>

#define TAPE_LENGTH 100
#define BLANK 'B'

void printTape(char tape[], int start, int end) {
    printf("Tape: ");
    for (int i = start; i <= end; i++) {
        printf("%c", tape[i]);
    }
    printf("\n");
}

int main() {
    char tape[TAPE_LENGTH];
    for (int i = 0; i < TAPE_LENGTH; i++) tape[i] = BLANK;

    char input[] = "1101";
    int input_len = strlen(input);
    int head = 1;

    for (int i = 0; i < input_len; i++) {
        tape[head + i] = input[i];
    }
    tape[head + input_len] = BLANK;

    printf("Initial ");
    printTape(tape, head - 1, head + input_len);

    int state = 0;
    while (state != 3) {
        switch (state) {
            case 0:
                if (tape[head] == '0' || tape[head] == '1') head++;
                else if (tape[head] == BLANK) { head--; state = 1; }
                break;

            case 1:
                if (tape[head] == '0') head--;
                else if (tape[head] == '1') { head--; state = 2; }
                break;

            case 2:
                if (tape[head] == '0') { tape[head] = '1'; head--; }
                else if (tape[head] == '1') { tape[head] = '0'; head--; }
                else if (tape[head] == BLANK) state = 3;
                break;
        }
    }

    printf("Final   ");
    printTape(tape, head + 1, head + 1 + input_len);
    return 0;
}
