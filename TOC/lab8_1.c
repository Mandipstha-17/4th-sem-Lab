#include <stdio.h>
#include <string.h>

#define MAX_TAPE_LENGTH 100
#define BLANK_SYMBOL 'B'

typedef struct {
    char tape[MAX_TAPE_LENGTH];
    int headPosition;
    const char *currentState;
} TuringMachine;

void initializeTM(TuringMachine *tm, const char *input) {
    strcpy(tm->tape, input);
    tm->headPosition = 0;
    tm->currentState = "q0";
}

void printTape(const char *label, const TuringMachine *tm) {
    printf("%sTape: %s\n", label, tm->tape);
}

void moveRight(TuringMachine *tm) {
    tm->headPosition++;
}

void writeSymbol(TuringMachine *tm, char symbol) {
    tm->tape[tm->headPosition] = symbol;
}

char readSymbol(const TuringMachine *tm) {
    return tm->tape[tm->headPosition];
}

void runTM(TuringMachine *tm) {
    while (1) {
        char currentSymbol = readSymbol(tm);

        if (strcmp(tm->currentState, "q0") == 0) {
            if (currentSymbol == '1') {
                moveRight(tm);
            } else if (currentSymbol == BLANK_SYMBOL) {
                writeSymbol(tm, '1');  // Append a '1'
                tm->currentState = "qAccept";
            }
        } else if (strcmp(tm->currentState, "qAccept") == 0) {
            return; // Halt
        }
    }
}

int main() {
    TuringMachine tm;

    char input[MAX_TAPE_LENGTH] = "111";  // x = 3 (in unary)
    char tape[MAX_TAPE_LENGTH] = {BLANK_SYMBOL};  // Start with one blank

    strcat(tape, input);   // Add input
    strcat(tape, "B");     // Add blank at the end

    initializeTM(&tm, tape);

    printTape("Initial ", &tm);

    runTM(&tm);

    printTape("Final   ", &tm);

    return 0;
}
