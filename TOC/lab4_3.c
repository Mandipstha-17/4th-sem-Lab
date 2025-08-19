#include <stdio.h>
#include <string.h>

#define MAX_STATES 20

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
                    if (str[i] == 'P') nextStates[nextStateCount++] = 1;
                    break;
                case 1:
                    if (str[i] == 'r') nextStates[nextStateCount++] = 2;
                    break;
                case 2:
                    if (str[i] == 'i') nextStates[nextStateCount++] = 3;
                    break;
                case 3:
                    if (str[i] == 'm') nextStates[nextStateCount++] = 4;
                    break;
                case 4:
                    if (str[i] == 'e') nextStates[nextStateCount++] = 5;
                    break;
                case 5:
                    if (str[i] == ' ') nextStates[nextStateCount++] = 6;
                    break;
                case 6:
                    if (str[i] == 'C') nextStates[nextStateCount++] = 7;
                    break;
                case 7:
                    if (str[i] == 'o') nextStates[nextStateCount++] = 8;
                    break;
                case 8:
                    if (str[i] == 'l') nextStates[nextStateCount++] = 9;
                    break;
                case 9:
                    if (str[i] == 'l') nextStates[nextStateCount++] = 10;
                    break;
                case 10:
                    if (str[i] == 'e') nextStates[nextStateCount++] = 11;
                    break;
                case 11:
                    if (str[i] == 'g') nextStates[nextStateCount++] = 12;
                    break;
                case 12:
                    if (str[i] == 'e') nextStates[nextStateCount++] = 13;
                    break;
                case 13:
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
        if (currentStates[i] == 13) {
            return 1;
        }
    }

    return 0;
}

int main() {
    char str[100];
    char choice;

    do {
        printf("Enter a string: ");
        fgets(str, 100, stdin);
        str[strcspn(str, "\n")] = '\0';

        if (isAccepted(str))
            printf("The string is accepted by the NFA.\n");
        else
            printf("The string is not accepted by the NFA.\n");

        printf("Do you want to continue? (y/n): ");
        choice = getchar();
        while (getchar() != '\n');  

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
