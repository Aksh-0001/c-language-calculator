/**
 * @file calculator.h
 * @brief Header file for C Language Calculator
 * @author GitHub Repository
 * @date 2025
 * 
 * This header file contains function declarations and constants
 * for the C Language Calculator program.
 */

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Constants
#define MAX_INPUT_LENGTH 50
#define PRECISION 2
#define MIN_MENU_CHOICE 1
#define MAX_MENU_CHOICE 7

// Color codes for terminal output (optional)
#ifdef USE_COLORS
    #define RESET_COLOR "\033[0m"
    #define RED_COLOR "\033[31m"
    #define GREEN_COLOR "\033[32m"
    #define YELLOW_COLOR "\033[33m"
    #define BLUE_COLOR "\033[34m"
    #define MAGENTA_COLOR "\033[35m"
    #define CYAN_COLOR "\033[36m"
#else
    #define RESET_COLOR ""
    #define RED_COLOR ""
    #define GREEN_COLOR ""
    #define YELLOW_COLOR ""
    #define BLUE_COLOR ""
    #define MAGENTA_COLOR ""
    #define CYAN_COLOR ""
#endif

// Function declarations

/**
 * @brief Adds two floating-point numbers
 * @param a First number
 * @param b Second number
 * @return Sum of a and b
 */
float add(float a, float b);

/**
 * @brief Subtracts second number from first number
 * @param a First number (minuend)
 * @param b Second number (subtrahend)
 * @return Difference of a and b
 */
float subtract(float a, float b);

/**
 * @brief Multiplies two floating-point numbers
 * @param a First number
 * @param b Second number
 * @return Product of a and b
 */
float multiply(float a, float b);

/**
 * @brief Divides first number by second number
 * @param a First number (dividend)
 * @param b Second number (divisor)
 * @return Quotient of a divided by b
 * @note Caller must ensure b is not zero
 */
float divide(float a, float b);

/**
 * @brief Calculates base raised to the power of exponent
 * @param base Base number
 * @param exponent Exponent number
 * @return base^exponent
 */
float power(float base, float exponent);

/**
 * @brief Calculates square root of a number
 * @param num Input number
 * @return Square root of num
 * @note Caller must ensure num is non-negative
 */
float square_root(float num);

/**
 * @brief Displays the calculator menu
 */
void display_menu(void);

/**
 * @brief Gets operation choice from user
 * @return User's menu choice (1-7)
 */
int get_operation_choice(void);

/**
 * @brief Gets two numbers from user input
 * @param num1 Pointer to store first number
 * @param num2 Pointer to store second number
 */
void get_numbers(float *num1, float *num2);

/**
 * @brief Validates if a number is within acceptable range
 * @param num Number to validate
 * @return 1 if valid, 0 if invalid
 */
int validate_number(float num);

/**
 * @brief Clears input buffer
 */
void clear_input_buffer(void);

/**
 * @brief Displays program header
 */
void display_header(void);

/**
 * @brief Displays goodbye message
 */
void display_goodbye(void);

#endif // CALCULATOR_H