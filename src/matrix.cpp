#include "../matrix.h"
#include <stdexcept>
#include <iostream>
using namespace std;

Matrix::Matrix(int r, int c, const float* input_data) {
        // Validate dimensions error handling
        //
        if (r <= 0 || c <= 0 ){
            throw std::invalid_argument("Invalid matrix dimensions. Rows and columns must be positive.");
        }

        // Validate input data pointer
        // 
        if (input_data == nullptr) {
            throw std::invalid_argument("Input data pointer is null.");
        }
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
        if( data != nullptr) {
            delete[] data;
            data = nullptr; // Avoid dangling pointer
        }
    }

    int Matrix::get_n_rows() const{
        // Return the number of rows in the matrix
        //
        return rows;
    }
 
    int Matrix::get_n_cols() const {
        // Return the number of columns in the matrix
        //
        return cols;
    }
 
    void Matrix::display() const {
        // Display the formatted matrix
        //
        for (int i = 0; i < rows; i++) {
            fprintf(stdout, "[ ");
            for (int j = 0; j < cols; j++) {
                // Access element using row-major formula: i * cols + j
                //
                fprintf(stdout, "%6.2f", data[i * cols + j]);
            }
            fprintf(stdout, " ]\n");
        }
    }
    
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

Matrix Matrix::operator+(const Matrix& other) const{

    // Check that rows == rows and cols == cols 
    if ((this->get_n_rows() == other.get_n_rows())  && (this->get_n_cols() == other.get_n_cols())){
        
        // Allocate temporary array for result data
        float* result_data = new float[rows * cols];
        
        // Add corresponding elements
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                result_data[i * cols + j] = this->operator()(i,j) + other.operator()(i,j);
            }
        }
        
        // Create result matrix and clean up temporary array
        Matrix result(rows, cols, result_data);
        delete[] result_data;
        return result;
    }

    else{
        std :: cout << "Error";
        throw std::runtime_error("");
    } 
}


Matrix Matrix::operator-(const Matrix& other) const{

    // Check that rows == rows and cols == cols 
    if ((this->get_n_rows() == other.get_n_rows())  && (this->get_n_cols() == other.get_n_cols())){
        
        // Allocate temporary array for result data
        float* result_data = new float[rows * cols];
        
        // Subtract corresponding elements (this - other)
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                result_data[i * cols + j] = this->operator()(i,j) - other.operator()(i,j);
            }
        }
        
        // Create result matrix and clean up temporary array
        Matrix result(rows, cols, result_data);
        delete[] result_data;
        return result;
    }

    // Throw in some comments 
    else{
        std :: cout << "Error";
        throw std::runtime_error("");
    }
}
