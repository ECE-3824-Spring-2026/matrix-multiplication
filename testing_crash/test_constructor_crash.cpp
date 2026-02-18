/*
Nathan and Shahzad

check for compilation errors using:
g++ -c test_constructor.cpp
*/

#include "../matrix.h"
#include <catch2/catch_test_macros.hpp>
#include <stdexcept>

TEST_CASE("Memory Issues"){
    float vals[] = {1.0f, 2.0f, 3.0f, 4.0f};
    
    try {
        Matrix(100000, 100000, vals);
    } catch (...) {}

    try {
        Matrix(2, 2, nullptr);
    } catch (...) {}

    SUCCEED();
}