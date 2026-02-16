// Timilehin olofinyolemi 
// Matrix operator*( const Matrix& ) const;

#define CATCH_CONFIG_MAIN 
// #include "catch.hpp"
#include <catch2/catch_test_macros.hpp>
#include "../matrix.h"

TEST_CASE("Matrix multiplication - basic 2x2") {
    float v1[] = {1, 2, 3, 4};
    float v2[] = {5, 6, 7, 8};
    float expected[] = {19, 22, 43, 50};
    
    Matrix A(2, 2, v1);
    Matrix B(2, 2, v2);
    Matrix C = A * B;
    Matrix Expected(2, 2, expected);
    
    REQUIRE(C == Expected);
}

TEST_CASE("Matrix multiplication - 2x3 times 3x2") {
    float v1[] = {1, 2, 3, 4, 5, 6};
    float v2[] = {7, 8, 9, 10, 11, 12};
    float expected[] = {58, 64, 139, 154};
    
    Matrix A(2, 3, v1);
    Matrix B(3, 2, v2);
    Matrix C = A * B;
    Matrix Expected(2, 2, expected);
    
    REQUIRE(C == Expected);
}

TEST_CASE("Matrix multiplication - identity matrix") {
    float v1[] = {1, 2, 3, 4};
    float identity[] = {1, 0, 0, 1};
    
    Matrix A(2, 2, v1);
    Matrix I(2, 2, identity);
    Matrix C = A * I;
    
    REQUIRE(C == A);
}

TEST_CASE("Matrix multiplication - incompatible dimensions") {
    float v1[] = {1, 2, 3, 4};
    float v2[] = {1, 2, 3, 4, 5, 6};
    
    Matrix A(2, 2, v1);
    Matrix B(3, 2, v2);
    
    REQUIRE_THROWS_AS(A * B, std::invalid_argument);
}