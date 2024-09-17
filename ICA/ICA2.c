// Michael Santoro
// CS 255
// ICA 2

#include <stdio.h>
#include <ctype.h>

void countVowelsConsonants(const char *str, int *vowels, int *consonants) {
    *vowels = 0;
    *consonants = 0;
    
    while (*str != '\0') {
        char ch = *str;
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            (*vowels)++;
        } 
        else {
            (*consonants)++;
        }
        str++;
    }
}

void printReverse(char strings[][100]){
    for(int i = 9; i >= 0; i--){
        printf("%s\n",strings[i]);
    }
}

int main() {
    // Count Vowels and Consonants
    char input_string[100];
    int num_vowels, num_consonants;

    printf("Enter a string: ");
    scanf("%[^\n]", input_string);

    countVowelsConsonants(input_string, &num_vowels, &num_consonants);

    printf("Number of vowels: %d\n", num_vowels);
    printf("Number of consonants: %d\n", num_consonants);

    // Print a newline  
    printf("\n\n");

    // String Array Reverse Order
    char strings[10][100];

    // Get Strings from user and store them in strings[]
    printf("Enter 10 Strings:\n");
    for(int i = 0; i < 10; i++){
        printf("String %d: ",i+1);
        scanf("%99s", strings[i]);
    }

    // Use User inputted Strings and pass it to printReverse()
    printf("\nStrings Entered in Reverse Order:\n");
    printReverse(strings);

    return 0;
}