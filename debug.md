# Debug Notes

## Catch2

two different versions of catch2 were being used in the testing folder. Several files where using catch2 2v. The makefile supported catch2 3v which required:
```C++
#include <catch2/catch_test_macros.hpp>
```
removed the catch.cpp

## Fails/Crashes

A test code in constructor is failing due to this constructor implementation
```C++
Matrix::Matrix(int r, int c, const float* input_data) {
        // Validate dimensions error handling
        //
        if (r <= 0 || c <= 0 ){
            error_handler("Invalid matrix dimensions. Rows and columns must be positive.");
            rows = 0;
            cols = 0;
            data = nullptr;
            return;
        }

        // Validate input data pointer
        // 
        if (input_data == nullptr) {
            error_handler("Input data pointer is null. Matrix will be initialized with zeros.");
            data = new float[r * c](); // Initialize with zeros
            rows = r;
            cols = c;
            return;
        }
        // Constructor to initialize the matrix with given dimensions and data
        //
        rows = r;
        cols = c;

        // Allocate memory for 1D array (row-major order)
        //
        data = new float[rows * cols];

        // Copy the input data into the matrix
        //
        for (int i = 0; i < rows * cols; i++) {
            data[i] = input_data[i];
        }
    }
```
when data was being used elsewhere in the program trying to retrieve values it did not have from being assigned nullptr. 
Used the same idea but instead initialized the matrix with zeros. 
