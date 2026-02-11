#ifndef MATRIX_H
#define MATRIX_H

class Matrix{
private:
    int rows;
    int cols;
    float* data;

public:
    Matrix(int,int,const float*);
    Matrix& operator=(const Matrix&);
    ~Matrix();

    const float& operator()(int,int) const;
    float& operator()(int,int);

    int get_n_rows() const;
    int get_n_cols() const;
    float determinant() const;
    int rank() const;
    void display() const;

    Matrix transpose() const;

    Matrix operator+(const Matrix&) const;
    Matrix operator-(const Matrix&) const;
    Matrix operator*(const Matrix&) const;
    Matrix operator+(const float&) const;
    Matrix operator-(const float&) const;
    Matrix operator*(const float&) const;
    Matrix operator/(const float&) const;
    bool operator==(const Matrix&) const;
};

#endif
