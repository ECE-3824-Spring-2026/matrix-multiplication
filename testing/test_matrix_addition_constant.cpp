// Mohamad Charabi
// Testing Matrix + Constant

#include <catch2/catch_test_macros.hpp>
#include "../matrix.h"

TEST_CASE("Matrix + constant - basic 2x2") {
    float v[] = {1, 2, 3, 4};
    float expected[] = {6, 7, 8, 9};

    Matrix A(2, 2, v);
    Matrix C = A + 5.0f;

    Matrix Expected(2, 2, expected);

    REQUIRE(C == Expected);
}

TEST_CASE("Matrix + constant - zero constant") {
    float v[] = {1, 2, 3, 4};

    Matrix A(2, 2, v);
    Matrix C = A + 0.0f;

    REQUIRE(C == A);   // should not change
}

TEST_CASE("Matrix + constant - negative constant") {
    float v[] = {5, 6, 7, 8};
    float expected[] = {0, 1, 2, 3};

    Matrix A(2, 2, v);
    Matrix C = A + (-5.0f);

    Matrix Expected(2, 2, expected);

    REQUIRE(C == Expected);
}

TEST_CASE("Matrix + constant - does not modify original") {
    float v[] = {1, 2, 3, 4};
    float original[] = {1, 2, 3, 4};

    Matrix A(2, 2, v);
    Matrix B = A + 5.0f;

    Matrix Original(2, 2, original);

    REQUIRE(A == Original);  // A should stay unchanged
}

TEST_CASE("Matrix + constant - larger matrix 3x3") {
    float v[] = {1,2,3,4,5,6,7,8,9};
    float expected[] = {2,3,4,5,6,7,8,9,10};

    Matrix A(3,3,v);
    Matrix C = A + 1.0f;

    Matrix Expected(3,3,expected);

    REQUIRE(C == Expected);
}