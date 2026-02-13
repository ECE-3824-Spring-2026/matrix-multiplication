//Mariya Denny
//Matrix operator/( const float& )  const;


#include <catch2/catch_test_macros.hpp>
#include "../matrix.h"
#include <stdexcept>

TEST_CASE("Scalar division with basic positive number"){
    //array of 4 elements to fill the matrix
    float vals[] = {2, 4, 6, 8};
    // we need a matrix to test division on and this creates 2by2 matrix
    Matrix A(2, 2, vals);
    
    //here we are testing if scalar division works and storing the new result in matrixB
    //this calls the operator/ and divides each element in A by 2
    Matrix B = A / 2.0f;
    
    //this checks if each element is approx equal to the quotient
    REQUIRE(B(0,0) == (1.0f));// 2/2=1
    REQUIRE(B(0,1) == (2.0f));// 4/2=2
    REQUIRE(B(1,0) == (3.0f));// 6/2=3
    REQUIRE(B(1,1) == (4.0f));// 8/2=4
}

TEST_CASE("Scalar division with negative number"){
    //array of 4 elements to fill the matrix
    float vals[] = {2, -4, 6, -8};
    // we need a matrix to test division on and this creates 2by2 matrix
    Matrix A(2, 2, vals);
    
    //here we are testing if scalar division works and storing the new result in matrixB
    //this calls the operator/ and divides each element in A by -2
    Matrix B = A / -2.0f;
    
    //this checks if each element is approx equal to the quotient
    REQUIRE(B(0,0) == (-1.0f));// 2/-2=-1
    REQUIRE(B(0,1) == (2.0f));// -4/-2=2
    REQUIRE(B(1,0) == (-3.0f));// 6/-2=-3
    REQUIRE(B(1,1) == (4.0f));// -8/-2=4
}

TEST_CASE("Scalar division by zero throws domain_error"){
    //array of 4 elements to fill the matrix
    float vals[] = {1, 2, 3, 4};
    Matrix A(2, 2, vals);
    // requires domain_error on divide by zero
    REQUIRE_THROWS_AS(A / 0.0f, std::domain_error);
}

TEST_CASE("Scalar division by Decimal number"){
    //array of 4 elements to fill the matrix
    float vals[] = {1, 2, 3, 4};
    Matrix A(2, 2, vals);
    
    // Matrix B would store the result of each element of matrix A divided by 0.5
    Matrix B = A / 0.5f;

    REQUIRE(B(0,0) == (2.0f));// 1/0.5=2
    REQUIRE(B(0,1) == (4.0f));// 2/0.5=4
    REQUIRE(B(1,0) == (6.0f));// 3/0.5=6
    REQUIRE(B(1,1) == (8.0f));// 4/0.5=8
}

TEST_CASE("Scalar division with negative decimal") {
    float vals[] = {1, -2, 3, -4};
    Matrix A(2,2,vals);
    Matrix B = A / -0.5f; // divide by -0.5 = multiply by -2
    REQUIRE(B(0,0) == (-2.0f));
    REQUIRE(B(0,1) == (4.0f));
    REQUIRE(B(1,0) == (-6.0f));
    REQUIRE(B(1,1) == (8.0f));
}

TEST_CASE("Scalar division Does not modify original matrix"){
    //array of 4 elements to fill the matrix
    float vals[] = {3, 6, 9, 12};
    Matrix A(2, 2, vals);
    
    // Matrix B would store the result of each element of matrix A divided by 3.0
    Matrix B = A / 3.0f;

    REQUIRE(A(0,0) == (3.0f));// confirms A(0,0)=3
    REQUIRE(A(0,1) == (6.0f));// confirms A(0,1)=6
    REQUIRE(A(1,0) == (9.0f));// confirms A(1,0)=9
    REQUIRE(A(1,1) == (12.0f));// confirms A(1,1)=12
}