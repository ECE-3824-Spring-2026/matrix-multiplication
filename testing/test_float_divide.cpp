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
    REQUIRE(B(0,0) == Approx(1.0f));// 2/2=1
    REQUIRE(B(0,1) == Approx(2.0f));// 4/2=2
    REQUIRE(B(1,0) == Approx(3.0f));// 6/2=3
    REQUIRE(B(1,1) == Approx(4.0f));// 8/2=4
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
    REQUIRE(B(0,0) == Approx(-1.0f));// 2/-2=-1
    REQUIRE(B(0,1) == Approx(2.0f));// -4/-2=2
    REQUIRE(B(1,0) == Approx(-3.0f));// 6/-2=-3
    REQUIRE(B(1,1) == Approx(4.0f));// -8/-2=4
}

TEST_CASE("Scalar division by zero throws domain_error"){
    //array of 4 elements to fill the matrix
    float vals[] = {1, 2, 3, 4};
    Matrix A(2, 2, vals);
    // requires domain_error on divide by zero
    REQUIRE_THROWS_AS(A / 0.0f, std::domain_error);
}