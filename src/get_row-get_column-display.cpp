/*
 * File: get_row-get_column-display.cpp
 * Author: ZhaoXiang Lan
 * Course: ECE 3824
 * Date: February 6, 2026
 * Description: Implementation of row/column getter and display functions for matrix operations
 */

#include "../matrix.h"
#include <iostream>
#include <stdexcept>
using namespace std;

Matrix::Matrix(int r, int c, const float* input_data) {
    // 1. invalid dimensions → throw
    if (r <= 0 || c <= 0) {
        throw std::invalid_argument("Invalid matrix dimensions");
    }

    rows = r;
    cols = c;

    // 2. allocate memory
    data = new float[rows * cols];

    // 3. null data = zero-initialize
    if (input_data == nullptr) {
        for (int i = 0; i < rows * cols; ++i) {
            data[i] = 0.0f;
        }
        return;
    }

    // 4. valid data = copy
    for (int i = 0; i < rows * cols; ++i) {
        data[i] = input_data[i];
    }
}

Matrix::~Matrix() {
    if (data != nullptr) {
        delete[] data;
        data = nullptr;
    }
}

int Matrix::get_n_rows() const {
    return rows;
}

int Matrix::get_n_cols() const {
    return cols;
}

void Matrix::display() const {
    if (data == nullptr || rows <= 0 || cols <= 0) {
        
        return;
    }

    for (int i = 0; i < rows; i++) {
        fprintf(stdout, "[ ");
        for (int j = 0; j < cols; j++) {
            fprintf(stdout, "%6.2f", data[i * cols + j]);
        }
        fprintf(stdout, " ]\n");
    }
}
