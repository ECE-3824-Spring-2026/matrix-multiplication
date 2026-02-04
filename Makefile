# Makefile for Matrix Library Testing Battle
#
# Structure:
#   matrix.h        - header file (root)
#   src/            - implementation code
#   testing/        - unit tests
#
# Usage:
#   make impl       - compile implementation only (check syntax)
#   make tests      - compile tests only (check syntax)
#   make all        - compile everything and link
#   make run        - compile and run tests
#   make clean      - remove all build files

CXX = g++
CXXFLAGS = -Wall -std=c++17 -I.
LDFLAGS = -lCatch2Main -lCatch2

# Source files
IMPL_SRC = $(wildcard src/*.cpp)
TEST_SRC = $(wildcard testing/*.cpp)

# Object files
IMPL_OBJ = $(IMPL_SRC:.cpp=.o)
TEST_OBJ = $(TEST_SRC:.cpp=.o)

# Executable
TARGET = run_tests

# Default target
all: $(TARGET)

# Link everything together
$(TARGET): $(IMPL_OBJ) $(TEST_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Compile implementation files (for implementers to check their code)
impl: $(IMPL_OBJ)
	@echo "Implementation compiles OK"

# Compile test files (for testers to check their code)
tests: $(TEST_OBJ)
	@echo "Tests compile OK"

# Generic rule for .cpp -> .o
%.o: %.cpp matrix.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Build and run tests
run: $(TARGET)
	./$(TARGET)

# Clean build files
clean:
	rm -f $(IMPL_OBJ) $(TEST_OBJ) $(TARGET)

.PHONY: all impl tests run clean
