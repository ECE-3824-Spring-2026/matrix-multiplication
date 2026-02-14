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