#include <stdio.h>
#include <string.h>

int isValidEmail(const char *email) {
    const char *at = strchr(email, '@');
    if (!at) return 0;  
    const char *dot = strchr(at, '.');
    if (!dot) return 0;  
    if (dot < at + 2) return 0; 
    if (strlen(dot) < 3) return 0; 
    return 1;
}

int main() {
    char email[100];
    char choice;

    do {
        printf("Enter an email address: ");
        scanf("%99s", email);

        if (isValidEmail(email))
            printf("The email address is valid.\n");
        else
            printf("The email address is not valid.\n");

        printf("Do you want to continue? (y/n): ");
        getchar();
        choice = getchar();
        while (getchar() != '\n');
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
