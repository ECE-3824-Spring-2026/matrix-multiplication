#include "../matrix.h"
#include <stdexcept>


Matrix Matrix::operator+(const float& k) const {
    float* vals = new float[rows * cols];

    for (int i = 0; i < rows * cols; i++)
        vals[i] = data[i] + k;

    Matrix result(rows, cols, vals);
    delete[] vals;
    return result;
}

Matrix Matrix::operator-(const float& k) const {
    float* vals = new float[rows * cols];

    for (int i = 0; i < rows * cols; i++)
        vals[i] = data[i] - k;

    Matrix result(rows, cols, vals);
    delete[] vals;
    return result;
}

Matrix Matrix::operator*(const float& k) const {
    float* vals = new float[rows * cols];

    for (int i = 0; i < rows * cols; i++)
        vals[i] = data[i] * k;

    Matrix result(rows, cols, vals);
    delete[] vals;
    return result;
}

Matrix Matrix::operator/(const float& k) const {
    if (k == 0.0f) {
        return *this;
    }

    float* vals = new float[rows * cols];

    for (int i = 0; i < rows * cols; i++)
        vals[i] = data[i] / k;

    Matrix result(rows, cols, vals);
    delete[] vals;
    return result;
}


float Matrix::determinant() const {

    if (rows != cols) {
        throw std::invalid_argument("determinant requires square matrix!!!");
    }

    // 1x1
    if (rows == 1) {
        return (*this)(0,0);
    }

    // 2x2
    if (rows == 2) {
        return (*this)(0,0) * (*this)(1,1)
             - (*this)(0,1) * (*this)(1,0);
    }

    float det = 0.0f;

    // cofactor expansion along first row
    for (int j = 0; j < cols; j++) {

        float* minor_vals = new float[(rows - 1) * (cols - 1)];
        int k = 0;

        for (int i = 1; i < rows; i++) {
            for (int c = 0; c < cols; c++) {
                if (c != j) {
                    minor_vals[k++] = (*this)(i, c);
                }
            }
        }

        Matrix minor(rows - 1, cols - 1, minor_vals);
        delete[] minor_vals;

        float sign = (j % 2 == 0) ? 1.0f : -1.0f;
        det += sign * (*this)(0, j) * minor.determinant();
    }

    return det;
}

