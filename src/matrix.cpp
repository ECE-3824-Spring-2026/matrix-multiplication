#include "matrix.h"

Matrix Matrix::transpose() const {
    // Create array for transposed data (swapped dimensions)
    float* transposed_data = new float[n_rows * n_cols];
    
    // Fill transposed data: element at (i,j) goes to (j,i)
    for (int i = 0; i < n_rows; ++i) {
        for (int j = 0; j < n_cols; ++j) {
            transposed_data[j * n_rows + i] = (*this)(i, j);
        }
    }
    
    // Create and return new matrix with swapped dimensions
    Matrix result(n_cols, n_rows, transposed_data);
    delete[] transposed_data;
    
    return result;
}
