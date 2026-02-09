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

    Matrix::Matrix(int rows, int cols, const float* input_data) {
        // Constructor to initialize the matrix with given dimensions and data
        // row and column
        //
        n_rows = rows;
        n_cols = cols;

        // Allocate memory for pointer to rows
        //
        data = new float*[n_rows];

        // Allocate memory for data in each row
        //
        for (int i =0; i < n_rows; i++){
            data[i] = new float[n_cols];
        }

        // copy the input data into the matrix
        // go through each row and column and assign the value from input_data into data
        //
        for (int i = 0; i < n_rows ; i++){
            for (int j = 0; j < n_cols  ; j++){
                // assign the value from input_data into data
                // [i * n_cols + j] convert 2D input array into 3D matrix access pattern for data[i][j]
                //
                data [i][j] = input_data[ i* n_cols + j];
            }
        }
        
    }
    
    Matrix::~Matrix() {
        // destructor to free allocated memory for the matrix
        // free memory for data in each row
        //
        for (int i = 0; i < n_rows; i++){
            delete[] data[i];
        }
        // free memory for pointer to rows
        //
        delete[] data;
    }

    int Matrix::get_n_rows() const{
        // Return the number of rows in the matrix
        //
        return n_rows;
    }
 
    int Matrix::get_n_cols() const{
        // Return the number of columns in the matrix
        //
        return n_cols;
    }

    void Matrix::display() const{
        // Display the formatted matrix
        // traverse through each row
        //
        for (int i = 0; i < n_rows; i++){
            // print the opening bracket for each row
            // 
            fprintf(stdout, "[");
            // traverse through each column
            //
            for (int j = 0; j < n_cols; j++){
                // print the data
                //
                fprintf(stdout, "%6.2f", data[i][j]);
            }
            // print the closing bracket for each row and move to the next line
            //
            fprintf(stdout, "]\n");
        }
    }