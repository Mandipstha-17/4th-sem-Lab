#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isAccepted(char *input) {
    int state = 0;
    int i = 0;

    while (input[i] != '\0') {
        switch (state) {
            case 0: 
                if (input[i] == 'a') {
                    state = 1; 
                } else {
                    return false; 
                }
                break;

            case 1: 
                if (input[i] == 'a' || input[i] == 'b') {
                    state = 1; 
                } else {
                    return false; 
                }
                break;

            default:
                return false; 
        }
        i++;
    }

    return (input[i-1] == 'b'); // accept if last char is 'b'
}

int main() {
    char input[100];
    char choice;

    do {
        printf("Enter a string: ");
        scanf("%s", input);

        if (isAccepted(input)) {
            printf("The string is accepted by the FA.\n");
        } else {
            printf("The string is not accepted by the FA.\n");
        }

        printf("Do you want to continue? (y/n): ");
        getchar(); // consume leftover newline
        choice = getchar();

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
