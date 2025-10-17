# Contributing to C Language Calculator

Thank you for your interest in contributing to the C Language Calculator project! This document provides guidelines and information for contributors.

## How to Contribute

### 1. Fork the Repository

1. Fork the repository on GitHub
2. Clone your fork locally:
```bash
git clone https://github.com/yourusername/c-language-calculator.git
cd c-language-calculator
```

### 2. Set Up Development Environment

#### Prerequisites
- GCC compiler
- Make utility
- Git
- Text editor or IDE

#### Optional Tools
- Valgrind (for memory checking)
- Cppcheck (for static analysis)
- Astyle (for code formatting)

### 3. Making Changes

1. Create a new branch for your feature or bug fix:
```bash
git checkout -b feature/your-feature-name
```

2. Make your changes following the coding standards below
3. Test your changes thoroughly
4. Commit your changes with clear, descriptive messages

### 4. Testing

Before submitting your changes:

1. **Compile and test:**
```bash
make clean
make
./calculator
```

2. **Run static analysis (if available):**
```bash
make analyze
```

3. **Check for memory leaks (if available):**
```bash
make memcheck
```

4. **Test all calculator functions:**
   - Basic operations: +, -, *, /
   - Advanced operations: power, square root
   - Error conditions: division by zero, negative square root
   - Invalid inputs

### 5. Submit Changes

1. Push your changes to your fork:
```bash
git push origin feature/your-feature-name
```

2. Create a Pull Request on GitHub with:
   - Clear title and description
   - Reference to any related issues
   - Description of changes made
   - Testing performed

## Coding Standards

### Code Style
- Use 4 spaces for indentation (no tabs)
- Keep lines under 80 characters when possible
- Use descriptive variable and function names
- Add comments for complex logic

### Function Documentation
```c
/**
 * @brief Brief description of the function
 * @param param_name Description of parameter
 * @return Description of return value
 */
```

### Naming Conventions
- Functions: `snake_case` (e.g., `calculate_result`)
- Variables: `snake_case` (e.g., `user_input`)
- Constants: `UPPER_CASE` (e.g., `MAX_VALUE`)
- Files: `lowercase` with underscores (e.g., `calculator.c`)

### Error Handling
- Always validate user input
- Check for mathematical errors (division by zero, etc.)
- Provide meaningful error messages
- Handle edge cases gracefully

## Types of Contributions Welcome

### New Features
- Additional mathematical operations
- Input validation improvements
- Better user interface
- Configuration options
- Unit testing framework

### Bug Fixes
- Fix calculation errors
- Improve error handling
- Memory leak fixes
- Compilation warnings

### Documentation
- Improve README
- Add code comments
- Create tutorials
- Update help messages

### Code Quality
- Refactoring for better readability
- Performance optimizations
- Code organization improvements
- Static analysis fixes

## Issue Guidelines

When reporting issues:

1. **Use descriptive titles**
2. **Provide detailed descriptions:**
   - Steps to reproduce
   - Expected behavior
   - Actual behavior
   - System information (OS, compiler version)

3. **Include code samples** when relevant
4. **Add appropriate labels** (bug, enhancement, question, etc.)

## Feature Requests

For new features:

1. Check existing issues first
2. Provide clear use case
3. Describe expected behavior
4. Consider implementation complexity
5. Be open to discussion and feedback

## Development Workflow

### Git Workflow
1. Keep your fork updated with upstream
2. Create feature branches from `main`
3. Make small, focused commits
4. Write clear commit messages
5. Rebase before submitting PR if needed

### Commit Message Format
```
type: brief description

Detailed explanation if needed

Fixes #issue-number
```

Types: `feat`, `fix`, `docs`, `style`, `refactor`, `test`, `chore`

## Code Review Process

All contributions go through code review:

1. **Automated checks** run on Pull Requests
2. **Maintainer review** for code quality and design
3. **Testing verification** by reviewers
4. **Feedback incorporation** may be requested
5. **Merge** after approval

## Getting Help

- **Questions:** Open an issue with the "question" label
- **Discussions:** Use GitHub Discussions
- **Documentation:** Check README.md first
- **Examples:** Look at existing code patterns

## Recognition

Contributors are recognized in:
- Git commit history
- Release notes (for significant contributions)
- Future CONTRIBUTORS.md file

## License

By contributing, you agree that your contributions will be licensed under the same MIT License that covers the project.

Thank you for helping make this project better!