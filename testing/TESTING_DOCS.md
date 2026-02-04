# Testing Documentation

##### We should have two people testing the constructor, destructor, and non-input functions
* input matrices of non square sizes
* possibly test memory allocation issues with input pointer

They should test the functions that aren't easy to break (no inputs):
```cpp
int get_n_rows() const;                 // return number of rows
int get_n_cols() const;                 // return number of columns
void display() const;                   // display formatted matrix
Matrix(int,int,const float*);           // constructor
Matrix& operator=(const Matrix&);       // copy assignment A = B
~Matrix();                              // destructor
```

##### The remaining 5 people should test two items each:
```cpp
float determinant() const;              // return matrix determinant
int rank() const;                       // return matrix rank
Matrix transpose() const;                   // B = A.transpose
Matrix operator+( const Matrix& ) const;    // add Matrix plus Matrix
Matrix operator-( const Matrix& ) const;
Matrix operator*( const Matrix& ) const;
Matrix operator+( const float& )  const;    // add constant to Matrix
Matrix operator-( const float& )  const;
Matrix operator*( const float& )  const;
Matrix operator/( const float& )  const;
```

### using catch2 (from Readings)
```cpp
#include<iostream>
#include <catch2/catch_test_macros.hpp>
using namespace std;

// install catch2 with
// sudo apt install catch2

// compile with 
// g++ testing.cpp -lCatch2Main -lCatch2 -o testing.exe


int f1(int x, int y){
    return x + y;
}

TEST_CASE("addition test"){
    int x = -1;
    int y = 1;
    int a = 4;
    int b = 3;
    REQUIRE(f1(a,b) == 7);
    REQUIRE(f1(x,y) == 0);
}

TEST_CASE("another addition test"){
    REQUIRE(f1(5,-4)==1);
}
```