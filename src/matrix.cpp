#include<iostream>
#include "../matrix.h"

Matrix get_submatrix(const Matrix &m , int skip);

Matrix::Matrix(int r, int c, const float *v){
    rows = r;
    cols = c;
    vals.assign(v,v+r*c);
}

Matrix::~Matrix(){}

int Matrix::get_n_rows() const {return rows;}
int Matrix::get_n_cols() const {return cols;}

float Matrix::determinant() const {
    if ( rows != cols )
        throw invalid_argument("determinant: matrix must be square");
    if (rows == 1)
        return vals[0];
    float det = 0;
    float sign = 1;
    for (int i = 0; i<rows ; i++){
        det += sign * get_submatrix(*this,i).determinant();
        sign *= -1;
    } 
    return det;
}

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

Matrix Matrix::operator-( const float& other) const{
    int nElem = rows*cols;
    float newVals[nElem];
    for (int i = 0; i<=nElem ; i++)
        newVals[i] = vals[i] - other;
    return Matrix(rows,cols,newVals);
}

Matrix Matrix::operator*( const float& other) const{
    int nElem = rows*cols;
    float newVals[nElem];
    for (int i = 0; i<=nElem ; i++)
        newVals[i] = vals[i] * other;
    return Matrix(rows,cols,newVals);
}

Matrix Matrix::operator/( const float& other) const{
    if (other==0)
        throw domain_error("Divide by zero, matrix ÷ 0");
    int nElem = rows*cols;
    float newVals[nElem];
    for (int i = 0; i<=nElem ; i++)
        newVals[i] = vals[i] / other;
    return Matrix(rows,cols,newVals);
}

Matrix Matrix::operator+( const Matrix& other) const {
    if (this->rows != other.rows || this->cols != other.cols)
        throw invalid_argument("Can't add: matrix dimensions don't agree");
    Matrix soln = other;
    for (int i=0;i<this->rows;i++)
        for (int j=0;j<this->cols;j++)
            soln(i,j) += this->operator()(i,j);
    return soln;

}

Matrix Matrix::operator-( const Matrix& other) const {return *this;}
Matrix Matrix::operator*( const Matrix& other) const {return *this;}

Matrix& Matrix::operator=(const Matrix& other) {
    int r = other.rows;
    int c = other.cols;
    int nElem = r*c;
    for (int i=0;i<nElem;i++)
        this->vals[i] = other.vals[i];
    return *this;
}

const float& Matrix::operator()(int r,int c) const{
    // enables A(1,2) = 3.14 -> data assignment
    int ind = c + r*cols;
    return vals[ind];
}

float& Matrix::operator()(int r, int c){
    // enables float x = A(1,2) -> data retrieval
    int ind = c + r*cols;
    return vals[ind];
}

Matrix get_submatrix(const Matrix &m , int skip){
    vector<float> newValsVec;
    int newRows = m.get_n_rows() - 1;
    int newCols = m.get_n_cols() - 1;

    for (int i = 1 ; i<m.get_n_rows() ; i++){
        for (int j = 0 ; j<m.get_n_cols() ; j++){
            if (j!=skip)
                newValsVec.push_back(m(i,j));
        }
    }

    float* vals = newValsVec.data();    
    return Matrix(newRows,newCols,vals);
}