#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int n;
    char choice;

    do {
        printf("Enter a number: ");
        scanf("%d", &n);

        if (isPrime(n))
            printf("%d is a prime number.\n", n);
        else
            printf("%d is not a prime number.\n", n);

        printf("Do you want to continue? (y/n): ");
        getchar();  
        choice = getchar();
        while (getchar() != '\n');  

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
