#include <stdio.h> 
#include <string.h> 
 
#define ACCEPT 1 
#define REJECT 0 
 
// Function prototypes for state functions 
int state0(char ch); 
int state1(char ch); 
int state2(char ch); 
 
// Global state variable 
int state = 0; // Initial state 
 
int dfa(char *input) { 
    // Reset state to initial state 
    state = 0; 
 
    for (int i = 0; i < strlen(input); i++) { 
        char ch = input[i]; 
         // Transition based on current state and input character 
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
                state = 3; // Trap state 
                break; 
        } 
    } 
 
    // Accept if we end in state 2 
    return (state == 2) ? ACCEPT : REJECT; 
} 
 
// State 0: Initial state 
int state0(char ch) { 
    if (ch == '0') { 
        return 1; // Transition to state 1 
    } else { 
        return 0; // Stay in state 0 
    } 
} 
 
// State 1: After reading '0' 
int state1(char ch) { 
    if (ch == '1') { 
        return 2; // Transition to accepting state 2 
    } else { 
        return 1; // Stay in state 1 for '0' 
    } 
} 
 
// State 2: Accepting state 
int state2(char ch) { 
    if (ch == '0') { 
        return 1; // Transition to state 1 to check for new sequence  
     } else { 
        return 1; // Transition to state 1 to check for new sequence 
    } 
} 
 
int main() { 
    char input[100]; 
    char choice; 
     
    do { 
        printf("Enter a binary string: "); 
        scanf("%s", input); 
 
        // Validate input 
        for (int i = 0; i < strlen(input); i++) { 
            if (input[i] != '0' && input[i] != '1') { 
                printf("Invalid input. Only binary strings are allowed.\n"); 
                return 1; 
            } 
        } 
 
        if (dfa(input) == ACCEPT) { 
            printf("The string is accepted.\n"); 
        } else { 
            printf("The string is rejected.\n"); 
        } 
 
        printf("Do you want to enter another string? (y/n): "); 
        scanf(" %c", &choice);  
 
    } while (choice == 'y' || choice == 'Y'); 
 
    printf("Closing The Program.\n"); 
    return 0; 
} 