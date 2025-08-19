#include <stdio.h>
#include <string.h>

#define ACCEPT 1
#define REJECT 0

// Function prototypes
int state0(char ch);
int state1(char ch);
int state2(char ch);

// Global state variable
int state = 0;

// DFA function
int dfa(char *input) {
    state = 0; // Reset to initial state

    for (int i = 0; i < strlen(input); i++) {
        char ch = input[i];

        switch (state) {
            case 0:
                state = state0(ch);
                break;
            case 1:
                state = state1(ch);
                break;
            case 2:
                state = state2(ch);
                break;
            default:
                return REJECT; // If it somehow enters an invalid state
        }
    }

    return (state == 2) ? ACCEPT : REJECT;
}

// State transitions
int state0(char ch) {
    if (ch == '0') return 1;
    else if (ch == '1') return 0;
    else return 3; // Trap
}

int state1(char ch) {
    if (ch == '1') return 2;
    else if (ch == '0') return 0;
    else return 3; // Trap
}

int state2(char ch) {
    return 2; // Accepting state, remains here
}

int main() {
    char input[100];
    char choice;

    do {
        printf("Enter a binary string: ");
        scanf("%s", input);

        // Input validation
        int valid = 1;
        for (int i = 0; i < strlen(input); i++) {
            if (input[i] != '0' && input[i] != '1') {
                valid = 0;
                break;
            }
        }

        if (!valid) {
            printf("Invalid input. Only binary digits (0 and 1) are allowed.\n");
        } else {
            if (dfa(input) == ACCEPT)
                printf("The string is accepted.\n");
            else
                printf("The string is rejected.\n");
        }

        printf("Do you want to enter another string? (y/n): ");
        scanf(" %c", &choice); // Leading space skips newline
    } while (choice == 'y' || choice == 'Y');

    printf("Exiting program.\n");
    return 0;
}

