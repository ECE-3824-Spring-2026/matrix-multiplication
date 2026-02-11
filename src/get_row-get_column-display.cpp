/*
 * File: get_row-get_column-display.cpp
 * Author: ZhaoXiang Lan
 * Course: ECE 3824
 * Date: February 6, 2026
 * Description: Implementation of row/column getter and display functions for matrix operations
 */

#include "../matrix.h"
#include <iostream>
using namespace std;

    Matrix::Matrix(int r, int c, const float* input_data) {
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
    
    Matrix::~Matrix() {
        // Destructor to free allocated memory for the matrix
        //
        delete[] data;
    }

    int Matrix::get_n_rows() const{
        // Return the number of rows in the matrix
        //
        return rows;
    }
 
    int Matrix::get_n_cols() const {
        // Return the number of columns in the matrix
        return cols;
    }
 
    void Matrix::display() const {
        // Display the formatted matrix
        for (int i = 0; i < rows; i++) {
            fprintf(stdout, "[ ");
            for (int j = 0; j < cols; j++) {
                // Access element using row-major formula: i * cols + j
                fprintf(stdout, "%6.2f", data[i * cols + j]);
            }
            fprintf(stdout, " ]\n");
        }
    }

    void test() {
        // Test function to demonstrate the usage of Matrix class
        float input_data[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
        Matrix A(3, 3, input_data);
        
        // Display the matrix
        A.display();
        
        // Test getter functions
        printf("\nRows: %d, Columns: %d\n", A.get_n_rows(), A.get_n_cols());
    }