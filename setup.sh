#!/bin/bash

# setup.sh - Setup script for C Language Calculator
# This script helps set up the development environment and build the calculator

set -e  # Exit on any error

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Print colored output
print_info() {
    echo -e "${BLUE}[INFO]${NC} $1"
}

print_success() {
    echo -e "${GREEN}[SUCCESS]${NC} $1"
}

print_warning() {
    echo -e "${YELLOW}[WARNING]${NC} $1"
}

print_error() {
    echo -e "${RED}[ERROR]${NC} $1"
}

# Check if command exists
check_command() {
    if command -v "$1" >/dev/null 2>&1; then
        return 0
    else
        return 1
    fi
}

# Main setup function
main() {
    echo "========================================"
    echo "  C Language Calculator Setup Script   "
    echo "========================================"
    echo

    # Check for required tools
    print_info "Checking for required tools..."

    if check_command gcc; then
        print_success "GCC compiler found: $(gcc --version | head -n1)"
    else
        print_error "GCC compiler not found. Please install GCC."
        print_info "On Ubuntu/Debian: sudo apt-get install gcc"
        print_info "On macOS: xcode-select --install"
        print_info "On Windows: Install MinGW or use WSL"
        exit 1
    fi

    if check_command make; then
        print_success "Make utility found: $(make --version | head -n1)"
    else
        print_warning "Make utility not found. You can still compile manually."
        print_info "On Ubuntu/Debian: sudo apt-get install make"
        print_info "On macOS: xcode-select --install"
    fi

    # Optional tools
    print_info "Checking for optional development tools..."

    if check_command valgrind; then
        print_success "Valgrind found (for memory checking)"
    else
        print_warning "Valgrind not found (optional - for memory checking)"
        print_info "Install with: sudo apt-get install valgrind"
    fi

    if check_command cppcheck; then
        print_success "Cppcheck found (for static analysis)"
    else
        print_warning "Cppcheck not found (optional - for static analysis)"
        print_info "Install with: sudo apt-get install cppcheck"
    fi

    echo

    # Build the calculator
    print_info "Building the calculator..."

    if [ -f "Makefile" ]; then
        if make clean && make; then
            print_success "Calculator built successfully!"
        else
            print_error "Build failed. Check the error messages above."
            exit 1
        fi
    else
        print_info "Makefile not found. Building manually..."
        if gcc -Wall -Wextra -std=c99 -O2 -o calculator calculator.c -lm; then
            print_success "Calculator built successfully!"
        else
            print_error "Manual build failed. Check the error messages above."
            exit 1
        fi
    fi

    # Test the build
    print_info "Testing the calculator..."
    if [ -x "./calculator" ]; then
        print_success "Calculator executable created successfully!"
        echo
        print_info "You can now run the calculator with: ./calculator"
        echo

        # Show usage information
        echo "Usage Instructions:"
        echo "=================="
        echo "1. Run the calculator: ./calculator"
        echo "2. Follow the on-screen menu"
        echo "3. Select operations by entering numbers 1-7"
        echo "4. Enter numbers when prompted"
        echo "5. Choose 'y' to continue or 'n' to exit"
        echo

        echo "Development Commands:"
        echo "===================="
        if [ -f "Makefile" ]; then
            echo "make          - Build the calculator"
            echo "make debug    - Build debug version"
            echo "make clean    - Clean build files"
            echo "make rebuild  - Clean and rebuild"
            echo "make run      - Build and run"
            echo "make test     - Run tests (if implemented)"
            echo "make help     - Show all make targets"
        else
            echo "gcc -o calculator calculator.c -lm  - Manual build"
            echo "gcc -g -o calculator_debug calculator.c -lm  - Debug build"
        fi
        echo

        print_success "Setup completed successfully!"
        echo
        print_info "Optional: Run './calculator' now to test the calculator."

    else
        print_error "Calculator executable not found after build."
        exit 1
    fi
}

# Help function
show_help() {
    echo "C Language Calculator Setup Script"
    echo
    echo "Usage: $0 [OPTIONS]"
    echo
    echo "Options:"
    echo "  -h, --help     Show this help message"
    echo "  -q, --quiet    Quiet mode (less output)"
    echo
    echo "This script will:"
    echo "1. Check for required development tools"
    echo "2. Build the calculator program"
    echo "3. Provide usage instructions"
    echo
}

# Parse command line arguments
while [[ $# -gt 0 ]]; do
    case $1 in
        -h|--help)
            show_help
            exit 0
            ;;
        -q|--quiet)
            # Implement quiet mode if needed
            shift
            ;;
        *)
            print_error "Unknown option: $1"
            show_help
            exit 1
            ;;
    esac
done

# Run main function
main