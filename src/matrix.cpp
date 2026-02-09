#include "../matrix.h"


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
