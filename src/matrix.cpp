#include "matrix.h"

Matrix Matrix::transpose() const {
    // Create array for transposed data (swapped dimensions)
    float* transposed_data = new float[rows * cols];
    
    // Fill transposed data: element at (i,j) goes to (j,i)
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            transposed_data[j * rows + i] = (*this)(i, j);
        }
    }
    
    // Create and return new matrix with swapped dimensions
    Matrix result(cols, rows, transposed_data);
    delete[] transposed_data;
    
    return result;
}
