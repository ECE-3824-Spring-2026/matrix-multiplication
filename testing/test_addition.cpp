// Timilehin olofinyolemi 
// Matrix operator+( const Matrix& ) const;

#define CATCH_CONFIG_MAIN 
#include "catch.hpp"
#include "../matrix.h"

TEST_CASE("Matrix addition - basic 2x2") {
    float v1[] = {1, 2, 3, 4};
    float v2[] = {5, 6, 7, 8};
    float expected[] = {6, 8, 10, 12};
    
    Matrix A(2, 2, v1);
    Matrix B(2, 2, v2);
    Matrix C = A + B;
    Matrix Expected(2, 2, expected);
    
    REQUIRE(C == Expected);
}

TEST_CASE("Matrix addition - different dimensions 2x3") {
    float v1[] = {1, 2, 3, 4, 5, 6};
    float v2[] = {2, 3, 4, 5, 6, 7};
    float expected[] = {3, 5, 7, 9, 11, 13};
    
    Matrix A(2, 3, v1);
    Matrix B(2, 3, v2);
    Matrix C = A + B;
    Matrix Expected(2, 3, expected);
    
    REQUIRE(C == Expected);
}

TEST_CASE("Matrix addition - with negative numbers") {
    float v1[] = {-1, 2, -3, 4};
    float v2[] = {1, -2, 3, -4};
    float expected[] = {0, 0, 0, 0};
    
    Matrix A(2, 2, v1);
    Matrix B(2, 2, v2);
    Matrix C = A + B;
    Matrix Expected(2, 2, expected);
    
    REQUIRE(C == Expected);
}

TEST_CASE("Matrix addition - incompatible dimensions throws error") {
    float v1[] = {1, 2, 3, 4};
    float v2[] = {1, 2, 3, 4, 5, 6};
    
    Matrix A(2, 2, v1);
    Matrix B(2, 3, v2);
    
    REQUIRE_THROWS_AS(A + B, std::invalid_argument);
}