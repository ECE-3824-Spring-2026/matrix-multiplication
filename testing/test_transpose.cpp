
// adil chariwala 

#include <catch2/catch_test_macros.hpp>
#include <cmath>
#include <stdexcept>
#include "../matrix.h"

TEST_CASE("0 based index, and matches doc"){
    // x = [[1,2,3],[4,5,6]]  (2x3)
    float vals[] = {1,2,3,4,5,6};
    Matrix x(2, 3, vals);

    REQUIRE(x(1,2) == 6.0f);
    REQUIRE(x(0,0) == 1.0f);
    REQUIRE(x(1,0) == 4.0f);
}
