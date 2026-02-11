# Testing Documentation

### We should have two people testing the constructor, destructor, and non-input functions

They should test the functions that aren't easy to break
```cpp
Matrix(int,int,const float*);           // constructor
Matrix& operator=(const Matrix&);       // copy assignment A = B
int get_n_rows() const;                 // return number of rows
int get_n_cols() const;                 // return number of columns
void display() const;                   // display formatted matrix
const float& operator()(int,int) const; // enables A(1,2) = 3.14 -> data assignment 
float& operator()(int i, int j);        // enables float x = A(1,2) -> data retrieval
~Matrix();                              // destructor
```

### The remaining 6 people should test two items each:
Ensure that there isn't an existing file testing that operation before choosing one to write.
```cpp
float determinant() const;              // return matrix determinant.  (Jass Gatewood)
int rank() const;                       // return matrix rank           (Jass Gatewood)
Matrix transpose() const;                   // B = A.transpose          (adil chariwala)
Matrix operator+( const Matrix& ) const;    // add Matrix plus Matrix
Matrix operator-( const Matrix& ) const;           // adil chariwala                                  
Matrix operator*( const Matrix& ) const;                              //    (Shahzad)
Matrix operator+( const float& )  const;    // add constant to Matrix    (Mohamad Charabi)
Matrix operator-( const float& )  const;
Matrix operator*( const float& )  const;  //                                              (Mariya Denny)
Matrix operator/( const float& )  const;  //                                              (Mariya Denny)
bool operator==(const Matrix& ) const;    // determine if two matrices are equal
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

See [test_constructor.cpp](https://github.com/ECE-3824-Spring-2026/matrix-multiplication/blob/testing-constructor/testing/test_constructor.cpp) for an example.

### Adding a test file
* clone the testing branch
* create a file called test_[name of test].cpp, ex. test_constructor.cpp
* add a comment with your name at the top
* push the new file directly to the testing branch (so others can see which operations are being developed already)

### Writing your tests
* create a branch from the testing branch
* make your changes then push to your branch
* when you are done writing tests, merge your branch into the testing branch
