//Mariya Denny
//Matrix operator*( const float& )  const;

#include <catch2/catch_test_macros.hpp>
#include "../matrix.h"
#include <stdexcept>

//Defines the first test case
//also, each testcases run separately.
TEST_CASE("Scalar multiplication with basic positive number"){
    //array of 4 elements to fill the matrix
    float vals[] = {1, 2, 3, 4};
    // we need a matrix to test multiplication on and this creates 2by2 matrix
    Matrix A(2, 2, vals);
    
    //here we are testing if scalar multiplication works and storing the new result in matrixB
    //this calls the operator* and multiplies each element in A by 2
    Matrix B = A * 2.0f;
    
    //this checks if each element is approx equal to the product
    REQUIRE(B(0,0) == Approx(2.0f)); 
    REQUIRE(B(0,1) == Approx(4.0f)); 
    REQUIRE(B(1,0) == Approx(6.0f)); 
    REQUIRE(B(1,1) == Approx(8.0f));
}

TEST_CASE("Scalar multiplication with zero"){
    float vals[] ={5,-3,2,7};
    Matrix A(2,2,vals);
    
    //The new matrix B will have the result of the product of the element in A matrix by zero
    Matrix B = A * 0.0f; 
    //the following lines checks if each element is approx equal to the product of element and zero
    REQUIRE(B(0,0) == Approx(0.0f)); //5*0=0
    REQUIRE(B(0,1) == Approx(0.0f)); //-3*0=0
    REQUIRE(B(1,0) == Approx(0.0f)); //2*0=0
    REQUIRE(B(1,1) == Approx(0.0f));//7*0=0

}

TEST_CASE("Scalar Multiplication  with a negative number"){
    float vals[]={1,-2,3,-4};
    Matrix A(2,2,vals);
    //this new matrix will be the product of elements in A matrix with a negative number
    Matrix B = A * -3.0f;
    //the following lines checks if each element is approx equal to the product of element and the negative number
    REQUIRE(B(0,0) == Approx(-3.0f)); //1*-3=-3
    REQUIRE(B(0,1) == Approx(6.0f)); //-2*-3=6
    REQUIRE(B(1,0) == Approx(-9.0f)); //3*-3=-9
    REQUIRE(B(1,1) == Approx(12.0f));//-4*-3=12
}

TEST_CASE("Scalar Multiplication with decimal numbers"){
    float vals[]={2,4,6,8};
    Matrix A(2,2,vals);
    //this new matrix will be the product of elements in A matrix with a decimal number
    Matrix B = A * 0.5f;
    //the following lines checks if each element is approx equal to the product of element and the decimal number
    REQUIRE(B(0,0)== Approx(1.0f));//2*0.5=1
    REQUIRE(B(0,1)== Approx(2.0f));//4*0.5=2
    REQUIRE(B(1,0)== Approx(3.0f));//6*0.5=3
    REQUIRE(B(1,1)== Approx(4.0f));//8*0.5=4
}

TEST_CASE("Scalar multiplication with negative decimal") {
    float vals[] = {1, -2, 3, -4};
    Matrix A(2, 2, vals);

    Matrix B = A * -0.5f;   // multiply by negative decimal

    REQUIRE(B(0,0) == Approx(-0.5f));  // 1 * -0.5 = -0.5
    REQUIRE(B(0,1) == Approx(1.0f));   // -2 * -0.5 = 1
    REQUIRE(B(1,0) == Approx(-1.5f));  // 3 * -0.5 = -1.5
    REQUIRE(B(1,1) == Approx(2.0f));   // -4 * -0.5 = 2
}

TEST_CASE("Scalar multiplication does not modify original matrix"){
    float vals[]={1,2,3,4};
    Matrix A(2,2,vals);
    //this new matrix will be the product
    Matrix B = A * 5.0f;
    //the following lines checks whether the original matrix stays the same after multiplication
    REQUIRE(A(0,0)== Approx(1.0f));// confirms A(0,0) is still 1
    REQUIRE(A(0,1)== Approx(2.0f));//confirms that A(0,1) is still 2
    REQUIRE(A(1,0)== Approx(3.0f));//A(1,0) is still 3
    REQUIRE(A(1,1)== Approx(4.0f));//A(1,1) is still 4
}