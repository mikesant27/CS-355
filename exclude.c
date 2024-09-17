#include <stdio.h>

void exclude(char str1[], char str2[]);

int main(int argc, char *argv[]) {
    if(argc < 3){
        printf("Not Enough Arguments Passed");
        return 1;
    }

    char *str1 = argv[1];
    char *str2 = argv[2];

    printf("%s\n",str1);
    printf("%s\n",str2);
    
    exclude(str1, str2);
    printf("String after removing matching characters: %s\n", str1);
    return 0;
}

void exclude(char str1[], char str2[]) {
    int i, j, k;
    for (i = 0; str1[i] != '\0'; i++) {
        for (j = 0; str2[j] != '\0'; j++) {
            if (str1[i] == str2[j]) {
                for (k = i; str1[k] != '\0'; k++) { //iterates over all characters to the right of found character 
                    str1[k] = str1[k + 1];  //copied element gets moved down like a line swapping until next element = '\0'
                }
                i--; // remove last element
                break; // Exit the inner loop
            }
        }
    }
}
