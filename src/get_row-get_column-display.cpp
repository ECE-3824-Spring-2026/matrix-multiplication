/*
 * File: get_row-get_column-display.cpp
 * Author: ZhaoXiang Lan
 * Course: ECE 3824
 * Date: February 6, 2026
 * Description: Implementation of row/column getter and display functions for matrix operations
 */


#include "../matrix.h"
#include <cstdio>
using namespace std;

int Matrix::get_n_rows() const {
    return rows;
}

int Matrix::get_n_cols() const {
    return cols;
}

void Matrix::display() const {
    if (data == nullptr) {
        return; // silently do nothing
    }

    for (int i = 0; i < rows; i++) {
        fprintf(stdout, "[ ");
        for (int j = 0; j < cols; j++) {
            fprintf(stdout, "%6.2f", data[i * cols + j]);
        }
        fprintf(stdout, " ]\n");
    }
}
