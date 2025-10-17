#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function declarations
float add(float a, float b);
float subtract(float a, float b);
float multiply(float a, float b);
float divide(float a, float b);
float power(float base, float exponent);
float square_root(float num);
void display_menu();
int get_operation_choice();
void get_numbers(float *num1, float *num2);

int main() {
    int choice;
    float num1, num2, result;
    char continue_calc = 'y';

    printf("===============================\n");
    printf("      C LANGUAGE CALCULATOR    \n");
    printf("===============================\n\n");

    while (continue_calc == 'y' || continue_calc == 'Y') {
        display_menu();
        choice = get_operation_choice();

        switch (choice) {
            case 1: // Addition
                get_numbers(&num1, &num2);
                result = add(num1, num2);
                printf("\nResult: %.2f + %.2f = %.2f\n", num1, num2, result);
                break;

            case 2: // Subtraction
                get_numbers(&num1, &num2);
                result = subtract(num1, num2);
                printf("\nResult: %.2f - %.2f = %.2f\n", num1, num2, result);
                break;

            case 3: // Multiplication
                get_numbers(&num1, &num2);
                result = multiply(num1, num2);
                printf("\nResult: %.2f * %.2f = %.2f\n", num1, num2, result);
                break;

            case 4: // Division
                get_numbers(&num1, &num2);
                if (num2 != 0) {
                    result = divide(num1, num2);
                    printf("\nResult: %.2f / %.2f = %.2f\n", num1, num2, result);
                } else {
                    printf("\nError: Division by zero is not allowed!\n");
                }
                break;

            case 5: // Power
                get_numbers(&num1, &num2);
                result = power(num1, num2);
                printf("\nResult: %.2f ^ %.2f = %.2f\n", num1, num2, result);
                break;

            case 6: // Square root
                printf("Enter a number: ");
                scanf("%f", &num1);
                if (num1 >= 0) {
                    result = square_root(num1);
                    printf("\nResult: √%.2f = %.2f\n", num1, result);
                } else {
                    printf("\nError: Cannot calculate square root of negative number!\n");
                }
                break;

            case 7: // Exit
                printf("\nThank you for using the calculator!\n");
                continue_calc = 'n';
                continue;

            default:
                printf("\nInvalid choice! Please try again.\n");
                continue;
        }

        if (continue_calc == 'y' || continue_calc == 'Y') {
            printf("\nDo you want to perform another calculation? (y/n): ");
            scanf(" %c", &continue_calc);
            printf("\n");
        }
    }

    return 0;
}

// Function to display the menu
void display_menu() {
    printf("Select an operation:\n");
    printf("1. Addition (+)\n");
    printf("2. Subtraction (-)\n");
    printf("3. Multiplication (*)\n");
    printf("4. Division (/)\n");
    printf("5. Power (^)\n");
    printf("6. Square Root (√)\n");
    printf("7. Exit\n");
    printf("Enter your choice (1-7): ");
}

// Function to get operation choice from user
int get_operation_choice() {
    int choice;
    scanf("%d", &choice);
    return choice;
}

// Function to get two numbers from user
void get_numbers(float *num1, float *num2) {
    printf("Enter first number: ");
    scanf("%f", num1);
    printf("Enter second number: ");
    scanf("%f", num2);
}

// Mathematical operation functions
float add(float a, float b) {
    return a + b;
}

float subtract(float a, float b) {
    return a - b;
}

float multiply(float a, float b) {
    return a * b;
}

float divide(float a, float b) {
    return a / b;
}

float power(float base, float exponent) {
    return pow(base, exponent);
}

float square_root(float num) {
    return sqrt(num);
}