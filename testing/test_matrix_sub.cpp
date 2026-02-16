
// adil chariwala

#include <catch2/catch_test_macros.hpp>
#include <stdexcept>
#include "../matrix.h"

TEST_CASE("normal subtraction operation") {
    float a_vals[] = {1,2,3,4,5,6};
    float b_vals[] = {6,5,4,3,2,1};

    Matrix A(2, 3, a_vals);
    Matrix B(2, 3, b_vals);

    Matrix C = A - B;

    REQUIRE(C.get_n_rows() == 2);
    REQUIRE(C.get_n_cols() == 3);

    REQUIRE(C(0,0) == -5.0f);
    REQUIRE(C(0,1) == -3.0f);
    REQUIRE(C(0,2) == -1.0f);

    REQUIRE(C(1,0) ==  1.0f);
    REQUIRE(C(1,1) ==  3.0f);
    REQUIRE(C(1,2) ==  5.0f);
}

TEST_CASE("sub from iteself = 0 ") {
    float vals[] = {-1.5f, 0.0f, 7.25f,
                     3.0f, 9.0f, -4.0f};

    Matrix A(2, 3, vals);
    Matrix Z = A - A;

    for(int i = 0; i < A.get_n_rows(); i++){
        for(int j = 0; j < A.get_n_cols(); j++){
            REQUIRE(Z(i,j) == 0.0f);
        }
    }
}

TEST_CASE("checks matrices for compatability") {
    float a_vals[] = {1,2,3,4,5,6};
    float b_vals[] = {1,2,3,4};

    Matrix A(2, 3, a_vals);
    Matrix B(2, 2, b_vals);

    // REQUIRE_THROWS_AS(A - B, std::logic_error);
    REQUIRE_THROWS_AS(A - B, std::invalid_argument);
}
