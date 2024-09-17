// Michael Santoro
// CS 355
// Homework 1

#include <stdio.h>
int main(){
    int grade;

    // Promopts User for Grade
    printf("Please Enter your Grade: ");

    // Checks if User Inputted Grade is valid
    if(scanf("%i",&grade) != 1){ // Stores User-Inputted Grade into grade. Also checks if it is a non-number
        printf("Your input could not be interpreted as an integer value.");
        return;
    }

    // Determines Letter Grade based off User-Inputted Grade
    if(grade > 100 || grade < 0) // Determines if grade is outside bounds of 0-100
        printf("You entered an invalid value.");
    else if (grade >= 90)
        printf("Your Grade is a A");
    else if (grade >= 80)
        printf("Your Grade is a B");
    else if (grade >= 70)
        printf("Your Grade is a C");
    else if (grade >= 60)
        printf("Your Grade is a D");
    else // if grade < 60
        printf("Your Grade is a F");
    return 0;
}

/*
100-90  A
90-80   B
80-70   C
70-60   D
60-0    F
Everything else is invalid

Test Cases: 95, 83, 77, 64, 49, 195, -12, abc
*/