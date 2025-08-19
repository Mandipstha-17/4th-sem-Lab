#include <stdio.h>
#include <string.h>

#define MAX_STATES 10

int isAccepted(char str[]) {
    int currentStates[MAX_STATES];
    int nextStates[MAX_STATES];
    int i, j, k;
    int currentStateCount, nextStateCount;

    
    currentStates[0] = 0;
    currentStateCount = 1;

    for (i = 0; str[i] != '\0'; i++) {
        nextStateCount = 0;

        for (j = 0; j < currentStateCount; j++) {
            switch (currentStates[j]) {
                case 0:
                    if (str[i] == '0') {
                        nextStates[nextStateCount++] = 1;
                    } else {
                        nextStates[nextStateCount++] = 0;
                    }
                    break;
                case 1:
                    if (str[i] == '1') {
                        nextStates[nextStateCount++] = 2;
                    } else {
                        nextStates[nextStateCount++] = 1;
                    }
                    break;
                case 2:
                    if (str[i] == '0') {
                        nextStates[nextStateCount++] = 1;
                    } else {
                        nextStates[nextStateCount++] = 0;
                    }
                    break;
            }
        }

        currentStateCount = nextStateCount;
        for (k = 0; k < nextStateCount; k++) {
            currentStates[k] = nextStates[k];
        }

        if (currentStateCount == 0) {
            return 0;
        }
    }

    for (i = 0; i < currentStateCount; i++) {
        if (currentStates[i] == 2) {
            return 1;
        }
    }

    return 0;
}

int main() {
    char str[100];
    char choice;

    do {
        printf("Enter a binary string: ");
        scanf("%s", str);

        if (isAccepted(str))
            printf("The string is accepted by the NFA.\n");
        else
            printf("The string is not accepted by the NFA.\n");

        printf("Do you want to continue? (y/n): ");
    
        getchar(); 
        choice = getchar();

    } while (choice == 'y' || choice == 'Y');

    printf("Program terminated.\n");
    return 0;
}
