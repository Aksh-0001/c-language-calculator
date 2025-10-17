[README.md](https://github.com/user-attachments/files/22973619/README.md)
# C Language Calculator

A simple yet comprehensive calculator program written in C that performs basic arithmetic operations and advanced mathematical functions.

## Features

- **Basic Operations:**
  - Addition (+)
  - Subtraction (-)
  - Multiplication (*)
  - Division (/)

- **Advanced Operations:**
  - Power (^)
  - Square Root (√)

- **User-Friendly Interface:**
  - Interactive menu system
  - Input validation
  - Error handling for division by zero and negative square roots
  - Continuous calculation option

## Getting Started

### Prerequisites

- GCC compiler or any C compiler
- Make utility (optional, for using Makefile)

### Installation

1. Clone the repository:
```bash
git clone https://github.com/yourusername/c-language-calculator.git
cd c-language-calculator
```

2. Compile the program:

**Using Makefile (recommended):**
```bash
make
```

**Manual compilation:**
```bash
gcc -o calculator calculator.c -lm
```

### Usage

1. Run the calculator:
```bash
./calculator
```

2. Follow the on-screen menu to select operations
3. Enter numbers when prompted
4. View results and choose to continue or exit

### Sample Output

```
===============================
      C LANGUAGE CALCULATOR    
===============================

Select an operation:
1. Addition (+)
2. Subtraction (-)
3. Multiplication (*)
4. Division (/)
5. Power (^)
6. Square Root (√)
7. Exit
Enter your choice (1-7): 1
Enter first number: 15.5
Enter second number: 24.3

Result: 15.50 + 24.30 = 39.80

Do you want to perform another calculation? (y/n): n

Thank you for using the calculator!
```

## Project Structure

```
c-language-calculator/
├── calculator.c        # Main calculator program
├── Makefile           # Build automation
├── README.md          # Project documentation
└── .gitignore         # Git ignore rules
```

## Building

### Using Make

```bash
# Compile the program
make

# Clean build files
make clean

# Force rebuild
make rebuild
```

### Manual Compilation

```bash
# Basic compilation
gcc -o calculator calculator.c -lm

# With debugging symbols
gcc -g -o calculator calculator.c -lm

# With optimization
gcc -O2 -o calculator calculator.c -lm
```

## Features in Detail

### Error Handling
- **Division by Zero**: Prevents crashes when dividing by zero
- **Negative Square Root**: Handles invalid square root operations
- **Invalid Input**: Graceful handling of invalid menu choices

### Input Validation
- Numeric input validation for calculations
- Menu choice validation
- Continuous operation support

## Contributing

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/new-feature`)
3. Commit your changes (`git commit -am 'Add new feature'`)
4. Push to the branch (`git push origin feature/new-feature`)
5. Create a Pull Request

## License

This project is open source and available under the [MIT License](LICENSE).

## Author

Created as a learning project to demonstrate C programming concepts including:
- Function declarations and definitions
- Switch-case statements
- Input/output operations
- Mathematical computations
- Error handling
- Modular programming

## Acknowledgments

- C programming community for best practices
- Mathematical functions from `math.h` library
- GitHub community for repository structure guidelines
