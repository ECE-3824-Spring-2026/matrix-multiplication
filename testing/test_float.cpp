//Mariya Denny
//Matrix operator*( const float& )  const;

#include <catch2/catch_test_macros.hpp>
#include "../matrix.h"
#include <stdexcept>

//Defines the first test case
//also, each testcases run separately.
TEST_CASE("Scalar multiplication - basic positive"){
//array of 4 elements to fill the matrix
float vals[] = {1, 2, 3, 4};
// we need a matrix to test multiplication on and this creates 2by2 matrix
Matrix A(2, 2, vals);

//here we are testing if scalar multiplication works and storing the new result in matrixB
//this calls the operator* and multiplies each element in A by 2
Matrix B = A * 2.0f;
REQUIRE(B(0,0) == Approx(2.0f)); 
REQUIRE(B(0,1) == Approx(4.0f)); 
REQUIRE(B(1,0) == Approx(6.0f)); 
REQUIRE(B(1,1) == Approx(8.0f));
}