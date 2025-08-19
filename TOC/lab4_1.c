#include <stdio.h>
#include <ctype.h>
#include <string.h>


const char *keywords[] = {
    "auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", 
    "extern", "float", "for", "goto", "if", "inline", "int", "long", "register", "restrict", "return", 
    "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", 
    "void", "volatile", "while", "_Bool", "_Complex", "_Imaginary"
};

int isKeyword(const char *str) {
    int keywordCount = sizeof(keywords) / sizeof(keywords[0]);
    for (int i = 0; i < keywordCount; i++) {
        if (strcmp(str, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}


int isValidIdentifier(const char *str) {
    if (!isalpha(str[0]) && str[0] != '_') {
        return 0;  
    }
    for (int i = 1; str[i] != '\0'; i++) {
        if (!isalnum(str[i]) && str[i] != '_') {
            return 0;  
        }
    }
    return 1;
}

int main() {
    char str[100];
    char choice;

    do {
        printf("Enter a string: ");
        scanf("%s", str);

        if (isKeyword(str)) {
            printf("\"%s\" is a keyword in C.\n", str);
        } else if (isValidIdentifier(str)) {
            printf("\"%s\" is a valid identifier in C.\n", str);
        } else {
            printf("\"%s\" is not a valid identifier in C.\n", str);
        }

        printf("Do you want to continue? (y/n): ");
        getchar();  
        choice = getchar();

    } while (choice == 'y' || choice == 'Y');

    return 0;
}