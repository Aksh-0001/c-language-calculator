/**
 * @file test_cases.c
 * @brief Test cases and examples for C Language Calculator
 * @author GitHub Repository
 * 
 * This file contains test cases that demonstrate the expected behavior
 * of the calculator functions. These can be used for manual testing
 * or as a reference for future automated testing implementation.
 */

#include <stdio.h>
#include <assert.h>
#include <math.h>

// Include calculator functions (for future modular implementation)
// #include "calculator.h"

// Test case structure
typedef struct {
    char description[100];
    float input1;
    float input2;
    float expected_result;
    int operation; // 1=add, 2=sub, 3=mul, 4=div, 5=pow, 6=sqrt
} TestCase;

// Function prototypes for calculator operations
float add(float a, float b) { return a + b; }
float subtract(float a, float b) { return a - b; }
float multiply(float a, float b) { return a * b; }
float divide(float a, float b) { return a / b; }
float power(float base, float exp) { return pow(base, exp); }
float square_root(float num) { return sqrt(num); }

void run_test_case(TestCase test) {
    float result = 0.0;
    const char* operation_names[] = {"", "Addition", "Subtraction", 
                                   "Multiplication", "Division", 
                                   "Power", "Square Root"};

    printf("Testing: %s\n", test.description);

    switch(test.operation) {
        case 1: result = add(test.input1, test.input2); break;
        case 2: result = subtract(test.input1, test.input2); break;
        case 3: result = multiply(test.input1, test.input2); break;
        case 4: result = divide(test.input1, test.input2); break;
        case 5: result = power(test.input1, test.input2); break;
        case 6: result = square_root(test.input1); break;
        default: printf("Unknown operation\n"); return;
    }

    printf("Operation: %s\n", operation_names[test.operation]);
    if (test.operation == 6) {
        printf("Input: %.2f\n", test.input1);
    } else {
        printf("Inputs: %.2f, %.2f\n", test.input1, test.input2);
    }
    printf("Expected: %.2f\n", test.expected_result);
    printf("Actual: %.2f\n", result);

    // Simple tolerance check for floating point comparison
    float tolerance = 0.01;
    if (fabs(result - test.expected_result) < tolerance) {
        printf("✓ PASS\n\n");
    } else {
        printf("✗ FAIL\n\n");
    }
}

int main() {
    printf("===========================================\n");
    printf("    C LANGUAGE CALCULATOR - TEST CASES    \n");
    printf("===========================================\n\n");

    // Define test cases
    TestCase tests[] = {
        // Basic Addition Tests
        {"Basic addition of positive numbers", 5.0, 3.0, 8.0, 1},
        {"Addition with decimal numbers", 2.5, 3.7, 6.2, 1},
        {"Addition with negative numbers", -5.0, -3.0, -8.0, 1},
        {"Addition with zero", 10.0, 0.0, 10.0, 1},
        {"Addition with mixed positive/negative", 15.0, -5.0, 10.0, 1},

        // Basic Subtraction Tests
        {"Basic subtraction", 10.0, 4.0, 6.0, 2},
        {"Subtraction with decimals", 7.5, 2.3, 5.2, 2},
        {"Subtraction resulting in negative", 3.0, 8.0, -5.0, 2},
        {"Subtraction with negative numbers", -5.0, -3.0, -2.0, 2},
        {"Subtraction with zero", 15.0, 0.0, 15.0, 2},

        // Basic Multiplication Tests
        {"Basic multiplication", 6.0, 7.0, 42.0, 3},
        {"Multiplication with decimals", 2.5, 4.0, 10.0, 3},
        {"Multiplication with negative", -3.0, 4.0, -12.0, 3},
        {"Multiplication with zero", 100.0, 0.0, 0.0, 3},
        {"Multiplication of negatives", -2.0, -5.0, 10.0, 3},

        // Basic Division Tests
        {"Basic division", 20.0, 4.0, 5.0, 4},
        {"Division with decimals", 7.5, 2.5, 3.0, 4},
        {"Division resulting in decimal", 10.0, 3.0, 3.33, 4},
        {"Division with negative", -12.0, 3.0, -4.0, 4},
        {"Division by negative", 15.0, -3.0, -5.0, 4},

        // Power Tests
        {"Basic power operation", 2.0, 3.0, 8.0, 5},
        {"Power with decimal base", 2.5, 2.0, 6.25, 5},
        {"Power to zero", 5.0, 0.0, 1.0, 5},
        {"Power to one", 7.0, 1.0, 7.0, 5},
        {"Square operation", 4.0, 2.0, 16.0, 5},

        // Square Root Tests
        {"Basic square root", 9.0, 0.0, 3.0, 6},
        {"Square root of decimal", 6.25, 0.0, 2.5, 6},
        {"Square root of 1", 1.0, 0.0, 1.0, 6},
        {"Square root of 0", 0.0, 0.0, 0.0, 6},
        {"Square root of large number", 144.0, 0.0, 12.0, 6}
    };

    int num_tests = sizeof(tests) / sizeof(TestCase);
    int passed = 0;

    // Run all tests
    for (int i = 0; i < num_tests; i++) {
        run_test_case(tests[i]);
        // This is a simplified pass/fail check - in real implementation
        // we would track actual pass/fail results
    }

    printf("===========================================\n");
    printf("Test Summary: %d tests completed\n", num_tests);
    printf("Note: This is a demonstration of test cases.\n");
    printf("For actual testing, implement proper assertions.\n");
    printf("===========================================\n\n");

    // Edge cases and error conditions to test manually:
    printf("Manual Test Cases to Verify:\n");
    printf("1. Division by zero (should show error)\n");
    printf("2. Square root of negative number (should show error)\n");
    printf("3. Very large numbers (check for overflow)\n");
    printf("4. Invalid menu selections\n");
    printf("5. Non-numeric input handling\n");
    printf("6. Continuous calculation flow\n\n");

    return 0;
}