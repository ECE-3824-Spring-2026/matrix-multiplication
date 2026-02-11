#include <iostream>
#include "matrix.h"

Matrix Matrix::operator+(const Matrix& other) const{

    // Check that rows == rows and cols == cols 
    if ((this->get_n_rows() == other.get_n_rows())  && (this->get_n_cols() == other.get_n_cols())){
        
        Matrix * result = new Matrix(this->get_n_rows(), this->get_n_cols(), nullptr);
        
        // find dimensions of Matrix A and Matrix B
        for (int i; i < other.get_n_rows(); i++){
            for (int j; j < other.get_n_rows(); j++){
            result->operator()(i,j) = other.operator()(i,j) + this->operator()(i,j);
          }
        }
        return(*result);
    }

    else{
        std :: cout << "Error";
        throw std::runtime_error("");
    } 
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

    else{
        std :: cout << "Error";
        throw std::runtime_error("");
    }
}









