// Jass Gatewood 
/*
 * test_determinant.cpp serves as a testing file implemented using catch to check the determinant function.
 * Test Cases:
 *  - Basic Determinant Values
 *      • 1×1 matrices
 *      • 2×2 and 3×3 matrices with known determinants
 *
 *  - Zero and Identity Matrices
 *      • det(0-matrix) = 0
 *      • det(I) = 1 for all sizes
 *
 *  - Row Operations
 *      • Row swap flips the sign of the determinant
 *      • Scaling a row scales the determinant
 *      • Adding a multiple of one row to another leaves det unchanged
 *
 *  - Triangular Matrices
 *      • Determinant equals the product of diagonal entries
 *
 *  - Linearity and Non-Linearity
 *      • det(kA) = k^n det(A)
 *      • det(A + B) ≠ det(A) + det(B)
 *
 *  - Singular vs. Non-Singular Matrices
 *      • Singular matrices have determinant 0
 *      • Non-singular matrices have non-zero determinant
 *
 *  - Miscellaneous Structural Tests
 *      • Determinant of matrices with repeated rows
 *      • Determinant of matrices with proportional rows
 *
 */


#include <iostream>
#include <catch2/catch_test_macros.hpp>
#include <cmath>
#include "matrix.h"
using namespace std;


//----------------------------------------------------------------------------
// 1. BASE CASES (1x1, 2x2, zero, negatives)

TEST_CASE("Determinant base cases") {

    SECTION("Determinant throws for non-square matrix") {
        // Determinant is undefined for non-square matrices.
        float data[] = {1.0f,2.0f,3.0f,4.0f,
                        5.0f,6.0f,7.0f,8.0f};
        Matrix M(2, 4, data);
        REQUIRE_THROWS(M.determinant());
    }

    SECTION("Determinant 1x1 base case") {
        // a 1x1 matrix's determinant is just its single entry.
        float data[] = {5.0f};
        Matrix M(1, 1, data);
        REQUIRE(M.determinant() == 5.0f);
    }

    SECTION("Determinant 2x2 base case") {
        // check formula det = ad - bc.
        float data[] = {1.0f, 2.0f,
                        3.0f, 4.0f};
        Matrix M(2, 2, data);
        // determinant = -2
        REQUIRE(fabs(M.determinant() + 2.0f) < 0.0001f);
    }

    SECTION("Determinant of zero matrix is zero") {
        // all zero matrix determinant is zero.
        float data[] = {0.0f, 0.0f,
                        0.0f, 0.0f};
        Matrix M(2, 2, data);
        REQUIRE(M.determinant() == 0.0f);
    }

    SECTION("Determinant with negative numbers") {
        // checking negative values.
        float data[] = {-3.0f, 2.0f,
                         5.0f, -1.0f};
        Matrix M(2, 2, data);
        // determinant = -7
        REQUIRE(fabs(M.determinant() + 7.0f) < 0.0001f);
    }

}


//----------------------------------------------------------------------------
// 2. IDENTITY & PERMUTATION MATRICES

TEST_CASE("Identity and permutation matrices") {

    SECTION("Determinant of identity matrix is 1") {
        // identity matrix always has determinant 1.
        float data[] = {1.0f, 0.0f,
                        0.0f, 1.0f};
        Matrix M(2, 2, data);
        REQUIRE(M.determinant() == 1.0f);
    }

    SECTION("Determinant of 3x3 identity matrix is 1") {
        // larger identity matrix also has determinant 1.
        float data[] = {1.0f, 0.0f, 0.0f,
                        0.0f, 1.0f, 0.0f,
                        0.0f, 0.0f, 1.0f};
        Matrix M(3, 3, data);
        REQUIRE(fabs(M.determinant() - 1.0f) < 0.0001f);
    }

    SECTION("Determinant of 2x2 reverse identity matrix is -1") {
        // reverse identity, determinant flips sign.
        float data[] = {0.0f, 1.0f,
                        1.0f, 0.0f};
        Matrix M(2, 2, data);
        REQUIRE(M.determinant() == -1.0f);
    }

    SECTION("Determinant of 3x3 reverse identity matrix is -1") {
        // reverse identity, determinant = -1.
        float data[] = {0.0f, 0.0f, 1.0f,
                        0.0f, 1.0f, 0.0f,
                        1.0f, 0.0f, 0.0f};
        Matrix M(3, 3, data);
        REQUIRE(fabs(M.determinant() + 1.0f) < 0.0001f);
    }
}


//----------------------------------------------------------------------------
// 3. SINGULAR MATRICES (det = 0)

