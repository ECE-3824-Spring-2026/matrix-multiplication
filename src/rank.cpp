/*
Tony Mejia-Cuba

file path: matrix-multiplication/src/rank.cpp

Description: This file has the implementation of the rank fuction.
This code will calculate the rank of a matrix using Guassian elimation
since no libraries are allowd.

history:

Feburuuary 6th, 2026: Created rank.cpp and bare bones fuctions
Febuuary 9th, 2026: starting coding fr fr
feburuary 10th, 2026: finsihed all of it, tested and debugged

*/

#include <cstdio>
#include "matrix.h"

// Implement operator() here to allow element access in rank calculation
const float& Matrix::operator()(int i, int j) const {
    return data[i * cols + j];
}

float& Matrix::operator()(int i, int j) {
    return data[i * cols + j];
}

// from row and collum get row and colloum. get_n_rows(), get_n_cols()

// helpers -----------------------------------------------------------------------------
// this is a helper function to calculate the absolute value of a float since we can't use the standard library
static float myAbs(float x) { return (x < 0.0f) ? -x : x; }

// error handler function
static void error_handler(const char* msg) {
    std::fprintf(stdout, "ERROR: %s\n", msg);
}

// this is a helper function that will be used to calculate the rank of a matrix
static int gauss_rank(const Matrix& A);


//-----------------------------------------------------------------------------------------

// main function
int Matrix::rank() const {
    // this is the main function that will be called to calculate the rank of a matrix
    // it will call the gauss_rank function to do the actual calculation
    return gauss_rank(*this);
}


// this is a helper function that will be used to calculate the rank of a matrix
static int gauss_rank(const Matrix& A) {
    // it will use Gaussian elimination to reduce the matrix
    // and then count the number of non-zero (pivot) rows

    // a small value to compare against zero
    // NOTE: since we are using floats, 1e-10 is usually too strict (can cause tiny pivots to look non-zero)
    const float EPSILON = 1e-6f;

    int n = A.get_n_rows();
    int m = A.get_n_cols();

    // basic guard (0xN or Nx0 matrix has rank 0)
    if (n <= 0 || m <= 0) return 0;

    // use the MAX that the Matrix class already defines so we stay consistent with the project
    const int MAX = Matrix::MAX;

    if (n > MAX || m > MAX) {
        error_handler("Matrix size exceeds maximum allowed.");
        return 0;
    }

    // copy matrix into local temp array so we don't modify the original matrix
    float temp[MAX][MAX];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            temp[i][j] = A(i, j);
        }
    }

    int rank = 0;
    int row  = 0;

    for (int col = 0; col < m && row < n; ++col) {

        // find the pivot row with the largest absolute value in the current column
        int pivot_row = row;
        for (int r = row + 1; r < n; ++r) {
            if (myAbs(temp[r][col]) > myAbs(temp[pivot_row][col])) {
                pivot_row = r;
            }
        }

        // if the pivot element is close to zero, skip this column
        if (myAbs(temp[pivot_row][col]) < EPSILON) {
            continue;
        }

        // swap the current row with the pivot row
        if (pivot_row != row) {
            for (int c = 0; c < m; ++c) {
                float t = temp[row][c];
                temp[row][c] = temp[pivot_row][c];
                temp[pivot_row][c] = t;
            }
        }

        // elimination:
        // This is Gauss-Jordan style (eliminates both above and below the pivot),
        // which is fine for rank because we just need to count pivots.
        for (int r = 0; r < n; ++r) {
            if (r == row) continue;

            float factor = temp[r][col] / temp[row][col];
            for (int c = col; c < m; ++c) {
                temp[r][c] -= factor * temp[row][c];
            }
        }

        ++row;
        ++rank;
    }

    return rank;
}


