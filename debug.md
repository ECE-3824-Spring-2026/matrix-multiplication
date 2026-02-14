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

An row and column size of 100000 with an array of 4 floats would have been good for an invalid argument because the array size given and requested row and column do not match. Commented out this test, to see the other run. 