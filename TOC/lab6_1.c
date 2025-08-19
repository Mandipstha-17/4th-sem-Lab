#include <stdio.h>
#include <stdbool.h>

bool isAccepted(char *input) {
    int state = 0;
    int i = 0;

    while (input[i] != '\0') {
        switch (state) {
            case 0: 
                if (input[i] == '0') {
                    state = 0;
                } else if (input[i] == '1') {
                    state = 1; 
                } else {
                    return false;
                }
                break;

            case 1: 
                if (input[i] == '0') {
                    state = 2;
                } else {
                    return false;
                }
                break;

            case 2: 
                if (input[i] == '0') {
                    state = 3;
                } else {
                    return false;
                }
                break;

            case 3: 
                if (input[i] == '1') {
                    state = 4;
                } else {
                    return false;
                }
                break;

            case 4: 
                return false;
        }
        i++;
    }

    return (state == 4);
}

int main() {
    char input[100];
    char choice;

    do {
        printf("Enter a binary string: ");
        scanf("%s", input);

        if (isAccepted(input))
            printf("The string is accepted by the FA.\n");
        else
            printf("The string is not accepted by the FA.\n");

        printf("Do you want to continue? (y/n): ");
        getchar(); 
        choice = getchar();
        while (getchar() != '\n'); 

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
