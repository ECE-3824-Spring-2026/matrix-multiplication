#include<iostream>
#include "../matrix.h"

Matrix get_submatrix(const Matrix &m , int skip);
Matrix zeros(int r, int j);

Matrix::Matrix(int r, int c, const float *v){
    if (r < 1)
        throw invalid_argument("constructor - rows must be >= 1");
    if (c < 1)
        throw invalid_argument("constructor - cols must be >= 1");
    rows = r;
    cols = c;
    vals.assign(v,v+r*c);
}

Matrix::~Matrix(){}

int Matrix::get_n_rows() const {
    return rows;
}

int Matrix::get_n_cols() const {
    return cols;
}

float Matrix::determinant() const {
    if ( rows != cols )
        throw invalid_argument("determinant: matrix must be square");
    if (rows == 1)
        return vals[0];
    float det = 0;
    float sign = 1;
    float v;
    for (int i = 0; i<rows ; i++){
        v = this->operator()(0,i);
        det += sign * v * get_submatrix(*this,i).determinant();
        sign *= -1;
    } 
    return det;
}

int Matrix::rank()          const {return 0;}

void Matrix::display()const {
    int ind = 0;
    for (int i = 0 ; i < rows ; i++){
        for (int j = 0 ; j < cols ; j++){
            printf("%5.2f\t",vals[ind++]);
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

Matrix Matrix::operator-( const Matrix& other) const {
    if (this->rows != other.rows || this->cols != other.cols)
        throw invalid_argument("Can't add: matrix dimensions don't agree");
    Matrix soln = other;
    for (int i=0;i<this->rows;i++)
        for (int j=0;j<this->cols;j++)
            soln(i,j) = this->operator()(i,j) - soln(i,j);
    return soln;
}

Matrix Matrix::operator*( const Matrix& other) const {
    if (this->cols != other.rows)
        throw invalid_argument("Matrix multiplication: inner dimensions don't match");
    Matrix result = zeros(this->rows , other.cols);
    for (int i = 0 ; i<this->rows ; i++){
        for (int j = 0 ; j<other.cols; j++){
            for (int k = 0 ; k<this->cols; k++){
                result(i,j) += this->operator()(i,k) * other(k,j);
            }
        }
    }
    return result;
}

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

bool Matrix::operator==(const Matrix& other) const{
    if (this->rows != other.rows)
        return false;
    if (this->cols != other.cols)
        return false;
    int nElems = rows*cols;
    for (int i = 0; i< nElems; i++)
        if (this->vals[i] != other.vals[i])
            return false;
    return true;
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

Matrix zeros(int r, int c){
    vector<float> vals(r*c , 0.0f);
    Matrix m(r,c,vals.data());
    return m;
}