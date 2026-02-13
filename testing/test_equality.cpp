/*
Nathan 

check for compilation errors using:
g++ -c test_equality.cpp
*/

#include "../matrix.h"
#include <catch2/catch_test_macros.hpp>
#include <stdexcept>

TEST_CASE("standard case (true)") {
    float vals[] = {1.0f, 2.0f, 3.0f, 4.0f};
    Matrix A(2, 2, vals);
    Matrix B(2, 2, vals);

    REQUIRE(A == B); 
}

TEST_CASE("standard case (false)") {
    float vals1[] = {1.0f, 2.0f, 3.0f, 4.0f};
    float vals2[] = {1.0f, 2.0f, 3.0f, 5.0f}; // Different last element

    Matrix A(2, 2, vals1);
    Matrix B(2, 2, vals2);

    REQUIRE_FALSE(A == B);
}

TEST_CASE("unequal dimensions") {
    float vals[] = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f};
    
    Matrix A(2, 3, vals); // 2x3
    Matrix B(3, 2, vals); // 3x2

    REQUIRE_FALSE(A == B);
}

TEST_CASE("self equality") {
    float vals[] = {1.0f, 2.0f, 3.0f, 4.0f};
    Matrix A(2, 2, vals);

    REQUIRE(A == A);
}

TEST_CASE("1x1 matrices") {
    float v1[] = {10.0f};
    float v2[] = {10.0f};
    float v3[] = {20.0f};

    Matrix A(1, 1, v1);
    Matrix B(1, 1, v2);
    Matrix C(1, 1, v3);

    REQUIRE(A == B);
    REQUIRE_FALSE(A == C);
}

TEST_CASE("zero matrices") {
    float v1[] = {0.0f, 0.0f, 0.0f, 0.0f};
    float v2[] = {0.0f, 0.0f, 0.0f, 0.0f};

    Matrix A(2, 2, v1);
    Matrix B(2, 2, v2);

    REQUIRE(A == B);
}
