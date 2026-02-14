# Debug Notes

```C++
code is seg faulting before the remaining test can be ran.
```

## Catch2

two different versions of catch2 were being used in the testing folder. Several files where using catch2 2v. The makefile supported catch2 3v which required:
```C++
#include <catch2/catch_test_macros.hpp>
```
removed the catch.cpp

## Fails/Crashes

A test code in constructor is failing due to this constructor implementation

when data was being used elsewhere in the program trying to retrieve values it did not have from being assigned nullptr. 
Used the same idea but instead initialized the matrix with zeros. None of the other test would run with this error. 

operator() needed error check, still getting seg fault. 

test_constructor is falling from this:
```C++
TEST_CASE("Memory Issues"){
    float vals[] = {1.0f, 2.0f, 3.0f, 4.0f};
    
    REQUIRE_THROWS_AS(Matrix(100000, 100000, vals), std::invalid_argument);
    REQUIRE_THROWS_AS(Matrix(2, 2, nullptr), std::invalid_argument);  
}
```
The test is expecting a invalid argument. the original constructor did not have many catches for error checks. The rewritten function to reflect same behavior and idea does not have this error as well. 

A row and column size of 100000 with an array of 4 floats would have been good for an invalid argument because the array size given and requested row and column do not match. The constructor does not catch this kind error. Commented out this test, to see the other run. 

```C++
./run_tests 
Randomness seeded to: 3766175149
ERROR: Input data pointer is null. Matrix will be initialized with zeros.

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
run_tests is a Catch2 v3.4.0 host application.
Run with -? for options

-------------------------------------------------------------------------------
Matrix addition - basic 2x2
-------------------------------------------------------------------------------
testing/test_addition.cpp:9
...............................................................................

testing/test_addition.cpp:19: FAILED:
  REQUIRE( C == Expected )
with expansion:
  {?} == {?}

ERROR: Input data pointer is null. Matrix will be initialized with zeros.
-------------------------------------------------------------------------------
Matrix addition - different dimensions 2x3
-------------------------------------------------------------------------------
testing/test_addition.cpp:22
...............................................................................

testing/test_addition.cpp:32: FAILED:
  REQUIRE( C == Expected )
with expansion:
  {?} == {?}

ERROR: Input data pointer is null. Matrix will be initialized with zeros.
Error-------------------------------------------------------------------------------
Matrix addition - incompatible dimensions throws error
-------------------------------------------------------------------------------
testing/test_addition.cpp:48
...............................................................................

testing/test_addition.cpp:55: FAILED:
  REQUIRE_THROWS_AS( A + B, std::invalid_argument )
due to unexpected exception with :

[   1.00  2.00  3.00 ]
[   4.00  5.00  6.00 ]
ERROR: Invalid matrix dimensions. Rows and columns must be positive.
-------------------------------------------------------------------------------
Input Rows/Columns Argument Errors
-------------------------------------------------------------------------------
testing/test_constructor.cpp:41
...............................................................................

testing/test_constructor.cpp:45: FAILED:
  REQUIRE_THROWS_AS( Matrix(0, 2, vals), std::invalid_argument )
because no exception was thrown where one was expected:

-------------------------------------------------------------------------------
Value Retrieval Bounds
-------------------------------------------------------------------------------
testing/test_constructor.cpp:75
...............................................................................

testing/test_constructor.cpp:80: FAILED:
  REQUIRE_THROWS_AS( m(-1, 0), std::invalid_argument )
due to unexpected exception with message:
  Matrix index out of bounds

-------------------------------------------------------------------------------
Value Assignment Bounds
-------------------------------------------------------------------------------
testing/test_constructor.cpp:109
...............................................................................

testing/test_constructor.cpp:115: FAILED:
  REQUIRE_THROWS_AS( m(0,2)=1.0f, std::invalid_argument )
due to unexpected exception with message:
  Matrix index out of bounds

-------------------------------------------------------------------------------
Row and column operations
  Determinant scales when a row is multiplied by a scalar
-------------------------------------------------------------------------------
testing/test_determinant.cpp:318
...............................................................................

testing/test_determinant.cpp:331: FAILED:
  REQUIRE( fabs(A.determinant() - 1.0f) < 0.0001f )
with expansion:
  10.0f < 0.0001f

-------------------------------------------------------------------------------
Row and column operations
  Determinant unchanged when adding a multiple of one row to another
-------------------------------------------------------------------------------
testing/test_determinant.cpp:335
...............................................................................

testing/test_determinant.cpp:348: FAILED:
  REQUIRE( fabs(A.determinant() - 1.0f) < 0.0001f )
with expansion:
  10.0f < 0.0001f

ERROR: Input data pointer is null. Matrix will be initialized with zeros.
-------------------------------------------------------------------------------
Scalar division with basic positive number
-------------------------------------------------------------------------------
testing/test_float_divide.cpp:9
...............................................................................

testing/test_float_divide.cpp:20: FAILED:
  REQUIRE( B(0,0) == (1.0f) )
with expansion:
  454667.21875f == 1.0f

free(): double free detected in tcache 2
testing/test_float_divide.cpp:20: FAILED:
  {Unknown expression after the reported line}
due to a fatal error condition:
  SIGABRT - Abort (abnormal termination) signal

===============================================================================
test cases:  34 | 26 passed |  8 failed
assertions: 101 | 91 passed | 10 failed

Aborted (core dumped)
```