TEST_CASE("Singular matrices (det = 0)") {

    SECTION("Determinant with two identical rows is zero") {
        // identical rows, linear dependence, determinant = 0.
        float data[] = {1.0f, 2.0f, 3.0f,
                        1.0f, 2.0f, 3.0f,
                        4.0f, 5.0f, 6.0f};
        Matrix M(3, 3, data);
        REQUIRE(M.determinant() == 0.0f);
    }

    SECTION("Determinant with two identical columns is zero") {
        // identical columns, determinant = 0.
        float data[] = {1.0f, 1.0f, 2.0f,
                        3.0f, 3.0f, 4.0f,
                        5.0f, 5.0f, 6.0f};
        Matrix M(3, 3, data);
        REQUIRE(M.determinant() == 0.0f);
    }

    SECTION("Determinant with a zero row is zero") {
        // zero row.
        float data[] = {1.0f, 2.0f, 3.0f,
                        0.0f, 0.0f, 0.0f,
                        4.0f, 5.0f, 6.0f};
        Matrix M(3, 3, data);
        REQUIRE(M.determinant() == 0.0f);
    }

    SECTION("Determinant with a zero column is zero") {
        // zero column.
        float data[] = {0.0f, 1.0f, 2.0f,
                        0.0f, 3.0f, 4.0f,
                        0.0f, 5.0f, 6.0f};
        Matrix M(3, 3, data);
        REQUIRE(M.determinant() == 0.0f);
    }

    SECTION("Determinant when one row is a multiple of another is zero") {
        // row 2 = 2 * row 1, determinant = zero.
        float data[] = {1.0f, 2.0f, 3.0f,
                        2.0f, 4.0f, 6.0f,
                        4.0f, 5.0f, 6.0f};
        Matrix M(3, 3, data);
        REQUIRE(M.determinant() == 0.0f);
    }

    SECTION("Determinant when one column is a multiple of another is zero") {
        // col 2 = 2 * col 1, determinant = 0.
        float data[] = {1.0f, 2.0f, 4.0f,
                        3.0f, 6.0f, 5.0f,
                        7.0f,14.0f, 9.0f};
        Matrix M(3, 3, data);
        REQUIRE(M.determinant() == 0.0f);
    }

    SECTION("Determinant of 4x4 all-ones matrix is zero") {
        // all rows identical, determinant = 0.
        float data[] = {1.0f,1.0f,1.0f,1.0f,
                        1.0f,1.0f,1.0f,1.0f,
                        1.0f,1.0f,1.0f,1.0f,
                        1.0f,1.0f,1.0f,1.0f};
        Matrix M(4, 4, data);
        REQUIRE(M.determinant() == 0.0f);
    }

    SECTION("Determinant of 4x4 all-negative matrix is zero") {
        // same idea as all-ones, just negative.
        float data[] = {-1.0f,-1.0f,-1.0f,-1.0f,
                        -1.0f,-1.0f,-1.0f,-1.0f,
                        -1.0f,-1.0f,-1.0f,-1.0f,
                        -1.0f,-1.0f,-1.0f,-1.0f};
        Matrix M(4, 4, data);
        REQUIRE(M.determinant() == 0.0f);
    }

}


//----------------------------------------------------------------------------
// 4. TRIANGULAR & BLOCK STRUCTURE

TEST_CASE("Triangular and block structure") {

    SECTION("Determinant of upper triangular matrix equals product of diagonal") {
        // upper triangular, determinant = product of diagonal entries.
        float data[] = {2.0f,5.0f,7.0f,
                        0.0f,3.0f,1.0f,
                        0.0f,0.0f,4.0f};
        Matrix M(3, 3, data);
        // determinant = 24
        REQUIRE(fabs(M.determinant() - 24.0f) < 0.0001f);
    }

    SECTION("Determinant of lower triangular matrix equals product of diagonal") {
        // lower triangular works the same way.
        float data[] = {2.0f,0.0f,0.0f,
                       -1.0f,3.0f,0.0f,
                        4.0f,2.0f,-5.0f};
        Matrix M(3, 3, data);
        REQUIRE(M.determinant() == -30.0f);
    }
}


//----------------------------------------------------------------------------
// 5. EXPANSION-FRIENDLY MATRICES

TEST_CASE("Expansion-friendly matrices") {

    SECTION("Determinant expansion along a row with many zeros") {
        // co-factor expansion.
        float data[] = {0.0f,0.0f,5.0f,
                        1.0f,2.0f,3.0f,
                        4.0f,5.0f,6.0f};
        Matrix M(3, 3, data);
        REQUIRE(M.determinant() == -15.0f);
    }

    SECTION("Determinant expansion along a column with many zeros") {
        // middle column is all zeros in a column
        float data[] = {7.0f,0.0f,1.0f,
                        8.0f,0.0f,2.0f,
                        9.0f,0.0f,3.0f};
        Matrix M(3, 3, data);
        REQUIRE(M.determinant() == 0.0f);
    }
}


//----------------------------------------------------------------------------
// 6. FLOAT & PRECISION TESTS

TEST_CASE("Float and precision tests") {

    SECTION("Determinant very small but not zero") {
        // tests floating‑point precision on tiny determinants.
        float data[] = {1.0f,1.0f,
                        1.0f,1.0001f};
        Matrix M(2, 2, data);
        REQUIRE(fabs(M.determinant() - 0.0001f) < 0.000001f);
    }

    SECTION("Determinant of mixed positive/negative floats") {
        // ensures mixed-sign floats compute correctly.
        float data[] = {1.5f,-2.0f,
                        3.0f, 0.5f};
        Matrix M(2, 2, data);
        REQUIRE(fabs(M.determinant() - 6.75f) < 0.0001f);
    }
}


