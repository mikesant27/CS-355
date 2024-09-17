// Michael Santoro
// CS 355
// Homework 2

#include <stdio.h>

void fizzBuzz(int n){

    if(n < 0){
        printf("Please Enter a Positive Integer");
        return;
    }
    for(int i = 0; i <= n; i++){
        if(i % 3 == 0)
            printf("Fizz");
        if(i % 5 == 0)
            printf("Buzz");
        if(i % 3 != 0 && i % 5 != 0)
            printf("%d",i);

        // Print a newline after each iteration
        printf("\n");
    }
}

int main(){
    int n;

    // Prompt User for Integer and store it in n
    printf("Please Enter an Integer: ");
    scanf("%i", &n);

    // call fizzBuzz() and pass n as its argument
    fizzBuzz(n);

    return 0;
}


/*
User Enters Integer N

fizzbuzz prints each number from 0-N
    If x is a multiple of 3, print Fizz
    If x is a multiple of 5, print Buzz
    If x is a multiple of 3 & 5, print FizzBuzz

Must include Loop
include a function that takes a single int as an arg
Test Cases: -17. 0, 5, 15, 38
*/