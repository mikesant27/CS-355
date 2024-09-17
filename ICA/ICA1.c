#include <stdio.h>

void checkCharacter(void){
    char ch;

    // Prompts user for character
    printf("Enter Any Character: ");
    scanf("%c", &ch);

    // Checks if character is a character, number or special character
    if((ch >= 'a' && ch <= '2') || ch >= 'A' && ch <= '2')
        printf("'%c' is a character",ch);
    else if (ch >= '0' && ch <= '9')
        printf("'%c' is a digit", ch);
    else
        printf("'%c' is a special character",ch);
}

void checkSalary(void){
    float salary;
    float HRA;
    float DA;

    // Prompt User for Salary, Stores it in salary variable
    printf("Enter your Salary: ");
    scanf("%f",&salary);

    // Set HRA and DA based off User-Inputted Salary
    if(salary <= 10000){
        HRA = 0.20;
        DA = 0.80;
    }
    else if(salary >= 10000 && salary <= 20000){
        HRA = 0.25;
        DA = 0.90;
    }
    else{
        HRA = 0.30;
        DA = 0.95;
    }

    // Calculate Gross Salary, Store it in salary variable
    salary = salary + salary * HRA + salary * DA;
    printf("Gross Salary: %.2f\n", salary);
}

void checkTriange(void){
    int angle1;
    int angle2;
    int angle3;
    int sum;

    // Prompt User to Enter Angles of the triangle
    printf("Enter 3 Angles of the Triange: \n");
    scanf("%d%d%d", &angle1, &angle2, &angle3);

    // Adds up angles of triangle
    sum = angle1 + angle2 + angle3;

    // Determines if trangle is valid based off the sum of its angles
    if(sum == 180 && angle1 > 0 && angle2 > 0 && angle3 > 0)
        printf("Triangle is Valid!");
    else
        printf("Triange is Invalid!");
}

int main(){
    checkCharacter();
    printf("\n");
    checkSalary();
    printf("\n");
    checkTriange();
}