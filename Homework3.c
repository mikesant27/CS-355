// Michael Santoro
// CS 355
// Homework 3

#include <stdio.h>

void printString(char *str) {
    char *ptr = str;

    while (*ptr != '\0') {
        if ((*ptr >= 'a' && *ptr <= 'z') || (*ptr >= 'A' && *ptr <= 'Z')) {
            char *temp = str;
            while (temp <= ptr) {
                printf("%c", *temp);                    // Print current line
                temp++;
            }
            printf("\n");                               // Print newline after each sequence
        }
        ptr++;
    }
}

int main() {
    char input[100];                                    // Holds User Input

    printf("Enter A String: ");                         // Prints Prompt for String
    int c;
    int i = 0;
    while ((c = getchar()) != '\n') {                   // Loop to put String into input
        input[i] = c;
        i++;
    }
    input[i] = '\0';                                    // Attach end of string "\0" to end

    char word[100];
    int wordIndex = 0;

    for (int i = 0; input[i] != '\0'; i++) {            // Goes through input, breaks string into words, words are broken up by ' '
        if (input[i] == ' ') {
            word[wordIndex] = '\0';                    
            printString(word);                          // Print the current word
            wordIndex = 0;                              // Reset the word index
        } else {
            word[wordIndex] = input[i];                 // Add current character to the current word
            wordIndex++;
        }
    }

   
    if (wordIndex > 0) {                                // Last word is not followed by a space
        word[wordIndex] = '\0';                         
        printString(word);                              // Print the last word
    }

    return 0;
}

/*
Prompt User for String
Print each argument starting with first character, then first 2 on next line, etc
Exclude all characters besides A-Z and a-z

Test Cases:
C language

Have a nice day!

paraskevidekatriaphobia = Friday 13
*/