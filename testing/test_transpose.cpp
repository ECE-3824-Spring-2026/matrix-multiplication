

// adil chariwala 

#include <catch2/catch_test_macros.hpp>
#include <stdexcept>
#include "../matrix.h"

TEST_CASE("0 based index, and matches doc format"){
    // x = [[1,2,3],[4,5,6]]  (2x3)
    float vals[] = {1,2,3,4,5,6};
    Matrix x(2, 3, vals);

    REQUIRE(x(1,2) == 6.0f);
    REQUIRE(x(0,0) == 1.0f);
    REQUIRE(x(1,0) == 4.0f);
}

TEST_CASE("ensure transpose dimensions change accordingly") {
    float vals[] = {1,2,3,4,5,6};
    Matrix x(2, 3, vals);
    Matrix y = x.transpose();

    REQUIRE(y.get_n_rows() == 3);
    REQUIRE(y.get_n_cols() == 2);
}

TEST_CASE("ensure elements mapped correctly") {
    float vals[] = {1,2,3,4,5,6};
    Matrix x(2, 3, vals);
    Matrix y = x.transpose();

    REQUIRE(y(0,0) == 1.0f);
    REQUIRE(y(1,0) == 2.0f);
    REQUIRE(y(2,0) == 3.0f);
    REQUIRE(y(0,1) == 4.0f);
    REQUIRE(y(1,1) == 5.0f);
    REQUIRE(y(2,1) == 6.0f);

}

TEST_CASE("transpose twice returns orginal matrix"){
    float v[] = { -1.5f, 0.0f,  7.25f,
                   3.0f, 9.0f, -4.0f };
    Matrix x(2, 3, v);

    Matrix xt = x.transpose();
    Matrix x2 = xt.transpose();

    REQUIRE(x2.get_n_rows() == x.get_n_rows());
    REQUIRE(x2.get_n_cols() == x.get_n_cols());

    for(int i = 0; i < x.get_n_rows(); i++){
        for(int j = 0; j < x.get_n_cols(); j++){
            REQUIRE(x2(i,j) == x(i,j));
        }
    }
}

