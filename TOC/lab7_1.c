#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STACK_SIZE 100

typedef struct {
    char stack[MAX_STACK_SIZE];
    int top;
} Stack;

void initializeStack(Stack *s) {
    s->top = -1;
}

void push(Stack *s, char c) {
    if (s->top < MAX_STACK_SIZE - 1) {
        s->stack[++(s->top)] = c;
    }
}

char pop(Stack *s) {
    if (s->top >= 0) {
        return s->stack[(s->top)--];
    }
    return '\0'; 
}

bool isAccepted(char *input) {
    Stack stack;
    initializeStack(&stack);

    int i = 0;
    int length = strlen(input);
    
    while (input[i] == 'a') {
        push(&stack, 'a');
        i++;
    }

    while (input[i] == 'b') {
        if (pop(&stack) != 'a') {
            return false; 
        }
        i++;
    }

    while (input[i] == 'c') {
        if (pop(&stack) != '\0') {
            return false;
        }
        i++;
    }

    return (i == length && stack.top == -1);
}

int main() {
    char input[100];
    char choice;

    do {
        printf("Enter a string: ");
        scanf("%s", input);

        if (isAccepted(input)) {
            printf("The string is accepted by the PDA.\n");
        } else {
            printf("The string is not accepted by the PDA.\n");
        }

        printf("Do you want to continue? (y/n): ");
        getchar();
        choice = getchar();

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
