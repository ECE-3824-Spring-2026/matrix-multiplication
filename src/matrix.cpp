#include<iostream>
#include "../matrix.h"

Matrix::Matrix(int r, int c, const float *v){
    rows = r;
    cols = c;
    vals.assign(v,v+r*c);
}

Matrix::~Matrix(){}

int Matrix::get_n_rows() const {return rows;}
int Matrix::get_n_cols() const {return cols;}

float Matrix::determinant() const {return 0;}
int Matrix::rank()          const {return 0;}

void Matrix::display()const {
    int ind = 0;
    for (int i = 0 ; i < rows ; i++){
        for (int j = 0 ; j < cols ; j++){
            printf("%0.2f\t",vals[ind++]);
        }
        printf("\n");
    }    
}

Matrix Matrix::operator+( const float& other) const{
    int nElem = rows*cols;
    float newVals[nElem];
    for (int i = 0; i<=nElem ; i++)
        newVals[i] = vals[i] + other;
    return Matrix(rows,cols,newVals);
}



Matrix Matrix::operator-( const float& other) const{return *this;}
Matrix Matrix::operator*( const float& other) const{return *this;}
Matrix Matrix::operator/( const float& other) const{return *this;}

Matrix Matrix::operator+( const Matrix& other) const {return *this;}
Matrix Matrix::operator-( const Matrix& other) const {return *this;}
Matrix Matrix::operator*( const Matrix& other) const {return *this;}

Matrix& Matrix::operator=(const Matrix& other) {return *this;}

const float& Matrix::operator()(int r,int c) const{
    // enables float x = A(1,2) -> data retrieval
    int ind = c + r*cols;
    return vals[ind];
}

float& Matrix::operator()(int r, int c){
    // enables A(1,2) = 3.14 -> data assignment
    int ind = c + r*cols;
    return vals[ind];
}
