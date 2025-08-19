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

    while (input[i] != '\0' && input[i] != 'c') {
        push(&stack, input[i]);
        i++;
    }

    if (input[i] != 'c' || i == 0) {
        return false;
    }

    i++;

    while (input[i] != '\0') {
        if (pop(&stack) != input[i]) {
            return false;
        }
        i++;
    }

    return (stack.top == -1);
}

int main() {
    char input[100];
    char choice;

    do {
        printf("Enter a string: ");
        scanf("%s", input);

        if (isAccepted(input)) {
            printf("ACCEPT\n");
        } else {
            printf("REJECT\n");
        }

        printf("Do you want to continue? (y/n): ");
        getchar();
        choice = getchar();
        while (getchar() != '\n');

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