//----------------------------------------------------------------------------
// 7. ROW/COLUMN OPERATIONS

TEST_CASE("Row and column operations") {

    SECTION("Determinant flips sign when swapping rows") {
        // Swapping rows should reverse the sign.
        float Adata[] = {1.0f,2.0f,
                         3.0f,4.0f};
        float Bdata[] = {3.0f,4.0f,
                         1.0f,2.0f};
        Matrix A(2, 2, Adata);
        Matrix B(2, 2, Bdata);
        REQUIRE(A.determinant() == -2.0f);
        REQUIRE(B.determinant() ==  2.0f);
    }

    SECTION("Determinant flips sign when swapping columns") {
        // same rule applies to column swaps.
        float Adata[] = {1.0f,2.0f,
                         3.0f,4.0f};
        float Cdata[] = {2.0f,1.0f,
                         4.0f,3.0f};
        Matrix A(2, 2, Adata);
        Matrix C(2, 2, Cdata);
        REQUIRE(A.determinant() == -2.0f);
        REQUIRE(C.determinant() ==  2.0f);
    }

    SECTION("Determinant scales when a row is multiplied by a scalar") {
        // row 2 in B is 3× row 2 in A, determinant scales by 3.
        float dataA[] = {1.0f,2.0f,1.0f,
                         0.0f,1.0f,4.0f,
                         5.0f,6.0f,0.0f};

        float dataB[] = {1.0f,2.0f,1.0f,
                         0.0f,3.0f,12.0f,
                         5.0f,6.0f,0.0f};

        Matrix A(3, 3, dataA);
        Matrix B(3, 3, dataB);

        REQUIRE(fabs(A.determinant() - 1.0f) < 0.0001f);
        REQUIRE(fabs(B.determinant() - 3.0f) < 0.0001f);
    }

    SECTION("Determinant unchanged when adding a multiple of one row to another") {
        // row 3 in B = row 3 in A + 2*Row1, determinant unchanged.
        float dataA[] = {1.0f,2.0f,1.0f,
                         0.0f,1.0f,4.0f,
                         5.0f,6.0f,0.0f};

        float dataB[] = {1.0f,2.0f,1.0f,
                         0.0f,1.0f,4.0f,
                         7.0f,10.0f,2.0f};

        Matrix A(3, 3, dataA);
        Matrix B(3, 3, dataB);

        REQUIRE(fabs(A.determinant() - 1.0f) < 0.0001f);
        REQUIRE(fabs(B.determinant() - 1.0f) < 0.0001f);
    }
}


//----------------------------------------------------------------------------
// 8. ALGEBRAIC DETERMINANT PROPERTIES

TEST_CASE("Algebraic determinant properties") {

    SECTION("Determinant of transpose equals determinant of original") {
        // det(A) should equal det(Aᵀ).
        float dataA[] = {1.0f,2.0f,3.0f,
                         0.0f,1.0f,4.0f,
                         5.0f,6.0f,0.0f};

        float dataAT[] = {1.0f,0.0f,5.0f,
                          2.0f,1.0f,6.0f,
                          3.0f,4.0f,0.0f};

        Matrix A(3, 3, dataA);
        Matrix AT(3, 3, dataAT);

        REQUIRE(fabs(A.determinant() - AT.determinant()) < 0.0001f);
    }

    SECTION("Determinant of product equals product of determinants") {
        // det(AB) = det(A) * det(B).
        float dataA[] = {1.0f,2.0f,
                         3.0f,4.0f};

        float dataB[] = {2.0f,0.0f,
                         1.0f,2.0f};

        Matrix A(2, 2, dataA);
        Matrix B(2, 2, dataB);
        Matrix AB = A * B;

        REQUIRE(fabs(AB.determinant() - (A.determinant() * B.determinant())) < 0.0001f);
    }

    SECTION("Determinant of inverse equals reciprocal of determinant") {
        // det(A^-1) = 1 / det(A).
        float dataA[] = {1.0f,  2.0f,
                         3.0f,  4.0f};

        float dataAinv[] = {-2.0f,  1.0f,
                             1.5f, -0.5f};

        Matrix A(2, 2, dataA);
        Matrix Ainv(2, 2, dataAinv);

        REQUIRE(fabs(Ainv.determinant() - (1.0f / A.determinant())) < 0.0001f);
    }

    SECTION("Determinant of sum is not sum of determinants") {
        // det(A + B ) does not equal sum det(A) + det(B)
        float dataA[] = {1,0,
                         0,1};

        float dataB[] = {1,0,
                         0,1};

        Matrix A(2, 2, dataA);
        Matrix B(2, 2, dataB);
        Matrix C = A + B;

        REQUIRE(C.determinant() != A.determinant() + B.determinant());
    }
}
