#include "../matrix.h"
#include <stdexcept>
#include <iostream>

Matrix Matrix::operator*(const Matrix& other) const {
    // Basic check: columns of A must match rows of B
    if (this->cols != other.get_n_rows()) {
        throw std::invalid_argument("Incompatible dimensions");
    }

    // Define dimensions for the new matrix
    int rows = this->rows;
    int cols = other.get_n_cols();
    float* result_vals = new float[rows * cols];

    // Simple triple loop for multiplication
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            float sum = 0;
            for (int k = 0; k < this->cols; k++) {
                // multiply row element by column element
                sum += (*this)(i, k) * other(k, j);
            }
            // Put the result in the 1D array
            result_vals[i * cols + j] = sum;
        }
    }

    // Create result object, clean up temporary memory, and return
    Matrix result(rows, cols, result_vals);
    delete[] result_vals;
    return result;
}
