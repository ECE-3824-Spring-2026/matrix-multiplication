/*
Nathan 

check for compilation errors using:
g++ -c test_subtraction_constant.cpp
*/

#include "../matrix.h"
#include <catch2/catch_test_macros.hpp>
#include <stdexcept>

TEST_CASE("standard case") {

    // 2x2
    float vals[] = {6.0f, 7.0f, 8.0f, 9.0f};
    float expected[] = {1.0f, 2.0f, 3.0f, 4.0f};

    Matrix A(2, 2, vals);
    Matrix C = A - 5.0f;

    Matrix ExpectedResult(2, 2, expected);

    REQUIRE(C == ExpectedResult);

    // 2x3
    float v[] = {2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f};
    float e[] = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f};

    Matrix A2(2, 3, v);
    Matrix B = A2 - 1.0f;

    Matrix Expected(2, 3, e);

    REQUIRE(B == Expected);
}

TEST_CASE("subtract by 0") {
    float vals[] = {1.0f, 2.0f, 3.0f, 4.0f};

    Matrix A(2, 2, vals);
    Matrix C = A - 0.0f;

    REQUIRE(C == A);   
}

TEST_CASE("double negative") {
    float vals[] = {0.0f, 1.0f, 2.0f, 3.0f};
    float expected[] = {5.0f, 6.0f, 7.0f, 8.0f};

    Matrix A(2, 2, vals);
    Matrix C = A - (-5.0f); // equivalent to A + 5.0f

    Matrix ExpectedResult(2, 2, expected);

    REQUIRE(C == ExpectedResult);
}

TEST_CASE("input matrix should not be modified") {
    float vals[] = {1.0f, 2.0f, 3.0f, 4.0f};
    Matrix A(2, 2, vals);

    // subtracting 5 from A should not modify A, 
    // but just return a new matrix with the result
    Matrix B = A - 5.0f;

    Matrix Original(2, 2, vals);
    REQUIRE(A == Original); 
}

TEST_CASE("negative numbered result") {
    float v[] = {1.0f, 2.0f, 3.0f, 4.0f};
    float expected[] = {-4.0f, -3.0f, -2.0f, -1.0f};

    Matrix A(2, 2, v);
    Matrix C = A - 5.0f;

    Matrix Expected(2, 2, expected);

    REQUIRE(C == Expected);
}

TEST_CASE("1x1 matrix") {
    float val[] = {10.0f};
    float expected[] = {7.0f};
    Matrix A(1, 1, val);
    Matrix B = A - 3.0f;
    Matrix C(1, 1, expected);

    REQUIRE(B == C);    
    REQUIRE(B(0, 0) == 7.0f);
}

TEST_CASE("sequential subtraction") {
    float vals[] = {10.0f, 20.0f, 30.0f, 40.0f};
    Matrix A(2, 2, vals);
    
    // (A - 5) - 2 = A - 7
    Matrix B = A - 5.0f - 2.0f;
    
    float expected[] = {3.0f, 13.0f, 23.0f, 33.0f};
    Matrix Expected(2, 2, expected);
    
    REQUIRE(B == Expected);
}