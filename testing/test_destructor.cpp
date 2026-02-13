// File: ~/matrix-multiplication/testing/test_destructor.cpp
// Shahzad, Nathan

#include "../matrix.h"

#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>

using namespace std;

TEST_CASE("seeing if the destructor actually works"){

  // 3x1 matrix
  float values[] = {1.0f, 2.0f, 3.0f};


  {
    Matrix m(2, 2, values);
    // You can optionally check constructor worked
    REQUIRE(m.get_n_rows() == 2);
    REQUIRE(m.get_n_cols() == 2);
    REQUIRE(m(0,0) == 1.0f);
  } // <-- m goes out of scope here, destructor is called automatically

  SUCCEED(); // if we get here, destructor did not crash

}


TEST_CASE("Run the code over and over again") {

  float values[] = {1.0f, 2.0f, 3.0f, 4.0f};


  for(int i = 0; i < 10000; i++){
    // Place random functions to see if the destructor works as needed
    // It probably will

    Matrix m(2, 2, values);
  }

  SUCCEED();
}
