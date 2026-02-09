#include<iostream>
#include"../matrix.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Constructor"){
    float a[] = {1,2,3,4};
    REQUIRE_THROWS(Matrix(0,0,a));
    REQUIRE_THROWS(Matrix(2,0,a));
    REQUIRE_THROWS(Matrix(0,2,a));   
    REQUIRE_THROWS(Matrix(-1,2,a));   

    // REQUIRE_THROWS(Matrix(2,2.5,a));   
    // This should be an error but C++ compiler allows 
    // it unless -Wconversion flag is added to compiler.
    // That will give a warning not a runtime exception.
}

TEST_CASE("Addition Test"){
    float a[] = {1  ,2  ,3  ,4};
    float b[] = {1.5,2.5,3.5,4.5};
    float c[] = {2.5,4.5,6.5,8.5};
    float d[] = {1,2,3};
    float e[] = {3,4,5,6};
    Matrix A (2,2,a);
    Matrix B (2,2,b);
    Matrix C (2,2,c);
    Matrix D (1,3,d);
    Matrix E (2,2,e);
    REQUIRE(A+B == C);
    REQUIRE(B + 1.5 == E);
    REQUIRE_THROWS(A+D);   
}

TEST_CASE("Subtraction Test"){
    float a[] = {1  ,2  ,3  ,4};
    float b[] = {1.5,2.5,3.5,4.5};
    float c[] = {0.5,0.5,0.5,0.5};
    float d[] = {1,2,3};
    float e[] = {1.25,2.25,3.25,4.25};
    Matrix A (2,2,a);
    Matrix B (2,2,b);
    Matrix C (2,2,c);
    Matrix D (1,3,d);
    Matrix E (2,2,e);
    REQUIRE(B-A == C);
    REQUIRE(B-0.25 == E);
    REQUIRE_THROWS(A+D);   
}

TEST_CASE("Transpose"){
    float v[] = {1,2,3};
    Matrix A (1,3,v);
    Matrix B (3,1,v);
    REQUIRE(A == B.transpose());    
    REQUIRE(B == A.transpose());    
}

int alternate_main(){
    float v[] = {1,2,3,4};
    Matrix A(2,2,v);
    Matrix B = A + 4;
    
    cout << endl;

    cout << "Matrix A" << endl;
    A.display();

    cout << endl;

    cout << "Matrix B" << endl;
    B.display();

    cout << endl;

    cout << "A(1,1) = " << A(1,1) << endl;
    cout << "B(0,1) = " << B(0,1) << endl;

    cout << endl;

    A(1,0) = 1.1f;
    cout << "Matrix A" << endl;
    A.display();

    cout << endl;
    cout << "Matrix C = A / 4.2" << endl;
    Matrix C = A / 4.2f;
    C.display();

    cout << endl;
    cout << "Matrix D = A / 0.0" << endl;
    try{
        Matrix D = A / 0.0;
        D.display();
    }
    catch(domain_error& e){
        cout << "Error: " << e.what() << endl;
    }

    cout << endl;
    cout << "Add matrix A and B, same dims" << endl;
    C = A + B;
    C.display();

    cout << endl;
    cout << "Add matrix A and E, different dims" << endl;
    try{
        float w[] = {-1,-2};
        Matrix E(1,2,w);
        C = A + E;
        C.display();
    }
    catch(invalid_argument& e){
        cout << "Error: " << e.what() << endl; 
    }

    cout << endl;
    cout << "determinant of matrix A" << endl;
    A.display();
    cout << "det(A) = " << A.determinant() << endl;;

    cout << endl;
    cout << "determinant of matrix D" << endl;
    float z[] = {5,-7,2,2,0,3,0,-4,-5,-8,0,3,0,5,0,-6};
    Matrix D(4,4,z);
    D.display();
    cout << "det(D) = " << D.determinant() << endl;

    cout << endl;
    cout << "A*B = " << endl;
    Matrix E = A*B;
    E.display();
    cout << endl;    

    cout << endl;
    cout << "Testing if A==A" << endl;
    cout << "It is " << (A==A ? "true" : "false") << " that A==A" << endl;
    cout << endl;

    cout << endl;
    cout << "Testing if A==B" << endl;
    cout << "It is " << (A==B ? "true" : "false") << " that A==B" << endl;
    cout << endl;

    return 0;
}