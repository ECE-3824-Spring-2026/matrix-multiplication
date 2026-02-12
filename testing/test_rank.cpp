// jass gatewood
/*
 * test_rank.cpp serves as a testing file implemented using catch to check the rank function.
 *
 * test categories:
 *
 *  basic rank values
 *      zero matrix
 *      identity matrices
 *      full‑rank rectangular matrices
 *
 *  linear dependence
 *      repeated rows or columns
 *      rows or columns that are scalar multiples
 *
 *  larger matrices
 *      3x3 examples with known rank
 *
 *  row operation invariance
 *      row swaps do not change rank
 *      scaling a row does not change rank
 *      adding a multiple of one row to another does not change rank
 *
 */

#include <iostream>
#include <catch2/catch_test_macros.hpp>
#include <cmath>
#include "matrix.h"
using namespace std;


TEST_CASE("rank base cases") {

    SECTION("rank of zero matrix is zero") {
        // all-zero matrices have no independent rows or columns.
        float data[] = {0.0f, 0.0f,
                        0.0f, 0.0f};
        Matrix M(2, 2, data);
        REQUIRE(M.rank() == 0);
    }

    SECTION("rank of identity matrix is full") {
        // identity matrix has full rank because rows and columns are independent.
        float data[] = {1.0f, 0.0f,
                        0.0f, 1.0f};
        Matrix M(2, 2, data);
        REQUIRE(M.rank() == 2);
    }

    SECTION("rank of 2x3 full‑rank rectangular matrix") {
        // two independent rows,  rank = 2.
        float data[] = {1.0f, 2.0f, 3.0f,
                        4.0f, 5.0f, 6.0f};
        Matrix M(2, 3, data);
        REQUIRE(M.rank() == 2);
    }
}


TEST_CASE("rank: linear dependence") {

    SECTION("repeated rows reduce rank") {
        // row1 = row2,  only 2 independent rows.
        float data[] = {1.0f, 2.0f, 3.0f,
                        1.0f, 2.0f, 3.0f,
                        4.0f, 5.0f, 6.0f};
        Matrix M(3, 3, data);
        REQUIRE(M.rank() == 2);
    }

    SECTION("repeated columns reduce rank") {
        // col1 = col2, only 2 independent columns.
        float data[] = {1.0f, 1.0f, 2.0f,
                        3.0f, 3.0f, 4.0f,
                        5.0f, 5.0f, 6.0f};
        Matrix M(3, 3, data);
        REQUIRE(M.rank() == 2);
    }

    SECTION("one independent row") {
        // two rows identical + one zero row, rank = 1.
        float data[] = {1.0f, 2.0f, 3.0f,
                        1.0f, 2.0f, 3.0f,
                        0.0f, 0.0f, 0.0f};
        Matrix M(3, 3, data);
        REQUIRE(M.rank() == 1);
    }

    SECTION("two independent rows") {
        // two independent rows + one zero row, rank = 2.
        float data[] = {1.0f, 2.0f, 3.0f,
                        0.0f, 1.0f, 4.0f,
                        0.0f, 0.0f, 0.0f};
        Matrix M(3, 3, data);
        REQUIRE(M.rank() == 2);
    }
}


TEST_CASE("rank: larger examples") {

    SECTION("3x3 full rank") {
        // three independent rows, rank = 3.
        float data[] = {1.0f, 2.0f, 3.0f,
                        0.0f, 1.0f, 4.0f,
                        5.0f, 6.0f, 0.0f};
        Matrix M(3, 3, data);
        REQUIRE(M.rank() == 3);
    }

    SECTION("3x3 rank 2") {
        // row2 = 2*row1, one dependent row.
        float data[] = {1.0f, 2.0f, 3.0f,
                        2.0f, 4.0f, 6.0f,
                        1.0f, 1.0f, 1.0f};
        Matrix M(3, 3, data);
        REQUIRE(M.rank() == 2);
    }
}


TEST_CASE("rank: invariance under row operations") {

    SECTION("row swap does not change rank") {
        // swapping rows preserves linear independence.
        float Adata[] = {1.0f, 2.0f, 3.0f,
                         4.0f, 5.0f, 6.0f};

        float Bdata[] = {4.0f, 5.0f, 6.0f,
                         1.0f, 2.0f, 3.0f};

        Matrix A(2, 3, Adata);
        Matrix B(2, 3, Bdata);

        REQUIRE(A.rank() == B.rank());
    }

    SECTION("row scaling does not change rank") {
        // multiplying a row by a scalar does not affect independence.
        float Adata[] = {1.0f, 2.0f,
                         3.0f, 4.0f};

        float Bdata[] = {2.0f, 4.0f,
                         3.0f, 4.0f};

        Matrix A(2, 2, Adata);
        Matrix B(2, 2, Bdata);

        REQUIRE(A.rank() == B.rank());
    }

    SECTION("row addition does not change rank") {
        // adding a multiple of one row to another preserves rank.
        float Adata[] = {1.0f, 2.0f,
                         3.0f, 4.0f};

        float Bdata[] = {1.0f, 2.0f,
                         4.0f, 6.0f}; // row2 + row1

        Matrix A(2, 2, Adata);
        Matrix B(2, 2, Bdata);

        REQUIRE(A.rank() == B.rank());
    }
}


