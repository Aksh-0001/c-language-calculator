# C Language Calculator Makefile
# Author: GitHub Repository
# Description: Build automation for C calculator project

# Compiler settings
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -pedantic
MATHLIB = -lm
DEBUG_FLAGS = -g -DDEBUG
RELEASE_FLAGS = -O2 -DNDEBUG

# Project settings
TARGET = calculator
SOURCE = calculator.c
OBJECT = calculator.o

# Default target
all: $(TARGET)

# Build the calculator (release mode)
$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) $(RELEASE_FLAGS) -o $(TARGET) $(SOURCE) $(MATHLIB)
	@echo "Calculator compiled successfully!"
	@echo "Run with: ./$(TARGET)"

# Build object file
$(OBJECT): $(SOURCE)
	$(CC) $(CFLAGS) -c $(SOURCE)

# Debug build
debug: $(SOURCE)
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) -o $(TARGET)_debug $(SOURCE) $(MATHLIB)
	@echo "Debug version compiled successfully!"
	@echo "Run with: ./$(TARGET)_debug"

# Release build (explicit)
release: $(SOURCE)
	$(CC) $(CFLAGS) $(RELEASE_FLAGS) -o $(TARGET) $(SOURCE) $(MATHLIB)
	@echo "Release version compiled successfully!"

# Install to system (optional)
install: $(TARGET)
	@echo "Installing calculator to /usr/local/bin/"
	sudo cp $(TARGET) /usr/local/bin/
	@echo "Installation complete!"

# Uninstall from system
uninstall:
	@echo "Removing calculator from /usr/local/bin/"
	sudo rm -f /usr/local/bin/$(TARGET)
	@echo "Uninstallation complete!"

# Clean build files
clean:
	rm -f $(TARGET) $(TARGET)_debug $(OBJECT) *.o
	@echo "Clean complete!"

# Force rebuild
rebuild: clean all

# Run the calculator
run: $(TARGET)
	./$(TARGET)

# Run tests (placeholder for future test implementation)
test:
	@echo "No tests implemented yet"
	@echo "TODO: Add unit tests for calculator functions"

# Show help
help:
	@echo "Available targets:"
	@echo "  all      - Build the calculator (default)"
	@echo "  debug    - Build debug version with debugging symbols"
	@echo "  release  - Build optimized release version"
	@echo "  clean    - Remove all build files"
	@echo "  rebuild  - Clean and build"
	@echo "  run      - Build and run the calculator"
	@echo "  install  - Install calculator to system path"
	@echo "  uninstall - Remove calculator from system path"
	@echo "  test     - Run tests (not implemented yet)"
	@echo "  help     - Show this help message"

# Check code style (requires astyle)
style:
	@echo "Checking code style..."
	@which astyle > /dev/null || (echo "astyle not found. Install with: apt-get install astyle"; exit 1)
	astyle --style=kr --indent=spaces=4 --max-code-length=80 $(SOURCE)
	@echo "Code style check complete!"

# Static analysis (requires cppcheck)
analyze:
	@echo "Running static analysis..."
	@which cppcheck > /dev/null || (echo "cppcheck not found. Install with: apt-get install cppcheck"; exit 1)
	cppcheck --enable=all --std=c99 $(SOURCE)
	@echo "Static analysis complete!"

# Memory check (requires valgrind)
memcheck: debug
	@echo "Running memory check..."
	@which valgrind > /dev/null || (echo "valgrind not found. Install with: apt-get install valgrind"; exit 1)
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)_debug
	@echo "Memory check complete!"

# Count lines of code
count:
	@echo "Lines of code:"
	@wc -l $(SOURCE)
	@echo "Total files: 1"

# Show compiler version
version:
	@$(CC) --version

# Phony targets (don't represent files)
.PHONY: all debug release clean rebuild run test help install uninstall style analyze memcheck count version