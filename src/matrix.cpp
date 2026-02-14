#include "../matrix.h"
#include <stdexcept>
#include <iostream>


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


Matrix& Matrix::operator=(const Matrix& other) {

    if (this == &other) return *this;

    float* nd = new float[other.rows * other.cols];

    for (int k = 0; k < other.rows * other.cols; ++k) nd[k] = other.data[k];

    delete[] data;

    data = nd;

    rows = other.rows;

    cols = other.cols;

    return *this;

}    

bool Matrix::operator==(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols) return false;
    for (int k = 0; k < rows * cols; ++k) {
        if (data[k] != other.data[k]) return false;
    }
    return true;
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

Matrix Matrix::operator+(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument("Matrix dimensions do not match");
    }

    float* vals = new float[rows * cols];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            vals[i * cols + j] = this->operator()(i, j) + other.operator()(i, j);
        }
    }

    Matrix result(rows, cols, vals);
    delete[] vals;
    return result;
}


Matrix Matrix::operator-(const Matrix& other) const{

    // Check that rows == rows and cols == cols 
    if ((this->get_n_rows() == other.get_n_rows())  && (this->get_n_cols() == other.get_n_cols())){
        
        Matrix * result = new Matrix(this->get_n_rows(), this->get_n_cols(), nullptr);        
        
        // find dimensions of Matrix A and Matrix B
        for (int i; i < other.get_n_rows(); i++){
            for (int j; j < other.get_n_rows(); j++){
            result->operator()(i,j) = other.operator()(i,j) - this->operator()(i,j);
          }
        }
        return(*result);
    }

    // Throw in some comments 
    else{
        std :: cout << "Error";
        throw std::runtime_error("");
    }
}
