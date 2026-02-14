/*
Nathan and Shahzad

check for compilation errors using:
g++ -c test_constructor.cpp
*/

#include "../matrix.h"
#include <catch2/catch_test_macros.hpp>
#include <stdexcept>

TEST_CASE("standard cases"){

    // 2x3 Matrix
    int rows = 2;
    int cols = 3;
    float mat[] = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f};
    Matrix myMatrix(rows, cols, mat);
    myMatrix.display();
    REQUIRE(myMatrix.get_n_rows() == rows);
    REQUIRE(myMatrix.get_n_cols() == cols);

    float vals[] = {1.0f, 2.0f, 3.0f};
    
    // 1x1 Matrix
    Matrix m1(1, 1, vals);
    REQUIRE(m1.get_n_rows() == 1);
    REQUIRE(m1.get_n_cols() == 1);

    // 1x3 Row Vector
    Matrix m2(1, 3, vals);
    REQUIRE(m2.get_n_rows() == 1);
    REQUIRE(m2.get_n_cols() == 3);

    // 3x1 Column Vector 
    Matrix m3(3, 1, vals);
    REQUIRE(m3.get_n_rows() == 3);
    REQUIRE(m3.get_n_cols() == 1);
}   

TEST_CASE("Input Rows/Columns Argument Errors"){
    float vals[] = {1.0f, 2.0f, 3.0f, 4.0f};

    // input for 0 rows/columns is an invalid argument
    REQUIRE_THROWS_AS(Matrix(0, 2, vals), std::invalid_argument); 
    REQUIRE_THROWS_AS(Matrix(2, 0, vals), std::invalid_argument); 
    REQUIRE_THROWS_AS(Matrix(0, 0, vals), std::invalid_argument); 
    
    // input for negative rows/columns is an invalid argument
    REQUIRE_THROWS_AS(Matrix(2, -1, vals), std::invalid_argument); 
    REQUIRE_THROWS_AS(Matrix(-1, 2, vals), std::invalid_argument); 
    REQUIRE_THROWS_AS(Matrix(-1, -1, vals), std::invalid_argument); 
}
/*
TEST_CASE("Memory Issues"){
    float vals[] = {1.0f, 2.0f, 3.0f, 4.0f};
    
    REQUIRE_THROWS_AS(Matrix(100000, 100000, vals), std::invalid_argument);
    REQUIRE_THROWS_AS(Matrix(2, 2, nullptr), std::invalid_argument);  
}
*/
TEST_CASE("Value Retrieval"){
    float vals[] = {1.0f, 2.0f, 3.0f, 4.0f};
    Matrix m(2, 2, vals);

    REQUIRE(m(0, 0) == 1.0f);
    REQUIRE(m(1, 1) == 4.0f);

    // Changing vals after matrix creation should not affect the matrix data
    vals[0] = 99.0f;
    REQUIRE(m(0, 0) == 1.0f);

}

TEST_CASE("Value Retrieval Bounds"){
    float vals[] = {1.0f, 2.0f, 3.0f, 4.0f};
    Matrix m(2, 2, vals);

    // negative indices are invalid arguments
    REQUIRE_THROWS_AS(m(-1, 0), std::invalid_argument);
    REQUIRE_THROWS_AS(m(0, -1), std::invalid_argument);
    REQUIRE_THROWS_AS(m(-1, -1), std::invalid_argument);

    // out of bounds indices are invalid arguments
    REQUIRE_THROWS_AS(m(0, 2), std::invalid_argument);
    REQUIRE_THROWS_AS(m(2, 0), std::invalid_argument);
    REQUIRE_THROWS_AS(m(0, 2), std::invalid_argument);
    REQUIRE_THROWS_AS(m(2, 2), std::invalid_argument);

}

TEST_CASE("Value Assignment"){
    float vals[] = {1.0f, 2.0f, 3.0f, 4.0f};
    Matrix m(2, 2, vals);

    // reassign matrix values
    m(0,0) = 5.0f;
    m(0,1) = 6.0f;
    m(1,0) = 7.0f;
    m(1,1) = 8.0f;

    // test regular usage
    REQUIRE(m(0, 0) == 5.0f);
    REQUIRE(m(0, 1) == 6.0f);
    REQUIRE(m(1, 0) == 7.0f);
    REQUIRE(m(1, 1) == 8.0f);
}

TEST_CASE("Value Assignment Bounds") {

    float vals[] = {1.0f, 2.0f, 3.0f, 4.0f};
    Matrix m(2, 2, vals);

    // Accessing out of bounds is an invalid argument
    REQUIRE_THROWS_AS(m(0,2)=1.0f, std::invalid_argument);
    REQUIRE_THROWS_AS(m(2,0)=1.0f, std::invalid_argument);
    REQUIRE_THROWS_AS(m(2,2)=1.0f, std::invalid_argument);

    // negative indices are invalid arguments
    REQUIRE_THROWS_AS(m(-1, 0)=1.0f, std::invalid_argument);
    REQUIRE_THROWS_AS(m(0, -1)=1.0f, std::invalid_argument);
    REQUIRE_THROWS_AS(m(-1, -1)=1.0f, std::invalid_argument);
}

TEST_CASE("Copy Assignment Operator") {
    float vals1[] = {1.0f, 2.0f, 3.0f, 4.0f};
    Matrix m1(2, 2, vals1);

    float vals2[] = {5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f};
    Matrix m2(2, 3, vals2);

    m2 = m1; // Use copy assignment

    // Check dimensions
    REQUIRE(m2.get_n_rows() == 2);
    REQUIRE(m2.get_n_cols() == 2);

    // Check values
    REQUIRE(m2(0, 0) == 1.0f);
    REQUIRE(m2(1, 1) == 4.0f);

    // Changing m1 should not affect m2
    m1(0, 0) = 99.0f;
    REQUIRE(m2(0, 0) == 1.0f); // m2 should not be affected

    // Test self-assignment
    m1 = m1;
    REQUIRE(m1.get_n_rows() == 2);
    REQUIRE(m1.get_n_cols() == 2);
    REQUIRE(m1(0, 0) == 99.0f);
}